#!/bin/bash

cp ../Tests/tuples_test.cc ./
g++ -std=c++11 -stdlib=libc++  tuples_test.cc gtest_main.cc tuple.cpp -lgtest -lpthread -o pointVecTest
./pointVecTest
