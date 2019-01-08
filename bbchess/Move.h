#pragma once
#include "bbtypes.h"
class Move
{
private:
	uint16_t _move;  //bits 1-6 for to, 7-12 for from, 13-16 for flag
public:
	Move(Square from, Square to, MoveType flag);
	
	//setters and getters
	int getFrom() const;
	int getTo() const;
	int getFlags() const;
	void setFrom(int from);
	void setTo(int to);
	void setFlags(int flags);

	bool isCapture() const; //sees if move is a capture

};

