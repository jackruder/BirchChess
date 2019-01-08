#pragma once
#include "bbtypes.h"

class position
{

private:
	//Data
	Color turn;

	//Bitboards
	BitBoard ptypeBB[NUM_PIECE_TYPES]; //includes bbs for all pieces, pieces of different types
	BitBoard colorsBB[NUM_COLORS]; // includes bbs for all colors
	
	
public:
	
	 
	
	inline BitBoard getAll() //gets the bitboard containing all occupied squares
	{
		return colorsBB[0] & colorsBB[1];
	}

	inline BitBoard getEmpty() // gets the biboard of all empty squares
	{
		return ~(colorsBB[0] & colorsBB[1]);
	}
	
	inline BitBoard getSet(PieceTypes ptype, Color c)
	{
		return ptypeBB[ptype] & colorsBB[c];
	}
};
