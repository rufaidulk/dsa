#include "coupon.hpp"

using namespace std;

void Coupon::createCoupon()
{
    cout<<"enter coupon name\n";
    cin>>this->name;
    cout<<"enter amount\n";
    cin>>this->amount;
    cout<<"enter max usage\n";
    cin>>this->max_usage;

    this->save();
    cout<<"new coupon created\n";
}

void Coupon::save()
{
    fstream file;
    file.open("coupon.txt", ios::app | ios::out);
    file <<this->name<<" "<<this->amount<<" "<<this->max_usage<<endl;
    file.close();
}

void Coupon::listAll()
{
    fstream file;
    file.open("coupon.txt", ios::app | ios::in);
    while (file)
    {
        file >>this->name>>this->amount>>this->max_usage;
        if (file.eof())
            break;

        if (this->max_usage <= 0)
            continue;

        cout<<"Name: "<<this->name<<" Amt: "<<this->amount<<endl;
    }

    file.close();
}

int Coupon::updateMaxUsage(string name)
{
    fstream file;
    fstream tmpFile;
    file.open("coupon.txt", ios::app | ios::in);
    tmpFile.open("tmp.txt", ios::app | ios::out);
    int amt;
    while (file)
    {
        file >>this->name>>this->amount>>this->max_usage;

        if (file.eof())
            break;

        if (this->name == name)
        {
            this->max_usage--;
            amt = this->amount;
        }

        tmpFile<<this->name<<" "<<this->amount<<" "<<this->max_usage<<endl;
    }
    file.close();
    tmpFile.close();

    remove("coupon.txt");
    rename("tmp.txt", "coupon.txt");

    return amt;
}