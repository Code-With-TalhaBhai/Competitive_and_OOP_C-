#include <iostream>
using namespace std;


// Transpose of a matrix but matrix is square(rows and colums are equal)
void solve1(){
    int row,col;
    cin >> row >> col;
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    int tmp;
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
           tmp = arr[i][j];
           arr[i][j] = arr[j][i];
           arr[j][i] = tmp;
        }
        
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}





// Multiplication of matrices
void solve2(){
    int row1,col1,row2,col2;
    cin >> row1 >> col1; 

    // Array: 1
    int arr1[row1][col1];

    // Input
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cin >> arr1[i][j];
        }
    }

    // Output
    // for (int i = 0; i < row1; i++)
    // {
    //     for (int j = 0; j < col1; j++)
    //     {
    //         cout << arr1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Array: 2
    // Input
    cin >> row2 >> col2; 
    int arr2[row2][col2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> arr2[i][j];
        }
    }

    // Output
    // for (int i = 0; i < row2; i++)
    // {
    //     for (int j = 0; j < col2; j++)
    //     {
    //         cout << arr2[i][j] << " ";
    //     }
    //         cout << endl;
    // }

    int res[row1][col2];
    if(row2 == col1){
        int element = 0;
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                // cout << res[i][j] << " ";
                element = 0;
                for (int k = 0; k < col1; k++)
                {
                    element += arr1[i][k] * arr2[k][j];
                }
                res[i][j] = element;
                // cout << res[i][j] << " ";
            }
            // cout << endl;
        }

        for (int a = 0; a < row1; a++)
        {
            for (int b = 0; b < col2; b++)
            {
                cout << res[a][b] << " ";
            }
                cout << endl;
        }
        
    }
    else{
        cout << "Multiplication doesn't exist of these metrices" << endl;
    }
}


// Matrix Search in Sorted Matrix
void solve3(){
   int row,col,key;
    cin >> row >> col;
    cin >> key;
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    int start = 0; int mid = 0;
    int end = row -1;

        


}


int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        cout << "Case #" << i << ": ";
        // solve1();
        solve2();
        solve3();
        cout << endl;
    }
    
    
    return 0;
}