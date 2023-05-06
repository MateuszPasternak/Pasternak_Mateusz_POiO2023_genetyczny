#pragma once

#include "TCandidate.h"

class TPopulation
{
	unsigned int _id;
	static unsigned int pop_count;

	unsigned int best_id = 0;
	double best_val = 0;
	
	std::vector<TCandidate> candidates;

public:
	TPopulation(int cand_num, bool rand = false);

	void calculate();
	TCandidate best_candidate();
	void info();

	unsigned int get_id() { return _id; };
	unsigned int get_pop_count() { return pop_count; };
	double get_best_val() { return best_val; };
	double get_best_val_id() { return best_id; };
};

