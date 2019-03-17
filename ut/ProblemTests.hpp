#pragma once

#include "../src/Problem.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../src/City.hpp"


Result prepareResult()
{
	Result result{10};
	return result;
}

Problem prepareProblem()
{
	Problem problem{5, 6, 50, 0.1, 1.0, 
		{City(1,0,0), City(2,1,0), City(3,1,1), City(4,0,1)},
		{Item(1, 10, 1, 1), Item(2, 15, 2, 2), Item(3, 1, 5, 3)}};


	return problem;
}

const float SQRT_2{1.4142135623730951};

TEST(CityShould, countDistance)
{
	City city1{1, 0, 0};
	City city2{2, 1, 0};

	ASSERT_EQ(city1.distance(city2), 1);

	City city3{3, 1, 1};

	ASSERT_NEAR(city1.distance(city3), SQRT_2, 0.0001);

	City city4{4, 3, 3};

	ASSERT_NEAR(city3.distance(city4), 2 * SQRT_2, 0.0001);
}

TEST(ProblemShould, returnProperDistance)
{
	auto problem = prepareProblem();

	ASSERT_EQ(problem.distance(), 4);
}

TEST(ProblemShould, countBackpackWorth)
{
	auto problem = prepareProblem();
}

TEST(ProblemShould, returnResultsCost)
{
	auto problem = prepareProblem();
	auto result = prepareResult();

	ASSERT_EQ(problem.cost(result), 0);
}
