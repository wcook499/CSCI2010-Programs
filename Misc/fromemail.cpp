/**	
Word document module6help.doc

I hope you are doing well and accumulated good programming experience despite the challenging subject of language C++ and on top dealing with OOP. 

As you have realized the module 5 was easier than you have expected with adding a few lines to the sample program. Module 6 is bit challenging, adding more experience to your OOP. You are incorporating inheritance in your payroll program by having two different employees hourly and salaried. 

The catch for the module 6th is the virtual function for the findgrosspay(). 

I am finishing evaluating the module 5 assignment and Please do not panic as we are getting to the bottom of the term. If for some reason you are behind, please communicate with me. I am providing the following code for those who are struggling with the concept of inheritance (you can change to your own flavor or get some ideas). Please email me your progress and what can I do to help you advance this course. Again, make sure to have enough postings in the discussions (posting 5 or more scattered entries such as answering a question, asking a question, comment on existing thread, open a new thread or your errors and your experience in making your assignment) to earn 35% of grade automatically (boosting your grade). Here is some code for helping with module 6th assignment. You may workout this program bottom-up in case something goes wrong you still will have the last working version and get points for it. You may break the program into 5 or more running programs starting with the main program and creation of the object and testing with a driver. Here is the hint. 

1)   Test the and output the input the data as whether the employee is hourly or salaried (1 means hourly and 2 is salaried) displaying the data. 

2) Testing the program for hourly employees since you have all the information from the previous program 

3) Testing the program for salaried employees by figuring out the hourly rate from the total grosspay. 
**/
  

class payroll{ 
    public: void setVariables(int empID, string fName, string lName, int stat, double rate, double hrs){ 
      employeeID = empID; firstName = fName; lastName = lName; payStat = stat; 
      if (payStat == 1){ hourlyRate = rate; } 
      else { salary = rate;} 
      hours = hrs; }  
   //declare function to calculate gross pay 
   public: virtual double calculateGrossPay() = 0;  
   double calculateTaxAmount(){ taxRate = .30; //set a flat taxrate 30% 
      taxAmount = grossPay * taxRate; //formula to calculate tax amount 
      return taxAmount; } //end calculateTaxAmount() function 
      double calculateNetPay(){ 
 …………..   return netPay;    } //end  
   void printData(){ //print out the data 
….   }//end printData() function 
}; //end Payroll class 
class employeeSalary : public payroll{ 
   public: double calculateGrossPay() {  
      regPay = ……. 
      hourlyRate = ……… 
      if (hours > 40) {otHours = (hours - 40); //calculate OT hours 
         otPay = (otHours * hourlyRate); //calculate OT pay 
         grossPay = (regPay + otPay); } 
      else if (hours <= 40) {otHours = 0; otPay = 0; grossPay = regPay;} 
      return grossPay;    }  
}; //end EmployeeSalary class  
class employeeHourly : public payroll{ 
      public: double calculateGrossPay(){  
      regPay = (40 * hourlyRate); //calculate regular hours 
      if (hours > 40){   otHours = (hours - 40); //calculate OT hours 
         otPay = (otHours * hourlyRate * 1.5); //calculate OT pay 
         grossPay = (regPay + otPay); //calculate gross pay 
      } //enf if clause for gross pay with overtime 
      else { otHours = 0;   otPay = 0; grossPay = regPay; 
      } //end else clause for four hours 
      return grossPay;  } //end calculateGrossPay() function 
}; //end EmployeeHourly class 
void printHeader(){ 
}//end printHeader() function 
int main(void){ 
   ….. 
   cout<<"Enter # of employees you want to process: "; 
   cin>>totalEmployeeCount; 
   payroll *employee[100];    
   //while loop to get input for each employee 
   while (employeeCounter < totalEmployeeCount){ 
  
      //prompt the user for hourly or salary employee 
      cout<<"Is employee "<<employeeCounter+1<<" hourly or salary? (Enter 1 for HOURLY / 2 for SALARY): "; 
      cin>>stat; 
      if (stat == 1){ cout<<"Instantiating an HOURLY employee object inherited from base class payroll..."<<endl<<endl;  
         cout<<"Enter employee's ID: ";cin>>empID; 
         cout<<"Enter employee's first name: “; cin>>fName; 
         cout<<"Enter employee's last name: ";cin>>lName; 
         cout<<"Enter employee's hourly wage: “; cin>>rate; 
         cout<<"Enter employee's hours for this week: "; cin>>hrs; 
         employee[employeeCounter] = new employeeHourly();          
         employee[employeeCounter]->setVariables(empID, fName, lName, stat, rate, hrs); 
         employee[employeeCounter]->calculateGrossPay();  
         employee[employeeCounter]->calculateTaxAmount();  
         employee[employeeCounter]->calculateNetPay(); } //end if 
      //if employee is NOT hourly (Salary clause) 
      else { cout<<"Instantiating a SALARY employee object inherited from base class payroll..."<<endl<<endl;  
……… } 