#include "employee.hpp"

using namespace std;

void Employee::create()
{
    cout<<"Enter name\n";
    cin>>this->name;
    cout<<"Enter address\n";
    cin>>this->address;
    cout<<"Enter mobile\n";
    cin>>this->mobile;
    cout<<"Enter joining date(dd-mm-yyy)\n";
    cin>>this->date;
    cout<<"Enter designation\n";
    cin>>this->designation;
    
    while (1)
    {
        cout<<"Enter grade like A, B, C, D, E\n";
        cin>>this->grade;

        if (this->grade >= 'A' && this->grade <= 'E')
            break;

        cout<<"Entered grade is wrong\n";
    }

    cout<<"Enter Loan amoutn\n";
    cin>>this->loanAmount;
    cout<<"Enter Salary\n";
    cin>>this->salary;
    cout<<"Enter house allowance\n";
    cin>>this->houseAllowance;
    this->code = rand();
    this->saveToFile();

    cout<<"Employee created\n";
}

void Employee::saveToFile()
{
    fstream file;
    file.open("employee.txt", ios::app | ios::out);
    
    file <<this->code<<" "<<this->name<<" "<<this->address<<" "<<this->mobile<<" "<<this->date<<" "
        <<this->designation<<" "<<this->grade<<" "<<this->loanAmount<<" "<<this->salary<<" "
        <<this->houseAllowance<<endl;

    file.close();
}

void Employee::view()
{
    int code;
    cout<<"Enter employee code\n";
    cin>>code;

    if (this->employeeExist(code))
    {
        this->show(code);
        return;        
    }

    cout<<"Invalid code\n";
}

int Employee::employeeExist(int code)
{
    fstream file;
    file.open("employee.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->code>>this->name>>this->address>>this->mobile>>this->date>>this->designation
            >>this->grade>>this->loanAmount>>this->salary>>this->houseAllowance;

        if (file.eof())
            break;

        if (this->code == code)
        {
            file.close();
            return 1;
        }
    }

    file.close();
    return 0;
}

void Employee::show(int code)
{
    fstream file;
    file.open("employee.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->code>>this->name>>this->address>>this->mobile>>this->date>>this->designation
            >>this->grade>>this->loanAmount>>this->salary>>this->houseAllowance;

        if (file.eof())
            break;

        if (this->code == code)
        {
            cout<<"Employee Code: "<<this->code<<" Name: "<<this->name<<" Address: "<<this->address<<endl;
            cout<<"Mobile: "<<this->mobile<<" Date: "<<this->date<<" Designation: "<<this->designation<<endl;
            cout<<"Grade: "<<this->grade<<" Loan: "<<this->loanAmount<<" salary: "<<this->salary<<endl;
            cout<<" House Allowance: "<<this->houseAllowance<<endl;

            break;
        }
    }

    file.close();
}

void Employee::edit()
{
    int code;
    cout<<"Enter employee code\n";
    cin>>code;

    if (this->employeeExist(code))
    {   
        this->getNewData(code);
        return;
    }

    cout<<"invalid code\n";
}

void Employee::removeEmployee()
{
    int code;
    cout<<"Enter employee code\n";
    cin>>code;

    if (this->employeeExist(code))
    {   
        this->deleteData(code);
        cout<<"deleted\n";
        return;
    }

    cout<<"invalid code\n";
}

void Employee::getNewData(int code)
{
    string name, address, mobile, date, designation;
    char grade;
    int loanAmount, salary, houseAllowance;
    
    cout<<"Enter name\n";
    cin>>name;
    cout<<"Enter address\n";
    cin>>address;
    cout<<"Enter mobile\n";
    cin>>mobile;
    cout<<"Enter joining date(dd-mm-yyy)\n";
    cin>>date;
    cout<<"Enter designation\n";
    cin>>designation;
    
    while (1)
    {
        cout<<"Enter grade like A, B, C, D, E\n";
        cin>>grade;

        if (grade >= 'A' && grade <= 'E')
            break;

        cout<<"Entered grade is wrong\n";
    }

    cout<<"Enter Loan amoutn\n";
    cin>>loanAmount;
    cout<<"Enter Salary\n";
    cin>>salary;
    cout<<"Enter house allowance\n";
    cin>>houseAllowance;

    this->update(code, name, address, mobile, date, designation, grade, loanAmount, salary, houseAllowance);

    cout<<"Employee updated\n";
}

