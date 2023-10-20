#include <iostream>
#include <string>
#include "./check-out.cpp"
#include "../utils/amount-utils.cpp"

using namespace std;

class BuyNowPayLater: public CheckOut {
    private: 
        double discountCupom;
        double feePercentage = 3;
        AmountUtils amountUtils;

    public: 
        BuyNowPayLater(double discountCupom) {
            this->discountCupom = discountCupom;
            this->amountUtils = AmountUtils();
        }

        double calculate_percentage_cupom_discount(double paymentAmount) {
            return this->amountUtils.get_amount_equivalent_to_percentage(paymentAmount, this->discountCupom);
        }

        double execute_payment(double amount, double discount, int installments, string customerType) {
            if (1 > installments) {
                throw invalid_argument("Installments should be at minimum 1");
            }

            double finalFeePercentage = "Gold" == customerType ? 0 : this->feePercentage;
            double amountLessDiscount = amount - discount;
            double feeAmount = this->amountUtils
                .get_amount_equivalent_to_percentage(amountLessDiscount, finalFeePercentage);
            double amountPlusFee = amountLessDiscount + feeAmount;
            return amountPlusFee / installments;
        }
};