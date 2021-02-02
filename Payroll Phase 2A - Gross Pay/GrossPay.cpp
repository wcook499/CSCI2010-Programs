#include <iostream>
using namespace std;

int main(){
    int employeeID;
    float hoursWorked, hourlyPay, grossPay;
    cout << "ENTER EMPLOYEE ID: ";
    cin >> employeeID;
    cout << "ENTER HOURS WORKED: ";
    cin >> hoursWorked;
    cout << "ENTER HOURLY PAY: $";
    cin >> hourlyPay;
    grossPay = hoursWorked * hourlyPay;
    cout << "\n";
    cout << "YOUR ID IS: " << employeeID << "\n";
    cout << "YOUR HOURS WORKED IS: " << hoursWorked << "\n";
    cout << "YOUR HOURLY RATE IS: $" << hourlyPay << "\n";
    cout << "YOUR GROSS PAY IS: $" << grossPay << "\n";
    return 0;
}