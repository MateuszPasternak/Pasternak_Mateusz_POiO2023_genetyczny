#pragma once

#include <vector>
#include <string>

class TGen
{
	std::string name, opis;
	double min = 0 , max = 0, step = 0;
	volatile double val = 0;
	volatile int _id = 0;

public:
	TGen(double min, double max, double step, std::string name, std::string opis="Gen");
	TGen(double min, double max, double step, double value, std::string name, std::string opis = "Gen");

	void set_value(double value);
	void info();
	int get_id(std::vector<double> values, double value);
	int find_closest(std::vector<double> values, double value);
	double get_val();
};

