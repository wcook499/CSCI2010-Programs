#include <fstream>
#include<iostream>
#include <string.h>
using namespace std;

class person{
    private: char name[20];
    char telephone[18];
    ifstream fin;
    public:  person(){ fin.open("data.in"); }
    ~person(){fin.close(); }
    search (char []);
};

person :: paint(char searchname[]){
    while(fin>>name>>telephone)
    if(strcmp(searchname, name) == 0){
     	cout<<"FOUND!"<<endl;
        cout<<"NAME : "<<name<<endl<<"PHONE NO : "<<telephone<<endl;
        return 1;
    }//IF
    cout<<"NOT FOUND..."<<endl;
    return 0;
}//SEARCH


void main(){
    person employee;
    char nametosearch[20];
    cout<<"ENTER NAME TO SEARCH : ";
    cin>>nametosearch;
    employee.search(nametosearch);
}//MAIN