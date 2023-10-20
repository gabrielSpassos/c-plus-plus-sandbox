#include <iostream>
#include <string>
#pragma once

using namespace std;

class CheckOut {
    public:
        virtual ~CheckOut() = default;

        virtual double execute_payment(double amount, double discount, int installments, string customerType) = 0;

        virtual double calculate_percentage_cupom_discount(double paymentAmount) = 0;
};