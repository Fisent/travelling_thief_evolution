#include "Random.hpp"

#include <random>
#include <chrono>

int random_int(int max){
    auto rand = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    return rand() % max;
}