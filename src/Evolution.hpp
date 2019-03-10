#pragma once

#include <memory>
#include <vector>
#include "Problem.hpp"

class Result;

class Evolution
{
public:
	Evolution(int pop_size, int gen, int px, int pm, int tour) : pop_size(pop_size), gen(gen), px(px), pm(pm), tour(tour)
	{

	}

	void step();

private:
	int pop_size;
    int gen;
    float px;
    float pm;
    int tour;

    std::vector<std::shared_ptr<Result>> population;
    Problem problem;
};