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