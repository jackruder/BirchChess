#include "Move.h"



Move::Move(Square from, Square to, MoveType flags)
{
	_move |= (flags & 0x0f) << 12;
	_move |= (from & 0x3f) << 6;
	_move |= to & 0x3f;
}

Move::Move(const Move& move)
	:_move(move.getMove16())
{
}

Move::Move(const uint16_t& move)
	:_move(move)
{
}

uint16_t Move::getMove16() const
{
	return _move;
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
bool Move::isQuiet() const
{
	return ((_move >> 12) == 0);
}
bool Move::isCapture() const
{
	return ((_move & 0x2000) >> 13) == 1;
}

ExtMove::ExtMove(Square from, Square to, MoveType flags, PieceType ptype_moving, Color c_moving, PieceType ptype_captured = NO_PIECE_TYPE, Color c_captured = WHITE)
	: Move(from, to, flags)
{ 
	_ext |= (c_captured << 7);
	_ext |= (ptype_captured << 4);
	_ext |= (c_moving << 3);
	_ext |= (ptype_moving);
}

ExtMove::ExtMove(Move move, PieceType ptype_moving, Color c_moving, PieceType ptype_captured, Color c_captured)
	: Move(move)
{
	_ext |= (c_captured << 7);
	_ext |= (ptype_captured << 4);
	_ext |= (c_moving << 3);
	_ext |= (ptype_moving);
}

ExtMove::ExtMove(uint16_t move, PieceType ptype_moving, Color c_moving, PieceType ptype_captured, Color c_captured)
	: Move(move)
{
	_ext |= (c_captured << 7);
	_ext |= (ptype_captured << 4);
	_ext |= (c_moving << 3);
	_ext |= (ptype_moving);
}

int ExtMove::getMovingPieceType() const
{
	return _ext & 0x07;
}

int ExtMove::getMovingPieceColor() const
{
	return _ext & 0x08;
}
int ExtMove::getCapturedPieceType() const
{
	return (_ext >> 4) & 0x07;
}

int ExtMove::getCapturedPieceTypeColor() const  //This will return white by default, so check if there is actually a piece type
{
	return (_ext >> 4) & 0x08;
}