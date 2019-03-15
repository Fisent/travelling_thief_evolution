#include "Evolution.hpp"
#include "Random.hpp"

Evolution::Evolution(int pop_size, int gen, float px, float pm, int tour, std::string filename): 
	pop_size(pop_size),
	gen(gen), 
	px(px), 
	pm(pm), 
	tour(tour), 
	problem(file_reader::read_problem(filename))
{
	for(int i = 0; i < pop_size; i++)
	{
		auto res = std::make_shared<Result>(problem.cities.size());
		population.push_back(res);
	}
}

bool Evolution::mutation_condition()
{
	return random_float(1.0) < pm;
}

bool Evolution::crossover_condition()
{
	return random_float(1.0) < px;
}

void Evolution::step()
{
	
}