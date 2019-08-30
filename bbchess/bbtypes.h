#pragma once
#include <cstdint>
#include <cassert>

typedef std::uint64_t BitBoard;



enum Color {WHITE, BLACK, NUM_COLORS = 2};


enum Piece { //enum for piece names
	NO_PIECE = 0,
	W_PAWN = 1, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
	B_PAWN = 9, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
	NUM_PIECES = 16
};

enum PieceType {
	
	NO_PIECE_TYPE = 0, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
	ALL_PIECES = 0,
	NUM_PIECE_TYPES = 8
};

enum MoveType {  //from lsb to msb: 1st bit - promo; 2nd bit-captures; last two bits for special cases
	QUIET, //no captures, no promotions 
	PUSHTWO, //pawn move 2 squares, last two bits 01
	CASTLE_KING, //last two bits 10
	CASTLE_QUEEN, //last two bits 11
	CAPTURE,
	EN_PASSANT,  //Last bit is 1, is capture
	PROMO_KN, PROMO_B, PROMO_R, PROMO_Q,    //KN = 00, B = 01, R = 10, Q = 11
	CAP_PROMO_KN, CAP_PROMO_B, CAP_PROMO_R, CAP_PROMO_Q,
};

enum Square : int { //enum for algebraic sqare names LERF mapping
	SQ_A1, SQ_B1, SQ_C1, SQ_D1, SQ_E1, SQ_F1, SQ_G1, SQ_H1,
	SQ_A2, SQ_B2, SQ_C2, SQ_D2, SQ_E2, SQ_F2, SQ_G2, SQ_H2,
	SQ_A3, SQ_B3, SQ_C3, SQ_D3, SQ_E3, SQ_F3, SQ_G3, SQ_H3,
	SQ_A4, SQ_B4, SQ_C4, SQ_D4, SQ_E4, SQ_F4, SQ_G4, SQ_H4,
	SQ_A5, SQ_B5, SQ_C5, SQ_D5, SQ_E5, SQ_F5, SQ_G5, SQ_H5,
	SQ_A6, SQ_B6, SQ_C6, SQ_D6, SQ_E6, SQ_F6, SQ_G6, SQ_H6,
	SQ_A7, SQ_B7, SQ_C7, SQ_D7, SQ_E7, SQ_F7, SQ_G7, SQ_H7,
	SQ_A8, SQ_B8, SQ_C8, SQ_D8, SQ_E8, SQ_F8, SQ_G8, SQ_H8,
	NUM_SQUARES = 64
};

enum File : int {
	FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, NUM_FILES
};

enum Rank : int {
	RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, NUM_RANKS
};

enum Direction : int {  //enum defining cardinal bitboard directions
	NORTH = 8,
	SOUTH = -8,
	EAST = 1,
	WEST = -1,

	NORTH_EAST = 9,
	NORTH_WEST = 7,
	SOUTH_EAST = -7,
	SOUTH_WEST = -9
	
};


//allows adding a direction to a square to find new square
constexpr Square operator+(Square s, Direction d) { return Square(int(s) + int(d)); }
constexpr Square operator-(Square s, Direction d) { return Square(int(s) - int(d)); }
inline Square& operator+=(Square& s, Direction d) { return s = s + d; }
inline Square& operator-=(Square& s, Direction d) { return s = s - d; }

#define OVERLOALD_ALG(T)											\
constexpr T operator+(T d1, T d2) { return T(int(d1) + int(d2)); }  \
constexpr T operator-(T d1, T d2) { return T(int(d1) - int(d2)); }  \
constexpr T operator-(T d) { return T(-int(d)); }					\
inline T& operator+=(T& d1, T d2) { return d1 = d1 + d2; }			\
inline T& operator-=(T& d1, T d2) { return d1 = d1 - d2; }

#define OVERLOAD_INC(T)											    \
inline T& operator++(T& d) { return d = T(int(d) + 1); }		    \
inline T& operator--(T& d) { return d = T(int(d) - 1); }

#define OVERLOAD_ALL(T)												 \
OVERLOALD_ALG(T)													 \
OVERLOAD_INC(T)														 \
constexpr T operator*(int i, T d) { return T(i * int(d)); }			 \
constexpr T operator*(T d, int i) { return T(int(d) * i); }			 \
constexpr T operator/(T d, int i) { return T(int(d) / i); }			 \
constexpr int operator/(T d1, T d2) { return int(d1) / int(d2); }	 \
inline T& operator*=(T& d, int i) { return d = T(int(d) * i); }		 \
inline T& operator/=(T& d, int i) { return d = T(int(d) / i); } 

OVERLOAD_ALL(Direction)
OVERLOAD_INC(PieceType)
OVERLOAD_INC(Piece)
OVERLOAD_INC(Color)
OVERLOAD_INC(Square)
OVERLOAD_INC(File)
OVERLOAD_INC(Rank)

#undef OVERLOAD_ALL
#undef OVERLOAD_INC
#undef OVERLOAD_ALG

//utility functions for defined types
// returns the opposite color
constexpr Color operator~(Color c) { return Color(c^1); }


//gets square at location specified by file and RANKS
constexpr Square get_square(File f, Rank r) { return Square((r << 3) + f); } //n << 3 = 2^3 * n 

constexpr Piece get_piece(PieceType t, Color c) { return Piece((c << 3) + t); } //gets piece of a certain color and type
constexpr PieceType get_ptype(Piece p) { return PieceType(p & 7); }

inline Color get_color(Piece p) //finds color of a piece 
{
 	assert(p != NO_PIECE); //cant get type of null piece
	return Color(p >> 3);
}

constexpr bool valid(Square s) { return s >= SQ_A1 && s <= SQ_H8; }//checks if square is valid

constexpr File get_file(Square s) { return File(s & 7); } //gets file of s
constexpr Rank get_rank(Square s) { return Rank(s >> 3); } // gets RANKS of s


//Finds the allowed movement of direction for pawn of Color c
constexpr Direction pawn_direction(Color c) { return c == WHITE ? NORTH : SOUTH; }

