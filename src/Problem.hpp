#pragma once

#include "FileReader.hpp"
#include "City.hpp"

#include <iostream>

struct Problem
{
	Problem(){}
	Problem(int dimension, int number_of_items, int capacity, float min_speed, float max_speed, std::vector<City> cities, std::vector<Item> items):
	dimension(dimension), number_of_items(number_of_items), capacity(capacity), min_speed(min_speed), max_speed(max_speed), cities(cities), items(items)
	{
	}

	int dimension;
	int number_of_items;
	int capacity;
	float min_speed;
	float max_speed;
	std::vector<City> cities;
	std::vector<Item> items;
};