#include<iostream>
using namespace std;
void rectangular(int num1,int num2);
void hollowRectangle(int num1,int num2);
void hollowRectangle2(int num1,int num2);
void halfPyramid(int n);
void halfPyramid1(int n);
void halfPyramid2(int n);
void halfPyramidNum(int n);
void halfPyramidNum1(int n);
void halfPyramidNum2(int n);
void floydsTriangle(int n);
void butterfly(int n);
void butterfly1(int n);

int main(){
    // Rectangular Pattern
    int num1,num2;
    cout << "Star Pattern" << endl;
    cout << "Enter the number of rows: ";
    cin >> num1;
    cout << "Enter the number of columns: ";
    cin >> num2;


    cout << "Rectangular Star Pattern" << endl;
    rectangular(num1,num2);


    cout << "Hollow Rectangular Pattern" << endl;
    hollowRectangle(num1,num2);

    cout << "Hollow Rectangular Pattern Method2" << endl;
    hollowRectangle2(num1,num2);

    cout << "Inverted Half Pyramid" << endl;
    halfPyramid(num1);

    cout << "Inverted Half Pyramid after 180deg" << endl;
    halfPyramid1(num1);

    cout << "Inverted Half Pyramid after 180deg from right side" << endl;
    halfPyramid2(num1);

    cout << "Half Pyramid using numbers" << endl;
    halfPyramidNum(num1);

    cout << "Half Pyramid1 using numbers" << endl;
    halfPyramidNum1(num1);

    cout << "Half Pyramid2 using numbers" << endl;
    halfPyramidNum2(num1);

    cout << "Floyds Triangle pattern" << endl;
    floydsTriangle(num1);

    cout << "Butterfly Pattern Method 1" << endl;
    butterfly(num1);

    cout << "Butterfly Pattern Method 2" << endl;
    butterfly1(num1);


    return 0;
}


// Rectangular Pattern
void rectangular(int num1,int num2){
    for (int i = 0; i < num1; i++)
    {
        for (int j = 0; j < num2; j++)
        {
            cout << "*";
        }
    cout << endl;
    }
}


// Hollow Rectangular Pattern
void hollowRectangle(int num1,int num2){
    for (int i = 0; i < num1; i++)
    {
        for (int z = 0; z < num2; z++)
        {
            if(i == 0 || i == (num1-1)){
                for (int j = 0; j < num2; j++)
                {
                    cout << "*";
                }
                break;
            }
    
            if(z == 0 || z == (num2-1)){
                cout << "*";
            }
            else{
                cout << " ";
            }

        }
        cout << endl;
    }
}


void hollowRectangle2(int num1,int num2){
    for (int row = 1; row <= num1; row++)
    {
        for(int col=1 ; col <=num2; col++){
            if(row == 1 || row == num1 || col == 1 || col == num2){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }   
}


// Inverted Half Pyramid
void halfPyramid(int n){
    for (int row = n; row >= 1; row--)
    {
        for (int col = 1; col <= row; col++)
        {
            cout << "*";
        }
        cout << endl;
    }
}


void halfPyramid1(int n){
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}


void halfPyramid2(int n){

    // 1st method
    // for (int k = n; k >= 1; k--){
    //     for (int j = 1; j <= k; j++){
    //         if(j == k){
    //             for (int z = 0; z <= n-j; z++)
    //             {
    //                 cout << "*";
    //             }               
    //         }
    //         else{
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }


    // 2nd Method

    for (int u = 1; u <= n; u++)
    {
        for (int w = 1; w <= n; w++)
        {
            if(w<=(n-u)){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }
}


void halfPyramidNum(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i<=j){
            cout << j << " ";
            }
        }
        cout << endl;
    }
    
}


void halfPyramidNum1(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(j<=i){
                cout << j << " ";
            }
        }
        cout << endl;
    } 
}


void halfPyramidNum2(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(j<=i){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}


void floydsTriangle(int n){
    int test = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {   
            if(j<=i){
            test ++;
            cout << test << " ";
            }
        }
        cout << endl;
    } 
}



void butterfly(int n){
    // n === "Total number of rows"
    int space;
    int tot_col = n*2;
    for (int row_no = 1; row_no <= n; row_no++)
    {
        for (int j = 1; j <= row_no; j++)
        {
            cout << "*";
        }

        space = tot_col-(row_no*2);
        for (int l = 1; l <= space; l++)
        {
            cout << " ";
        }
        
        
        for (int k = 1; k <= row_no; k++)
        {
            cout << "*";
        }
        
    cout << endl;
    };

    for (int row_no = n; row_no >= 1; row_no--)
    {
        for (int y = 1; y <= row_no; y++)
        {
            cout << "*";
        }

        space = tot_col - (row_no*2);
        for (int m = 0; m < space; m++)
        {
            cout << " ";
        }
        

        for (int z = 1; z <= row_no; z++)
        {
            cout << "*";
        }

            cout << endl;
    }   
}



void butterfly1(int n){
    cout << endl;
    int col = n*2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if(j<=i || j>=((col)-i+1)){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    
    for(int h=1; h<=n; h++){
        for (int m = 1; m <= col; m++)
        {
            if(m<=(n-h+1) || m>=(n+h)){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}