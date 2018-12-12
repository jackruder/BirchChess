#pragma once
#include "bitboard.h"
namespace BitBoards
{
	//attack generators
	BitBoard diagonalAttacks(BitBoard occ, Square sq);
	BitBoard antiAttacks(BitBoard occ, Square sq);
	BitBoard fileAttacks(BitBoard occ, Square sq);
	BitBoard rankAttacks(BitBoard occ, Square sq);
}