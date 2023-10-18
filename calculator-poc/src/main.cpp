#include <iostream>
#include <string>
#include "./calculator.cpp"

using namespace std;

int main() {
    try {
        Calculator calculator;
        cout << calculator.add(2, 4) << endl;
        cout << calculator.subtract(2, 4) << endl;
        cout << calculator.multiply(2, 4) << endl;
        cout << calculator.divide(2, 4) << endl;
        cout << calculator.divide(2, 0) << endl;
    } catch (std::invalid_argument& e) {
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}