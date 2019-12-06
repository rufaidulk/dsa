#include <bits/stdc++.h>

#ifndef USER_H
#define USER_H

using namespace std;

class User
{
    public:
        string name;
        string mobile;
        string password;
        string role;
        int wallet_balance;

        void setData(string name, string mobile, string password, string role);
        string encryptPassword(string password);
        void writeToFile();
        void save();
        int login(string mobile, string password, string role);
        void showUser(string mobile);
        int findUser(string mobile);
        void updateUser(string name, string mobile, string password, string role);
        void deleteUser(string mobile);
        void rechargeWallet(string role);
        void updateWallet(string mobile, int amount, int opt);
        void creditSellerWallet(string seller_name, int product_price);
        void creditAdminWallet(int product_price);
};

#endif