#include <iostream>
#include <string>
#include "./cart/shopping-cart.cpp"

using namespace std;

int main() {
    Product tshirt("thsirt", 20.00, 1);
    Product pants("pants", 30.00, 1);
    Product shoes("shoes", 15.00, 1);
    ShoppingCart shoppingCart;

    shoppingCart.add_product(tshirt);
    shoppingCart.add_product(pants);
    shoppingCart.add_product(shoes);
    shoppingCart.remove_product(shoes);

    double productsTotalPrice = shoppingCart.check_out("Regular", "Credit Card", 0, "Fixed", 1);
    cout << "ProductsTotalPrice: " << productsTotalPrice;

    return 1;
}