void Employee::update(
    int code, 
    string name, 
    string address, 
    string mobile, 
    string date, 
    string designation, 
    char grade, 
    int loanAmount, 
    int salary, 
    int houseAllowance)
{
    fstream file;
    fstream tmpFile;
    file.open("employee.txt", ios::app | ios::in);
    tmpFile.open("employee.txt", ios::app | ios::out);

    while (file)
    {
        file >>this->code>>this->name>>this->address>>this->mobile>>this->date>>this->designation
            >>this->grade>>this->loanAmount>>this->salary>>this->houseAllowance;

        if (file.eof())
            break;

        if (this->code == code)
        {
            tmpFile <<this->code<<" "<<name<<" "<<address<<" "<<mobile<<" "
                <<date<<" "<<designation<<" "<<grade<<" "<<loanAmount<<" "
                <<salary<<" "<<houseAllowance<<endl;

            continue;
        }

        tmpFile <<this->code<<" "<<this->name<<" "<<this->address<<" "<<this->mobile<<" "<<this->date<<" "
        <<this->designation<<" "<<this->grade<<" "<<this->loanAmount<<" "<<this->salary<<" "
        <<this->houseAllowance<<endl;
    }

    file.close();
    tmpFile.close();

    remove("employee.txt");
    rename("tmp.txt", "employee.txt");
}

void Employee::deleteData(int code)
{
    fstream file;
    fstream tmpFile;
    file.open("employee.txt", ios::app | ios::in);
    tmpFile.open("employee.txt", ios::app | ios::out);

    while (file)
    {
        file >>this->code>>this->name>>this->address>>this->mobile>>this->date>>this->designation
            >>this->grade>>this->loanAmount>>this->salary>>this->houseAllowance;

        if (file.eof())
            break;

        if (this->code == code)
            continue;

        tmpFile <<this->code<<" "<<this->name<<" "<<this->address<<" "<<this->mobile<<" "<<this->date<<" "
        <<this->designation<<" "<<this->grade<<" "<<this->loanAmount<<" "<<this->salary<<" "
        <<this->houseAllowance<<endl;
    }

    file.close();
    tmpFile.close();

    remove("employee.txt");
    rename("tmp.txt", "employee.txt");
}

void Employee::listAll()
{
    fstream file;
    file.open("employee.txt", ios::app | ios::in);
    int i = 1;
    while (file)
    {
        file >>this->code>>this->name>>this->address>>this->mobile>>this->date>>this->designation
            >>this->grade>>this->loanAmount>>this->salary>>this->houseAllowance;

        if (file.eof())
            break;

        cout<<"Employee :"<<i++<<endl;
        cout<<"Employee Code: "<<this->code<<" Name: "<<this->name<<" Address: "<<this->address<<endl;
        cout<<"Mobile: "<<this->mobile<<" Date: "<<this->date<<" Designation: "<<this->designation<<endl;
        cout<<"Grade: "<<this->grade<<" Loan: "<<this->loanAmount<<" salary: "<<this->salary<<endl;
        cout<<" House Allowance: "<<this->houseAllowance<<endl;

    }

    file.close();
}

void Employee::salarySlip()
{
    int code;
    cout<<"Enter employee code\n";
    cin>>code;

    string date;
    if (this->employeeExist(code))
    {   
        cout<<"Enter date(dd-mm-yyyy)\n";
        cin>>date;
        this->viewSlip(code, date);
        return;
    }

    cout<<"invalid code\n";
}

void Employee::viewSlip(int code, string date)
{
    fstream file;
    file.open("employee.txt", ios::app | ios::in);

    while (file)
    {
        file >>this->code>>this->name>>this->address>>this->mobile>>this->date>>this->designation
            >>this->grade>>this->loanAmount>>this->salary>>this->houseAllowance;

        if (file.eof())
            break;

        if (this->code == code && this->date == date)
        {
            cout<<"Employee Code: "<<this->code<<" Name: "<<this->name<<" salary: "<<this->salary<<endl;
            break;
        }
    }

    file.close();
}