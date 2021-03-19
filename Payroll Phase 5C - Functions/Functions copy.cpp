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


//Function Prototypes
int         readAllData(string[], string[], char[], int[], float[], float[],
                       const int);

void        getOvertimeHours(float[], float[], int),
            getOvertimePay(float[], float[], float[], int),
            getRegularPay(float[], float[], float[], int),
            getGrossPay(float[], float[], float[], int),
            getBaseTaxRate(float[], float[], int),
            modifyTaxRate(char[], float[], int),
            getTaxAmount(float[], float[], float[], int),
            getNetPay(float[], float[], float[], int),
            printHeader(),
            printAllData(string[], string[], char[], int[], float[], float[],
                         float[], float[], float[], float[], float[], float[], int);


int main(){

    const int   maxSize = 100;
    char        maritalStatus[maxSize];
    string      firstName[maxSize],
                lastName[maxSize];
    int         n,
                employeeID[maxSize];
    float       hoursWorked[maxSize],
                hourlyPay[maxSize],
                overtimeHours[maxSize],
                overtimePay[maxSize],
                regularPay[maxSize],
                grossPay[maxSize],
                taxRate[maxSize],
                taxAmount[maxSize],
                netPay[maxSize];
                

    n = readAllData(firstName, lastName, maritalStatus, employeeID, hoursWorked,
                    hourlyPay, maxSize);
    getOvertimeHours(hoursWorked, overtimeHours, n);
    getOvertimePay(overtimeHours, hourlyPay, overtimePay, n);
    getRegularPay(hoursWorked, hourlyPay, regularPay, n);
    getGrossPay(regularPay, overtimePay, grossPay, n);
    getBaseTaxRate(grossPay, taxRate, n);
    modifyTaxRate(maritalStatus, taxRate, n);
    getTaxAmount(grossPay, taxRate, taxAmount, n);
    getNetPay(grossPay, taxAmount, netPay, n);
    printHeader();
    printAllData(firstName, lastName, maritalStatus, employeeID, hoursWorked,
                 hourlyPay, overtimeHours, overtimePay, regularPay, grossPay,
                 taxAmount, netPay, n);

return 0;
}//MAIN


int readAllData(string firstName[], string lastName[], char maritalStatus[],
                int employeeID[], float hoursWorked[], float hourlyPay[], int n){
    n = 0;
    //Read all data into arrays
    ifstream fin("employee.in");
    while(fin >> firstName[n] >> lastName[n] >> maritalStatus[n] >> employeeID[n]
          >> hoursWorked[n] >> hourlyPay[n]) n++;
    fin.close();
return n;
}//readAllData


void getOvertimeHours(float hoursWorked[], float overtimeHours[], int n){
    for(int i = 0; i < n; i++){
        if (hoursWorked[i] > 40){
            overtimeHours[i] = hoursWorked[i] - 40;
        }//if
        else if (hoursWorked[i] <= 40){
            overtimeHours[i] = 0;
        }//else if
    }//for
}//getOvertimeHours


void getOvertimePay(float overtimeHours[], float hourlyPay[], float overtimePay[],
                     int n){
    for(int i = 0; i < n; i++){
        overtimePay[i] = 0;
        if (overtimeHours[i] != 0){
            overtimePay[i] = overtimeHours[i] * (hourlyPay[i] * 1.5);
        }//if
    }//for
}//getOvertimePay


void getRegularPay(float hoursWorked[], float hourlyPay[], float regularPay[],
                    int n){
    for(int i = 0; i < n; i++){
        regularPay[i] = hourlyPay[i] * hoursWorked[i];
    }//for
}//getRegularPay


void getGrossPay(float regularPay[], float overtimePay[], float grossPay[], int n){
    for(int i = 0; i < n; i++){
        grossPay[i] = regularPay[i] + overtimePay[i];
    }//for
}//getGrossPay


void getBaseTaxRate(float grossPay[], float taxRate[], int n){
    for(int i = 0; i < n; i++){
        if (grossPay[i] > 1000) taxRate[i] = 0.3;
        else if (grossPay[i] > 800) taxRate[i] = 0.2;
        else if (grossPay[i] > 500) taxRate[i] = 0.2;
        else taxRate[i] = 0;
    }//for
}//getBaseTaxRate


void modifyTaxRate(char maritalStatus[], float taxRate[], int n){
    for (int i = 0; i < n; i++){
        if ((maritalStatus[i] == 's') || (maritalStatus[i] == 'S')) taxRate[i] += 0.05;
        if ((maritalStatus[i] == 'h') || (maritalStatus[i] == 'H')) taxRate[i] -= 0.05;
        
        //Catch negative tax rates and correct to 0
        if (taxRate[i] < 0) taxRate[i] = 0;
    }//for
}//modifyTaxRate


void getTaxAmount(float grossPay[], float taxRate[], float taxAmount[], int n){
    for (int i = 0; i < n; i++){
        taxAmount[i] = grossPay[i] * taxRate[i];
    }//for
}//getTaxAmount


void getNetPay(float grossPay[], float taxAmount[], float netPay[], int n){
    for (int i = 0; i < n; i++){
        //Determine Net Pay
        netPay[i] = grossPay[i] - taxAmount[i];
    }//for
}//getNetPay


void printHeader(){
    cout << "DR. EBRAHIMI'S PAYROLL INSTITUTE" << endl;
    cout << endl;
    cout << setw(10) << "FIRST NAME" << setw(10) << "LAST NAME" << setw(10) << "STAT" <<  setw(10) << "SSN"
         << setw(10) << "HW" << setw(10) << "HR" << setw(10) << "OTH" << setw(10) << "OTP" << setw(10) << "REGP"
         << setw(10) << "GROSS" << setw(10) << "TAX" << setw(10) << "NET" << endl;
    cout << string(120, '=') << endl;
}//printHeader


void printAllData(string firstName[], string lastName[], char maritalStatus[],
                  int employeeID[], float hoursWorked[], float hourlyPay[],
                  float overtimeHours[], float overtimePay[], float regularPay[],
                  float grossPay[], float taxAmount[], float netPay[], int n){
    for (int i = 0; i < n; i++){
        if( firstName[i] != "" && lastName[i] != ""){
            cout << setw(10) << firstName[i] << setw(10) << lastName[i] << setw(10) << maritalStatus[i] << setw(10)
                << employeeID[i] << setw(10) << hoursWorked[i] << setw(10) << hourlyPay[i] << setw(10)
                << overtimeHours[i] <<setw(10) << overtimePay[i] << setw(10) << regularPay[i] << setw(10) << grossPay[i]
                << setw(10) << taxAmount[i] << setw(10) << netPay[i] << endl;
        }//if
    }//for
}//printAllData