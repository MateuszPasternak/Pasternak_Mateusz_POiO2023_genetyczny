#pragma once

#include "TGen.h"
#include <vector>

class TCandidate
{
	double ocena;
	std::vector<TGen> genotyp;

public:
	TCandidate();

	void rand_gens_val();
	void rate();
	void info();
};

