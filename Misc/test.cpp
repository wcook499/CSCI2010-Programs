#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class employee{
   
   public: 
	int 		EmployeeID;
	string	FirstName,
				LastName;
	char		MaritalStatus;
	float		HourlyRate,
            HoursWorked,
				OvertimeHours,
            OvertimePay,
				TaxRate,
				TaxAmount,
				GrossPay,
				NetPay;
};

Employee::Employee(){	
    fin.open("employee.in");
}//constructor

Employee::~Employee(){	
    fin.close();
}//destructor


class hourly: public employee{
   public:  
   float    RegularPay;
}

class salary: public employee{
   public:
   float    Salary;   
}