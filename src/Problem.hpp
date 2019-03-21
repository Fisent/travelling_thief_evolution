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

	int weight_sum()
	{
		int sum{0};
		for(auto item : backpack)
			sum += item->weight;
		return sum;
	}

	float backpack_worth(const Result& result)
	{
		for(auto city : cities)
		{
			if(city.items.size() == 0)
				continue;
			Item* best_item = &city.items.at(0);
			int best_items_worth = 0;
			bool selected{false};

			for(auto item : city.items)
			{
				backpack.push_back(&item);
				if(item.profit > best_items_worth)
				{
					best_item = &item;
					best_items_worth = item.profit;
					selected = true;
				}
			}
			if(selected and capacity - weight_sum() <= best_item->weight)
				backpack.push_back(best_item);
		}
		int sum = 0;
		for(auto item : backpack)
			sum += item->profit;
		return sum;
	}

	float distance(const Result& result)
	{
		float distance = 0;
		auto size = cities.size();
		auto res = result.getRes();
		// for(auto r : res)
			// std::cout << r << ',';
		// std::cout << '\n';
		for(int i = 0; i < res.size() - 1; i++)
		{
			auto city1 = cities.at(res.at(i));
			auto city2 = cities.at(res.at(i + 1));
			distance += city1.distance(city2);
		}
		distance += cities.back().distance(cities.front());
		// std::cout << distance << '\n';
		return distance;
	}

	float travel_time(const Result& result)
	{
		return distance(result) / current_speed;
	}

	float cost(const Result& result)
	{
		backpack = {};
		return distance(result) - backpack_worth(result);
	}

	int dimension;
	int number_of_items;
	int capacity;
	float min_speed;
	float max_speed;
	std::vector<City> cities;
	std::vector<Item> items;

	int current_speed{1};

	std::vector<Item*> backpack{};
};
