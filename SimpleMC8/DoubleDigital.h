#pragma once
#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff
{
public:
	PayOffDoubleDigital(double fLowerLevel, double fUpperLevel);
	virtual ~PayOffDoubleDigital() {}
	virtual double operator()(double Spot) const;

private:
	double LowerLevel;
	double UpperLevel;
};
