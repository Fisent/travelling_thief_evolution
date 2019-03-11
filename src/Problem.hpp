#pragma once

#include "FileReader.hpp"
#include "City.hpp"

class Problem
{
public:
	Problem(std::string filename)
	{

	}

private:
	int dimension;
	int number_of_items;
	int capacity;
	float min_speed;
	float max_speed;
	std::vector<City> cities;
};