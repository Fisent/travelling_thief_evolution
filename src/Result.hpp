#pragma once

class Result
{
public:
	Result(int N): N(N), res(N) {}

private:
	int N;
	std::vector<int> res;
};