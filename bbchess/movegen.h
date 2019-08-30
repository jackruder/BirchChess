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
	//pushes
	BitBoard wpSinglePush(BitBoard wpawns, BitBoard empty);
	BitBoard wpDoublePush(BitBoard wpawns, BitBoard empty);
	BitBoard bpSinglePush(BitBoard bpawns, BitBoard empty);
	BitBoard bpDoublePush(BitBoard bpawns, BitBoard empty);
	BitBoard wpCanPushOne(BitBoard wpawns, BitBoard empty);
	BitBoard wpCanPushTwo(BitBoard wpawns, BitBoard empty);
	BitBoard bpCanPushOne(BitBoard bpawns, BitBoard empty);
	BitBoard bpCanPushTwo(BitBoard bpawns, BitBoard empty);
	//attacks
	inline BitBoard wpEastAttacks(BitBoard wpawns) { return northeastOne(wpawns); }
	inline BitBoard wpWestAttacks(BitBoard wpawns) { return northwestOne(wpawns); }
	inline BitBoard bpEastAttacks(BitBoard bpawns) { return southeastOne(bpawns); }
	inline BitBoard bpWestAttacks(BitBoard bpawns) { return southwestOne(bpawns); }

	inline BitBoard wpAllAttacks(BitBoard wpawns) { return wpEastAttacks(wpawns) | wpWestAttacks(wpawns); }
	inline BitBoard bpAllAttacks(BitBoard bpawns) { return bpEastAttacks(bpawns) | bpWestAttacks(bpawns); }
	inline BitBoard wpAttackedTwice(BitBoard wpawns) { return wpEastAttacks(wpawns) & wpWestAttacks(wpawns); }
	inline BitBoard bpAttackedTwice(BitBoard bpawns) { return bpEastAttacks(bpawns) & bpWestAttacks(bpawns); }
	inline BitBoard wpAttackedOnce(BitBoard wpawns) { return wpEastAttacks(wpawns) ^ wpWestAttacks(wpawns); }
	inline BitBoard bpAttackedOnce(BitBoard bpawns) { return bpEastAttacks(bpawns) ^ bpWestAttacks(bpawns); }

	//captures
	inline BitBoard wpCanCaptureEast(BitBoard wpawns, BitBoard bpieces) { return (bpWestAttacks(bpieces) & wpawns); }
	inline BitBoard wpCanCaptureWest(BitBoard wpawns, BitBoard bpieces) { return (bpEastAttacks(bpieces) & wpawns); }
	inline BitBoard bpCanCaptureEast(BitBoard bpawns, BitBoard wpieces) { return (wpWestAttacks(wpieces) & bpawns); }
	inline BitBoard bpCanCaptureWest(BitBoard bpawns, BitBoard wpieces) { return (wpEastAttacks(wpieces) & bpawns); }
	inline BitBoard wpCanCapture(BitBoard wpawns, BitBoard bpieces) { return bpAllAttacks(bpieces) & wpawns; }
	inline BitBoard bpCanCapture(BitBoard bpawns, BitBoard wpieces) { return wpAllAttacks(wpieces) & bpawns; }

	//Piece attacks
	inline BitBoard knightAttacks(Square sq) { return KNIGHTMASK[sq]; }
	inline BitBoard kingAttacks(Square sq) { return KINGMASK[sq]; }
	inline BitBoard rookAttacks(BitBoard occ, Square sq) { return fileAttacks(occ, sq) | rankAttacks(occ, sq); }
	inline BitBoard bishopAttacks(BitBoard occ, Square sq) { return diagonalAttacks(occ, sq) | antiAttacks(occ, sq);}
	inline BitBoard queenAttacks(BitBoard occ, Square sq) { return fileAttacks(occ, sq) | rankAttacks(occ, sq) | diagonalAttacks(occ, sq) | antiAttacks(occ, sq); }
	BitBoard knightAttacks(BitBoard knights);
	
	
}


