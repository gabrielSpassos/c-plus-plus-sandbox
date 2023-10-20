#include <iostream>
#include <string>

using namespace std;

class Product {
    private: 
        string name;
        double price;
        int quantity;
    
    public:
        Product(string name, double price, int quantity) {
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }

        double get_total_price() {
            return this->price * this->quantity;
        }
};