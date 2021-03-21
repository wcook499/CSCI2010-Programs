#include <fstream>

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PA(int a[], int size){
    int *pointa[size];

    for (int i = 0; i < size; i++){
        pointa[i] = a + i;
    }

    for (int i = 0; i < size; i++){
        cout << pointa[i];
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        cout << *pointa[i];
    }
    cout << endl;
}


int main(){

int a[] = {1,2,3,4,5};
int size = 5;
PA(a, size);

return 0;
}