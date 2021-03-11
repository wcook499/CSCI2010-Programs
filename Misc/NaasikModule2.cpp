#include<iostream>

using namespace std;
int main(){
	cout<<	"PAYROLL SYSTEM FOR DrEbrahimi.com Inc."<<endl;
	cout<<	"Saratoga Springs, NY 12866"<<endl;
	cout << "\n\n";
	
	int numberofemployees;
	int employeeid;
	int hoursworked;
	float hourlyrate, taxamount, grosspay, netpay;
	const float TAXRATE = 0.10;

	numberofemployees = 0;

	while( numberofemployees < 6){
		cout<<"ENTER THE EMPLOYEE ID:";
		cin>>employeeid;
		cout<<"ENTER THE HOURS WORKED:";
		cin>>hoursworked;
		cout<<"ENTER THE HOURLY RATE:";
		cin>>hourlyrate;
		grosspay=hoursworked*hourlyrate;
		taxamount=grosspay*TAXRATE;
		netpay=grosspay-taxamount;
		cout<<"EMPLOYEE ID IS		"<<employeeid<<endl;
		cout<<"THE HOURS WORK ARE	"<<hoursworked<<endl;
		cout<<"THE HOURLY RATE IS	"<<hourlyrate<<endl;
		cout<<"THE GROSS PAY IS	"<<grosspay<<endl;
		cout<<"THE TAX RATE IS		"<<TAXRATE<<endl;
		cout<<"THE TAX AMOUNT IS	"<<taxamount<<endl;
		cout<<"THE NETPAY IS		"<<netpay<<endl;
		numberofemployees = numberofemployees +1 ;
	}//WHILE
}