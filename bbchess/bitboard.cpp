
#include "bitboard.h"
namespace BitBoards 
{
	BitBoard SQUARES[NUM_SQUARES];
	BitBoard FILES[NUM_FILES];
	BitBoard RANKS[NUM_RANKS];

	BitBoard NORTHMASK[NUM_SQUARES];
	BitBoard SOUTHMASK[NUM_SQUARES];
	BitBoard EASTMASK[NUM_SQUARES];
	BitBoard WESTMASK[NUM_SQUARES];
	BitBoard NWMASK[NUM_SQUARES];
	BitBoard NEMASK[NUM_SQUARES];
	BitBoard SWMASK[NUM_SQUARES];
	BitBoard SEMASK[NUM_SQUARES];
	uint8_t FIRSTRANKATTACKS[64*8];

	BitBoard RANKMASK[NUM_SQUARES];
	BitBoard FILEMASK[NUM_SQUARES];
	BitBoard DIAGONALMASK[NUM_SQUARES];
	BitBoard ANTIMASK[NUM_SQUARES];
	BitBoard KNIGHTMASK[NUM_SQUARES];
	BitBoard KINGMASK[NUM_SQUARES];
	
	//BitBoard ROOKMASKS[NUM_SQUARES];
	//BitBoard BISHOPMASKS[NUM_SQUARES];
	//BitBoard QUEENMASKS[NUM_SQUARES];
}

void BitBoards::fillSquares()
{
	for (Square s = SQ_A1; s <= SQ_H8; ++s)
		SQUARES[s] = (1ULL << s);
}

void BitBoards::fillFiles()
{
	for (File f = FILE_A; f <= FILE_H; ++f)
	{
		FILES[f] = (f > FILE_A) ? (FILES[f - 1] << 1) : (BBFILE_A);
	}
}

void BitBoards::fillRanks()
{
	for (Rank r = RANK_1; r <= RANK_8; ++r)
	{
		RANKS[r] = (r > RANK_1) ? (RANKS[r - 1] << 1) : (BBRANK_1);
	}
}

BitBoard BitBoards::removeSideBorder(BitBoard b)
{
	return b & 0b0111111001111110011111100111111001111110011111100111111001111110ULL;
}

BitBoard BitBoards::removeTopBorder(BitBoard b)
{
	return b & 0b0000000011111111111111111111111111111111111111111111111100000000ULL;
}

BitBoard BitBoards::removeBorder(BitBoard b)
{
	return b & 0b0000000001111110011111100111111001111110011111100111111000000000ULL;
}



void BitBoards::fillNorth()
{
	BitBoard north = 0x0101010101010100ULL;
	for (Square sq = SQ_A1; sq <= SQ_A8; ++sq, north <<= 1)
		NORTHMASK[sq] = north;
}

void BitBoards::fillSouth()
{
	BitBoard south = 0x0080808080808080ULL;
	for (Square sq = SQ_H8; sq >= SQ_A1; --sq, south >>= 1)
		SOUTHMASK[sq] = south;
}

void BitBoards::fillEast()
{
	const BitBoard one = 1ULL;
	for (Square sq = SQ_A1; sq <= SQ_H8; ++sq)
		EASTMASK[sq] = 2 * ((one << (sq | 7)) - (one << sq));
}

void BitBoards::fillWest()
{
	const BitBoard one = 1ULL;
	for (Square sq = SQ_A1; sq <= SQ_H8; ++sq)
		WESTMASK[sq] = (one << sq) - (one << (sq & 56));
}




void BitBoards::fillNorthEast()
{
	BitBoard noea = 0x8040201008040200ULL;
	for (File f = FILE_A; f <= FILE_H; ++f, noea = eastOne(noea))
	{
		BitBoard ne = noea; //so we can change in second iteration
		for (int r = 0; r < 64; r+=8, ne <<= 8)
		{
			NEMASK[r+f] = ne;
		}
	}

}

void BitBoards::fillNorthWest()
{
	BitBoard nowe = 0x102040810204000ULL;
	for (File f = FILE_H; f >= FILE_A; --f, nowe = westOne(nowe))
	{
		BitBoard nw = nowe; //so we can change in second iteration
		for (Rank r = RANK_1; r <= RANK_8; ++r, nw <<= 8)
		{
			NWMASK[get_square(f, r)] = nw;
		}
	}
}

