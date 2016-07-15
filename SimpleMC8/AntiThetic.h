#pragma once
#include "Random2.h"
#include "Wrapper2.h"

class AntiThetic : public RandomBase
{
public:
	AntiThetic(const Wrapper<RandomBase>& finnerGenerator);
	virtual RandomBase* clone() const;
	virtual void GetUniforms(std::vector<double>& variates);
	virtual void Skip(unsigned long numberOfPaths);
	virtual void SetSeed(unsigned long Seed);
	virtual void ResetDimensionality(unsigned long NewDimensionality);
	virtual void Reset();
private:
	Wrapper<RandomBase> InnerGenerator;
	bool OddEven;
	std::vector<double> NextVariates;
};