#include "gtest/gtest.h"
#include <vector>
#include <utility>
#include "../src/SquareMatrix.h"
#include "../src/Evolution.hpp"
#include "../src/Result.hpp"
#include "../src/FileReader.hpp"

TEST(SquareMatrixShould, beCreated){
    SquareMatrix sm{10};
}

TEST(SquareMatrixShould, createATableWith10Zeros){
    SquareMatrix sm{10};

    ASSERT_EQ(sm.get(0,0), 0);
}

TEST(FileReaderShould, readNumberOfCitiesFromFile)
{
    ASSERT_EQ(file_reader::read_number_of_cities("easy_0.ttp"), 51);
}

TEST(ResultShould, beCreated)
{
    Result r{10};
}

TEST(EvolutionShould, beCreated){
    // Evolution e{};
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
