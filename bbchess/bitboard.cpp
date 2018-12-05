
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

	BitBoard RANKSMASK[NUM_SQUARES];
	BitBoard FILEMASK[NUM_SQUARES];
	BitBoard DIAGONALMASK[NUM_SQUARES];
	BitBoard ANTIMASK[NUM_SQUARES];
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
	for (Square sq = SQ_H8; sq >= 0; --sq, south >>= 1)
		SOUTHMASK[sq] = south;
}

void BitBoards::fillEast()
{
	const BitBoard one = 1ULL;
	for (Square sq = SQ_A1; sq <= SQ_A8; ++sq)
		EASTMASK[sq] = 2 * ((one << (sq | 7)) - (one << sq));
}

void BitBoards::fillWest()
{
	const BitBoard one = 1ULL;
	for (Square sq = SQ_A1; sq <= SQ_A8; ++sq)
		WESTMASK[sq] = (one << sq) - (one << (sq & 56));
}



/*
void BitBoards::fillNorthEast()
{
	BitBoard noea = 0x8040201008040200ULL;
}
*/
void BitBoards::fillSquares()
{
	for (Square s = SQ_A1; s <= SQ_H8; ++s)
		SQUARES[s] = (1ULL << s);
}

void BitBoards::init()
{
	fillNorth(); fillSouth(); fillEast(); fillWest();
	fillSquares();
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