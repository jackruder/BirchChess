#pragma once
#include "bitboard.h"
namespace BitBoards
{
	//attack generators for sliding pieces
	BitBoard diagonalAttacks(BitBoard occ, Square sq);
	BitBoard antiAttacks(BitBoard occ, Square sq);
	BitBoard fileAttacks(BitBoard occ, Square sq);
	BitBoard rankAttacks(BitBoard occ, Square sq);

	//pawn stuff

	BitBoard wSinglePush(BitBoard wpawns, BitBoard empty);
	BitBoard wDoublePush(BitBoard wpawns, BitBoard empty);
	BitBoard bSinglePush(BitBoard bpawns, BitBoard empty);
	BitBoard bDoublePush(BitBoard bpawns, BitBoard empty);
	BitBoard wCanPushOne(BitBoard wpawns, BitBoard empty);
	BitBoard wCanPushTwo(BitBoard wpawns, BitBoard empty);
	BitBoard bCanPushOne(BitBoard bpawns, BitBoard empty);
	BitBoard bCanPushTwo(BitBoard bpawns, BitBoard empty);
} 