#!/bin/bash

rm -rf target/
cmake -S . -B target
cmake --build target
target/shopping-cart-test
