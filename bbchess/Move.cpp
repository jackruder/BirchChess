#include "Move.h"



Move::Move(Square from, Square to, MoveType flag)
{
}



int Move::getFrom() const
{
	return (_move >>6) & 0x3f;
}

int Move::getTo() const
{
	return (_move & 0x3f);
}

int Move::getFlags() const
{
	return (_move >> 12) & 0x0f;
}

void Move::setFrom(int from)
{
	_move &= ~0xfc0;
	_move |= (from & 0x3f) << 6;
}

void Move::setTo(int to)
{
	_move &= ~0x3f;
	_move |= to & 0x3f;
}

void Move::setFlags(int flags)
{
	_move &= ~0x0fff;
	_move |= (flags & 0x0f) << 12;

}

bool Move::isCapture() const
{
	return ((_move & 0x2000) >> 13) == 1;
}