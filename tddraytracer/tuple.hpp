//
//  tuple.hpp
//  tddraytracer
//
//  Created by Gary Marshall on 3/1/20.
//  Copyright © 2020 Gary Marshall. All rights reserved.
//

#ifndef tuple_hpp
#define tuple_hpp

#include <stdio.h>
#include <cmath>



template <typename T>
struct Tuple
{
    T x;
    T y;
    T z;
    T w;
};


class FBaseData
{
    const double EPSILON = 0.00001;
    
public:
    explicit FBaseData(Tuple<float> inTuple);
    FBaseData(const FBaseData& other);
    
    //data gettrz
    const Tuple<float>& getData() const {return mTuple; }
    const float getX() const { return mTuple.x; }
    const float getY() const { return mTuple.y; }
    const float getZ() const { return mTuple.z; }
    const float getW() const { return mTuple.w; }
    
    void setX(float x)  {  mTuple.x = x; }
    void setY(float y)  {  mTuple.y = y; }
    void setZ(float z)  {  mTuple.z = z; }
    void setW(float w)  {  mTuple.w = w; }
    
    //operators
    bool operator==(const FBaseData& other) const;
    friend FBaseData operator+(const FBaseData& f1, const FBaseData& f2);
    friend FBaseData operator-(const FBaseData& f1, const FBaseData& f2);
    friend FBaseData operator*(const FBaseData& f1, const float scalar);
    //negation
    void negate();
    
protected:
    Tuple<float> mTuple;
};

FBaseData vector(float x, float y, float z);
FBaseData point(float x, float y, float z);
FBaseData color(float r, float g, float b, float a);


#endif /* tuple_hpp */
