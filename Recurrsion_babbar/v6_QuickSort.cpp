#include <iostream>
using namespace std;


void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int partition(int arr[],int s,int e){

    int pivot = arr[s];
    int count = 0;

    for (int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);


    int i = s;
    int j = e;

    while (i<pivotIndex && j>pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot) 
        {
            j--;
        }
        


        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;
}


// Just for practice repition
// int partition2(int arr[],int s,int e){
//     int pivot = arr[s];
//     int count = 0;

//     for (int i = s+1; i <= e; i++)
//     {
//         if(arr[i] <= pivot){
//             count++;
//         }
//     }

//     int pivotIndex = s+count;
//     swap(arr[s],arr[pivotIndex]);

//     int i,j;
//     i = s;
//     j = e;

//     while (i<pivotIndex  && j>pivotIndex)
//     {
//         while(arr[i]<=pivot){
//             i++;
//         }

//         while(arr[j]>pivot){
//             j--;
//         }

//         if(i<pivotIndex && j>pivotIndex){
//             swap(arr[i++],arr[j--]);
//         }

//     }
//     return pivotIndex;
    
// }



void quick_sort(int arr[],int s,int e){

    if(e == 0 || e == 1){
        return;
    }

    // cout << "(" << s << "," << e << ")" << endl;

    if(s >= e){
        return ;
    }

    int pivot = partition(arr,s,e);
    // int pivot = partition2(arr,s,e); //Just for practice repetition

    quick_sort(arr,s,pivot-1);

    quick_sort(arr,pivot+1,e);

}



int main(){

    int n = 11;
    int arr[n] = {23,23,5,3,12,53,62,1,53,32,6};


    // Quick Sort is preferred in linkedList over Merge sort
    quick_sort(arr,0,n-1);
    print(arr,n);

    return 0;
}