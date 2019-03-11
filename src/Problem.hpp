#pragma once

struct City
{
	City(int id, int x, int y): id(id), x(x), y(y) {};

	int id;
	int x;
	int y;
};

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