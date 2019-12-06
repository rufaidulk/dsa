#include "user.hpp"
#include "employee.hpp"

const int User::STATUS_ACTIVE = 1;
const int User::STATUS_INACTIVE = 2;
const int User::STATUS_NEW_USER = 3;
const string User::USER_ADMIN = "Admin";
const string User::USER_NORMAL = "Normal";

void User::login()
{
    cout<<this->role<<" Login\n";
    cout<<"Enter username\n";
    cin>>this->username;
    cout<<"Enter password\n";
    cin>>this->inputPassword;
    
    if (this->validatePassword())
    {
        if (this->role == User::USER_ADMIN)
            this->showAdminDashboard();
        else 
            this->showUserDashboard();

        return;
    }

    cout<<"Invalid credientials\n";
}

int User::validatePassword()
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->role>>this->username>>this->password>>this->status;

        if (file.eof())
            break;

        if (this->password == this->inputPassword)
        {
            if (this->status == User::STATUS_ACTIVE)
            {
                file.close();
                return 1;
            }
            else if (this->status == User::STATUS_NEW_USER)
            {
                cout<<"Your account is not approved yet\n";
                file.close();
                return 0;
            }
        }
    }

    file.close();
    return 0;
}

int User::userExist(string username)
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->role>>this->username>>this->password>>this->status;

        if (file.eof())
            break;

        if (this->username == username)
        {
            file.close();
            return 1;
        }
    }

    file.close();
    return 0;
}

void User::showAdminDashboard()
{
    char choice;

    do 
    {
        cout<<"Admin Dashboard\n";
        cout<<"1.List all users\n2.Update user status\n3.List new users\n";
        cout<<"Enter 'q' for logout\n";
        cin>>choice;

        switch (choice)
        {
            case '1':
                this->showAllUsers();
                break;
            case '2':
                this->updateUserStatus();
                break;
            case '3':
                this->listNewUsers();
                break;
            case 'q':
                break;
        }

    } while (choice != 'q');
    
}

void User::showAllUsers()
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->role>>this->username>>this->password>>this->status;
        
        if (file.eof())
            break;

        cout<<"Username: "<<this->username<<" Status: "<<this->status_text[this->status]<<endl;
    }

    file.close();
}

void User::listNewUsers()
{
    fstream file;
    file.open("user.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->role>>this->username>>this->password>>this->status;
        
        if (file.eof())
            break;

        if (this->status != User::STATUS_NEW_USER)
            continue;
         
        cout<<"Username: "<<this->username<<" Status: "<<this->status_text[this->status]<<endl;
    }

    file.close();
}

void User::updateUserStatus()
{
    int choice;
    string username;
    cout<<"Enter username\n";
    cin>>username;

    if (this->userExist(username))
    {
        while (1)
        {
            cout<<"Enter 1.For Activate\n2.For Inactive\n3.For Block\n";
            cin>>choice;
            if (choice == 1 || choice == 2 || choice == 3)
            {
                this->saveUserStatus(choice, username);
                cout<<"Status updated success\n";
                break;
            }
            cout<<"Invalid input\n";
        }

    }
    
}

void User::saveUserStatus(int status, string username)
{
    fstream file;
    fstream tmpFile;
    file.open("user.txt", ios::app | ios::in);
    tmpFile.open("tmp.txt", ios::app | ios::out);

    while (file)
    {
        file >>this->role>>this->username>>this->password>>this->status;

        if (file.eof())
            break;

        if (this->username == username)
            this->status = status;

        tmpFile <<this->role<<" "<<this->username<<" "<<this->password<<" "<<this->status<<endl;
    }

    tmpFile.close();
    file.close();

    remove("user.txt");
    rename("tmp.txt", "user.txt"); 
}

void User::showUserDashboard()
{
    char choice;
    Employee employee;

    do 
    {
        cout<<"User Dashboard\n";
        cout<<"1. Create employee\n2. View employee\n3. Edit employee\n4.delete employee\n";
        cout<<"5. List all employees\n6.Salary slip\n";
        cout<<"Enter 'q' for logout\n";
        cin>>choice;

        switch (choice)
        {
            case '1':
                employee.create();
                break;
            case '2':
                employee.view();
                break;
            case '3':
                employee.edit();
                break;
            case '4':
                employee.removeEmployee();
                break;
            case '5':
                employee.listAll();
                break;
            case '6':
                employee.salarySlip();
                break;
            case 'q':
                break;
        }

    } while (choice != 'q');
}