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

TEST(FileReaderShould, readNthLineFromFile)
{
    std::string first_line{"PROBLEM NAME: \tberlin52-TTP\r"};
    std::string read_first_line = file_reader::read_nth_line("easy_0.ttp", 1);
    std::string fourth_line{"NUMBER OF ITEMS: \t51\r"};
    std::string read_fourth_line = file_reader::read_nth_line("easy_0.ttp", 4);
    ASSERT_EQ(first_line, read_first_line);
    ASSERT_EQ(fourth_line, read_fourth_line);
}

TEST(FileReaderShould, readNumberOfCitiesFromFile)
{
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
    ASSERT_EQ(file_reader::read_number_of_items("easy_0.ttp"), 51);
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
