#include<iostream>
using namespace std;


int binarySearch(arr,start,end,mid){
    if(arr[mid] == search){
        return mid;
    }



}



int solve1(){

    int n = 10;
    int arr[n] = {7,21,83,89,90,92,324,432,532,614};

    int mid = (0 + n)/2;

    return binarySearch(arr,0,n,mid);

}


int main(){

    cout << "The index is: " << solve1();

    return 0;
}