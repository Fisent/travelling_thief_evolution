#pragma once
#include <vector>

class SquareMatrix{
public:
	SquareMatrix(int N);
    SquareMatrix(int N, std::vector<int>);
    int get(int x, int y);
private:
    int N;
    std::vector<int> table;
};