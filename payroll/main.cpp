#include <bits/stdc++.h>
#include "user.hpp"

using namespace std;

int main()
{
    char choice;
    User user;

    do 
    {
        cout<<"1.Admin Login\n2.User Login\n"<<endl;
        cout<<"Enter 'q' for exit\n"<<endl;
        cin>>choice;

        switch (choice)
        {
            case '1':
                user.role = "Admin";
                user.login();
                break;
            case '2':
                user.role = "Normal";
                user.login();
                break;
            case 'q':
                break;
        }

    } while (choice != 'q');
}