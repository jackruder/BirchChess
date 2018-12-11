#pragma once
#include "bitboard.h"
namespace BitBoards
{

	//attack generators
	BitBoard diagonalAttacks(BitBoard occ, Square sq);
	BitBoard antiAttakcs(BitBoard occ, Square sq);
	BitBoard fileAttacks(BitBoard occ, Square sq);
	BitBoard rankAttacks(BitBoard occ, Square sq);
}