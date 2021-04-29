#include <iostream>
using namespace std;


int swap(int slot[], int i, int j){
    int temp;
    temp=slot[i];
    slot[i]=slot[j];
    slot[j]=temp;
    return 0;
}

int main(){-
    int slot[10]={8,3,1,5,7,10,4,9,6,2};
    int n=10,i;
    int lower, upper, sortflag, sml, scan;
    lower = 0;                                      // lower = 0 (First Index of the array)
    upper = n-1;                                    // upper = n-1 (The last index of the array)
    sortflag = 1;                                   // sortflag tells us if the array is sorted yet or not.
    while((lower<upper)&&(sortflag==1)){            // ?????
        sml = lower;                                // First, set smallest known value to the first index of the array
        sortflag = 0;                               // Set the sort flag to zero.  If no swaps are needed, we know the array is sorted
        scan = lower+1;                             // We start scanning at the first index of the array
        while(scan<=upper-lower){                   // ??? What does this do? Does this force the while loop to stop half way?
            if(slot[scan]>slot[scan+1]){            // If the first index value is larger than the second index value...
                swap(slot,scan,scan+1);             // SWAP EM
                sortflag=1;                         // A swap was needed, so we know the array needs another pass
                if(slot[scan]<slot[sml]) sml=scan;  // If the current index value is less than the smallest known value, set the smallest known value to that
            }
        scan++;                                     // increment scan to move to the next index
        }
    swap(slot, lower, sml);                         // swap the current index with the smallest known value... hmm is this the key to "exsel" sort?... seems to cut needed passes short?
    }

cout << "after sort: " << endl;
for(i=1;i<n+1;i++) cout << slot[i]<<" ";
cout << endl;
return 0;
}
