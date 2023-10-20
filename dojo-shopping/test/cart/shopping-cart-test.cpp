#include <gtest/gtest.h>
#include "../../src/cart/shopping-cart.cpp"

TEST(ShoppingCartTest, CreditCardCheckOut){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Credit Card", 0, "Fixed", 1);

    ASSERT_EQ(50, result);
}

TEST(ShoppingCartTest, CreditCardCheckOutWithFixedDiscount){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Credit Card", 10, "Fixed", 1);

    ASSERT_EQ(40, result);
}

TEST(ShoppingCartTest, CreditCardCheckOutWithPercentageDiscount){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Credit Card", 10, "Percentage", 1);

    ASSERT_EQ(45, result);
}

TEST(ShoppingCartTest, BankTransferCheckOut){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Bank Transfer", 0, "Fixed", 1);

    ASSERT_EQ(47.5, result);
}

TEST(ShoppingCartTest, BankTransferCheckOutWithFixedDiscount){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Bank Transfer", 10, "Fixed", 1);

    ASSERT_EQ(38.00, result);
}

TEST(ShoppingCartTest, BankTransferCheckOutWithPercentageDiscount){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "Bank Transfer", 10, "Percentage", 1);

    ASSERT_EQ(42.75, result);
}

TEST(ShoppingCartTest, BuyNowPayLaterCheckOut){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "BNPL", 0, "Fixed", 1);

    ASSERT_EQ(51.5, result);
}

TEST(ShoppingCartTest, BuyNowPayLaterCheckOutWithInstallments){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "BNPL", 0, "Fixed", 2);

    ASSERT_EQ(25.75, result);
}

TEST(ShoppingCartTest, BuyNowPayLaterCheckOutWithFixedDiscount){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "BNPL", 10, "Fixed", 1);

    ASSERT_EQ(41.20, result);
}

TEST(ShoppingCartTest, BuyNowPayLaterCheckOutWithPercentageDiscount){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Regular", "BNPL", 10, "Percentage", 1);

    ASSERT_EQ(46.35, result);
}

TEST(ShoppingCartTest, BuyNowPayLaterCheckOutWithGoldCustomer){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    double result = shoppingCart.check_out("Gold", "BNPL", 0, "Fixed", 1);

    ASSERT_EQ(50.00, result);
}

TEST(ShoppingCartTest, ShouldThrowErrorForInvalidInstallment){
    ShoppingCart shoppingCart;
    shoppingCart.add_product(Product("thsirt", 20.00, 1));
    shoppingCart.add_product(Product("pants", 30.00, 1));

    EXPECT_THROW(shoppingCart.check_out("Regular", "BNPL", 0, "Fixed", 0);, std::invalid_argument);
    EXPECT_THROW(shoppingCart.check_out("Regular", "BNPL", 0, "Fixed", -1);, std::invalid_argument);
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