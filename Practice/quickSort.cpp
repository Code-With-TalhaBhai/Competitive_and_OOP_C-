#include<iostream>
using namespace std;


int partition(int arr[],int start,int end){
    int count = start;
    int realpivot = arr[start];

    for (int i = start+1; i < end; i++)
    {
        if(realpivot>arr[i]){
            count++;
        }
    }

    swap(realpivot,arr[count]);

    int i = start;
    int j = end;

    while(i<=j){
        if(arr[i]>realpivot && arr[j]<realpivot){
            swap();
        }
    }

    
}



void quickSort(int arr[],int start,int end){
    if(start>=end){
        return ;
    }

    int pivot = partition(arr,start,end);

    quickSort(arr,start,pivot);

    quickSort(arr,pivot+1,end);
}



int main(){

    int n = 11;
    int arr[n] = {234,52,4,346,45,65,68,2,6,7,48};

    quickSort(arr,0,n-1);

    return 0;
}