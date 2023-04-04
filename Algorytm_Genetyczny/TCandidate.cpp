#include "TCandidate.h"
#include <vector>
#include <iostream>

TCandidate::TCandidate()
{
	for (size_t i = 0; i < 2; i++)
	{
		std::string name = "gen_" + std::to_string(i+1);
		TGen param{ 0, 0, 0, name };
		genotyp.push_back(param);
	}
	rand_gens_val();
}

void TCandidate::rand_gens_val()
{
	/*for (size_t i = 0; i < this->genotyp.size(); i++)
	{

	}*/
}

void TCandidate::rate()
{

}

void TCandidate::info()
{
	std::cout << "\n############ GENOTYPE ###########\n" <<
		"++ gens count: " << this->genotyp.size();

	/*for (size_t i = 0; i < this->genotyp.size(); i++)
	{
		std::cout << "\n#############################\n" <<
			"";
	}*/
}