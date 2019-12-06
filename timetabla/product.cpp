#include "product.hpp"
#include<bits/stdc++.h>

using namespace std;

void Product::addProduct(string seller_name, string product_name, int price)
{
    fstream file;
    file.open("product.txt", ios::app | ios::out);
    file <<seller_name<<" "<<product_name<<" "<<price<<endl;
    file.close();

    cout<<"Product added\n";
}

void Product::displayAll(string seller_Name)
{
    fstream file;
    file.open("product.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->seller_name>>this->product_name>>this->product_price;
        if (file.eof())
            break;

        if (this->seller_name != seller_Name)
            continue;

        cout<<"Product : "<<this->product_name<<" Price: "<<this->product_price<<endl;

    }
}

void Product::showProductCatalog()
{
    fstream file;
    file.open("product.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->seller_name>>this->product_name>>this->product_price;
        if (file.eof())
            break;

        cout<<"Product : "<<this->product_name<<" Price: "<<this->product_price<<endl;

    }
}

void Product::getProduct(string product_name)
{
    fstream file;
    file.open("product.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->seller_name>>this->product_name>>this->product_price;
        if (file.eof())
            break;

        if (this->product_name == product_name)
            return;

    }
}

