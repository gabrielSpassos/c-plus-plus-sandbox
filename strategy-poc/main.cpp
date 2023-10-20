#include <iostream>
#include <string>
#include "./payment-method.cpp"
#include "./credit-card.cpp"
#include "./cash.cpp"

using namespace std;

std::unique_ptr<PaymentMethod> getPaymentMethod(string paymentMethod) {
    if ("Cash" == paymentMethod) {
        return std::make_unique<Cash>("Josh");
    }

    if ("Credit Card" == paymentMethod) {
        return std::make_unique<CreditCard>("Josh");
    }

    throw invalid_argument("Invalid payment method");
}

PaymentMethod* getPaymentMethodPointer(string paymentMethod) {
    if ("Cash" == paymentMethod) {
        Cash* c = new Cash("Mike");
        return c;
    }

    if ("Credit Card" == paymentMethod) {
        CreditCard* cc = new CreditCard("Mike");
        return cc;
    }

    throw invalid_argument("Invalid payment method");
}

int main() {
    try {
        std::unique_ptr<PaymentMethod> cash = getPaymentMethod("Cash");
        cash->pay(25.00);

        std::unique_ptr<PaymentMethod> creditCard = getPaymentMethod("Credit Card");
        creditCard->pay(152.57);

        PaymentMethod* cashPointer = getPaymentMethodPointer("Cash");
        cashPointer->pay(32.00);

        PaymentMethod* creditCardPointer = getPaymentMethodPointer("Credit Card");
        creditCardPointer->pay(8.32);

        std::unique_ptr<PaymentMethod> testPaymentMethod = getPaymentMethod("Test");

        return 0;
    } catch (std::invalid_argument& e) {
        cerr << e.what() << endl;
        return -1;
    }
}
