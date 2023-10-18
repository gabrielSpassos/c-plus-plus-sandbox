#include <gtest/gtest.h>
#include "../src/calculator.cpp"

TEST(CalculatorTest, AddNumbers){
    Calculator calculator;
    double result = calculator.add(5, -9);
    ASSERT_EQ(-4, result);
}

TEST(CalculatorTest, AddOnlyPositiveNumbers){
    Calculator calculator;
    double result = calculator.add(5, 9);
    ASSERT_EQ(14, result);
}

TEST(CalculatorTest, AddOnlyNegativeNumbers){
    Calculator calculator;
    double result = calculator.add(-5, -9);
    ASSERT_EQ(-14, result);
}

TEST(CalculatorTest, SubtractNumbers){
    Calculator calculator;
    double result = calculator.subtract(5, -9);
    ASSERT_EQ(14, result);
}

TEST(CalculatorTest, SubtractOnlyPositiveNumbers){
    Calculator calculator;
    double result = calculator.subtract(5, 9);
    ASSERT_EQ(-4, result);
}

TEST(CalculatorTest, SubtractOnlyNegativeNumbers){
    Calculator calculator;
    double result = calculator.subtract(-5, -9);
    ASSERT_EQ(4, result);
}

TEST(CalculatorTest, MultiplyNumbers){
    Calculator calculator;
    double result = calculator.multiply(5, -9);
    ASSERT_EQ(-45, result);
}

TEST(CalculatorTest, MultiplyOnlyPositiveNumbers){
    Calculator calculator;
    double result = calculator.multiply(5, 9);
    ASSERT_EQ(45, result);
}

TEST(CalculatorTest, MultiplyOnlyNegativeNumbers){
    Calculator calculator;
    double result = calculator.multiply(-5, -9);
    ASSERT_EQ(45, result);
}

TEST(CalculatorTest, DivideNumbers){
    Calculator calculator;
    double result = calculator.divide(5, -10);
    ASSERT_EQ(-0.5, result);
}

TEST(CalculatorTest, DivideOnlyPositiveNumbers){
    Calculator calculator;
    double result = calculator.divide(5, 10);
    ASSERT_EQ(0.5, result);
}

TEST(CalculatorTest, DivideOnlyNegativeNumbers){
    Calculator calculator;
    double result = calculator.divide(-5, -10);
    ASSERT_EQ(0.5, result);
}

TEST(CalculatorTest, DivideShouldThrowErrorForInvalidSeconParam){
    Calculator calculator;
    EXPECT_THROW(calculator.divide(-5, 0), std::invalid_argument);
}