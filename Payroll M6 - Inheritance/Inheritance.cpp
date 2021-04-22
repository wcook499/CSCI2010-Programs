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
			OvertimePay,
			RegularPay,
			TaxRate,
			TaxAmount;
	string	FirstName,
			LastName;
	char	MaritalStatus;


	void SetVariables( string iFirstName, string iLastName, char iMaritalStatus, int iEmployeeID, float iHoursWorked, float iBasePay){
		
		FirstName = iFirstName;
		LastName = iLastName;
		MaritalStatus = iMaritalStatus;
		EmployeeID = iEmployeeID;
		HoursWorked = iHoursWorked;
		BasePay = iBasePay;
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



	void PrintData(){
		cout << fixed << setprecision(2) << setw(10) << FirstName << setw(10)
		<< LastName << setw(10) << MaritalStatus << setw(10) << EmployeeID
		<< setw(10) << HoursWorked << setw(10) << HourlyRate << setw(10)
		<< OvertimeHours << setw(10) << OvertimePay << setw(10) << RegularPay
		<< setw(10) << GrossPay << setw(10) << TaxAmount << setw(10) << NetPay
		<< endl;
	}




};


class Salary: public Employee{
	
	public: float GetGrossPay(){
		OvertimeHours = GetOvertimeHours();
		RegularPay = BasePay / 52;
		HourlyRate = RegularPay / 40;

		OvertimePay = OvertimeHours * (HourlyRate * 1.5);

		GrossPay = RegularPay + OvertimePay;

		return GrossPay;
	}//

	Salary(){};

};


class Hourly: public Employee{
	
	public: float GetGrossPay(){
		HourlyRate = BasePay;
		OvertimeHours = GetOvertimeHours();
		RegularPay = BasePay * HoursWorked;
		OvertimePay = OvertimeHours * (BasePay * 1.5);
		GrossPay = RegularPay + OvertimePay;

		return GrossPay;
	}//

	Hourly(){};
};


	void PrintDataHeading(){
		cout << endl << endl;
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
	}


	void PrintMinMaxHeading(){
		cout << endl << endl;
		cout << "NET PAY MIN/MAX" << endl;
		cout << string(120, '=') << endl;
	}


	void PointerSort(Employee **EmployeeList, int n){
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(EmployeeList[i]->NetPay > EmployeeList[j]->NetPay){
					Employee *Temp = EmployeeList[i];
					EmployeeList[i] = EmployeeList[j];
					EmployeeList[j] = Temp;
				}
			}
		}
	}



int main(){
	int 	NumberEmployees = 0,
			ArraySize = 16,
			EmployeeID;
	char	SalaryOrHourly;
	float	BasePay,
			HoursWorked;
	string	FirstName,
			LastName;
	char	MaritalStatus;

	Employee *EmployeeList[ArraySize];

	ifstream fin("employee.in");

	while (fin >> SalaryOrHourly >> FirstName >> LastName >> MaritalStatus >> EmployeeID >> HoursWorked >> BasePay){

		if(SalaryOrHourly == 'H'){
			EmployeeList[NumberEmployees] = new Hourly();
			EmployeeList[NumberEmployees]->SetVariables(FirstName, LastName, MaritalStatus, EmployeeID, HoursWorked, BasePay);
			EmployeeList[NumberEmployees]->GetGrossPay();
			EmployeeList[NumberEmployees]->GetNetPay();
		}

		if(SalaryOrHourly == 'S'){
			EmployeeList[NumberEmployees] = new Salary();
			EmployeeList[NumberEmployees]->SetVariables(FirstName, LastName, MaritalStatus, EmployeeID, HoursWorked, BasePay);
			EmployeeList[NumberEmployees]->GetGrossPay();
			EmployeeList[NumberEmployees]->GetNetPay();
		}
	NumberEmployees++;

	}
	
	PrintDataHeading();
	
	PointerSort(EmployeeList, NumberEmployees);

	for (int i=0; i<NumberEmployees; i++){
		EmployeeList[i]->PrintData();
	}

	PrintMinMaxHeading();

	cout << "Max Net Pay: " << setw(10) << EmployeeList[NumberEmployees-1]->NetPay << endl;
	cout << "Min Net Pay: " << setw(10) << EmployeeList[0]->NetPay << endl;
return 0;
}