#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int N) :N(N), table(std::vector<int>(N)) 
{}

SquareMatrix::SquareMatrix(int N, std::vector<int> table): N(N), table(table)
{}

int SquareMatrix::get(int x, int y) {
    return table.at(y*N + x);
}
