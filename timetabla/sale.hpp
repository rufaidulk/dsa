#include <bits/stdc++.h>
#include "product.hpp"
#include "user.hpp"

#ifndef SALE_H
#define SALE_H

using namespace std;

// class Product;
// class User;

class Sale
{
    public:
        string customer_name;
        string seller_name;
        string product_name;
        int product_price;
        int product_qntity;
        int is_wallet;
        string coupon;

        void displayAll();
        void displaySellerData(string seller_name);
        void purchaseProduct(User user, Product product);
        void payment(User user);
        void save();
        void displayAllInvoice(string customer_name);
        void addToCart(string customer_name);
        void viewCart(string customer_name);
        void checkoutCart(User user, Product product);
        void emptyCart(string customer_name);
        void walletPayment(User user);
};

#endif