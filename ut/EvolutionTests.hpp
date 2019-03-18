#pragma once

#include "gtest/gtest.h"
#include <string>

const int POP_SIZE{100};
const int GEN{1000};
const float PM{0.01};
const float PX{0.7};
const int TOUR{10};

const float NUM_OF_ITERATIONS{10000};

struct EvolutionTestable : public Evolution
{
	EvolutionTestable(int pop_size, int gen, float px, float pm, int tour, std::string filename):
		Evolution(pop_size, gen, px, pm, tour, filename){}

	using Evolution::population;
	using Evolution::problem;
	using Evolution::mutation_condition;
	using Evolution::crossover_condition;
	using Evolution::selection;
	using Evolution::tournament;
	using Evolution::mutation;
};

TEST(EvolutionShould, beCreated){
    Evolution e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};
}

TEST(EvolutionShould, readContentFromFile){
	EvolutionTestable e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};

	ASSERT_EQ(e.population.size(), 100);

	auto problem = e.problem;
	ASSERT_EQ(problem.cities.size(), 52);
	ASSERT_EQ(problem.items.size(), 51);
}

TEST(EvolutionShould, makeAStep){
	EvolutionTestable e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};

	auto pop_before_step = e.population;
	e.step();
	auto pop_after_step = e.population;

	//TODO uncomment
	// ASSERT_NE(pop_before_step, pop_after_step);
}

TEST(EvolutionShould, checkMutationCondition)
{
	EvolutionTestable e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};
	int counter = 0;
	for(int i = 0; i < NUM_OF_ITERATIONS; i++)
	{
		if(e.mutation_condition())
			counter++;
	}
	auto ratio = counter / NUM_OF_ITERATIONS;

	ASSERT_NEAR(ratio, PM, 0.01);
}

TEST(EvolutionShould, checkCrossoverCondition)
{
	EvolutionTestable e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};
	int counter = 0;
	for(int i = 0; i < NUM_OF_ITERATIONS; i ++)
	{
		if(e.crossover_condition())
			counter++;
	}
	auto ratio = counter / NUM_OF_ITERATIONS + 0.0;
	ASSERT_NEAR(ratio, PX, 0.1);
}

TEST(EvolutionShould, returnTournamentWinner)
{
	EvolutionTestable e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};

	//TODO expand this test with results with precounted costs
	auto winner = e.tournament();

	ASSERT_NE(e.population.at(winner), nullptr);
}

TEST(EvolutionShould, returnPairFromSelection)
{
	EvolutionTestable e{100, 1000, PX, PM, TOUR, "easy_0.ttp"};

	auto winners = e.selection();

	for(int i = 0; i < NUM_OF_ITERATIONS; i++){
		ASSERT_NE(e.population.at(winners.first), nullptr);
		ASSERT_NE(e.population.at(winners.second), nullptr);
		ASSERT_NE(winners.first, winners.second);
	}

}
