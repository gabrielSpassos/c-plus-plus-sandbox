#include <iostream>
#include <stdexcept>

using namespace std;

class Calculator {
    public:
        double add(double x, double y) {
            return x + y;
        }

        double subtract(double x, double y) {
            return x - y;
        }

        double multiply(double x, double y) {
            return x * y;
        }

        double divide(double x, double y) {
            if (y == 0) {
                throw std::invalid_argument("The second parameter on divide should be positive");
            }

            return x / y;
        }
};

