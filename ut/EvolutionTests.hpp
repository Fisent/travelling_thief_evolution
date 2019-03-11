#include "gtest/gtest.h"

TEST(EvolutionShould, beCreated){
    Evolution e{100, 1000, 0.1, 0.01, 10, "easy_0.ttp"};
}

TEST(EvolutionShould, makeAStep){
	Evolution e{100, 1000, 0.1, 0.01, 10, "easy_0.ttp"};

	e.step();
}
