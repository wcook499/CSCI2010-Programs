/*
WILLIAM COOK
2/14/21

This program takes a predetermined number of entries from the user and outputs
the same information as the Phase 2B Net Pay program.
*/
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
        cout << endl;
        cout << "YOUR ID IS: " << employeeID << endl;
        cout << "YOUR HOURS WORKED IS: " << hoursWorked << endl;
        cout << "YOUR HOURLY RATE IS: $" << hourlyPay << endl;
        cout << "YOUR GROSS PAY IS: $" << grossPay << endl;
        cout << "YOUR TAX RATE IS: " << taxRate << endl;
        cout << "YOUR TAX AMOUNT IS: $" << taxAmount << endl;
        cout << "YOUR NET PAY IS: $" << netPay << endl;
    }//WHILE
    return 0;
}//MAIN