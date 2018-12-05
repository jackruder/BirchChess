#pragma once
#include "bbtypes.h"

class position
{

private:
	//Data
	//Bitboards
	BitBoard ptypeBB[NUM_PIECE_TYPES]; //includes bbs for all pieces, pieces of different types
	BitBoard colorsBB[NUM_COLORS]; // includes bbs for all colors
	
	
public:
	position();
	~position();
};