void BitBoards::fillSouthEast()
{
	BitBoard soea = 0x002040810204080ULL;
	for (File f = FILE_A; f <= FILE_H; ++f, soea = eastOne(soea))
	{
		BitBoard se = soea;
		for (Rank r = RANK_8; r >= RANK_1; --r, se >>= 8)
		{
			SEMASK[get_square(f, r)] = se;
		}
	}
}

void BitBoards::fillSouthWest()
{
	BitBoard sowe = 0x0040201008040201ULL;
	for (File f = FILE_H; f >= FILE_A; --f, sowe = westOne(sowe))
	{
		BitBoard sw = sowe;
		for (Rank r = RANK_8; r >= RANK_1; --r, sw >>= 8)
		{
			SWMASK[get_square(f, r)] = sw;
		}
	}
}

void BitBoards::fillFirstRankAttacks()
{
	for (uint8_t occ = 0; occ < 64; ++occ)
	{
		for (File f = FILE_A; f <= FILE_H; ++f)
		{
			uint8_t buffer = 0;
			for (int l = f - 1; l >= 0; --l)
			{
				uint8_t piece = 1 << l;
				buffer |= piece;
				if ((2 * occ & piece) == piece) break;
			}

			for (int r = f + 1; r <= 8; ++r)
			{
				uint8_t piece = 1 << r;
				buffer |= piece;
				if ((2 * occ & piece) == piece) break;
			}
			FIRSTRANKATTACKS[8 * occ + f] = buffer;
		}
	}
}


void BitBoards::fillFRDmasks() //fill file, rook, diagonal/antidiagonal and queen masks
{
	for (Square s = SQ_A1; s <= SQ_H8; ++s)
	{
		RANKMASK[s] = WESTMASK [s] | EASTMASK[s];
		FILEMASK[s] = NORTHMASK[s] | SOUTHMASK[s];
		DIAGONALMASK[s] = NEMASK[s] | SWMASK[s];
		ANTIMASK[s] = NWMASK[s] | SEMASK[s];
		
		//BISHOPMASKS[s] = DIAGONALMASK[s] | ANTIMASK[s];
		//ROOKMASKS[s] = FILEMASK[s] | RANKMASK[s];
		//QUEENMASKS[s] = BISHOPMASKS[s] | ROOKMASKS[s];



	}
}

void BitBoards::fillKnight()
{
	for (Square sq = SQ_A1; sq < SQ_H8; ++sq)
	{
		BitBoard east, west, attacks;
		east = eastOne(sq);
		west = westOne(sq);
		attacks = (east | west) << 16;
		attacks |= (east | west) >> 16;
		east = eastOne(east);
		west = westOne(west);
		attacks |= (east | west) << 8;
		attacks |= (east | west) >> 8;
		KNIGHTMASK[sq] = attacks;
	}
}

void BitBoards::fillKing()
{
	for (Square sq = SQ_A1; sq < SQ_H8; ++sq)
	{
		BitBoard king = sq;
		BitBoard attacks = eastOne(sq) | westOne(sq);
		king |= attacks;
		attacks |= northOne(king) | southOne(king);
		KINGMASK[sq] = attacks;
	}
}

void BitBoards::init()
{
	fillRanks(); fillFiles(); fillSquares();
	fillNorth(); fillSouth(); fillEast(); fillWest();
	fillNorthEast(); fillNorthWest(); fillSouthEast(); fillSouthWest();
	fillFRDmasks(); fillFirstRankAttacks();	
	fillKnight(); fillKing();
}

const std::string BitBoards::pretty(BitBoard b) {

	std::string s = "+---+---+---+---+---+---+---+---+\n";

	for (Rank r = RANK_8; r >= RANK_1; --r)
	{
		for (File f = FILE_A; f <= FILE_H; ++f)
			s += b & get_square(f, r) ? "| X " : "|   ";

		s += "|\n+---+---+---+---+---+---+---+---+\n";
	}

	return s;
}