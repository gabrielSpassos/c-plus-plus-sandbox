#include <iostream>
#include <string>
#include <vector>
#include "./product.cpp"
#include "../check-out/check-out.cpp"
#include "../check-out/credit-card.cpp"
#include "../check-out/bank-transfer.cpp"
#include "../check-out/buy-now-pay-later.cpp"

using namespace std;

class ShoppingCart {

    private:
        vector<Product> products;
        int find_index_of(Product product);
        double get_total_products_price();
        CheckOut* get_check_out_by_type(string checkOutType, double discountCupom);
    
    public:
        Product add_product(Product product) {
            this->products.push_back(product);
            return product;
        }

        Product remove_product(Product product) {
            int index = find_index_of(product);
            if (-1 == index) {
                throw invalid_argument("Product is not on the cart");
            };
            
            this->products.erase(this->products.begin() + index);
            return product;
        }

        double check_out(string customerType, string checkOutType, double discountCupom, string discountType, int installments) {
            CheckOut* check_out = get_check_out_by_type(checkOutType, discountCupom);

            double productsTotalPrice = get_total_products_price();

            double discountAmount = "Percentage" == discountType 
                ? check_out->calculate_percentage_cupom_discount(productsTotalPrice)
                : discountCupom;

            return check_out->execute_payment(productsTotalPrice, discountAmount, installments, customerType);
        }

};

int ShoppingCart::find_index_of(Product product) {
    int size = ShoppingCart::products.size();

    for (int i = 0; i < size; i++) {
        Product p = ShoppingCart::products.at(i);

        if(p.get_total_price() == product.get_total_price()) {
            return i;
        }
    }

    return -1;
}

double ShoppingCart::get_total_products_price() {
    double total = 0;
    for (Product product : ShoppingCart::products) {
        total += product.get_total_price();
    }
    return total;
}

CheckOut* ShoppingCart::get_check_out_by_type(string checkOutType, double discountCupom) {
    if ("Credit Card" == checkOutType) {
        return new CreditCard(discountCupom);
    }

    if ("Bank Transfer" == checkOutType) {
        return new BankTransfer(discountCupom);
    }

    if ("BNPL" == checkOutType) {
        return new BuyNowPayLater(discountCupom);
    }

    throw invalid_argument("Invalid check out type");
}
