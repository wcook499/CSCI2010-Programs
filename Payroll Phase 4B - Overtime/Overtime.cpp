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
    char maritalStatus;
    int employeeID, counter, inputQuantity;
    float hoursWorked, hourlyPay, overtimeHours, overtimePay, grossPay, taxRate, taxAmount, 
        netPay;

    ifstream fin("./employee.in");
    while(fin >> employeeID >> hoursWorked >> hourlyPay  >> maritalStatus){

        //Determine Gross Pay based on hours worked and pay rate
        //grossPay = hoursWorked * hourlyPay;

        if (hoursWorked > 40){
            overtimeHours = hoursWorked - 40;
            overtimePay = (hourlyPay * 0.5) * overtimeHours;
            grossPay = (40 * hourlyPay) + overtimeHours;
        }
        else if (hoursWorked <= 40){
            grossPay = hoursWorked * hourlyPay;
        }
        
        //Get base Tax Rate based on gross pay
        if (grossPay > 1000) taxRate = 0.3;
        else if (grossPay > 800) taxRate = 0.2;
        else if (grossPay > 500) taxRate = 0.1;
        else taxRate = 0.0;

        //Modify base tax rate based on marital status:
        //Married (NC), Head of Household (-5%), Single (+5%)
        if ((maritalStatus == 's') || (maritalStatus == 'S')) taxRate += 0.05;
        if ((maritalStatus == 'h') || (maritalStatus == 'H')) taxRate -= 0.05;
        
        //Determine Net Pay
        taxAmount = grossPay * taxRate;
        netPay = grossPay - taxAmount;
        
        //Display information to user
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