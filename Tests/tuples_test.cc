#include <limits.h>
#include "tuple.hpp"
#include "/usr/local/include/gtest/gtest.h"
namespace {

TEST(TupleTest, Point) {
    FBaseData P = point(-1.0, 2.0, 3.0);
    EXPECT_EQ(1.0, P.getW());
 
}

TEST(TupleTest, Vector) {
    FBaseData V = vector(-1.0, 2.0, 3.0);
    EXPECT_EQ(0, V.getW());
 
}

TEST(TupleTest, Equality){
    FBaseData T1(Tuple<float>{1.0, 2.0, 3.0, 1.0});
    FBaseData T2(Tuple<float>{1.0, 2.0, 3.0, 1.0});
    ASSERT_TRUE(T1==T2);
}

TEST(Operations, Addition){
    FBaseData T1(Tuple<float>{3, -2, 5, 1});
    FBaseData T2(Tuple<float>{-2, 3, 1, 0});
    
    FBaseData Sum = T1+T2;
    FBaseData ExpectedResult = point(1,1,6);
    ASSERT_TRUE(Sum == ExpectedResult);

}

TEST(Operations, SubtractionPP){
    FBaseData P1 = point(3, 2, 1);
    FBaseData P2 = point(5, 6, 7);

    FBaseData Subtract = P1-P2;
    FBaseData ExpectedResult = vector(-2,-4,-6);
    ASSERT_TRUE(Subtract == ExpectedResult);
    
}

TEST(Operations, SubtractionVP){
    FBaseData P = point(3, 2, 1);
    FBaseData V = vector(5, 6, 7);

    FBaseData Subtract = P - V;
    FBaseData ExpectedResult = point(-2,-4,-6);
    ASSERT_TRUE(Subtract == ExpectedResult);
    
}

TEST(Operations, SubtractionVV){
    FBaseData V1 = vector(3, 2, 1);
    FBaseData V2 = vector(5, 6, 7);

    FBaseData Subtract = V1 - V2;
    FBaseData ExpectedResult = vector(-2,-4,-6);
    ASSERT_TRUE(Subtract == ExpectedResult);
    
}

TEST(Operations, Negation){
    //FBaseData V0 = vector(0, 0, 0);
    FBaseData V = vector(1, -2, 3);

    V.negate();
    FBaseData ExpectedResult = vector(-1,2,-3);
    ASSERT_TRUE(V == ExpectedResult);
    
}




} //namespace

