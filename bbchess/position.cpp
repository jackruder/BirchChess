#include "position.h"

void position::updateMake(ExtMove m)
{
	
	int move = m.getFlags();
	BitBoard fromBB = 1ULL << m.getFrom();
	BitBoard toBB = 1ULL < m.getTo();
	BitBoard from_to = fromBB ^ toBB;
	switch (move)
	{
	case QUIET:
		
		ptypeBB[m.getMovingPieceType()] ^= from_to;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case PUSHTWO:
	
		ptypeBB[m.getMovingPieceType()] ^= from_to;
		colorsBB[m.getMovingPieceColor()] ^= from_to;
		
	case CASTLE_KING:
		break;

	case CASTLE_QUEEN:
		break;

	case CAPTURE:
	
		ptypeBB[m.getCapturedPieceType()] ^= toBB;
		ptypeBB[m.getCapturedPieceTypeColor()] ^= toBB;
		ptypeBB[m.getMovingPieceType()] ^= from_to;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case EN_PASSANT:
		break;

	case PROMO_KN:
	
		ptypeBB[m.getMovingPieceType()] ^= fromBB; 
		ptypeBB[KNIGHT] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case PROMO_B:
	
		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[BISHOP] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case PROMO_R:

		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[ROOK] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case PROMO_Q:

		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[QUEEN] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case CAP_PROMO_KN:

		ptypeBB[m.getCapturedPieceType()] ^= toBB;
		ptypeBB[m.getCapturedPieceTypeColor()] ^= toBB;
		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[KNIGHT] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case CAP_PROMO_B:

		ptypeBB[m.getCapturedPieceType()] ^= toBB;
		ptypeBB[m.getCapturedPieceTypeColor()] ^= toBB;
		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[BISHOP] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case CAP_PROMO_R:
		
		ptypeBB[m.getCapturedPieceType()] ^= toBB;
		ptypeBB[m.getCapturedPieceTypeColor()] ^= toBB;
		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[ROOK] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	case CAP_PROMO_Q:
	
		ptypeBB[m.getCapturedPieceType()] ^= toBB;
		ptypeBB[m.getCapturedPieceTypeColor()] ^= toBB;
		ptypeBB[m.getMovingPieceType()] ^= fromBB;
		ptypeBB[QUEEN] ^= toBB;
		colorsBB[m.getMovingPieceColor()] ^= from_to;

	}
}
     