#include<iostream>
using namespace std;


void bubbleSort(int arr[],int n,int i){
        if(i == n){
            return ;
        }

        for(int j = 0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
        
        bubbleSort(arr,n,i+1);
}

void selectionSort(int arr[],int n,int i){

    if(i == n-1){
        return ;
    }
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }

    selectionSort(arr,n,i+1);
}

void insertionSort(int arr[],int n,int i){
    ++i;
    if(i == n){
        return ;
    }

        int comp = arr[i];
        int j = i - 1;
        while (j>=0 && comp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        
    arr[j+1] = comp;
    insertionSort(arr,n,i);

}



void solve1(){
    int n = 10;
    int arr[n] = {324,532,614,432,89,92,83,90,21,7};

    // Bubble Sort
    // cout << "Bubble sort working-->" << endl;
    // bubbleSort(arr,n,0);

    // Selection Sort
    // cout << "Selection sort working-->" << endl;
    // selectionSort(arr,n,0);

    cout << "Insertion sort working-->" << endl;
    insertionSort(arr,n,0);


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}


int main(){

    solve1();
    cout << endl;

    return 0;
}