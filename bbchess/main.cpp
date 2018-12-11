#include "bitboard.h"
#include "bbtypes.h"
#include <iostream>
#include <string>
#include <bitset>

int main()
{
	BitBoards::init();

	for (int i = 0; i < 63; i++)
		std::cout << std::bitset<8>(2 * i).to_string() << std::endl;
	std::cin.ignore();
	return 0;
}