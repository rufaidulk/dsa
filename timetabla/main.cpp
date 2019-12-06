#include <bits/stdc++.h>
// #include "user.hpp"
// #include "product.hpp"
#include "sale.hpp"
#include "coupon.hpp"

using namespace std;

void setupFiles()
{
    fstream file;
    file.open("user.txt", ios::trunc | ios::out);
    file.close();
    file.open("sale.txt", ios::trunc | ios::out);
    file.close();
    file.open("product.txt", ios::trunc | ios::out);
    file.close();
}

void createAdmin()
{
    User user;
    user.setData("rufaid", "9999", "admin123", "Admin");
    user.save();
}

void createUser()
{
    string name, mobile, password, role;
    cout<<"Enter name\n";
    cin>>name;
    cout<<"enter mobile\n";
    cin>>mobile;
    cout<<"Enter password\n";
    cin>>password;
    cout<<"Enter role\n";
    cin>>role;

    User user;
    user.setData(name, mobile, password, role);
    user.save();

    cout<<"User created successfully\n";
}

void viewUser()
{
    string mobile;
    cout<<"Enter mobile\n";
    cin>>mobile;
    User user;
    user.showUser(mobile);
}

void editUser()
{
    string mobile;
    cout<<"Enter mobile\n";
    cin>>mobile;
    User user;
    if (user.findUser(mobile))
    {
        string name, password, role;
        cout<<"Enter new name\n";
        cin>>name;
        cout<<"enter new password\n";
        cin>>password;
        cout<<"enter new role\n";
        cin>>role;

        user.updateUser(name, mobile, password, role);
        return;
    }

    cout<<"invalid mobile\n";
}

void deleteUser()
{
    string mobile;
    cout<<"Enter mobile\n";
    cin>>mobile;
    User user;
    if (user.findUser(mobile))
    {
        user.deleteUser(mobile);
    }

    cout<<"invalid mobile\n";
}

void printSalesDetials()
{
    Sale sale;
    sale.displayAll();
}

void showAdminMenu(User user)
{
    char choice;
    Coupon coupon;

    do 
    {
        cout<<"Admin Menu\n1.create user\n2.view user\n3.edit user\n4.delete user\n5.Display sales details\n";
        cout<<"6.recharge wallet\n7.create coupon\nenter 'q' for logout\n";
        cin>>choice;

        switch (choice)
        {
            case '1':
                createUser();
                break;
            case '2':
                viewUser();
                break;
            case '3':
                editUser();
                break;
            case '4':
                deleteUser();
                break;
            case '5':
                printSalesDetials();
                break;
            case '6':
                user.rechargeWallet("Admin");
                break;
            case '7':
                coupon.createCoupon();
                break;
            case 'q':
                break;
        }

    } while (choice != 'q');
}

void addProduct(User user)
{
    string product_name;
    int price;
    cout<<"enter product name\n";
    cin>>product_name;
    cout<<"enter price\n";
    cin>>price;

    Product product;
    product.addProduct(user.name, product_name, price);
}

void printSellerSalesData(User user)
{
    Sale sale;
    sale.displaySellerData(user.name);
}

void productSummary(User user)
{
    Product product;
    product.displayAll(user.name);
}

void showSellerMenu(User user)
{
    char choice;
    Coupon coupon;
    do 
    {
        cout<<"seller menu\n1.add product\n2.sales details\n3.summary of products\n4.recharge wallet\n";
        cout<<"5.create coupon\nenter 'q' for logout\n";
        cin>>choice;

        switch (choice)
        {
            case '1':
                addProduct(user);
                break;
            case '2':
                printSellerSalesData(user);
                break;
            case '3':
                productSummary(user);
                break;
            case '4':
                user.rechargeWallet("Seller");
                break;
            case '5':
                coupon.createCoupon();
                break;
            case 'q':
                break;
        }

    } while (choice != 'q');
}

void showCustomerMenu(User user)
{
    char choice;
    Product product;
    Sale sale;
    Coupon coupon;

    do 
    {
        cout<<"customer menu\n1.See products\n2.purchase product\n3.Add to cart\n4.view cart\n5.checkout cart";
        cout<<"\n6.See invoices\n7.recharge wallet\n8.list coupons\nenter 'q' for logout\n";
        cin>>choice;

        switch (choice)
        {
            case '1':
                product.showProductCatalog();
                break;
            case '2':
                sale.purchaseProduct(user, product);
                user.creditSellerWallet(sale.seller_name, sale.product_price);
                user.creditAdminWallet(sale.product_price);
                if (sale.is_wallet)
                    user.updateWallet(user.mobile, sale.product_price, -1);
                if (sale.is_wallet && sale.coupon != "q")
                {
                    int amt = coupon.updateMaxUsage(sale.coupon);
                    user.updateWallet(user.mobile, amt, 1);
                }
                break;
            case '3':
                sale.addToCart(user.name);
                break;
            case '4':
                sale.viewCart(user.name);
                break;
            case '5':
                sale.checkoutCart(user, product);
                user.creditSellerWallet(sale.seller_name, sale.product_price);
                user.creditAdminWallet(sale.product_price);
                if (sale.is_wallet)
                    user.updateWallet(user.mobile, sale.product_price, -1);
                if (sale.is_wallet && sale.coupon != "q")
                {
                    int amt = coupon.updateMaxUsage(sale.coupon);
                    user.updateWallet(user.mobile, amt, 1);
                }
                break;
            case '6':
                sale.displayAllInvoice(user.name);
                break;
            case '7':
                user.rechargeWallet("Customer");
                break;
            case '8':
                coupon.listAll();
                break;
            case 'q':
                break;
        }

    } while (choice != 'q');
}

void login(string role)
{
    string mobile, password;
    cout<<role<<" Login\n"<<"Enter mobile\n";
    cin>>mobile;
    cout<<"Enter password\n";
    cin>>password;
    
    User user;
    if (user.login(mobile, password, role))
    {
        if (role == "Admin")
            showAdminMenu(user);
        else if (role == "Seller")
            showSellerMenu(user);
        else 
            showCustomerMenu(user);

        return;
    }

    cout<<"Unauthorized\n";
}

/**
 * Main function
 */
int main()
{
    // setupFiles();
    // createAdmin();

    char choice;
    do 
    {
        cout<<"#------- Online Shopping ----------#\n1.Admin Login\n2.Seller Login\n3.Customer Login\n";
        cout<<"Enter 'q' for exit\n";
        cin>>choice;

        switch (choice)
        {
            case '1':
                login("Admin");
                break;
            case '2':
                login("Seller");
                break;
            case '3':
                login("Customer");
                break;
            case 'q':
                break;

        }

    } while (choice != 'q');

    return 0;
}