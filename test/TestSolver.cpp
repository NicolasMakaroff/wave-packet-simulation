// Test_Solver.cpp
#include "../src/solver.hpp"
#include <gtest/gtest.h>

class TestSolver : public ::testing::Test{
        protected:
                virtual void SetUp(){}
                virtual void TearDown(){}
};



TEST_F(TestSolver, FirstTest){
        EXPECT_EQ(solver::Factorial(1), 1);
        EXPECT_EQ(solver::Factorial(2), 2);
}


