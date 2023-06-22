#include <iostream>
using namespace std;
class Employee
{
protected:
    int emp_id;
    string name;
    double salary;
public:
    Employee(int e, string n, double s){
        emp_id = e;
        name = n;
        salary = s;
    }
    virtual float get_total_salary() = 0;
    virtual void print()
    {
        cout << "Emp name is: " << name << "\n" << "Emp ID is: " << emp_id << "\n" << "Emp salary is: " << salary << "\n"; 
    }
};


class Engineer : public Employee
{
private:
    float overtime_hour_rate;
    int experience, overtime_hour;
    string specilty;
public:
    Engineer(int e, string n, double s, float otr, int exp, int oh, string sp) : Employee(e, n, s)
    {
        overtime_hour = oh;
        overtime_hour_rate = otr;
        specilty = sp;
        experience = exp;
    }
    void set_overtime_hours(int h)
    {
        overtime_hour = h;
    }
    void set_overtime_hour_rate(int hr)
    {
        overtime_hour_rate = hr;
    }
    void print()
    {
    Employee::print();
    cout << "Over time hour is:" << overtime_hour << " per week\n" << "Over time hour rate = " << overtime_hour_rate << "\n"
    << "Eng specility is: " << specilty << "\n" << "Eng exp is: " << experience <<"\n";
    }
    float get_total_salary()
    {
    return salary + (overtime_hour * overtime_hour_rate);
    }
};

class Sales : public Employee
{
private:
    float gross_sale, commision_rate;
public:
    Sales(int e, string n, double s,float gs, float cr) : Employee(e, n, s)
    {
        gross_sale = gs;
        commision_rate = cr;
    }
    float get_total_salary()
    {
        return salary + (gross_sale * commision_rate);
    }
    void print()
    {
        Employee :: print();
        cout << "Gross sale is: " << gross_sale << "\n" << "Commision rate is: " << commision_rate << "\n";
    }
};
int main()
{
    Employee* emp_ptr;
    Engineer person(3040, "Yousef", 15000,10, 5, 20, "AI");
    Sales per(34, "Name", 10000, 20000, 20);

    emp_ptr = &person;
    emp_ptr -> get_total_salary();
    emp_ptr -> print();

    emp_ptr = &per;
    emp_ptr -> get_total_salary();
    emp_ptr -> print();
return 0;
}