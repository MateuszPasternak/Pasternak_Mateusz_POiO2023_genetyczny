#include "TAlgorithm.h"


TAlgorithm::TAlgorithm(int pop_size, int count, int postep)
{
	this->pres_popul = new TPopulation(pop_size);
	this->max_pop_count = count;
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
	int num = 0;

	while (!this->is_stopped())
	{
		show(num);	

		delete this->prev_popul;
		this->prev_popul = this->pres_popul;
		this->pres_popul = new TPopulation(this->pop_size);
		num++;
	}
}

void TAlgorithm::show(int num)
{
	if (num == this->max_pop_count)
	{
		std::cout << "\n\n Best value globally: " << this->_min << std::endl;
	}
	else
	{
		std::cout << "\n+ Population: " << num + 1 << " \tBest Candidate rate: " << this->pres_popul->best_candidate().get_rate() << std::endl;
	}
}

bool TAlgorithm::is_stopped()
{
	TPopulation population = (*pres_popul);

	bool bool_stop_pop_max = 0;
	bool bool_stop_improvement = 0;

	if (prev_popul == nullptr) //pierwsza popul
	{
		bool_stop_pop_max = (population.get_id() == this->max_pop_count);
		this->_min = population.get_best_val();
	}
	else
	{
		TPopulation pop_prev = (*prev_popul);

		double population_val = population.get_best_val();
		double population_prev_val = pop_prev.get_best_val();
		//unsigned int error = fabs(population_prev_val - population_val) / population_prev_val * 100;

		if (population_val > _min)
		{
			this->blad++;
		}
		else
		{
			this->blad = 0;
			this->_min = population_val;
		}

		bool_stop_pop_max = (population.get_id() == this->max_pop_count);
		//bool_stop_improvement = (error < this->postep);
		bool_stop_improvement = (this->blad > this->postep);
	}

	return bool_stop_pop_max || bool_stop_improvement;
}