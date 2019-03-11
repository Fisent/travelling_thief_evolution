#pragma once

struct Item
{
	Item(int id, int profit, int weight, int city_id): id(id), profit(profit), weight(weight), city_id(city_id) 
	{}

	int id;
	int profit;
	int weight;
	int city_id;
};