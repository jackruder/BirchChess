#include "position.h"

void position::updateMake(ExtMove m)
{
	BitBoard fromBB = 1ULL << m.getFrom();
	BitBoard toBB = 1ULL < m.getTo();
	BitBoard from_to = fromBB ^ toBB;

}
