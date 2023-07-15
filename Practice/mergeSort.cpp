#include<iostream>
using namespace std;

void mergeSort(int arr[],int start,int end){
    
    
    if(start >= end){
         return ;
    }
    
    for(int i=start; i<end; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    int mid = (start + end)/2;
    
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
}
    


void solve1(){

    int n = 11;
    int arr[n] = {234,52,4,346,45,65,68,2,6,7,48};
    int start = 0;
    // int mid = (start + n)/2;
    
    mergeSort(arr,start,n);  
}



int main(){
   
    solve1();

}



// (0,5)
// (0,2)
// (0,1)
// (0,0) backfire

// (1,1) backfire

// (0,1) passed

// (2,2) backfire

// (0,2) passed

// (3,5)
// (3,4)
// (3,3) backfire

// (4,4) backfire
// (3,4)

// (5,5) backfire
// (3,5) passed

// (0,5) passed


// (6,10) 
// (6,8)
// (6,7)
// (6,6) backfire

// (7,7) backfire

// (6,7) passed

// (8,8) backfire

// (6,8) passed

// (9,10) 
// (9,9) backfire
// (10,10) // backfire

// (6,10) passed

// (0,10) passed