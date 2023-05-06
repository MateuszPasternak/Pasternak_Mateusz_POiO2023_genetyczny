#include "TAlgorithm.h"


TAlgorithm::TAlgorithm(int pop_size, int count, int postep)
{
	this->pres_popul = new TPopulation(pop_size, true);
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
		crossOver(CROSS_OVER_PROBABILITY);
		this->pres_popul->calculate();
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

void TAlgorithm::mutate(double mutationPossibility)
{

}

void TAlgorithm::crossOver(double crossPossibility)
{
	std::vector<TCandidate> candidates = this->prev_popul->get_candidatesList();
	std::vector<TCandidate> crossOver_ParentsList;
	std::vector<int> crossOver_ParentsIds;
	std::vector<TCandidate> crossOver_ChildrenList;

	for (int i = 0; i < candidates.size(); i++)
	{
		candidates[i].set_CrossPossibilityRate();
		//std::cout << "\n\nPopulation: " << this->prev_popul->get_id() << std::endl;
		//candidates[i].info();

		if (candidates[i].get_CrossPossibilityRate() < crossPossibility)
		{
			crossOver_ParentsList.push_back(candidates[i]);
			crossOver_ParentsIds.push_back(i);
		}
	}

	//std::cout << "\n\n\n Number of parents: " << crossOver_ParentsList.size() << "\n";
	if (crossOver_ParentsList.size() > 1)
	{
		for (int i = 0; i < crossOver_ParentsList.size(); i++)
		{
			int _id = 0;
			int crossOverPoint = std::rand() % (GENS_NUM - 1);
			int gens_count = crossOver_ParentsList[i].get_genotypeOfCand().size();

			do 
			{
				_id = std::rand() % crossOver_ParentsList.size();	
			} while (_id == i);

			//std::cout << " \n\nCross over parent _id: " << crossOver_ParentsIds[_id] << " for parent with id: " << crossOver_ParentsIds[i] << std::endl;
			//candidates[i].info();
			//candidates[_id].info();

			TCandidate child1, child2;
			child1.set_gens(crossOver_ParentsList[i], crossOver_ParentsList[_id], crossOverPoint);
			child2.set_gens(crossOver_ParentsList[_id], crossOver_ParentsList[i], crossOverPoint);
			/*std::cout << " \n\n cand count: " << this->pres_popul->get_cand_count() << "\n\n";
			std::cout << "\n\n CrossOver point : " << crossOverPoint << "\n\n";
			std::cout << "\n\n Child of parents: " << crossOver_ParentsIds[i] << " and: " << crossOver_ParentsIds[_id] << ": \n";
			child1.info();
			std::cout << "\n\n Child of parents: " << crossOver_ParentsIds[_id] << " and: " << crossOver_ParentsIds[i] << ": \n";
			child2.info();*/
			if (this->pres_popul->get_cand_count() >= this->pres_popul->get_cand_MaxCount())
			{
				return;
			}
			else
			{
				this->pres_popul->add_Candidate(child1);
				this->pres_popul->add_Candidate(child2);
				this->pres_popul->iterate_candidatesCount(2);
				
			}
			
			//crossOver_ChildrenList.push_back(child1);
			//crossOver_ChildrenList.push_back(child2);
			/*std::cout << "\n\n CrossOver point : " << crossOverPoint << "\n\n";
			std::cout << "\n\n Child of parents: " << crossOver_ParentsIds[i] << " and: " << crossOver_ParentsIds[_id] << ": \n";
			child1.info();
			std::cout << "\n\n Child of parents: " << crossOver_ParentsIds[_id] << " and: " << crossOver_ParentsIds[i] << ": \n";
			child2.info();*/
		}
	}
	//std::cout << " \n\n cand count: " << this->pres_popul->get_cand_count() << "\n\n";
	this->pres_popul->generate_restOfCandidates();
}