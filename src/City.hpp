#pragma once

#include "Item.hpp"

struct City
{
	City(int id, int x, int y): id(id), x(x), y(y) {
		for(auto& item: items)
			this->items.push_back(item);
	};
	float distance(const City& other) const
	{
		int x = this->x;
		int y = this->y;

		int other_x = other.x;
		int other_y = other.y;

		return sqrt(((x - other_x) * (x - other_x)) + ((y - other_y) * (y - other_y)));
	}

	Item* getBestItem(int weight_left){
		if(0 == items.size())
			return;
		Item* best_item = items.at(0);

		for(auto item : items)
		{
			if(item.profit > best_item.profit and item.weight <= weight_left)
				best_item = &item;
		}

		return &best_item;
	}

	int id;
	int x;
	int y;
	std::vector<Item> items;
};