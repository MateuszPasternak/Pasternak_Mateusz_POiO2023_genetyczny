#include "TCandidateStiffGensCount4.h"
#include <vector>
#include <iostream>
#include <random>

TCandidateStiffGensCount4::TCandidateStiffGensCount4()
{
	this->ocena = 0;
	this->rand_gens_val();
}

void TCandidateStiffGensCount4::rand_gens_val()
{
	for (size_t i = 0; i < 4; i++)
	{
		int min_i = rand() % 100;
		int max_i = min_i + rand() % 10000 + 1;
		int step_i = rand() % 10 + 1;
		std::uniform_real_distribution<double> unif_min(-min_i, min_i);
		std::uniform_real_distribution<double> unif_max(min_i, max_i);
		std::uniform_real_distribution<double> unif_step(0.001, step_i);

		std::default_random_engine ra;

		// Getting a random double value
		double min = unif_min(ra);
		double max = unif_max(ra);
		double step = unif_step(ra);

		std::uniform_real_distribution<double> unif_val(min, max);
		double val = unif_val(ra);

		std::string name = "gen_" + std::to_string(i + 1);

		TGen param{ min, max, step, val, name };
		genotyp.push_back(param);
	}
}