/*

WILLIAM COOK
04/04/21
Module 18 Assignment


Expand the Employee Payroll program to include hourly based and salary based
employees. This phase uses an array of employee objects, inheritance for
different classes of employees, and polymorphism for salary computation. The 52
week yearly salary as well as number of overtime hours worked by a salary based
employee is given). For salary based employees, to find the regular (gross) pay
for a week, divide the salary by 52. To compute the overtime pay for a salary
based employee, first find the hourly rate by dividing the gross pay by 40, and
then compute overtime pay. For every employee, overtime pay, tax amount, and 
net pay must also be computed. In addition, the program should find the minimum
and maximum net pay of all employees as well as sort the employees based on
their net pay (ascending order).

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

class Hourly : public Employee{

}//Hourly

class Salary : public Employee{

}//Salary

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