#include "Evolution.hpp"
#include "Random.hpp"

#include <limits.h>
#include <set>
#include <ctime>
#include <fstream>

Evolution::Evolution(int pop_size, int gen, float px, float pm, int tour, std::string filename): 
	pop_size(pop_size),
	gen(gen), 
	px(px), 
	pm(pm), 
	tour(tour), 
	problem(file_reader::read_problem(filename)),
	filename(filename)
{
	for(int i = 0; i < pop_size; i++)
	{
		population.push_back(std::make_shared<Result>(problem.cities.size()));
	}

	warnings();
	delete_file_content();

	//small hack to make pm count for every gene, not whole organism
	pm = pm * problem.dimension;
}

void Evolution::warnings()
{
	if(pop_size == tour)
		std::cout<< "WARNING! pop_size is equal to tour. Program may fall into infinite loop during selection\n";
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
	// std::cout<< __FUNCTION__ << '\n';
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
	//std::cout<< __FUNCTION__ << '\n';
	int winner1 = tournament();
	int winner2 = tournament();
	while(winner2 == winner1){
		//std::cout<< population.size() << '\n';
		//std::cout<< std::time(0) << " winner1: " << winner1 << ", winner2: " << winner2 << '\n'; 
		winner2 = tournament();
	}
	//std::cout<< __FUNCTION__ << " end\n";
	return std::pair<int,int>{winner1, winner2};
}

int Evolution::tournament()
{
	//std::cout<< __FUNCTION__ << '\n';
	std::set<int> participants{};
	while(participants.size() < tour)
	{
		participants.insert(random_int(population.size()));
	}

	int winner{0};
	int best_cost{INT_MAX};

	for(auto index : participants)
	{
		if(index >= population.size())
			std::cout<< "ERROR, invalid index!\n";
		auto participant = population.at(index);
		auto cost = problem.cost(*participant);
		//std::cout<< "participant cost " << cost << "index: " << index << " size of old population " << population.size() << '\n';


		if(cost < best_cost)
		{
			winner = index;
			best_cost = cost;
		}
	}
	//std::cout<< __FUNCTION__ << " end\n";
	return winner;
}

void Evolution::crossover()
{
	//std::cout<< __FUNCTION__ << '\n';
	std::vector<std::shared_ptr<Result>> new_population{};

	int how_many_crossovers = pop_size * px;

	for(int i = 0; i < how_many_crossovers; i++)
	{
		//std::cout<< "crossover loop start\n";
		if(crossover_condition()){
		auto parents_indexes = selection();
		auto child = population.at(parents_indexes.first)->crossover(*(population.at(parents_indexes.second)));
		new_population.push_back(std::make_shared<Result>(child));
	}
		//std::cout<< "crossover loop end\n";
	}

	while(new_population.size() < pop_size)
	{
		//std::cout<< "second crossover loop start\n";
		auto survivor_index = tournament();
		new_population.push_back(std::shared_ptr<Result>{(population.at(survivor_index))});
		population.erase(population.begin() + survivor_index);
		//std::cout<< "second crossover loop end\n";
	}

	population = new_population;
}

//TODO check if mutation probability should be for whole result, or checked in every gene?
void Evolution::mutation()
{
	//std::cout<< __FUNCTION__ << '\n';
	for(auto result : population)
	{
		if(mutation_condition())
		{
			result->mutate();
		}
	}
}

void Evolution::step()
{
	// std::cout<< __FUNCTION__ << '\n';
	crossover();
	mutation();
}

Snapshot Evolution::take_snapshot(){
	auto result = best_worst_average();
	return Snapshot{result.at(0), result.at(1), result.at(2)};
}

std::vector<float> Evolution::best_worst_average()
{
	int sum{0};
	int best{INT_MAX};
	int worst{0};

	for(auto& result : population)
	{
		int cost = problem.cost(*result);
		sum += cost;
		if(cost < best)
			best = cost;
		if(cost > worst)
			worst = cost;
	}

	float average = sum / population.size();

	return {best, worst, average};
}

void Evolution::delete_file_content()
{
	std::ofstream ofs;
	ofs.open(OUTPUT_PREFIX + get_output_filename(), std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

std::string Evolution::get_output_filename()
{
	return filename + 'p' + std::to_string(pop_size) + 'g' + std::to_string(gen) + 'x' + std::to_string(px) + 'm' + std::to_string(pm) + 't' + std::to_string(tour) + ".out";
}