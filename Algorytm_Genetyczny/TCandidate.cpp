#include "TCandidate.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <random>

TCandidate::TCandidate()
{
	this->ocena = 0;
	rand_gens_val();
}

void TCandidate::rand_gens_val()
{
	srand(time(NULL));

	for (size_t i = 0; i < 2; i++)
	{
		int min_i = rand() % 100;
		int max_i = min_i + rand() % 10000 +1;
		int step_i = rand() % 10 +1;
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

		TGen param{ min, max, step, val, name};
		genotyp.push_back(param);
	}
}

void TCandidate::rate()
{
	this->ocena = 2;

	for (size_t i = 0; i < this->genotyp.size(); i++)
	{
		this->ocena += genotyp[i].get_val();
	}
}

void TCandidate::info()
{
	std::cout << "\n############ GENOTYPE ###########\n" <<
		"++ gens count: " << this->genotyp.size();

	for (size_t i = 0; i < this->genotyp.size(); i++)
	{
		std::cout << "\n" <<
			"++ x" << std::to_string(i + 1) << ": " << genotyp[i].get_val()  << " And _id of this val in given gene is: " << genotyp[i].get_val_id();
	}
	std::cout << "\n++\n";
	std::cout << "++ rate:" << this->ocena;
	std::cout << "\n###################################\n";

	for (size_t i = 0; i < this->genotyp.size(); i++)
	{
		genotyp[i].info();
	}
}