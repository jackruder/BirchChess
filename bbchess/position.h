#pragma once
#include <iostream>
#include "bbtypes.h"
#include "Move.h"
class Position
{

private:
	//Data
	Color turn;
	int rule50;
	uint8_t castlingRights;  //lsb(1st bit) represents white kingside, 2nd is white queenside, third is black kingside, last is black queenside
	Square enPSquare;

	//Bitboards
	BitBoard ptypeBB[NUM_PIECE_TYPES]; //includes bbs for all pieces, pieces of different types
	BitBoard colorsBB[NUM_COLORS]; // includes bbs for all colors


public:

	Position(const std::string fen);
	void updateMake(ExtMove m);
	
	BitBoard attackedBy(Square sq) const;
	inline BitBoard getAll() //gets the bitboard containing all occupied squares
	{
		return colorsBB[0] & colorsBB[1];
	}

	inline BitBoard getEmpty() // gets the biboard of all empty squares
	{
		return ~(colorsBB[0] & colorsBB[1]);
	}
	
	inline BitBoard getSet(PieceType ptype, Color c)
	{
		return ptypeBB[ptype] & colorsBB[c];
	}
};
