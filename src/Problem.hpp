#pragma once

#include "FileReader.hpp"
#include "City.hpp"
#include "Result.hpp"

#include <boost/optional/optional.hpp>
#include <iostream>

struct Problem
{
	Problem(){}
	Problem(int dimension, int number_of_items, int capacity, float min_speed, float max_speed, std::vector<City> cities, std::vector<Item> items):
	dimension(dimension), number_of_items(number_of_items), capacity(capacity), min_speed(min_speed), max_speed(max_speed), cities(cities), items(items)
	{
	}

	float backpack_worth(const Result& result) const
	{
		return 0;
	}

	float distance() const
	{
		float distance = 0;
		auto size = cities.size();
		for(int i = 0; i < size - 1 ; i++)
		{
			auto city1 = cities.at(i);
			auto city2 = cities.at(i + 1);
			distance += city1.distance(city2);
		}
		distance += cities.back().distance(cities.front());
		return distance;
	}

	float travel_time(const Result& result) const
	{
		return 0;
	}

	float cost(const Result& result) const
	{
		return backpack_worth(result) - travel_time(result); 
	}

	int dimension;
	int number_of_items;
	int capacity;
	float min_speed;
	float max_speed;
	std::vector<City> cities;
	std::vector<Item> items;
};
