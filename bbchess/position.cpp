#include "position.h"

Position::Position(const std::string fen)
{
	//for now we keep the game to pawns only
	//loop pawns
	//loop knights
	
	//ptypeBB[PAWN] = ;
	//colorsBB[WHITE] = ;
	//colorsBB[BLACK] = ;
	//rule50 = 0;
	
	
}

void Position::updateMake(ExtMove m)
{
	//firstly the pieces need to be moved, calculations are done later
	int move = m.getFlags();
	BitBoard fromBB = 1ULL << m.getFrom();
	BitBoard toBB = 1ULL < m.getTo();
	BitBoard from_to = fromBB ^ toBB;
	switch (move)
	{
	case QUIET:
		
		ptypeBB[m.getMovingPieceType()] ^= from_to;
		colorsBB[m.getMovingPieceColor()] ^= from_to;
		rule50 += 1;

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

BitBoard Position::attackedBy(Square sq) const
{
	return BitBoard();
}
     