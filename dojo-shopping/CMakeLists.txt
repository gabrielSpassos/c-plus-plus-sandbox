cmake_minimum_required(VERSION 3.14)
project(dojo-shopping)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/9bb354fa8325fa31faa1e12627b25ab445e6eed3.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(shopping-cart-test test/cart/shopping-cart-test.cpp)
target_link_libraries(shopping-cart-test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(shopping-cart-test)