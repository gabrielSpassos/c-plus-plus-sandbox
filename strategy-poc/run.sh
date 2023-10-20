#!/bin/bash

rm -rf target/
mkdir target
g++ -std=c++14 -o target/main *.cpp
target/main