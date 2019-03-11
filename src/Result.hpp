#pragma once

#include <vector>

class Result
{
public:
	Result(int N): N(N), res(N) {}
	void mutate();
	Result crossover(Result& other);

protected:
	void repair();
	int N;
	std::vector<int> res;
};