#include "fraction.h"
#include <gtest/gtest.h>


TEST(Other, Reduction){
    fraction a(9,27);
    EXPECT_EQ(a.get_num(), 1);
    EXPECT_EQ(a.get_denom(), 3);
}

TEST(Other, ReductionNegative){
    fraction a(9,-27);
    EXPECT_EQ(a.get_num(), -1);
    EXPECT_EQ(a.get_denom(), 3);
}

TEST(Other, GetNumeration){
    fraction a(1,3);
    EXPECT_EQ(a.get_num(), 1);
}

TEST(Other, GetDenomiration){
    fraction a(1,3);
    EXPECT_EQ(a.get_denom(), 3);
}

TEST(Other, NormalConstructor){
    fraction a(3,-4);
    EXPECT_EQ(a.get_num(), -3);
    EXPECT_EQ(a.get_denom(), 4);
}

TEST(Other, DenominatorZero_Constructor){
    EXPECT_THROW(fraction a(3,0), std::invalid_argument);
}

TEST(Other, CopyConstructor){
    fraction a(3,4);
    fraction b(a);
    EXPECT_EQ(b.get_num(), 3);
    EXPECT_EQ(b.get_denom(), 4);
}


TEST(OutputTest, Output){
    fraction a(3,4);
    EXPECT_EQ(a.StringOutput(), "3/4");
}

TEST(OutputTest, Output_WithWholeNumber){
    fraction a(5,4);
    EXPECT_EQ(a.StringOutput(), "1 1/4");
}

TEST(OutputTest, Output_WholeNumber){
    fraction a(16,4);
    EXPECT_EQ(a.StringOutput(), "4");
}

TEST(OutputTest, Output_Zero){
    fraction a(0,4);
    EXPECT_EQ(a.StringOutput(), "0");
}

TEST(OutputTest, Output_One){
    fraction a(4,4);
    EXPECT_EQ(a.StringOutput(), "1");
}

TEST(OutputTest, OutputNegative){
    fraction a(-3,4);
    EXPECT_EQ(a.StringOutput(), "-3/4");
}

TEST(OutputTest, OutputNegative_WithWholeNumber){
    fraction a(-5,4);
    EXPECT_EQ(a.StringOutput(), "-1 1/4");
}

TEST(OutputTest, OutputNegative_WholeNumber){
    fraction a(-16,4);
    EXPECT_EQ(a.StringOutput(), "-4");
}

TEST(OutputTest, OutputNegative_One){
    fraction a(-4,-4);
    EXPECT_EQ(a.StringOutput(), "1");
}



TEST(Algebra, Sum){
fraction a(3,5);
fraction b(9,10);
fraction c(1,1);
c=a+b;
EXPECT_EQ(c.get_num(), 3);
EXPECT_EQ(c.get_denom(), 2);
}

TEST(Algebra, Sum_1Negative){
    fraction a(3,5);
    fraction b(-9,10);
    fraction c(1,1);
    c=a+b;
    EXPECT_EQ(c.get_num(), -3);
    EXPECT_EQ(c.get_denom(), 10);
}

TEST(Algebra, Sum_2Negative){
    fraction a(-3,5);
    fraction b(-9,10);
    fraction c(1,1);
    c=a+b;
    EXPECT_EQ(c.get_num(), -3);
    EXPECT_EQ(c.get_denom(), 2);
}

TEST(Algebra, Sum_Zero){
    fraction a(-3,5);
    fraction b(0,10);
    fraction c(1,1);
    c=a+b;
    EXPECT_EQ(c.get_num(), -3);
    EXPECT_EQ(c.get_denom(), 5);
}

TEST(Algebra, Sum_One){
    fraction a(3,5);
    fraction b(10,10);
    fraction c(1,1);
    c=a+b;
    EXPECT_EQ(c.get_num(), 8);
    EXPECT_EQ(c.get_denom(), 5);
}

TEST(Algebra, Multipl){
    fraction a(3,5);
    fraction b(9,10);
    fraction c(1,1);
    c=a*b;
    EXPECT_EQ(c.get_num(), 27);
    EXPECT_EQ(c.get_denom(), 50);
}

TEST(Algebra, Multipl_1Negative){
    fraction a(-3,5);
    fraction b(9,10);
    fraction c(1,1);
    c=a*b;
    EXPECT_EQ(c.get_num(), -27);
    EXPECT_EQ(c.get_denom(), 50);
}

TEST(Algebra, Multipl_2Negative){
    fraction a(-3,5);
    fraction b(-9,10);
    fraction c(1,1);
    c=a*b;
    EXPECT_EQ(c.get_num(), 27);
    EXPECT_EQ(c.get_denom(), 50);
}

TEST(Algebra, Multipl_Zero){
    fraction a(-3,5);
    fraction b(0,10);
    fraction c(1,1);
    c=a*b;
    EXPECT_EQ(c.get_num(), 0);
}

TEST(Algebra, Multipl_One){
    fraction a(3,5);
    fraction b(9,9);
    fraction c(1,1);
    c=a*b;
    EXPECT_EQ(c.get_num(), 3);
    EXPECT_EQ(c.get_denom(), 5);
}

TEST(Algebra, Divide){
    fraction a(3,5);
    fraction b(9,10);
    fraction c(1,1);
    c=a/b;
    EXPECT_EQ(c.get_num(), 2);
    EXPECT_EQ(c.get_denom(), 3);
}

TEST(Algebra, Divide_1Negative){
    fraction a(-3,5);
    fraction b(9,10);
    fraction c(1,1);
    c=a/b;
    EXPECT_EQ(c.get_num(), -2);
    EXPECT_EQ(c.get_denom(), 3);
}

TEST(Algebra, Divide_2Negative){
    fraction a(-3,5);
    fraction b(-9,10);
    fraction c(1,1);
    c=a/b;
    EXPECT_EQ(c.get_num(), 2);
    EXPECT_EQ(c.get_denom(), 3);
}


TEST(Algebra, Divide_Zero){
    fraction a(-3,5);
    fraction b(0,10);
    EXPECT_THROW((a/b), std::invalid_argument);
}

TEST(Algebra, Divide_One){
    fraction a(3,5);
    fraction b(9,9);
    fraction c(1,1);
    c=a/b;
    EXPECT_EQ(c.get_num(), 3);
    EXPECT_EQ(c.get_denom(), 5);
}

