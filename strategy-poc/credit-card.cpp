#include <iostream>
#include <string>
#include "./payment-method.cpp"

using namespace std;

class CreditCard : public PaymentMethod {
    private: 
        string customerName;

    public:
        CreditCard(string customerName) {
            this->customerName = customerName;
        }

        virtual bool pay(double amount) override {
            cout << "Customer " << this->customerName << " payed with credit card value: " << amount << "\n";
            return true;
        }
};