       #include <iostream> 
      #include <fstream>
      #include <cstring>
      using namespace std;
      
      int main(){
            char searchname[15], itemname [15], associateitem[14],  filename[13];
            cout << "ENTER THE DATA FILE NAME:  ";
            cin >> filename;
           cout << endl << "ENTER THE SEARCH NAME:  ";
           cin >> searchname;
             ifstream fin( filename );
           while( fin >> itemname >> associateitem ){
                if( strcmp( searchname, itemname ) == 0 ){
                     cout << associateitem << endl;
                     return 0;
                }  // end of if
           }  // end of loop
           cout << "NAME NOT FOUND" << endl;
           return 0;
     }  // end of main