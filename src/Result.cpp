#include "Result.hpp"

#include <set>
#include <iostream>

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

int Result::findByValue(int value) {
    for (int i = 0; i < N; i++) {
        if (res[i] == (int) value)
            return i;
    }
    return -1;
}

void Result::fix(){
    for(int i = 0; i < N; i++) {
        for(int j = N; j > 0; j--){
            int number = -2;
            for(int k = 0; k < N; k++){
                if(findByValue(k) == -1) number = k;
            }
            if(findByValue(i) == findByValue(j) && number != -2)
                res[j] = number;
        }
    }
}