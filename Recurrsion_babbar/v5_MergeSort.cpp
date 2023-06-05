#include <iostream>
using namespace std;

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
        cout << endl;
}


void merge(int arr[],int s,int e){

    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    int mainIndex = s;

    int *first_arr = new int[len1];
    int *second_arr = new int[len2];

    for (int i = 0; i < len1; i++)
    {
        first_arr[i] = arr[mainIndex++];
    }

    for (int i = 0; i < len2; i++)
    {
        second_arr[i] = arr[mainIndex++];
    }
    

    int i , j;
    i = j = 0;
    mainIndex = s;
    while (i < len1 && j < len2)
    {
        if(first_arr[i] < second_arr[j]){
            arr[mainIndex++] = first_arr[i++];
        }
        else{
            arr[mainIndex++] = second_arr[j++];
        }
    }
    

    while (i < len1)
    {
        arr[mainIndex++] = first_arr[i++];
    }
    
    while (j < len2)
    {
        arr[mainIndex++] = second_arr[j++];
    }


    delete[] first_arr;
    delete[] second_arr;
}


int inversion_merge(int arr[],int start,int end){
    int mid = (start+end)/2;
    int len1 = mid - start + 1;
    int len2 = end - mid;


    int *first = new int[len1];
    int *second = new int[len2];

    int index = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[index++];
    }
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[index++];
    }
    
    int i,j,count;
    i = j = count = 0;
    index = start;
    while (i < len1 && j < len2)
    {
        if(first[i] < second[j]){
            arr[index++]  = first[i++];
        }
        else{
            arr[index++] = second[j++];
            count++;
        }
    }
    
    while (i < len1)
    {
        arr[index++] = first[i++];
    }
    
    while (j < len2)
    {
        arr[index++] = second[j++];
        count++;
    }
    
    delete[] first;
    delete[] second;
    // cout << "count " << count << endl;
    return count;

}





void mergeSort(int arr[],int s,int e){
    // cout << "(" << s << " , " << e << ")" << endl;
    if(s >= e){
        return ;
    }

    int mid = (s+e)/2;
    mergeSort(arr,s,mid); 
    // cout << "Passing middle" << endl;
    mergeSort(arr,mid+1,e);
    cout << "(" << s << " , " << e << ")" << endl;

    merge(arr,s,e);
}


int inversion_count(int arr[],int start,int end){
    // cout << "(" << start << "," << end << ")" << endl;
    if(start>=end){
        return 0;
    }
    int mid = (start + end)/2;

    inversion_count(arr,start,mid);

    inversion_count(arr,mid+1,end);

    return inversion_merge(arr,start,end);
}


int main(){

    int n = 11;
    int arr[n] = {234,253,2,54,523,526,234,46346,74,342213123,232};
    // int n = 6;
    // int arr[n] = {234,423,525,353,43,5};
    mergeSort(arr,0,n-1);
    // print(arr,n);

    // Count the number of inversion(how many values to be placed in need to sort the array) through merge sort
    // cout << "Inversion count: " << inversion_count(arr,0,n-1) << endl;
    // print(arr,n);

    

    return 0;
}