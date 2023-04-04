#include "TCandidate.h"
#include <vector>
#include <iostream>
#include <ctime>

TCandidate::TCandidate()
{
	rand_gens_val();
}

void TCandidate::rand_gens_val()
{
	srand(time(NULL));

	for (size_t i = 0; i < 2; i++)
	{
		double min = rand() % 100;
		double max = min + rand() % 10000 +1;
		double step = rand() % 10 +1;
		double val = rand() % static_cast<int>(max-min) + min;
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
			"++ x" << std::to_string(i + 1) << ": " << genotyp[i].get_val();
	}
	std::cout << "\n++\n";
	std::cout << "++ rate:" << this->ocena;
	std::cout << "\n###################################\n";

	for (size_t i = 0; i < this->genotyp.size(); i++)
	{
		genotyp[i].info();
	}
}