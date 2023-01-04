#include <iostream>
using namespace std;




int main(){

    int n,m;
    cout << "Enter the number of rows: ";
    cin >> n;

    cout << "Enter the number of columns: ";
    cin >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        cout << "Input: ";
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << "Index--> row: " << i << " Column: " << j << " = " << arr[i][j] << " ";
            cout << arr[i][j] << " ";
        }
        // cout << endl << endl << endl;
        cout << endl;
    }
    
    int key;
    cout << "Enter your key: ";
    cin >> key;
    // Serching from 2d arrays matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == key){
                cout << "Row: " << i << " Column: " << j;
            }   
        }
        cout << endl;
    }

    int row_start,row_end, col_start,col_end;
    row_start = col_start = 0;

    row_end = m - 1;
    col_end = n - 1;

    while (row_start<=row_end && col_start<=col_end)
    {
        for (int col = col_start; col <= col_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }
        row_start++;

        for (int row = row_start; row <= row_end; row++)
        {
            cout << arr[row][col_end] << " ";
        }
        col_end--;
        
        for (int col = col_end; col >= col_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }
        row_end--;
        
        for (int row = row_end; row >= row_start; row--)
        {
            cout << arr[row][col_start] << " ";   
        }
        col_start++;
        
    }
    




    return 0;
}