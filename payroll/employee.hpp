#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <bits/stdc++.h>

using namespace std;

class Employee
{
    public:
        int code;
        string name;
        string address;
        string mobile;
        string date;//dd-mm-yyyy format
        string designation;
        char grade;
        int loanAmount;
        int salary;
        int houseAllowance;

        void create();
        void saveToFile();
        void view();
        int employeeExist(int code);
        void show(int code);
        void edit();
        void getNewData(int code);
        void update(int code, string name, string address, string mobile, string date, string designation, 
            char grade, int loanAmount, int salary, int houseAllowance);
        void removeEmployee();
        void deleteData(int code);
        void listAll();
        void salarySlip();
        void viewSlip(int code, string date);

};

#endif