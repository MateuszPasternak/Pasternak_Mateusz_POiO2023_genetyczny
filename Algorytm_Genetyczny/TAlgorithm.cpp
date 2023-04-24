#include "TAlgorithm.h"


TAlgorithm::TAlgorithm(int pop_size, int count, int postep)
{
	this->pres_popul = new TPopulation(pop_size);
	this->prev_popul = new TPopulation(pop_size);
	this->count = count;
	this->postep = postep;
	this->pop_size = pop_size;
}

TAlgorithm::~TAlgorithm()
{
	delete this->pres_popul;
	delete this->prev_popul;
	std::cout << "\nMemory cleaned\n";
}

void TAlgorithm::alg()
{
	int num = 0, num2 = 0;
	int zbiezn = this->postep;
	double buff = this->pres_popul->best_candidate().get_rate();
	bool ENDING = 0;

	while (ENDING == 0)
	{
		show(num);	

		if (this->pres_popul->best_candidate().get_rate() > buff)
		{
			num2++;
		}
		else
		{
			num2 = 0;
			buff = this->pres_popul->best_candidate().get_rate();
		}
		if (num2 == zbiezn)
		{
			ENDING = 1;
			this->_min = buff;
			show(this->count);
		}

		this->prev_popul = this->pres_popul;
		this->pres_popul = new TPopulation(this->pop_size);
		num++;

		if (num == this->count)
		{
			ENDING = 1;
			show(num);
		}
	}
}

void TAlgorithm::show(int num)
{
	if (num == this->count)
	{
		std::cout << "\n\n Best value globally: " << this->_min << std::endl;
	}
	else
	{
		std::cout << "\n+ Population: " << num + 1 << " \tBest Candidate rate: " << this->pres_popul->best_candidate().get_rate() << std::endl;
	}
}