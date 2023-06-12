#pragma once

#include "TGen.h"

#define GENS_NUM 6

class TCandidate
{
protected:
	double ocena;
	std::vector<TGen> genotyp;
	double crossPossibiltyRate;

public:
	TCandidate();
	virtual void rand_gens_val();
	void set_gens(TCandidate Parent1, TCandidate Parent2, int crossOverPoint);
	void rate();
	void info();
	void set_CrossPossibilityRate();
	double get_rate();
	double get_CrossPossibilityRate() { return crossPossibiltyRate; };
	std::vector<TGen> get_genotypeOfCand() { return genotyp; };
};

