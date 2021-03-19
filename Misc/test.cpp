#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int testFunction(int input);

int main(){
    cout << testFunction(2);
return 0;
}

int testFunction(int input){
    int thing = 1 + input;
    return thing;
}