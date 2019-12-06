#include<bits/stdc++.h>

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product
{
    public:
        string seller_name;
        string product_name;
        int product_price;

        void addProduct(string seller_name, string product_name, int price);
        void displayAll(string seller_name);
        void showProductCatalog();
        void getProduct(string product_name);
};

#endif