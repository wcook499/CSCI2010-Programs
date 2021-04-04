/*

WILLIAM COOK
04/04/21

Phase 1)

Create an Employee class for a basic payroll program to compute the net pay 
salary of hourly based employees. Your program should also find the average net
pay for a small company. To define the class, include the appropriate data
members, member functions, and access modifiers. For simplicity, use a constant
tax rate of 30% to compute the tax amount. Employees that work over 40 hours
will receive overtime pay of one and a half of their hourly rate for overtime
hours worked. The output should display the name of each employee, hours worked,
hourly rate, overtime pay, regular (gross) pay, tax amount, and net pay. The
average net pay of all employees should also be displayed.

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


class Employee{
	//data members
	int 		EmployeeID,
				NumEmployees;
	string		FirstName,
				LastName;
	char		MaritalStatus;
	float		HourlyRate,
				HoursWorked,
				OvertimeHours,
				TaxRate,
				TaxAmount,
				RegularPay,
				OvertimePay,
				GrossPay,
				NetPay,
				NetPayAverage,
				NetPayTotal;
				
	ifstream 	fin;

	public:		Employee();			//constructor
				~Employee();		//destructor

	void 		PrintReport(),
				PrintDataHeading(),
				PrintData(),
				GetOvertimeHours(),
				GetOvertimePay(),
				GetRegularPay(),
				GetGrossPay(),
				GetTaxRate(),
				GetTaxAmount(),
				GetNetPay(),
				GetNetPayAverage(),
				PrintNetPayAverage();

};

Employee::Employee(){	
    fin.open("employee.in");
}//constructor


Employee::~Employee(){	
    fin.close();
}//destructor


void Employee::PrintReport(){
	NumEmployees = 0;
	NetPayTotal = 0;

	PrintDataHeading();

	while(fin >> FirstName >> LastName >> MaritalStatus >> EmployeeID 
		  >> HoursWorked >> HourlyRate){
		GetOvertimeHours();
		GetOvertimePay();
		GetRegularPay();
		GetGrossPay();
		GetTaxRate();
		GetTaxAmount();
		GetNetPay();
		PrintData();
		NumEmployees++;
		NetPayTotal = NetPayTotal + NetPay;
	}//while

	GetNetPayAverage();
	PrintNetPayAverage();
}//PrintReport


void Employee::PrintDataHeading(){
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
}//PrintHeading


void Employee::PrintData(){
	cout << fixed << setprecision(2) << setw(10) << FirstName << setw(10)
	<< LastName << setw(10) << MaritalStatus << setw(10) << EmployeeID
	<< setw(10) << HoursWorked << setw(10) << HourlyRate << setw(10)
	<< OvertimeHours << setw(10) << OvertimePay << setw(10) << RegularPay
	<< setw(10) << GrossPay << setw(10) << TaxAmount << setw(10) << NetPay
	<< endl;
}//PrintData


void Employee::GetOvertimeHours(){
        if (HoursWorked > 40){
            OvertimeHours = HoursWorked - 40;
        }//if
        else if (HoursWorked <= 40){
            OvertimeHours = 0;
        }//else if
}//GetOvertimeHours


void Employee::GetOvertimePay(){
	OvertimePay = OvertimeHours * (HourlyRate * 1.5);
}


void Employee::GetRegularPay(){
	RegularPay = HourlyRate * HoursWorked;
}//GetRegularPay


void Employee::GetGrossPay(){
	GrossPay = RegularPay + OvertimePay;
}//GetGrossPay


void Employee::GetTaxRate(){
	TaxRate = .3;
}//GetTaxRate


void Employee::GetTaxAmount(){
	TaxAmount = GrossPay * TaxRate;
}//GetTaxAmount


void Employee::GetNetPay(){
	NetPay = GrossPay - TaxAmount;
}//GetNetPay


void Employee::GetNetPayAverage(){
	NetPayAverage = NetPayTotal / NumEmployees;
}//GetNetPayAverage


void Employee::PrintNetPayAverage(){
	cout << endl << endl;
    cout << string(120, '-') << endl;
	cout << "NET PAY AVERAGE: " << NetPayAverage << endl;
	cout << string(120, '-') << endl;
	cout << endl << endl;
	cout << string(120, '=') << endl;
}//PrintNetPayAverage


int main(){
	Employee employee;
	employee.PrintReport();
	return 0;
}