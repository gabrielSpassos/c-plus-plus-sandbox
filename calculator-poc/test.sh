#!/bin/bash

rm -rf target/
cmake -S . -B target
cmake --build target
target/calculator_test

# g++ -std=c++14 -o target/test test/*.cpp src/calculator.cpp -lgtest -pthread -lgtest_main
# target/test