#pragma once

class PaymentMethod {
    public:
        virtual ~PaymentMethod() = default;

        virtual bool pay(double amount) = 0;
};