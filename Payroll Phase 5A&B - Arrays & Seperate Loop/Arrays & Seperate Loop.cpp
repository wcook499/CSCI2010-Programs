/*

WILLIAM COOK
2/28/21

Payroll Phase 5A & B - Arrays & Seperate Loop

*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){

    //First, determine number of lines in "employee.in" file.  We will use this to determine the correct size of the
    //arrays.
    ifstream myFile;
    string line;
    int numLines;
    myFile.open("employee.in");
    for(numLines = 0; getline(myFile,line); numLines++);


    //Declare variables
    const int arrayLen = numLines;
    char maritalStatus[arrayLen];
    string firstName[arrayLen], lastName[arrayLen];
    int employeeID[arrayLen], i = 0;
    float hoursWorked[arrayLen], hourlyPay[arrayLen], overtimeHours[arrayLen], overtimePay[arrayLen], grossPay[arrayLen],
    taxRate[arrayLen], taxAmount[arrayLen], netPay[arrayLen], regularPay[arrayLen];


    //Read all data into arrays
    ifstream fin("./employee.in");
    for (i = 0; i < arrayLen; i++){
        fin >> firstName[i] >> lastName[i] >> maritalStatus[i] >> employeeID[i] >> hoursWorked[i] >> hourlyPay[i];
    }//for


    //Determine Gross Pay based on hours worked and pay rate, calculating
    //overtime if necessary.
    for (i = 0; i < arrayLen; i++){

        if (hoursWorked[i] > 40){
            overtimeHours[i] = hoursWorked[i] - 40;
            overtimePay[i] = (hourlyPay[i] * 1.5) * overtimeHours[i];
            regularPay[i] = hoursWorked[i] * hourlyPay[i];
            grossPay[i] = regularPay[i] + overtimePay[i];
        }//if

        else if (hoursWorked[i] <= 40){
            grossPay[i] = hoursWorked[i] * hourlyPay[i];
        }//else if
    }//for


    //Get base Tax Rate based on gross pay
    for (i = 0; i < arrayLen; i++){
        if (grossPay[i] > 1000) taxRate[i] = 0.3;
        else if (grossPay[i] > 800) taxRate[i] = 0.2;
        else if (grossPay[i] > 500) taxRate[i] = 0.1;
        else taxRate[i] = 0.0;
    }//for


    //Modify base tax rate based on marital status:
    //Married (NC), Head of Household (-5%), Single (+5%)
    for (i = 0; i < arrayLen; i++){
        if ((maritalStatus[i] == 's') || (maritalStatus[i] == 'S')) taxRate[i] += 0.05;
        if ((maritalStatus[i] == 'h') || (maritalStatus[i] == 'H')) taxRate[i] -= 0.05;
    

        //Catch negative tax rates and correct to 0
        if (taxRate[i] < 0) taxRate[i] = 0;
    }//for


    //Determine Net Pay
    for (i = 0; i < arrayLen; i++){
        taxAmount[i] = grossPay[i] * taxRate[i];
        netPay[i] = grossPay[i] - taxAmount[i];
    }//for


    //Display information to user
    cout << "DR. EBRAHIMI'S PAYROLL INSTITUTE" << endl;

    cout << endl;

    cout << setw(10) << "FIRST NAME" << setw(10) << "LAST NAME" << setw(10) << "STAT" <<  setw(10) << "SSN"
         << setw(10) << "HW" << setw(10) << "HR" << setw(10) << "OTH" << setw(10) << "OTP" << setw(10) << "REGP"
         << setw(10) << "GROSS" << setw(10) << "TAX" << setw(10) << "NET" << endl;

    cout << string(120, '=') << endl;

    for (i = 0; i < arrayLen; i++){
        cout << setw(10) << firstName[i] << setw(10) << lastName[i] << setw(10) << maritalStatus[i] << setw(10)
             << employeeID[i] << setw(10) << hoursWorked[i] << setw(10) << hourlyPay[i] << setw(10)
             << overtimeHours[i] << setw(10) << overtimePay[i] << setw(10) << regularPay[i] << setw(10) << grossPay[i] << setw(10)
             << taxAmount[i] << setw(10) << netPay[i] << endl;
    }//for
return 0;
}//MAIN
