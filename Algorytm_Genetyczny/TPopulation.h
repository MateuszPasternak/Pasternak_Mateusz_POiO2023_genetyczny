#pragma once

#include "TCandidate.h"

class TPopulation
{
	unsigned int _id;
	static unsigned int pop_count;

	unsigned int best_id = 0;
	double best_val = 0;

	unsigned int cand_count;
	unsigned int Max_candidates_num;
	
	std::vector<TCandidate> candidates;

public:
	TPopulation(int cand_num, bool rand = false);

	void calculate();
	TCandidate best_candidate();
	void info();
	void add_Candidate(TCandidate candidateAdded, int id);
	void generate_restOfCandidates();
	void iterate_candidatesCount(int times);

	unsigned int get_id() { return _id; };
	unsigned int get_pop_count() { return pop_count; };
	unsigned int get_cand_count() { return cand_count; };
	unsigned int get_cand_MaxCount() { return Max_candidates_num; };
	double get_best_val() { return best_val; };
	double get_best_val_id() { return best_id; };
	std::vector<TCandidate> get_candidatesList() { return candidates; };
};

