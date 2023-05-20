#pragma once

#include <iostream>
#include "TPopulation.h"

#define CROSS_OVER_PROBABILITY 0.2
#define MUTATION_POSSIBILITY 0.1

class TAlgorithm
{
	TPopulation* pres_popul = nullptr;
	TPopulation* prev_popul = nullptr;
	int max_pop_count;
	int postep = 0;
	int pop_size = 0;
	double _min = 0;
	int blad = 0; //zmienna tymczasowa do testowania is_stopped dla zbieznoœci

public:
	TAlgorithm(int pop_size, int count = 20, int postep = 2);
	~TAlgorithm();
	void alg();
	void show(int num);

private:
	bool is_stopped();
	void mutate(double mutationPossibility);
	void crossOver(double crossPossibility);
};

