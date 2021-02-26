/*
WILLIAM COOK
2/14/21

Payroll Phase 5A - Arrays
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
    for(numLines = 0; std::getline(myFile,line); numLines++);


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
            overtimePay[i] = (hourlyPay[i] * 0.5) * overtimeHours[i];
            regularPay[i] = hoursWorked[i] * hourlyPay[i];
            grossPay[i] = regularPay[i] + overtimePay[i];
        }//if
        else if (hoursWorked[i] <= 40){
            grossPay[i] = hoursWorked[i] * hourlyPay[i];
        }//else if
    }//for


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

    //Display information to user
    cout << "DR. EBRAHIMI'S PAYROLL INSTITUTE" << endl;
    cout << endl;
    cout << setw(15) << "FIRST NAME" << setw(15) << "LAST NAME" << setw(15) << "STAT" <<  setw(15) << "SSN"
         << setw(15) << "HW" << setw(15) << "HR" << setw(15) << "OTH" << setw(15) << "REGP"
         << setw(15) << "GROSS" << setw(15) << "TAX" << setw(15) << "NET" << endl;
    cout << string(165, '=') << endl;
    for (i = 0; i < arrayLen; i++){
        cout << setw(15) << firstName[i] << setw(15) << lastName[i] << setw(15) << maritalStatus[i] << setw(15)
             << employeeID[i] << setw(15) << hoursWorked[i] << setw(15) << hourlyPay[i] << setw(15)
             << overtimeHours[i] << setw(15) << regularPay[i] << setw(15) << grossPay[i] << setw(15)
             << taxAmount[i] << setw(15) << netPay[i] << endl;
    }
}//MAIN















/*


/*



        

        
        //Display information to user
        cout << "DR. EBRAHIMI'S PAYROLL INSTITUTE" << endl;
        cout << endl;
        cout << "FIRST NAME" << setw(15) << "LAST NAME" << setw(15) << "STAT" <<  setw(15) << "SSN"
            << setw(15) << "HW" << setw(15) << "HR" << setw(15) << "OTH" << setw(15) << "REGP"
            << setw(15) << "GROSS" << setw(15) << "TAX" << setw(15) << "NET" << endl;


        i++
        /*
        cout << "YOUR ID IS: " << employeeID[i] << endl;
        cout << "YOUR HOURS WORKED IS: " << hoursWorked[i] << endl;
        cout << "YOUR HOURLY RATE IS: $" << hourlyPay[i] << endl;
        cout << "YOUR GROSS PAY IS: $" << grossPay[i] << endl;
        cout << "YOUR TAX RATE IS: " << taxRate[i] << endl;
        cout << "YOUR TAX AMOUNT IS: $" << taxAmount[i] << endl;
        cout << "YOUR NET PAY IS: $" << netPay[i] << endl;
        i++;
        }//WHILE
    }//for
    return 0;
}//MAIN
*/