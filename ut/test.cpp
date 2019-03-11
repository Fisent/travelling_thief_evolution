#include "gtest/gtest.h"
#include <vector>
#include <utility>
#include "../src/SquareMatrix.h"
#include "../src/Evolution.hpp"
#include "../src/Result.hpp"
#include "../src/Item.hpp"
#include "../src/Problem.hpp"

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

TEST(FileReaderShould, readNthLineValueFromFile)
{
    int third_line_value{52};
    int read_third_line_value = file_reader::read_nth_line_value<int>("easy_0.ttp", 3);
    float sixth_line_value{0.1};
    float read_sixt_line_value = file_reader::read_nth_line_value<float>("easy_0.ttp", 6);

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

TEST(FileReaderShould, readProblemFromFile)
{
    int e_dimension = 52;
    int e_num_of_items = 51;
    int e_capacity = 4046;
    float e_min_speed = 0.1;
    float e_max_speed = 1.0;
    int e_size_of_cities_vector = 52;

    Problem prob = file_reader::read_problem("easy_0.ttp");

    EXPECT_EQ(e_dimension, prob.dimension);
    EXPECT_EQ(e_num_of_items, prob.number_of_items);
    EXPECT_EQ(e_capacity, prob.capacity);
    EXPECT_EQ(e_min_speed, prob.min_speed);
    EXPECT_EQ(e_max_speed, prob.max_speed);
    //TODO add vector reading and check it
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
