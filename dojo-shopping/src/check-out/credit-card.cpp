#include <iostream>
#include <string>
#include "./check-out.cpp"
#include "../utils/amount-utils.cpp"

using namespace std;

class CreditCard: public CheckOut {
    private: 
        double discountCupom;

    public: 
        CreditCard(double discountCupom) {
            this->discountCupom = discountCupom;
        }

        double calculate_percentage_cupom_discount(double paymentAmount) {
            AmountUtils amountUtils;
            return amountUtils.get_amount_equivalent_to_percentage(paymentAmount, this->discountCupom);
        }

        double execute_payment(double amount, double discount, int installments, string customerType) {
            return amount - discount;
        }
};