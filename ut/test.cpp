#include "gtest/gtest.h"
#include <vector>
#include <utility>
#include "../src/SquareMatrix.h"
#include "../src/Evolution.hpp"
#include "../src/Result.hpp"
#include "../src/Item.hpp"

TEST(SquareMatrixShould, beCreated){
    SquareMatrix sm{10};
}

TEST(SquareMatrixShould, createATableWith10Zeros){
    SquareMatrix sm{10};

    ASSERT_EQ(sm.get(0,0), 0);
}

TEST(FileReaderShould, readNumberOfCitiesFromFile)
{
    //TODO: fix this, it whould be 52
    ASSERT_EQ(file_reader::read_number_of_cities("easy_0.ttp"), 52);
}

TEST(FileReaderShould, readCitiesFromFile)
{
    auto cities = file_reader::read_cities("easy_0.ttp");
    City first = cities.front();
    City last = cities.back();

    ASSERT_EQ(first.id, 1);
    ASSERT_EQ(first.x, 565.0);
    ASSERT_EQ(first.y, 575.0);

    ASSERT_EQ(last.id, 52);
    ASSERT_EQ(last.x, 1740.0);
    ASSERT_EQ(last.y, 245.0);
}

TEST(FileReaderShould, readNumberOfItemsFromFile)
{
    ASSERT_EQ(file_reader::read_number_of_cities("easy_0.ttp"), 51);
}

TEST(FileReaderShould, readItemsFromFile)
{
    auto items = file_reader::read_items("easy_0.ttp");
}

TEST(ResultShould, beCreated)
{
    Result r{10};
}

TEST(EvolutionShould, beCreated){
    Evolution e{100, 1000, 0.1, 0.01, 10, "easy_0.ttp"};
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
