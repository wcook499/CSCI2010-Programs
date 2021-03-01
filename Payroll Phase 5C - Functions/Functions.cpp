/*

WILLIAM COOK
2/28/21

Payroll Phase 5C - Functions

*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//Declare variables
const int   arrayLen = 100;
char        maritalStatus[arrayLen];
string      firstName[arrayLen],
            lastName[arrayLen];
int         i = 0,
            employeeID[arrayLen];
float       hoursWorked[arrayLen],
            hourlyPay[arrayLen],
            overtimeHours[arrayLen],
            overtimePay[arrayLen],
            grossPay[arrayLen],
            taxRate[arrayLen],
            taxAmount[arrayLen],
            netPay[arrayLen],
            regularPay[arrayLen];


//int function(int);
void        createArrays(int),
            getGrossPay(),
            getBaseTaxRate(),
            modifyTaxRate(),
            getNetPay(),
            displayAllData();

int main(){

    createArrays(arrayLen);
    getGrossPay();
    getBaseTaxRate();
    modifyTaxRate();
    getNetPay();
    displayAllData();

return 0;
}//MAIN

void createArrays(int arrayLen){
    int i;
    //Read all data into arrays
    ifstream fin("./employee.in");
    for (i = 0; i < arrayLen; i++){
        fin >> firstName[i] >> lastName[i] >> maritalStatus[i] >> employeeID[i] >> hoursWorked[i] >> hourlyPay[i];
    }//for
return;
}

void getGrossPay(){
    //Determine Gross Pay based on hours worked and pay rate, calculating
    //overtime if necessary.
    int i = 0;

    for (i = 0; i < arrayLen; i++){

        if (hoursWorked[i] > 40){
            overtimeHours[i] = hoursWorked[i] - 40;
            overtimePay[i] = (hourlyPay[i] * 0.5) * overtimeHours[i];
            regularPay[i] = hoursWorked[i] * hourlyPay[i];
            grossPay[i] = regularPay[i] + overtimePay[i];
        }//if

        else if (hoursWorked[i] <= 40){
            grossPay[i] = hoursWorked[i] * hourlyPay[i];
        }//else if
    }//for
return;
}

void getBaseTaxRate(){
    //Get base Tax Rate based on gross pay
    for (i = 0; i < arrayLen; i++){
        if (grossPay[i] > 1000) taxRate[i] = 0.3;
        else if (grossPay[i] > 800) taxRate[i] = 0.2;
        else if (grossPay[i] > 500) taxRate[i] = 0.1;
        else taxRate[i] = 0.0;
    }//for
return;
}

void modifyTaxRate(){
    //Modify base tax rate based on marital status:
    //Married (NC), Head of Household (-5%), Single (+5%)
    for (i = 0; i < arrayLen; i++){
        if ((maritalStatus[i] == 's') || (maritalStatus[i] == 'S')) taxRate[i] += 0.05;
        if ((maritalStatus[i] == 'h') || (maritalStatus[i] == 'H')) taxRate[i] -= 0.05;
        
        //Catch negative tax rates and correct to 0
        if (taxRate[i] < 0) taxRate[i] = 0;
    }//for
return;
}

void getNetPay(){
    //Determine Net Pay
    for (i = 0; i < arrayLen; i++){
        taxAmount[i] = grossPay[i] * taxRate[i];
        netPay[i] = grossPay[i] - taxAmount[i];
    }//for
return;
}

void displayAllData(){
    //Display information to user
    cout << "DR. EBRAHIMI'S PAYROLL INSTITUTE" << endl;

    cout << endl;

    cout << setw(10) << "FIRST NAME" << setw(10) << "LAST NAME" << setw(10) << "STAT" <<  setw(10) << "SSN"
         << setw(10) << "HW" << setw(10) << "HR" << setw(10) << "OTH" << setw(10) << "REGP"
         << setw(10) << "GROSS" << setw(10) << "TAX" << setw(10) << "NET" << endl;

    cout << string(110, '=') << endl;

    for (i = 0; i < arrayLen; i++){
        if( firstName[i] != "" && lastName[i] != ""){
            cout << setw(10) << firstName[i] << setw(10) << lastName[i] << setw(10) << maritalStatus[i] << setw(10)
                 << employeeID[i] << setw(10) << hoursWorked[i] << setw(10) << hourlyPay[i] << setw(10)
                << overtimeHours[i] << setw(10) << regularPay[i] << setw(10) << grossPay[i]
                << setw(10) << taxAmount[i] << setw(10) << netPay[i] << endl;
        }//if
    }//for
}