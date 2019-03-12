#pragma once

#include "../src/Problem.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

Result prepareResult()
{
	Result result{10};
	return result;
}

Problem prepareProblem()
{
	Problem problem;
	return problem;
}

TEST(ProblemShould, countBackpackWorth)
{

}

TEST(ProblemShould, returnResultssConst)
{
	auto problem = prepareProblem();
	auto result = prepareResult();

	ASSERT_EQ(problem.cost(result), 66);
}