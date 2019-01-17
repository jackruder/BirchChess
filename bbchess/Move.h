#pragma once
#include "bbtypes.h"
class Move
{
protected:
	uint16_t _move;  //bits 1-6 for to, 7-12 for from, 13-16 for flag
public:
	Move(Square from, Square to, MoveType flags);
	Move(const Move & move);
	Move(const uint16_t & move);

	//setters and getters
	uint16_t getMove16() const;
	int getFrom() const;
	int getTo() const;
	int getFlags() const;
	void setFrom(int from);
	void setTo(int to);
	void setFlags(int flags);

	bool isCapture() const; //sees if move is a capture

};

class ExtMove : public Move
{
private:
	uint8_t _ext; //first four bits are for piece being moved, last four are for a capture if applicable.  last of the four bits reperesent color, first three represent piece type

	//int value //use later for move ordering, possibly add to _ext later
public:
	ExtMove(Square from, Square to, MoveType flags, PieceType ptype_moving, Color c_moving, PieceType ptype_captured, Color c_captured);
	ExtMove(Move move, PieceType ptype_moving, Color c_moving, PieceType ptype_captured, Color c_captured);
	ExtMove(uint16_t move, PieceType ptype_moving, Color c_moving, PieceType ptype_captured, Color c_captured);
	int getMovingPieceType() const;
	int getMovingPieceColor() const;
	int getCapturedPieceType() const;
	int getCapturedPieceTypeColor() const;

	

};

