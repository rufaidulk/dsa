#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
#include "employee.hpp"

using namespace std;

class User
{
    public:
        static const int STATUS_ACTIVE;// = 1;
        static const int STATUS_INACTIVE;// = 2;
        static const int STATUS_NEW_USER;// = 3;
        static const string USER_ADMIN;// = "Admin";
        static const string USER_NORMAL;// = "Normal";

        map<int, string> status_text {
            {STATUS_ACTIVE, "Active"},
            {STATUS_INACTIVE, "Inactive"},
            {STATUS_NEW_USER, "New User"}
        };

        string role;
        string username;
        string password;
        int status;
        string inputPassword;

        void login();
        int validatePassword();
        void showAdminDashboard();
        void showAllUsers();
        void updateUserStatus();
        int userExist(string username);
        void saveUserStatus(int status, string username);
        void listNewUsers();
        void showUserDashboard();

};

#endif