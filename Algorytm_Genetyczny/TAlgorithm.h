#pragma once

#include <iostream>
#include "TPopulation.h"


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
};

