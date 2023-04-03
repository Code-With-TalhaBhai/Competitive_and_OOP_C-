#include<iostream>
using namespace std;


bool sortedArray(int arr[],int index,int n){
    if(index == n-1){
        return true;
    }

    return arr[index]<arr[index+1] && sortedArray(arr,++index,n);
}

int linearSearch(int arr[],int index,int n,int find){
    if(index == n-1){
        return -1;
    }

    if(arr[index] == find){
        return index;
    }

    return linearSearch(arr,++index,n,find);
}

void multiSearch(int arr[],int index,int len,int find){

    if(arr[index] == find){
        cout << index << " ";
    }

    if(index == len-1){
        return;
    }

    multiSearch(arr,++index,len,find);
}

int temp = 0;
void sort(int arr[],int index,int iter,int len){
    if(arr[index] > arr[iter]){
        temp = arr[index];
        arr[index] = arr[iter];
        arr[iter] = temp;
    }

    if(iter == len){
        if(index == len-1){
            return;
        }
        index++;
        iter = index;
    }
    iter++;

    sort(arr,index,iter,len);
}



int main(){

    int t = 1;
    int n = 5;
    int arr[n] = {23,45,63,18,3};
    int arr1[n] = {23,45,63,88,45};


    for (int i = 1; i <= t; i++)
    {
        cout << "Case" << i << ": " << endl;
        cout << (sortedArray(arr,0,n) ? "It is sorted" : "It is not sorted") << endl;

        // Linear Search using Recurrsion first and single occurence
        int callback = linearSearch(arr,0,n,18);
        (callback == -1) ? cout << "Not Found" : cout << callback << endl;


        // Linear Search using Recurrsion multiple occurrences
        multiSearch(arr1,0,n,45);
    }

    cout << endl;


    // buble sort
    sort(arr,0,1,n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    
    

    return 0;
}