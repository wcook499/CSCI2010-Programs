#include <iostream>
using namespace std;

int main(){
    int employeeID, counter, inputQuantity;
    float hoursWorked, hourlyPay, grossPay, taxRate, taxAmount, netPay;
    taxRate = 0.10;
    counter = 0;

    cout << "How many employees would you like to enter? ";
    cin >> inputQuantity;

    while(counter < inputQuantity){
        counter++; // increase counter by 1
        cout << "ENTER EMPLOYEE ID: ";
        cin >> employeeID;
        cout << "ENTER HOURS WORKED: ";
        cin >> hoursWorked;
        cout << "ENTER HOURLY PAY: $";
        cin >> hourlyPay;
        grossPay = hoursWorked * hourlyPay;
        taxAmount = grossPay * taxRate;
        netPay = grossPay - taxAmount;
        cout << "\n";
        cout << "YOUR ID IS: " << employeeID << "\n";
        cout << "YOUR HOURS WORKED IS: " << hoursWorked << "\n";
        cout << "YOUR HOURLY RATE IS: $" << hourlyPay << "\n";
        cout << "YOUR GROSS PAY IS: $" << grossPay << "\n";
        cout << "YOUR TAX RATE IS: " << taxRate << "\n";
        cout << "YOUR TAX AMOUNT IS: $" << taxAmount << "\n";
        cout << "YOUR NET PAY IS: $" << netPay << "\n";
    }//WHILE
    return 0;
}//MAIN