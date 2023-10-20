#include <iostream>
#include <string>
#include "./check-out.cpp"
#include "../utils/amount-utils.cpp"

using namespace std;

class BankTransfer: public CheckOut {
    private: 
        double discountCupom;
        double baseDiscountPercentage = 5;
        AmountUtils amountUtils;

    public: 
        BankTransfer(double discountCupom) {
            this->discountCupom = discountCupom;
            this->amountUtils = AmountUtils();
        }

        double calculate_percentage_cupom_discount(double paymentAmount) {
            return this->amountUtils.get_amount_equivalent_to_percentage(paymentAmount, this->discountCupom);
        }

        double execute_payment(double amount, double discount, int installments, string customerType) {
            double amountLessDiscount = amount - discount;
            double bankTransferDiscount = this->amountUtils
                .get_amount_equivalent_to_percentage(amountLessDiscount, this->baseDiscountPercentage);
            return amountLessDiscount - bankTransferDiscount;
        }
};