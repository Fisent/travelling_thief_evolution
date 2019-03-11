#include "Evolution.hpp"

Evolution::Evolution(int pop_size, int gen, float px, float pm, int tour, std::string filename): 
	pop_size(pop_size),
	gen(gen), 
	px(px), 
	pm(pm), 
	tour(tour), 
	problem()
{
	auto num_of_cities = file_reader::read_number_of_cities(filename);

	for(int i = 0; i < pop_size; i++)
	{
		auto res = std::make_shared<Result>(num_of_cities);
		population.push_back(res);
	}
}

void Evolution::step()
{
	
}