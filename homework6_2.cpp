#include <iostream>
using namespace std;

class Employee 
{
private:
    string Name;
    unsigned short Age;
    unsigned short YearsOfService;
    unsigned int Salary;
public:
    Employee(string AName, unsigned short AAge, unsigned short AYearsOfService, unsigned int ASalary);
    ~Employee();
    unsigned short GetAge() {return Age;};
    void SetAge(unsigned short AValue) {Age=AValue;};
    unsigned short GetYearsOfService() {return YearsOfService;};
    void SetYearsOfService(unsigned short AValue) {YearsOfService=AValue;};
    unsigned int GetSalary () {return Salary;};
    void SetSalary (unsigned int AValue) {Salary=AValue;};
    void ShowInfo();
    void ShowSalaryRounded();
};

Employee::Employee(string AName, unsigned short AAge, unsigned short AYearsOfService, unsigned int ASalary)
{
    Name=AName;
    Age=AAge;
    YearsOfService=AYearsOfService;
    Salary=ASalary;
}

 Employee::~Employee(){};

void Employee::ShowSalaryRounded()
{
    cout <<"Rounded salary of "<< Name << " is " << 10*((Salary+5)/10) << " USD \n";
}


void Employee::ShowInfo()
{
    cout << Name <<"\t\t"<< Age <<"\t" <<YearsOfService <<"\t" << Salary <<" USD\n";
}

int main()
{
    Employee Emp1=Employee("Vasya", 25,2, 1814);
    Employee Emp2=Employee("Petya", 30,8, 2999);
    cout << "Employee list\n";
    cout << "Name\t\tAge\tYears\tSalary\n";    
    Emp1.ShowInfo();
    Emp2.ShowInfo();
    Emp1.ShowSalaryRounded();
    Emp2.ShowSalaryRounded();
 
    return 0;
}