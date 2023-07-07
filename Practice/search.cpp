#include<iostream>
#include<vector>
using namespace std;


void multiLinearSearch(int arr[][3],int i, int j,int x, int search, vector <int> &ans_arr){
    if(i == 0 && x == 0){
        ans_arr.push_back(-1);
        return ;
    }

    if(j == x-1){
        j = 0;
        --i;
    }

    --j;


    if(arr[i][j] == search){
        ans_arr.push_back(i);
        ans_arr.push_back(j);
        return ;
    }

    multiLinearSearch(arr,i,j,x,search,ans_arr);
}



int main(){

    int i = 2;
    int j = 3;
    int arr[i][j] = {
        {543,43,64},
        {534,643,63}
    };

    int search = 543;

    vector <int> ans_arr;

    multiLinearSearch(arr,i,j,j,search,ans_arr);

    for(int i:ans_arr){
        cout << i << " ";
    }

    cout << endl;

    return 0;
}