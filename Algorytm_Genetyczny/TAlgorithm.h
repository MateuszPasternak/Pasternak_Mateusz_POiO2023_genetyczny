#pragma once

#include <iostream>
#include "TPopulation.h"


class TAlgorithm
{
	TPopulation* pres_popul;
	TPopulation* prev_popul;
	int count;
	int postep;
	int pop_size;
	double _min;

public:
	TAlgorithm(int pop_size, int count = 20, int postep = 2);
	~TAlgorithm();
	void alg();
	void show(int num);
};

