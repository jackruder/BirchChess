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

BitBoard BitBoards::antiAttacks(BitBoard occ, Square sq)
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
	BitBoard attacks = FIRSTRANKATTACKS[occ * 4 + file] << r8;
	return attacks;
}

BitBoard BitBoards::wpSinglePush(BitBoard wpawns, BitBoard empty)
{
	return northOne(wpawns) & empty;
}

BitBoard BitBoards::wpDoublePush(BitBoard wpawns, BitBoard empty)
{
	const BitBoard r4 = 0x00000000FF000000ULL;
	BitBoard push_one = wpSinglePush(wpawns, empty);
	return wpSinglePush(push_one, empty) & empty & r4;
}

BitBoard BitBoards::bpSinglePush(BitBoard bpawns, BitBoard empty)
{
	return southOne(bpawns) & empty;
}

BitBoard BitBoards::bpDoublePush(BitBoard bpawns, BitBoard empty)
{
	const BitBoard r5 = 0x000000FF00000000ULL;
	BitBoard push_one = bpSinglePush(bpawns, empty);
	return bpSinglePush(push_one, empty) & empty & r5;
}

BitBoard BitBoards::wpCanPushOne(BitBoard wpawns, BitBoard empty)
{
	return southOne(empty) & wpawns;
}

BitBoard BitBoards::wpCanPushTwo(BitBoard wpawns, BitBoard empty)
{
	const BitBoard r4 = 0x00000000FF000000ULL;
	BitBoard emptyR3 = southOne(empty & r4) & empty;
	return wpCanPushOne(wpawns, emptyR3);
}

BitBoard BitBoards::bpCanPushOne(BitBoard bpawns, BitBoard empty)
{
	return northOne(empty) & bpawns;
}

BitBoard BitBoards::bpCanPushTwo(BitBoard bpawns, BitBoard empty)
{
	const BitBoard r5 = 0x000000FF00000000ULL;
	BitBoard emptyR6 = northOne(empty & r5) & empty;
	return bpCanPushOne(bpawns, emptyR6);
}


