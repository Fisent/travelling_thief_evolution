#include "gtest/gtest.h"
#include <vector>
#include <utility>

#include "FileReaderTests.hpp"
#include "SquareMatrixTests.hpp"
#include "EvolutionTests.hpp"
#include "ResultTests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
