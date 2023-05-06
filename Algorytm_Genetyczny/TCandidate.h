#pragma once

#include "TGen.h"

#define GENS_NUM 6

class TCandidate
{
	double ocena;
	std::vector<TGen> genotyp;

public:
	TCandidate();
	void rand_gens_val();
	void rate();
	void info();
	double get_rate();
};

