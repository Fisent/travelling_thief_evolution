#include "Evolution.hpp"
#include "Random.hpp"

#include <limits.h>
#include <set>

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
	std::vector<int> results;
	assert(pop_size == population.size());

	for(int i = 0; i < how_many; i++)
	{
		int index = random_int(pop_size);
		results.push_back(index);
	}

	return results;
}

//This function selects two results
std::pair<int,int> Evolution::selection()
{
	int winner1 = tournament();
	int winner2 = tournament();
	while(winner2 == winner1)
		winner2 = tournament();

	return std::pair<int,int>{winner1, winner2};
}

int Evolution::tournament()
{
	std::set<int> participants{};
	while(participants.size() < tour)
	{
		participants.insert(random_int(population.size()));
	}

	int winner{0};
	int best_cost{INT_MAX};

	for(auto index : participants)
	{
		auto participant = population.at(index);
		auto cost = problem.cost(*participant);

		if(cost < best_cost)
		{
			winner = index;
			best_cost = cost;
		}
	}
	return winner;
}

void Evolution::crossover()
{
	
}

void Evolution::mutation()
{

}

void Evolution::step()
{
	
}