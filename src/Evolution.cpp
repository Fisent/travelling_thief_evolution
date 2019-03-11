#include "Evolution.hpp"

Evolution::Evolution(int pop_size, int gen, float px, float pm, int tour, std::string filename): 
	pop_size(pop_size),
	gen(gen), 
	px(px), 
	pm(pm), 
	tour(tour), 
	problem(file_reader::read_problem(filename))
{
	// for(int i = 0; i < pop_size; i++)
	for(auto& city : problem.cities)
	{
		auto res = std::make_shared<Result>(problem.cities.size());
		population.push_back(res);
	}
}

void Evolution::step()
{
	
}