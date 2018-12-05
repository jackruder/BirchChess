#pragma once
#include "bbtypes.h"
#include <iostream>
//defining bitboards and bitboard operations

namespace BitBoards
{
	void init();
	const std::string pretty(BitBoard b);

	//basic bitboards
	constexpr BitBoard ALLSQUARES = ~BitBoard(0);
	constexpr BitBoard WHITESQUARES = 0x55AA55AA55AA55AAULL;

	//Files
	constexpr BitBoard FILE_ABB = 0x0101010101010101ULL;
	constexpr BitBoard FILE_BBB = FILE_ABB << 1;
	constexpr BitBoard FILE_CBB = FILE_ABB << 2;
	constexpr BitBoard FILE_DBB = FILE_ABB << 3;
	constexpr BitBoard FILE_EBB = FILE_ABB << 4;
	constexpr BitBoard FILE_FBB = FILE_ABB << 5;
	constexpr BitBoard FILE_GBB = FILE_ABB << 6;
	constexpr BitBoard FILE_HBB = FILE_ABB << 7;

	//RANKSS 
	constexpr BitBoard RANK_1BB = 0x00000000000000FFULL;
	constexpr BitBoard RANK_2BB = RANK_1BB << (8 * 1);
	constexpr BitBoard RANK_3BB = RANK_1BB << (8 * 2);
	constexpr BitBoard RANK_4BB = RANK_1BB << (8 * 3);
	constexpr BitBoard RANK_5BB = RANK_1BB << (8 * 4);
	constexpr BitBoard RANK_6BB = RANK_1BB << (8 * 5);
	constexpr BitBoard RANK_7BB = RANK_1BB << (8 * 6);
	constexpr BitBoard RANK_8BB = RANK_1BB << (8 * 7);
										

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
	
	extern BitBoard RANKSMASK[NUM_SQUARES];
	extern BitBoard FILEMASK[NUM_SQUARES];
	extern BitBoard DIAGONALMASK[NUM_SQUARES];
	extern BitBoard ANTIMASK[NUM_SQUARES];

	void fillNorth();
	void fillSouth();
	void fillEast();
	void fillWest();
	
	void fillSquares();
	

	inline BitBoard operator&(BitBoard b, Square s) {
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b & SQUARES[s];
	}

	inline BitBoard operator|(BitBoard b, Square s) {
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b | SQUARES[s];
	}

	inline BitBoard operator^(BitBoard b, Square s) {
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b ^ SQUARES[s];
	}

	inline BitBoard& operator|=(BitBoard& b, Square s) {
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b |= SQUARES[s];
	}

	inline BitBoard& operator^=(BitBoard& b, Square s) {
		assert(s >= SQ_A1 && s <= SQ_H8);
		return b ^= SQUARES[s];
	}

}

