#include<iostream>
using namespace std;

int binary_search(int n,int arr[],int key){
    int start,end,mid;
    start = mid = 0;
    end = n; // array length;

    while (start <= end)
    {
        mid = (start + end)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            end = mid -1;
        }
        else {
            start = mid + 1;
        }

    }
    return -1;
}



int main(){
    int n;
    cout << "How much element you want to add: ";
    cin >> n;

    int arr[n];
    cout << "Enter your array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key you want to search: ";
    cin >> key;

    //liner_search
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == key){
            cout << key;
        }
    }
    // Its time-complexity is O(n)
    
    
    // binary_search
    cout << binary_search(n,arr,key) << endl;
    // Its time-complexity is O(log2(k)) --> Log of 2 with base k(length of array)

    return 0;
}