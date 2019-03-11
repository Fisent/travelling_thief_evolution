#pragma once
#include <vector>

class SquareMatrix{
public:
	SquareMatrix(int N): N(N), table(std::vector<int>(N))  {}
    SquareMatrix(int N, std::vector<int>): N(N), table(table) {}
    int get(int x, int y) {
    	return table.at(y*N + x);
	}

private:
    int N;
    std::vector<int> table;
};