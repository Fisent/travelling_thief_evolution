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
	Result(std::vector<int> res): N(res.size()), res(res){

	}
	std::vector<int> getRes() const {return res;}

	void mutate();
	Result crossover(const Result& other, int pivot_index) const;

protected:
	void fix();
	void flip(int first_index, int second_index);
	int find_by_value(int value);
	bool needs_fixing();

	int N;
	std::vector<int> res;
};