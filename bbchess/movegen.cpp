#include "movegen.h"



//hyperbola quinessence attacks
BitBoard BitBoards::diagonalAttacks(BitBoard occ, Square sq)
{
	BitBoard forward, reverse;
	forward = occ & DIAGONALMASK[sq];
	reverse = _byteswap_uint64(forward);
	forward -= SQUARES[sq];
	reverse -= _byteswap_uint64(SQUARES[sq]);
	forward ^= _byteswap_uint64(reverse);
	forward &= DIAGONALMASK[sq];
	return forward;
}

BitBoard BitBoards::antiAttakcs(BitBoard occ, Square sq)
{
	BitBoard forward, reverse;
	forward = occ & ANTIMASK[sq];
	reverse = _byteswap_uint64(forward);
	forward -= SQUARES[sq];
	reverse -= _byteswap_uint64(SQUARES[sq]);
	forward ^= _byteswap_uint64(reverse);
	forward &= ANTIMASK[sq];
	return forward;
}

BitBoard BitBoards::fileAttacks(BitBoard occ, Square sq)
{
	BitBoard forward, reverse;
	forward = occ & FILEMASK[sq];
	reverse = _byteswap_uint64(forward);
	forward -= SQUARES[sq];
	reverse -= _byteswap_uint64(SQUARES[sq]);
	forward ^= _byteswap_uint64(reverse);
	forward &= FILEMASK[sq];
	return forward;
}

//Simple rank attack generator to compliment above generators
BitBoard BitBoards::rankAttacks(BitBoard occ, Square sq)
{
	uint8_t file = sq & 7;
	uint8_t r8 = sq & 56;
	occ = (occ >> r8) & 126;
	BitBoard attacks = FIRSTRANKATTACKS[occ * 4 + file];
	return attacks;
}
