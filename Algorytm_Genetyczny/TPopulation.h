#pragma once

#include "TCandidate.h"

class TPopulation
{
	unsigned int _id;
	unsigned int best_id;
	double best_val;
	static unsigned int candidates_count;
	
	std::vector<TCandidate> candidates;

public:
	TPopulation(int cand_num);

	void calculate();
	TCandidate best_candidate();
	void info();
};

