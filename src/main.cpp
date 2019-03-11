#include <iostream>

#include "Evolution.hpp"
#include "Random.hpp"

int main(){
	std::cout << "Hello evolution\n";
	for(int i = 0; i < 1000; i++)
		std::cout << "random 10: " << random_int(10) + 1 << '\n';
}