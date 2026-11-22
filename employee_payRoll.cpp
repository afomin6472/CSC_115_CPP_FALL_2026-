#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>

//Variable section
using namespace std;

//Function Prototypes for getters
string getEmployeeName();
int getEmployeeID();
double getHourlyRate();
double getHoursWorked();

//Function Prototypes for setters
void setEmployeeName(string &employeeName);
void setEmployeeID(int &employeeID);
void setHourlyRate(double &hourlyRate);
void setHoursWorked(double &hoursWorked);

// Function Prototypes for Calculation
double getOvertimeHours(double);
double calculateRegularPay(double, double);
double calculateOvertimePay(double, double);
double calculateGrossPay(double, double);

// Function Prototypes for Payroll
void updatePayroll(string &, int &, double &, double &);
void printPayroll(string, int, double, double);

// Function Prototype for menu
void displayMenu();
int main()
{
  string employeeName;
    int employeeID = 0;
    double hourlyRate = 0.0;
    double hoursWorked = 0.0;
    int choice;
    bool payrollEntered = false;

do{
displayMenu();    
 cin >> choice ;
 if (cin.fail())
 {
 cin.clear();
 cin.ignore(10000, '\n');
 choice = 0;
 }
  switch (choice)
{
 case 1:
 updatePayroll(employeeName, employeeID, hourlyRate, hoursWorked);
 payrollEntered = true;
   break;
 
 case 2:
 if (payrollEntered)
 {
 printPayroll(employeeName, employeeID, hourlyRate, hoursWorked);
 }
 else
 {
 cout << "Please update payroll first." << endl;
 }
   break;
 
 case 3:
 cout << "Thank you for using the Employee Payroll System.\nGoodbye! " << endl;
   break;
 
 default:
 cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
    break;
}    
 } while (choice != 3);    
    
return 0;
}

void displayMenu()
{
 cout << "========================" << endl;
 cout << "EMPLOYEE PAYROLL SYSTEM" << endl;
 cout << "========================" << endl;
 cout << "1. Update Payroll" << endl;
 cout << "2. Print Payroll" << endl;
 cout << "3. Exit " << endl;
 cout << "Enter your choice: " ;
}

string getEmployeeName()
{
    string name;
 cout << "Enter employee name: " ;
 getline(cin >> ws, name);
 return name;
}

int getEmployeeID()
{
    int id;
    do
    {
        cout << "Enter employee ID: ";
        cin >> id;

        if (cin.fail())
        {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            id = 0;
        }
        else if (id <= 0)
        {
            cout << "Invalid employee ID. Please enter a value greater than 0." << endl;
        }

    } while (id <= 0);

    return id;
}

double getHourlyRate()
{
    double rate;
    do
    {
    cout << "Enter hourly pay rate: ";
    cin >> rate;    
    if (cin.fail())
        {
        cout << "Invalid input." << endl;
        cin.clear();            cin.ignore(10000, '\n');
            rate = 0;
        }
        else if (rate <= 0)
        {
         cout << "Invalid hourly pay rate. Please enter a value greater than 0." << endl;
        }
    } while (rate <= 0);
    return rate;
}

double getHoursWorked()
{
    double hours;

    do
    {
        cout << "Enter hours worked: ";
        cin >> hours;

        if (cin.fail())
        {
           cout << "Invalid input." << endl;
           cin.clear();
       cin.ignore(10000, '\n');
        hours = -1;
        }
        else if (hours < 0 || hours > 168)
        {
            cout << "Invalid hours worked. Please enter a value between 0 and 168." << endl;
        }

    } while (hours < 0 || hours > 168);

    return hours;
}

void setEmployeeName(string &employeeName)
{
    employeeName = getEmployeeName();
}

void setEmployeeID(int &employeeID)
{
    employeeID = getEmployeeID();
}

void setHourlyRate(double &hourlyRate)
{
    hourlyRate = getHourlyRate();
}

void setHoursWorked(double &hoursWorked)
{
    hoursWorked = getHoursWorked();
}

void updatePayroll(string &employeeName, int &employeeID,
                   double &hourlyRate, double &hoursWorked)
{
    cout << "===========================" << endl;
    cout << "  UPDATE EMPLOYEE PAYROLL" << endl;
    cout << "===========================" << endl;

    setEmployeeName(employeeName);
    setEmployeeID(employeeID);
    setHourlyRate(hourlyRate);
    setHoursWorked(hoursWorked);

    cout << "Payroll information updated successfully." << endl;
}

double getOvertimeHours(double hoursWorked)
{
    if (hoursWorked > 40)
    {
        return hoursWorked - 40;
    }
    else
    {
        return 0;
    }
}

double calculateRegularPay(double hourlyRate, double hoursWorked)
{
    if (hoursWorked > 40)
    {
        return 40 * hourlyRate;
    }
    else
    {
        return hoursWorked * hourlyRate;
    }
}

double calculateOvertimePay(double hourlyRate, double hoursWorked)
{
    double overtimeHours = getOvertimeHours(hoursWorked);
    double overtimeRate = hourlyRate * 1.5;
    return overtimeHours * overtimeRate;
}

double calculateGrossPay(double hourlyRate, double hoursWorked)
{
    double regularPay = calculateRegularPay(hourlyRate, hoursWorked);
    double overtimePay = calculateOvertimePay(hourlyRate, hoursWorked);

    return regularPay + overtimePay;
}

void printPayroll(string employeeName, int employeeID,
                  double hourlyRate, double hoursWorked)
{
    double regularHours;
    double overtimeHours = getOvertimeHours(hoursWorked);
    double regularPay = calculateRegularPay(hourlyRate, hoursWorked);
    double overtimeRate = hourlyRate * 1.5;
    double overtimePay = calculateOvertimePay(hourlyRate, hoursWorked);
    double grossPay = calculateGrossPay(hourlyRate, hoursWorked);

    if (hoursWorked > 40)
    {
        regularHours = 40;
    }
    else
    {
        regularHours = hoursWorked;
    }
    cout << fixed << setprecision(2);
    cout << "========================================" << endl;
    cout << "          EMPLOYEE PAYROLL" << endl;
    cout << "========================================" << endl;

    cout << "Employee Name: " << employeeName << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Hourly Pay Rate: $" << hourlyRate << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Regular Hours: " << regularHours << endl;
    cout << "Overtime Hours: " << overtimeHours << endl;
    cout << "Regular Pay: $" << regularPay << endl;
    cout << "Overtime Rate: $" << overtimeRate << endl;
    cout << "Overtime Pay: $" << overtimePay << endl;
    cout << "----------------------------------------" << endl;
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "========================================" << endl;
}