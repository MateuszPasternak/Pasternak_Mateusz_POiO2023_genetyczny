#include "PopulationStiff4Gens.h"

PopulationStiff4Gens::PopulationStiff4Gens(int cand_num, bool rand)
{
	this->Max_candidates_num = cand_num;

	for (size_t i = 0; i < cand_num; i++)
	{
		TCandidateStiffGensCount4 cand;
		if (rand == true)
		{
			//cand.rand_gens_val();
			this->candidates.push_back(cand);
		}
		else
		{
			this->candidates.push_back(cand);
		}
	}

	this->best_val = 0;
	this->best_id = 0;
	this->cand_count = cand_num;
	this->_id = PopulationStiff4Gens::pop_count;
	PopulationStiff4Gens::pop_count++;
	calculate();
}

void PopulationStiff4Gens::calculate()
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