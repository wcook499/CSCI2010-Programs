/*
WILLIAM COOK
2/14/21

This program opens a file and reads employee information, then outputs the same
information as the Phase 2B Net Pay program.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int employeeID, counter, inputQuantity;
    float hoursWorked, hourlyPay, grossPay, taxRate, taxAmount, netPay;

    ifstream fin("./employee.in");
    while(fin >> employeeID >> hoursWorked >> hourlyPay){
        grossPay = hoursWorked * hourlyPay;

        if (grossPay > 1000) taxRate = 0.3;
        else if (grossPay > 800) taxRate = 0.2;
        else if (grossPay > 500) taxRate = 0.1;
        else taxRate = 0.0;

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