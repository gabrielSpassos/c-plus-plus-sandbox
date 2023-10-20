#pragma once

class AmountUtils {
    private:
        double oneHundread = 100.00;

    public:
        double get_amount_equivalent_to_percentage(double amount, double amountPercentage) {
            double amountEquivalentToPercentage = (amount * amountPercentage) / oneHundread;
            return amountEquivalentToPercentage;
        }
};