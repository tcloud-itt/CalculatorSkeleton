///////////////////////////////////////////////////
/**
 * @file MultiplyCalculatorGTest.cpp
 * @brief Unit tests for MultiplyCalculator
 */
///////////////////////////////////////////////////

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<limits>

#include "CalculatorApplication.h"
#include "CalculatorApplicationFactory.h"
#include "CalculatorStrings.h"
#include "MultiplyCalculator.h"

using namespace calculator;
using namespace testing;

class whenTestingMultiplyCalculator : public :: testing :: Test
{

};

/**
 * @brief Unit test to make sure multiply with positive floating points works
 * 
 */
TEST_F(whenTestingMultiplyCalculator, WhenCallingMultiplyWithPositiveFloatingPoints_ThenCorrectPositiveValueReturn)
{
    MultiplyCalculator multiCalc = MultiplyCalculator(10.0, 5.0);
    float result = multiCalc.getResult();
    EXPECT_FLOAT_EQ(50.0, result);
}

/**
 * @brief Unit test to make sure multiply with positive and negative floating points works
 * 
 */
TEST_F(whenTestingMultiplyCalculator, WhenCallingMultiplyWithPositiveAndNegativeFloatingPoints_ThenCorrectNegativeValueReturn)
{
    MultiplyCalculator multiCalc = MultiplyCalculator(10.0, -5.0);
    float result = multiCalc.getResult();
    EXPECT_FLOAT_EQ(-50.0, result);
}

/**
 * @brief Unit test to make sure multiply with negative floating points works
 * 
 */
TEST_F(whenTestingMultiplyCalculator, WhenCallingMultiplyWithNegativeFloatingPoints_ThenCorrectPositiveValueReturn)
{
    MultiplyCalculator multiCalc = MultiplyCalculator(-10.0, -5.0);
    float result = multiCalc.getResult();
    EXPECT_FLOAT_EQ(50.0, result);
}
