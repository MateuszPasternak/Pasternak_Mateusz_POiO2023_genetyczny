#pragma once

#include "TGen.h"

#define GENS_NUM 2

class TCandidate
{
	double ocena;
	std::vector<TGen> genotyp;
	void rand_gens_val();

public:
	TCandidate();

	void rate();
	void info();
	double get_rate();
};

