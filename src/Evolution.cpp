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

std::vector<int> Evolution::random_selection(int how_many)
{
	std::vector<int> result;
	assert(pop_size == population.size());

	for(int i = 0; i < how_many; i++)
	{
		int index = random_int(pop_size);
	}

	return result;
}

//this stub function returns all results from population
// TODO: implement it for real
std::vector<int> Evolution::selection()
{
	std::vector<int> result{};
	for(int i = 0; i<population.size(); i++)
		result.push_back(i);
	return result;
}

void Evolution::step()
{
	
}