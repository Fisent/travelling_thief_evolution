#include "Result.hpp"

void Result::mutate()
{
	int first_index = random_int(N);
	int second_index = random_int(N);
	while(first_index == second_index)
		second_index = random_int(N);
	flip(first_index, second_index);
}

void Result::flip(int first_index, int second_index)
{
	int first = res.at(first_index);
	int second = res.at(second_index);

	res.at(first_index) = second;
	res.at(second_index) = first;
}

void Result::fix()
{
	
}