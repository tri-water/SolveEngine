#pragma once
#include "MCStatistics.h"
#include "Wrapper2.h"

class ConvergenceTable : public StatisticsMC
{
public:
	ConvergenceTable(Wrapper<StatisticsMC> fInner);
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>> GetResultsSoFar() const;
	virtual StatisticsMC* clone() const;

private:
	Wrapper<StatisticsMC> Inner;
	std::vector<std::vector<double>> ResultsSoFar;
	unsigned long StoppingPoint;
	unsigned long PathsDone;
};