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
   
	public: 
	int		EmployeeID;
	float	HoursWorked,
			BasePay,
			GrossPay,
			HourlyRate,
			NetPay,
			OvertimeHours,
			RegularPay,
			TaxRate,
			TaxAmount;
	string	FirstName,
			LastName;

	void SetVariables( int iEmployeeID, string iFirstName, string iLastName, float iBasePay, float iHoursWorked){
		EmployeeID = iEmployeeID;
		FirstName = iFirstName;
		LastName = iLastName;
		BasePay = iBasePay;
		HoursWorked = iHoursWorked;
	}

	virtual float GetGrossPay() = 0;

	float GetTaxAmount(){
		TaxRate = 0.3;
		TaxAmount = TaxRate * GrossPay;
		return TaxAmount;
	}

	float GetOvertimeHours(){
		if (HoursWorked > 40){
            OvertimeHours = HoursWorked - 40;
        }//if
        
		else if (HoursWorked <= 40){
            OvertimeHours = 0;
        }//else if
		
		return OvertimeHours;
	}

	float GetNetPay(){
		NetPay = GrossPay - GetTaxAmount();
		return NetPay;
	}

	void Print(){
		cout << EmployeeID << " " << FirstName << " " << LastName << NetPay << endl;
	}
};


class Salary: public Employee{
	
	public: float GetGrossPay(){
		OvertimeHours = GetOvertimeHours();
		RegularPay = BasePay / 52;
		HourlyRate = RegularPay / 40;

		GrossPay = RegularPay + (OvertimeHours * (HourlyRate * 1.5));

		return GrossPay;
	}//

	Salary(){};

};


class Hourly: public Employee{
	public:
	float	HourlyRate;
	int		EmployeeID;

	public: float GetGrossPay(){
		OvertimeHours = GetOvertimeHours();
		RegularPay = BasePay * HoursWorked;
		GrossPay = RegularPay + (OvertimeHours * (HourlyRate * 1.5));

		return GrossPay;
	}//

	Hourly(){};
};



int main(){
	int 	i = 0,
			ArraySize = 16,
			EmployeeID;
	char	SalaryOrHourly;
	float	BasePay,
			HoursWorked;
	string	FirstName,
			LastName;

	Employee *EmployeeList[ArraySize];

	ifstream fin("employee.in");

	while (fin >> SalaryOrHourly >> EmployeeID >> FirstName >> LastName >> BasePay >> HoursWorked){

		if(SalaryOrHourly == 'H'){
			EmployeeList[i] = new Hourly();
			EmployeeList[i]->SetVariables(EmployeeID, FirstName, LastName, BasePay, HoursWorked);
			EmployeeList[i]->GetGrossPay();
			EmployeeList[i]->GetNetPay();
			EmployeeList[i]->Print();
		}

		if(SalaryOrHourly == 'S'){
			EmployeeList[i] = new Salary();
			EmployeeList[i]->SetVariables(EmployeeID, FirstName, LastName, BasePay, HoursWorked);
			EmployeeList[i]->GetGrossPay();
			EmployeeList[i]->GetNetPay();
			EmployeeList[i]->Print();
		}
	i++;
	}
	
return 0;
}