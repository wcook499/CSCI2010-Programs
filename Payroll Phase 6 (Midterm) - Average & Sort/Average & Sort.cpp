/*

WILLIAM COOK
2/28/21

Payroll Phase 6 (Midterm)
Net Pay Average
Regular Sort
Pointer Sort

Program 1- netpay average
Calculate the average of all employee net pays (salary). Display the 
computations and average of at least 5 employees. 

 
Program 2 - sort netpay (regular sort- exchange or selection)
Sort the net pays (salary). For now, display only the net pays before sorting 
and after sorting. 

Program 3 - Sort the netpay by the pointers
Sort the net pays (salary) using an array of pointers (do not change the data 
in the original array). For now, display only the net pays before sorting Sort
the net pays (salary) using an array of pointers (do not change the data in the
original array). For now, display only the net pays before sorting and after 
sorting.  

*/


#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;


//Function Prototypes
int         readAllData(string[], string[], char[], int[], float[], float[],
                       const int);

//swap function used for sorting netPays
int         arraySwap(float[], int, int),
            pointerSwap(float[], int, int);

//functions that involve printing basic information
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

//function that creates space between different parts of the program output
void        makeSpace();

//functions that involve calculating and displaying net pay average
float       getNetPayAverage(float[], int);
void        printNPAHeader(),
            printNPAData(float, int);

//sorting functions
void        exchangeSort(float[], int),
            pointerSort(float[], int);

//print netPay & sorted arrays
void        printNetPaySortHeader(),
            printUnsortedNetPays(float[], int);


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
                netPay[maxSize],
                netPayExchangeSort[maxSize], //copy of netPay array, to be modified by exchangeSort()
                netPayPointerSort[maxSize]; //copy of netPay array, to show pointerSort() does not modify origional variable
                
    //read all data into arrays
    n = readAllData(firstName, lastName, maritalStatus, employeeID, hoursWorked,
                    hourlyPay, maxSize);

    //perform calculations on data
    getOvertimeHours(hoursWorked, overtimeHours, n);
    getOvertimePay(overtimeHours, hourlyPay, overtimePay, n);
    getRegularPay(hoursWorked, hourlyPay, regularPay, n);
    getGrossPay(regularPay, overtimePay, grossPay, n);
    getBaseTaxRate(grossPay, taxRate, n);
    modifyTaxRate(maritalStatus, taxRate, n);
    getTaxAmount(grossPay, taxRate, taxAmount, n);
    getNetPay(grossPay, taxAmount, netPay, n);
    memmove(netPayExchangeSort, netPay, sizeof(netPayExchangeSort));
    memmove(netPayPointerSort, netPay, sizeof(netPayPointerSort));

    //print headers and data
    printHeader();
    printAllData(firstName, lastName, maritalStatus, employeeID, hoursWorked,
                 hourlyPay, overtimeHours, overtimePay, regularPay, grossPay,
                 taxAmount, netPay, n);

    //calculate net pay average
    //netPayAverage = getNetPayAverage(netPay, netPayAverage, n);

    //make space
    makeSpace();

    //display net pay average headers and data
    printNPAHeader();
    printNPAData(getNetPayAverage(netPay, n), n);

    //make space
    makeSpace();

    //print unsorted net pays
    printNetPaySortHeader();
    printUnsortedNetPays(netPay, n);
    makeSpace();
    exchangeSort(netPayExchangeSort, n);
    makeSpace();
    pointerSort(netPayPointerSort, n);

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

    cout << "              ██████╗ ██████╗        ███████╗██████╗ ██████╗  █████╗ ██╗  ██╗██╗███╗   ███╗██╗███████╗" << endl;
    cout << "              ██╔══██╗██╔══██╗       ██╔════╝██╔══██╗██╔══██╗██╔══██╗██║  ██║██║████╗ ████║██║██╔════╝" << endl;
    cout << "              ██║  ██║██████╔╝       █████╗  ██████╔╝██████╔╝███████║███████║██║██╔████╔██║██║███████╗" << endl;
    cout << "              ██║  ██║██╔══██╗       ██╔══╝  ██╔══██╗██╔══██╗██╔══██║██╔══██║██║██║╚██╔╝██║██║╚════██║ PAYROLL" << endl;
    cout << "              ██████╔╝██║  ██║██╗    ███████╗██████╔╝██║  ██║██║  ██║██║  ██║██║██║ ╚═╝ ██║██║███████║ INSTITUTE" << endl;
    cout << "              ╚═════╝ ╚═╝  ╚═╝╚═╝    ╚══════╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝     ╚═╝╚═╝╚══════╝" << endl;
    cout << endl;
    cout << setw(10) << "FIRST NAME" << setw(10) << "LAST NAME" << setw(10)
         << "STAT" <<  setw(10) << "SSN" << setw(10) << "HW" << setw(10) << "HR"
         << setw(10) << "OTH" << setw(10) << "OTP" << setw(10) << "REGP"
         << setw(10) << "GROSS" << setw(10) << "TAX" << setw(10) << "NET" << endl;
    cout << string(120, '=') << endl;
}//printHeader


