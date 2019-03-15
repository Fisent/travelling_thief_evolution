#pragma once

#include "gtest/gtest.h"

struct EvolutionTestable : public Evolution
{
	EvolutionTestable(int pop_size, int gen, float px, float pm, int tour, std::string filename):
		Evolution(pop_size, gen, px, pm, tour, filename){}

	using Evolution::population;
	using Evolution::problem;
	using Evolution::mutation_condition;
	using Evolution::crossover_condition;
};

const int ITERATIONS = 1000000;

TEST(EvolutionShould, beCreated){
    Evolution e{100, 1000, 0.1, 0.01, 10, "easy_0.ttp"};
}

TEST(EvolutionShould, readContentFromFile){
	EvolutionTestable e{100, 1000, 0.9, 0.01, 10, "easy_0.ttp"};

	ASSERT_EQ(e.population.size(), 100);

	auto problem = e.problem;
	ASSERT_EQ(problem.cities.size(), 52);
	ASSERT_EQ(problem.items.size(), 51);
}

TEST(EvolutionShould, makeAStep){
	EvolutionTestable e{100, 1000, 0.1, 0.01, 10, "easy_0.ttp"};

	auto pop_before_step = e.population;
	e.step();
	auto pop_after_step = e.population;

	//TODO uncomment
	// ASSERT_NE(pop_before_step, pop_after_step);
}

TEST(EvolutionShould, checkMutationCondition)
{
	EvolutionTestable e{100, 1000, 0.1, 0.01, 10, "easy_0.ttp"};
	int counter = 0;
	for(int i = 0; i < 1000000; i++)
	{
		if(e.mutation_condition())
			counter++;
	}
	auto ratio = counter / 1000000.;
}
