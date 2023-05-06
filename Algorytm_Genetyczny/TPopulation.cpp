#include <iostream>
#include "TPopulation.h"

unsigned int TPopulation::pop_count = 0;

TPopulation::TPopulation(int cand_num, bool rand)
{
	for (size_t i = 0; i < cand_num; i++)
	{
		TCandidate cand;
		if (rand == true)
		{
			cand.rand_gens_val();
		}	
		this->candidates.push_back(cand);
	}

	best_val = 0;
	best_id = 0;

	this->_id = TPopulation::pop_count;
	TPopulation::pop_count++;
	calculate();
}

void TPopulation::calculate()
{
	double buff = -10000;
	double val;
	for (size_t i = 0; i < this->candidates.size(); i++)
	{
		candidates[i].rate();
		val = candidates[i].get_rate();

		if (val > buff)
		{
			buff = val;
			this->best_id = i;
		}
	}

	this->best_val = buff;
}

TCandidate TPopulation::best_candidate()
{
	return candidates[best_id];
}

void TPopulation::info()
{
	std::cout << "####### POPUlATION " << _id + 1 << "/" << pop_count << "#######\n";
	for (size_t i = 0; i < this->candidates.size(); i++)
	{
		std::cout << "++ candidate#" << i << ":\t" << this->candidates[i].get_rate() <<std::endl;
	}
	std::cout << "##########################\n";
}