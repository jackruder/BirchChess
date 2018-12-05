#include "bitboard.h"
#include "bbtypes.h"
#include <iostream>
#include <string>

int main()
{
	BitBoards::init();

	for (Square sq = SQ_A1; sq <= SQ_H8; ++sq)
	{
		std::string north = BitBoards::pretty(BitBoards::NORTHMASK[sq]);
		std::string south = BitBoards::pretty(BitBoards::SOUTHMASK[sq]);
		std::string east = BitBoards::pretty(BitBoards::EASTMASK[sq]);
		std::string west = BitBoards::pretty(BitBoards::WESTMASK[sq]);
		std::string rank = BitBoards::pretty(BitBoards::EASTMASK[sq] | BitBoards::WESTMASK[sq]);
		std::string file = BitBoards::pretty(BitBoards::NORTHMASK[sq] | BitBoards::SOUTHMASK[sq]);
		std::string rook = BitBoards::pretty(BitBoards::NORTHMASK[sq] | BitBoards::SOUTHMASK[sq] | BitBoards::EASTMASK[sq] | BitBoards::WESTMASK[sq]);
		std::cout << "rank " << sq << std::endl << rank << std::endl;
		std::cout << "file " << sq << std::endl << file << std::endl;
		std::cout << "rook " << sq << std::endl << rook << std::endl;
		std::cin.ignore();
	}
	return 0;
}