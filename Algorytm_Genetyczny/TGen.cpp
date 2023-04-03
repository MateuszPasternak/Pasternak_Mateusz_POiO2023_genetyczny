#include "TGen.h"
#include <iostream>
#include <vector>
#include <string>

TGen::TGen(double min, double max, double step, std::string name, std::string opis)
{
	this->min = min;
	this->max = max;
	this->step = step;
	this->val = min;
	this->name = name;
	this->opis = opis;
}

TGen::TGen(double min, double max, double step, double value, std::string name, std::string opis)
{
	this->min = min;
	this->max = max;
	this->step = step;
	this->val = min;
	this->name = name;
	this->opis = opis;
	this->set_value(value);
}

void TGen::set_value(double value)
{
	std::vector<double> values;
	int length = static_cast<int>((this->max-this->min)/this->step);

	//std::cout << "\n\n" << val << "\n" << length << std::endl;

	for (size_t i = this->min; i <= this->max; i+=this->step)
	{
		values.push_back(i);
		//std::cout << "\n" << i << "\n";
	}

	this->_id = get_id(values, value);
	//std::cout << "\n" << this->_id << "\n";

	if (this->_id != -1)
	{
		this->val = value;
	}
	else
	{
		//std::cout << "Ta wartosc: " << value << " - wykracza poza dozwolony zakres!!!" << "\n\n";
		if (value > this->max)
		{
			this->val = max;
			this->_id = values.size()-1;
		}
		else if (value < this->min)
		{
			this->val = min;
			this->_id = 0;
		}
		else
		{
			int id = find_closest(values, value);
			this->val = values[id];
			this->_id = id;
			//std::cout << "\n" << id << "\n";
		}
	}

}

void TGen::info()
{
	std::cout << "\n\n###########################\n" <<
		this->name << "\n###########################\n" <<
		"++ Parameter range:" <<
		"\n++ - start value: " << this->min <<
		"\n++ - end value: " << this->max <<
		"\n++ - step value: " << this->step <<
		"\n++" <<
		"\n++ - Present value: " << this->val <<
		"\n++ - Present val_id: " << this->_id;
}

int TGen::get_id(std::vector<double> values, double value)
{
	int id = -1;
	size_t count = values.size();
	bool run = count;

	while (run)
	{
		id += 1;

		if (values[id] == value) run = false;

		if ((run == true) && (id + 1 == count))
		{
			id = -1;
			run = false;
		}
	}

	return id;
}

int TGen::find_closest(std::vector<double> values, double value)
{
	int pos;
	double buff = values[values.size()-1], dist;

	for (size_t i = 0; i < values.size(); i++)
	{
		dist = abs(value - values[i]);

		if (dist <= buff)
		{
			buff = dist;
			//std::cout << "\nbuff: " << buff << "\n";
			pos = i;
		}
	}

	return pos;
}