#include "sale.hpp"
#include <bits/stdc++.h>

using namespace std;

void Sale::displayAll()
{
    fstream file;
    file.open("sale.txt", ios::app | ios::in);
    while (!file.eof())
    {
        file >>this->customer_name>>this->seller_name>>this->product_name>>this->product_price
            >>this->product_qntity;
        
        cout<<"Customer: "<<this->customer_name<<" Seller: "<<this->seller_name<<" Product: "
            <<this->product_name<<" Price: "<<this->product_price<<" Qntity: "<<this->product_qntity<<endl;
           
    }

    file.close();
}

void Sale::displaySellerData(string seller_name)
{
    fstream file;
    file.open("sale.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->customer_name>>this->seller_name>>this->product_name>>this->product_price
            >>this->product_qntity;
        
        if (file.eof())
            break;

        if (this->seller_name != seller_name)
            continue;

        cout<<"Customer: "<<this->customer_name<<" Seller: "<<this->seller_name<<" Product: "
            <<this->product_name<<" Price: "<<this->product_price<<" Qntity: "<<this->product_qntity<<endl;
           
    }

    file.close();
}


void Sale::purchaseProduct(User user, Product product)
{
    cout<<"enter your product name\n";
    cin>>this->product_name;
    cout<<"enter product qntity\n";
    cin>>this->product_qntity;

    product.getProduct(this->product_name);
    this->product_price = product.product_price * this->product_qntity;
    this->seller_name = product.seller_name;
    this->customer_name = user.name;

    this->payment(user);
}

void Sale::payment(User user)
{
    int choice;
    cout<<"1.Pay by cash\n2.Pay by wallet\n";
    cin>>choice;
    if (choice == 1)
    {
        this->save();
        this->is_wallet = 0;
    }
    else 
        this->walletPayment(user);

    cout<<"purchased\n";
}

void Sale::walletPayment(User user)
{
    if (user.wallet_balance < this->product_price)
    {
        cout<<"Not enough balance\n";
        this->payment(user);
    }
    cout<<"enter coupon, if no coupon just enter 'q'\n";
    cin>>this->coupon;

    this->is_wallet = 1;
    this->save();
}

void Sale::save()
{
    fstream file;
    file.open("sale.txt", ios::app | ios::out);
    file <<this->customer_name<<" "<<this->seller_name<<" "<<this->product_name<<" "<<this->product_price
            <<" "<<this->product_qntity<<endl;

    file.close();
}


void Sale::displayAllInvoice(string customer_name)
{
    fstream file;
    file.open("sale.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->customer_name>>this->seller_name>>this->product_name>>this->product_price
            >>this->product_qntity;
        
        if (file.eof())
            break;

        if (this->customer_name != customer_name)
            continue;

        cout<<"Customer: "<<this->customer_name<<" Seller: "<<this->seller_name<<" Product: "
            <<this->product_name<<" Price: "<<this->product_price<<" Qntity: "<<this->product_qntity<<endl;
           
    }

    file.close();
}

void Sale::addToCart(string customer_name)
{
    cout<<"enter your product name\n";
    cin>>this->product_name;
    cout<<"enter product qntity\n";
    cin>>this->product_qntity;
    
    fstream file;
    file.open("cart.txt", ios::app | ios::out);
    file <<customer_name<<" "<<this->product_name<<" "<<this->product_qntity<<endl;

    file.close();

    cout<<"product added to cart\n";
}

void Sale::viewCart(string customer_name)
{
    fstream file;
    file.open("cart.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->customer_name>>this->product_name>>this->product_qntity;
        if (file.eof())
            break;

        if (this->customer_name != customer_name)
            continue;

        cout<<"Product: "<<this->product_name<<" Qntity: "<<this->product_qntity<<endl;
    }
}

void Sale::checkoutCart(User user, Product product)
{
    string customer_name = user.name;
    fstream file;
    file.open("cart.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->customer_name>>this->product_name>>this->product_qntity;
        if (file.eof())
            break;

        if (this->customer_name == customer_name)
        {
            product.getProduct(this->product_name);
            this->product_price = product.product_price * this->product_qntity;
            this->seller_name = product.seller_name;
            this->payment(user);
            this->emptyCart(customer_name);
            break;
        }
    }
    file.close();
}

void Sale::emptyCart(string customer_name)
{
    fstream file;
    fstream tmpFile;
    file.open("cart.txt", ios::app | ios::in);
    tmpFile.open("tmp.txt", ios::app | ios::out);

    while (!file.eof())
    {
        file >>this->customer_name>>this->product_name>>this->product_qntity;
        if (file.eof())
            break;

        if (this->customer_name == customer_name)
            continue;

        tmpFile <<this->customer_name<<" "<<this->product_name<<" "<<this->product_qntity<<endl;
    }

    file.close();
    tmpFile.close();

    remove("cart.txt");
    rename("tmp.txt", "cart.txt");
}

