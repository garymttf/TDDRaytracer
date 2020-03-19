//
//  tuple.cpp
//  tddraytracer
//
//  Created by Gary Marshall on 3/1/20.
//  Copyright © 2020 Gary Marshall. All rights reserved.
//

#include "tuple.hpp"

static const float POINT_W = 1.0;
static const int VECTOR_W = 0;

FBaseData::FBaseData(Tuple<float> inTuple)
{
    this->mTuple = inTuple;
}

FBaseData::FBaseData(const FBaseData& other)
{
    this->mTuple = other.mTuple;
}

bool FBaseData::operator==(const FBaseData& other) const
{
    
    return (std::abs(this->getX() - other.getX()) < EPSILON
                                    && std::abs(this->getY() - other.getY()) < EPSILON
                                    && std::abs(this->getZ() - other.getZ()) < EPSILON
                                    && std::abs(this->getW() - other.getW()) < EPSILON ? true : false );
}

void FBaseData::negate()
{
    this->setX(this->getX()*-1);
    this->setY(this->getY()*-1);
    this->setZ(this->getZ()*-1);
}

FBaseData operator+(const FBaseData& f1, const FBaseData& f2)
{

    FBaseData F(Tuple<float>{f1.getX() + f2.getX(),
                f1.getY() + f2.getY(),
                f1.getZ() + f2.getZ(),
                f1.getW() + f2.getW()});
    return F;
}

FBaseData operator-(const FBaseData& f1, const FBaseData& f2)
{

    FBaseData F(Tuple<float>{f1.getX() - f2.getX(),
                f1.getY() - f2.getY(),
                f1.getZ() - f2.getZ(),
                f1.getW() - f2.getW()});
    return F;
}


/* FACTORY FUNCTIONS */
FBaseData vector(float x, float y, float z)
{
    return FBaseData(Tuple<float>{x, y, z, VECTOR_W});
}

FBaseData point(float x, float y, float z)
{
    return FBaseData(Tuple<float>{x, y, z, POINT_W});
}
