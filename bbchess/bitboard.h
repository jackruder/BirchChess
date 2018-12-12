#pragma once
#include "bbtypes.h"
#include <iostream>
//defining const bitboards, masks, and bitboard operations

namespace BitBoards
{
	void init();
	const std::string pretty(BitBoard b);

	//basic bitboards
	constexpr BitBoard ALLSQUARES = ~BitBoard(0);
	constexpr BitBoard WHITESQUARES = 0x55AA55AA55AA55AAULL;

	//Files
	constexpr BitBoard BBFILE_A = 0x0101010101010101ULL;
	constexpr BitBoard BBFILE_NOT_A = ~BBFILE_A;
	constexpr BitBoard BBFILE_NOT_H = ~(BBFILE_A << 7);


	//RANKS
	constexpr BitBoard BBRANK_1 = 0x00000000000000FFULL;
										

	//bitboard constants defining starting pieces
	constexpr BitBoard PAWNSTART = 0b0000000011111111000000000000000000000000000000001111111100000000ULL;
	constexpr BitBoard ROOKSTART = 0b1000000100000000000000000000000000000000000000000000000010000001ULL;
	constexpr BitBoard KNIGHTSTART = 0b0100001000000000000000000000000000000000000000000000000001000010ULL;
	constexpr BitBoard BISHOPSTART = 0b0010010000000000000000000000000000000000000000000000000000100100ULL;
	constexpr BitBoard QUEENSTART = 0b0000100000000000000000000000000000000000000000000000000000001000ULL;
	constexpr BitBoard KINGSTART = 0b0001000000000000000000000000000000000000000000000000000000010000ULL;
	constexpr BitBoard ALLWHITESTART = 0b0000000000000000000000000000000000000000000000001111111111111111ULL;
	constexpr BitBoard ALLBLACKSTART = 0b1111111111111111000000000000000000000000000000000000000000000000ULL;
	
	//bitboards to be filled at runtime in init()
	extern BitBoard SQUARES[NUM_SQUARES];
	extern BitBoard FILES[NUM_FILES];
	extern BitBoard RANKS[NUM_RANKS];
	
	extern BitBoard NORTHMASK[NUM_SQUARES];
	extern BitBoard SOUTHMASK[NUM_SQUARES];
	extern BitBoard EASTMASK[NUM_SQUARES];
	extern BitBoard WESTMASK[NUM_SQUARES];
	extern BitBoard NWMASK[NUM_SQUARES];
	extern BitBoard NEMASK[NUM_SQUARES];
	extern BitBoard SWMASK[NUM_SQUARES];
	extern BitBoard SEMASK[NUM_SQUARES];
	
	extern BitBoard RANKMASK[NUM_SQUARES];
	extern BitBoard FILEMASK[NUM_SQUARES];
	extern BitBoard DIAGONALMASK[NUM_SQUARES];
	extern BitBoard ANTIMASK[NUM_SQUARES];
	extern uint8_t FIRSTRANKATTACKS[8 * 64];

	//extern BitBoard ROOKMASKS[NUM_SQUARES];
	//extern BitBoard BISHOPMASKS[NUM_SQUARES];
	//extern BitBoard QUEENMASKS[NUM_SQUARES];
	
	BitBoard removeSideBorder(BitBoard b);
	BitBoard removeTopBorder(BitBoard b);
	BitBoard removeBorder(BitBoard b);

	void fillNorth();
	void fillSouth();
	void fillEast();
	void fillWest();	
	void fillNorthEast();
	void fillNorthWest();
	void fillSouthEast();
	void fillSouthWest();
	void fillFirstRankAttacks();
	
	void fillFRDmasks();
	
	void fillSquares();
	void fillFiles();
	void fillRanks();

	inline BitBoard operator&(BitBoard b, Square s) 
	{
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b & SQUARES[s];
	}

	inline BitBoard operator|(BitBoard b, Square s) 
	{
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b | SQUARES[s];
	}

	inline BitBoard operator^(BitBoard b, Square s)
	{
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b ^ SQUARES[s];
	}

	inline BitBoard& operator|=(BitBoard& b, Square s) 
	{
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b |= SQUARES[s];
	}

	inline BitBoard& operator^=(BitBoard& b, Square s) 
	{
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b ^= SQUARES[s];
	}

	inline BitBoard eastOne(BitBoard b)
	{
		return ((b << 1) & BBFILE_NOT_A);
	} 
	
	inline BitBoard northeastOne(BitBoard b)
	{
		return ((b << 9) & BBFILE_NOT_A);
	}
	
	inline BitBoard southeastOne(BitBoard b)
	{
		return ((b >> 7) & BBFILE_NOT_A);
	}

	inline BitBoard westOne(BitBoard b)
	{
		return ((b >> 1) & BBFILE_NOT_H);
	}
	inline BitBoard southwestOne(BitBoard b)
	{
		return ((b >> 9) & BBFILE_NOT_H);
	}
	inline BitBoard northwestOne(BitBoard b)
	{
		return ((b << 7) & BBFILE_NOT_H);
	}

}