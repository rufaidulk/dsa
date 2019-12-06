#include <bits/stdc++.h>

using namespace std;

#ifndef COUPON_H
#define COUPON_H

class Coupon
{
    public:
        string name;
        int max_usage;
        int amount;

        void createCoupon();
        void save();
        void listAll();
        int updateMaxUsage(string name);
};

#endif