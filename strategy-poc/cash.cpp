#include <iostream>
#include <string>
#include "./payment-method.cpp"

using namespace std;

class Cash : public PaymentMethod {
    private:
        string customerName;

    public:
        Cash(string customerName) {
            this->customerName = customerName;
        }

        virtual bool pay(double amount) override {
            cout << "Customer " << this->customerName << " payed with cash value: " << amount << "\n";
            return true;
        }
};