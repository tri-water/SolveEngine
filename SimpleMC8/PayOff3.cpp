#include "PayOff3.h"
#include <minmax.h>

PayOffCall::PayOffCall(double fStrike):
	Strike(fStrike){}

double PayOffCall::operator()(double Spot) const
{
	return max(Spot - Strike, 0.0);
}

PayOff* PayOffCall::clone() const
{
	return new PayOffCall(*this);
}

PayOffPut::PayOffPut(double fStrike):
	Strike(fStrike){}

double PayOffPut::operator()(double Spot) const
{
	return max(Strike - Spot, 0.0);
}

PayOff* PayOffPut::clone() const
{
	return new PayOffPut(*this);
}