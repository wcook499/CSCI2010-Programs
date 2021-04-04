#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class payroll{
    ifstream fin;
    char employeeid[12];
    char employeename[20];
    char maritalstatus;
    int  hoursworked,overtime;
    double hourlyrate,overtimepay,regularpay,grosspay,taxrate,taxamount,netpay;
    
    void calculategrosspay();
    void calculatetax();
    void calculatenetpay();
    void printheadings();
    void printdata(); 
    
    public: payroll();

    ~payroll();

    void printreport();
};//payroll


payroll::payroll(){	
    fin.open("payroll.dat");
}//CONSTRUCTOR


payroll::~payroll(){	
    fin.close();
}//DESTRUCTOR


void payroll:: calculategrosspay(){	
    if(hoursworked  >  40){
 		overtime = hoursworked - 40;
 		regularpay = hoursworked * hourlyrate;
 		overtimepay = overtime * (hourlyrate * 1.5);
 		grosspay = regularpay + overtimepay;
    }//IF
    else  grosspay = hoursworked * hourlyrate;
}//CALCULATEGROSSPAY


void payroll ::calculatetax(){	
if(grosspay >= 500)  taxrate = .30;
            else if(grosspay > 200.00)  taxrate = .20;
            else  taxrate = .10;
            if(maritalstatus == 'S' ||maritalstatus == 's')
 		taxrate = taxrate + .05;
 	taxamount = grosspay * taxrate;   }//CALCULATETAX
void payroll :: calculatenetpay(){          
 	netpay = grosspay - taxamount;  }//CALCULATENETPAY
void payroll::printheadings(){	
 	cout<<setw(45)<<"-PAYROLL REPORT-"<<endl;
	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<" NAME      ID       HW OT  RT-PAY  OT-PAY  GROSS"
		   "    TAX   NETPAY"<<endl;
cout<<"------------------------------------------------------------------------------"<<endl; 
}//PRINTHEADINGS
void payroll::printdata(){	
 	cout<<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint);
 	cout<<setw(6)<<employeename<<setw(12)<<employeeid<<setw(4)
 	<<hoursworked<<setw(3)<<overtime<<setw(8)<<regularpay<<setw(8)
 	<<overtimepay<<setw(8)<<grosspay<<setw(8)<<taxamount<<setw(8)
 	<<netpay<<endl;   }//PRINTDATA
void payroll::printreport(){	
 	int i = 0;
	printheadings();
	while(fin>>employeename>>employeeid>>maritalstatus>>hoursworked>>hourlyrate){
        calculategrosspay();
        calculatetax();
        calculatenetpay();
        printdata();
        i++;  }//WHILE
}//PRINTREPORT

int main(){
	payroll employee;
	employee.printreport();    }//MAIN