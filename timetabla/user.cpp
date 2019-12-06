#include "user.hpp"
#include <bits/stdc++.h>

using namespace std;

void User::setData(string name, string mobile, string password, string role)
{
    this->name = name;
    this->mobile = mobile;
    this->password = password;
    this->role = role;
}

string User::encryptPassword(string password)
{
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
            password[i] = password[i] - 32;
        else if (password[i] >= 'A' && password[i] <= 'Z')
            password[i] = this->password[i] + 32;
        else if (password[i] >= '0' && password[i] < '9')
            password[i] = password[i] + 1;
        else 
            password[i] = '0';
    }

    return password;
}

void User::writeToFile()
{
    fstream file;
    file.open("user.txt", ios::app | ios::out);
    file <<this->name<<" "<<this->mobile<<" "<<this->password<<" "<<this->role
        <<" "<<this->wallet_balance<<"\n";
    file.close();

}

void User::save()
{
    this->password = this->encryptPassword(this->password);
    this->wallet_balance = 0;
    this->writeToFile();
}

int User::login(string mobile, string password, string role)
{
    fstream file;
    file.open("user.txt", ios::in);
    while (!file.eof())
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        
        if (this->mobile == mobile && this->password == this->encryptPassword(password) && this->role == role)
            return 1;
    }

    return 0;
}

void User::showUser(string mobile)
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);
    while (!file.eof())
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        
        if (this->mobile == mobile)
        {
            cout<<"Name: "<<this->name<<" Mobile: "<<this->mobile<<" Role: "<<this->role
                <<" Balance: "<<this->wallet_balance<<endl;
            return;
        }
    }
    file.close();
    cout<<"invalid mobile\n";
}

int User::findUser(string mobile)
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);
    while (!file.eof())
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        
        if (this->mobile == mobile)
        {
            return 1;
        }
    }

    file.close();

    return 0;
}

void User::updateUser(string name, string mobile, string password, string role)
{
    fstream file;
    fstream tmpFile;
    file.open("user.txt", ios::app | ios::in);
    tmpFile.open("tmp.txt", ios::app | ios::out);

    while (!file.eof())
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        if (file.eof())
            break;
        
        if (this->mobile == mobile)
        {
            this->name = name;
            this->password = this->encryptPassword(password);
            this->role = role;
        }

        tmpFile <<this->name<<" "<<this->mobile<<" "<<this->password<<" "<<this->role
            <<" "<<this->wallet_balance<<"\n";
    }

    file.close();
    tmpFile.close();

    remove("user.txt");
    rename("tmp.txt", "user.txt");

    cout<<"User updated\n";
}

void User::deleteUser(string mobile)
{
    fstream file;
    fstream tmpFile;
    file.open("user.txt", ios::app | ios::in);
    tmpFile.open("tmp.txt", ios::app | ios::out);

    while (!file.eof())
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        
        if (this->mobile == mobile)
            continue;

        tmpFile <<this->name<<" "<<this->mobile<<" "<<this->password<<" "<<this->role<<" "
            <<this->wallet_balance<<"\n";
    }

    file.close();
    tmpFile.close();

    remove("user.txt");
    rename("tmp.txt", "user.txt");

    cout<<"User deleted\n";
}

void User::rechargeWallet(string role)
{
    int amount;
    cout<<"Enter amount\n";
    cin>>amount;

    this->updateWallet(this->mobile, amount, 1);
}

void User::creditSellerWallet(string seller_name, int product_price)
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        if (file.eof())
            break;

        if (this->name == seller_name)
        {
            int amt = 0.9 * product_price;
            this->updateWallet(this->mobile, amt, 1);
        }
    }

    file.close();
}

void User::creditAdminWallet(int product_price)
{
    int amt = 0.1 * product_price;
    this->updateWallet("9999", amt, 1);
}

void User::updateWallet(string mobile, int amount, int opt)
{
    cout<<mobile<<endl;
    fstream file;
    fstream tmpFile;
    file.open("user.txt", ios::app | ios::in);
    tmpFile.open("tmp.txt", ios::app | ios::out);

    while (!file.eof())
    {
        file >>this->name>>this->mobile>>this->password>>this->role>>this->wallet_balance;
        if (file.eof())
            break;
        
        if (this->mobile == mobile)
        {
            this->wallet_balance = this->wallet_balance + (opt * amount);
        }

        tmpFile <<this->name<<" "<<this->mobile<<" "<<this->password<<" "<<this->role
            <<" "<<this->wallet_balance<<"\n";
    }

    file.close();
    tmpFile.close();

    remove("user.txt");
    rename("tmp.txt", "user.txt");

    cout<<"wallet updated\n";
}

