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
    char maritalStatus[100];
    int employeeID[100], i = 0;
    float hoursWorked[100], hourlyPay[100], overtimeHours[100], overtimePay[100], grossPay[100],
    taxRate[100], taxAmount[100], netPay[100];

    ifstream fin("./employee.in");
    while(fin >> employeeID[i] >> hoursWorked[i] >> hourlyPay[i]  >> maritalStatus[i]){

        //Determine Gross Pay based on hours worked and pay rate, calculating
        //overtime if necessary.
        if (hoursWorked[i] > 40){
            overtimeHours[i] = hoursWorked[i] - 40;
            overtimePay[i] = (hourlyPay[i] * 0.5) * overtimeHours[i];
            grossPay[i] = (hoursWorked[i] * hourlyPay[i]) + overtimePay[i];
        }
        else if (hoursWorked[i] <= 40){
            grossPay[i] = hoursWorked[i] * hourlyPay[i];
        }

        //Get base Tax Rate based on gross pay
        if (grossPay[i] > 1000) taxRate[i] = 0.3;
        else if (grossPay[i] > 800) taxRate[i] = 0.2;
        else if (grossPay[i] > 500) taxRate[i] = 0.1;
        else taxRate[i] = 0.0;

        //Modify base tax rate based on marital status:
        //Married (NC), Head of Household (-5%), Single (+5%)
        if ((maritalStatus[i] == 's') || (maritalStatus[i] == 'S')) taxRate[i] += 0.05;
        if ((maritalStatus[i] == 'h') || (maritalStatus[i] == 'H')) taxRate[i] -= 0.05;
        
        //Catch negative tax rates and correct to 0
        if (taxRate[i] < 0) taxRate[i] = 0;

        //Determine Net Pay
        taxAmount[i] = grossPay[i] * taxRate[i];
        netPay[i] = grossPay[i] - taxAmount[i];
        
        i++;

        //Display information to user
        cout << endl;
        cout << "INDEX IS: " << i << endl;
        cout << "YOUR ID IS: " << employeeID[i] << endl;
        cout << "YOUR HOURS WORKED IS: " << hoursWorked[i] << endl;
        cout << "YOUR HOURLY RATE IS: $" << hourlyPay[i] << endl;
        cout << "YOUR GROSS PAY IS: $" << grossPay[i] << endl;
        cout << "YOUR TAX RATE IS: " << taxRate[i] << endl;
        cout << "YOUR TAX AMOUNT IS: $" << taxAmount[i] << endl;
        cout << "YOUR NET PAY IS: $" << netPay[i] << endl;
    }//WHILE
    return 0;
}//MAIN