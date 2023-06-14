#pragma once
#include "TPopulation.h"
class PopulationStiff4Gens :
    public TPopulation
{
    std::vector<TCandidateStiffGensCount4> candidates;

public:
    PopulationStiff4Gens(int cand_num, bool rand = false);
    std::vector<TCandidateStiffGensCount4> get_candidatesList2() { return candidates; };
    void calculate();
};

