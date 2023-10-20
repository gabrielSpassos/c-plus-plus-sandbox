#include <gtest/gtest.h>
#include "../../src/cart/shopping-cart.cpp"

TEST(ShoppingCartTest, CreditCardCheckOut){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Credit Card", 0, "Fixed", 1);

    ASSERT_EQ(50, result);
}

TEST(ShoppingCartTest, BankTransferCheckOut){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Bank Transfer", 0, "Fixed", 1);

    ASSERT_EQ(47.5, result);
}

TEST(ShoppingCartTest, BuyNowPayLaterCheckOut){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "BNPL", 0, "Fixed", 1);

    ASSERT_EQ(51.5, result);
}

TEST(ShoppingCartTest, ShouldRemoveProductFromCart){
    ShoppingCart shoppingCart;
    Product shoes("shoes", 15.00, 2);
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(shoes);
    shoppingCart.add_product(Product("pants", 30.00, 1));
    shoppingCart.remove_product(shoes);

    double result = shoppingCart.check_out("Regular", "Credit Card", 0, "Fixed", 1);
    
    ASSERT_EQ(50, result);
}

TEST(ShoppingCartTest, ShouldThrowErrorForProductThatIsNotOnCart){
    ShoppingCart shoppingCart;
    Product shoes("shoes", 15.00, 2);
    
    EXPECT_THROW(shoppingCart.remove_product(shoes);, std::invalid_argument);
}