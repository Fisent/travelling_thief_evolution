#pragma once

#include <vector>
#include <algorithm>

#include "Random.hpp"

class Result
{
public:
	Result(int N): N(N) {
		for(int i = 0; i < N; i++) {res.push_back(i);}
		std::random_shuffle(res.begin(), res.end());
	}
	void mutate();
	Result crossover(Result& other);

protected:
	void fix();
	void flip(int first_index, int second_index);
	Result crossover(Result& first_result, Result& second_result, int pivot_index);
	int findByValue(int value);

	int N;
	std::vector<int> res;
};