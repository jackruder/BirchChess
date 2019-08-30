#include "bitboard.h"
#include "bbtypes.h"
#include <iostream>
#include <string>
#include <bitset>
#include "movegen.h"

int main()
{
	BitBoards::init();
	uint64_t hello = 534174112465763422ULL;
	for (Square sq = SQ_A1; sq <= SQ_H8; ++sq)
	{
		std::cout << BitBoards::pretty(hello) << std::endl;
		std::cout << BitBoards::pretty(BitBoards::rankAttacks(hello, sq)) << std::endl;
		std::cout << BitBoards::pretty(BitBoards::fileAttacks(hello, sq)) << std::endl;
		std::cout << BitBoards::pretty(BitBoards::diagonalAttacks(hello, sq)) << std::endl;
		std::cout << BitBoards::pretty(BitBoards::antiAttacks(hello, sq)) << std::endl;
		std::cin.ignore();
	}



	return 0;
}