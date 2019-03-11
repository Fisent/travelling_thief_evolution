#include <gtest/gtest.h>
#include "../src/SquareMatrix.h"

TEST(SquareMatrixShould, beCreated){
    SquareMatrix sm{10};
}

TEST(SquareMatrixShould, createATableWith10Zeros){
    SquareMatrix sm{10};

    ASSERT_EQ(sm.get(0,0), 0);
}