void printAllData(string firstName[], string lastName[], char maritalStatus[],
                  int employeeID[], float hoursWorked[], float hourlyPay[],
                  float overtimeHours[], float overtimePay[], float regularPay[],
                  float grossPay[], float taxAmount[], float netPay[], int n){
    for (int i = 0; i < n; i++){
        if( firstName[i] != "" && lastName[i] != ""){
            cout << fixed << setprecision(2) << setw(10) << firstName[i]
            << setw(10) << lastName[i] << setw(10) << maritalStatus[i] << setw(10)
            << employeeID[i] << setw(10) << hoursWorked[i] << setw(10)
            << hourlyPay[i] << setw(10) << overtimeHours[i] <<setw(10)
            << overtimePay[i] << setw(10) << regularPay[i] << setw(10)
            << grossPay[i] << setw(10) << taxAmount[i]  << setw(10) << netPay[i]
            << endl;
        }//if
    }//for
}//printAllData


void makeSpace(){
    cout << endl;
    cout << endl;
}//makeSpace

//---------------------------------------------------------------------------//
//         MODULE 4 MIDTERM PART 1 - NET PAY AVERAGE FUNCTIONS               //
//---------------------------------------------------------------------------//
float getNetPayAverage(float netPay[], int n){
    float netPayAverage = 0;
    for (int i = 0; i < n; i++){
        netPayAverage += netPay[i];
    }//for
    netPayAverage = netPayAverage / n;
return netPayAverage;
}//getNetPayAverage


void printNPAHeader(){
    cout << "NET PAY AVERAGE" << endl;
    cout << string(120, '=') << endl;
}//printNPAHeader


void printNPAData(float netPayAverage, int n){
    cout << "Number of Employees:" << setw(10) << n << endl;
    cout << "    Net Pay Average:" << setw(10) << netPayAverage << endl;
}//printNPAData


//---------------------------------------------------------------------------//
//       MODULE 4 MIDTERM PART 2 - REGULAR (EXCHANGE) SWAP FUNCITONS         //
//---------------------------------------------------------------------------//
int arraySwap(float slot[], int i, int j){
    int temp;
    temp = slot[i];
    slot[i] = slot[j];
    slot[j] = temp;
    return 0;
}//swap


void exchangeSort(float netPay[], int n){
    cout << "Exchange Sort Before: ";

    for (int i = 0; i < n; i++){
        cout << netPay[i] << " ";
    }//for

    cout << endl;

    for (int pass = 1; pass <= n; pass++){
        for(int scan = 0; scan < n; scan++){
            if (netPay[scan] > netPay[scan+1]) arraySwap(netPay, scan, scan+1);
        }//for
    }//for

    cout << "Exchange Sort After:  ";
    
    for (int i = 1; i < n+1; i++){      //ISSUE - all of the data in the array shifted +1 after the exchange sort
        cout << netPay[i] << " ";       //had to set i = 1 and compare i < n+1 to compensate
    }//for

    cout << endl;
}//exchangeSort


//---------------------------------------------------------------------------//
//           MODULE 4 MIDTERM PART 3 - POINTER SWAP FUNCITONS                //
//---------------------------------------------------------------------------//

int pointerSwap(float slot[], int i, int j){
    int temp;
    temp = slot[i];
    slot[i] = slot[j];
    slot[j] = temp;
    return 0;
}


void pointerSort(float netPay[], int n){
    float *netPayPointer[n];

    for (int i = 0; i < n; i++){
        netPayPointer[i] = netPay + i;
    }//for

    cout << "Pointer Sort Before:  ";

    for (int i = 0; i < n; i++){
        cout << *netPayPointer[i] << " ";
    }//for

    cout << endl;
    for (int pass = 1; pass <= n; pass++){
        for (int i = 0; i < n -1; i++){
           if (*netPayPointer[i] > *netPayPointer[i+1]) pointerSwap(*netPayPointer, i, i + 1);
        }//for
    }//for

    cout << "Pointer Sort After:   ";
    
    for (int i = 0; i < n; i++){      
        cout << *netPayPointer[i] << " ";      
    }//for

    cout << endl << endl;
}//pointerSort



//---------------------------------------------------------------------------//
//             PRINT DATA FOR MODULE 4 MIDTERM PARTS 2 & 3                   //
//---------------------------------------------------------------------------//
void printNetPaySortHeader(){
    cout << "NET PAY SORTS" << endl;
    cout << string(120, '=') << endl;
}//printNetPaySortHeader


void printUnsortedNetPays(float netPay[], int n){
    cout << "Unsorted Net Pays:    ";
    for (int i = 0; i < n; i++){
        cout << netPay[i] << " "; 
    }//for
    cout << endl;
}//printUnsortedNetPays


