#include<iostream>
using namespace std;
void invertedPattern(int n);
void ZeroOnePattern(int n);
void RhombusPattern(int n);
void MiddleNumPattern(int n);
void PalindromicPattern(int n);
void UniqueStarPattern(int n);
void ZigZagPattern(int n);


int main(){
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;


    cout << "We are printing inverted pattern" << endl;
    invertedPattern(n);

    cout << "We are printing 0 and 1 pattern" << endl;
    ZeroOnePattern(n);


    cout << "We are printing Rhombus pattern" << endl;
    RhombusPattern(n);


    cout << "We are printing Middle Number Pattern" << endl;
    MiddleNumPattern(n);


    cout << "We are printing Palindramoic Pattern" << endl;
    PalindromicPattern(n);


    cout << "We are printing Unique Star Pattern" << endl;
    UniqueStarPattern(n);


    cout << "We are printing Zig Zag Pattern" << endl;
    ZigZagPattern(n);

    return 0;
};


void invertedPattern(int n){
    // 1st method
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // 2nd method
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1;j <= (n+1-i);j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }   
}


void ZeroOnePattern(int n){
    int bit;
    // 1st method
    for (int i = 1; i <= n; i++)
    {   
        bit = i%2 == 0 ? 0 : 1;
        for (int j = 1; j <= i; j++)
        {
            cout << bit << " ";
            bit = bit == 0 ? 1 : 0;
        }
        cout << endl;
    }

    cout << endl;

    // 2nd method
    for (int k = 1; k <= n; k++)
    {
        for (int l = 1; l <= k; l++)
        {
           if((k+l)%2 == 0){
            cout << "0 ";
           }
           else if((k+l)%2 == 1){
            cout << "1 ";
           }
           else{
            cout << " ";
           }
        }
        cout << endl;
    }  
}


void RhombusPattern(int n){
    for (int i = 1; i <= n; i++)
    {   
        for (int k = 1; k <= (n-i); k++)
        {
            cout << " ";
        }
        
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }   
};



void MiddleNumPattern(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int spc = 1; spc <= n-i; spc++)
        {
            cout << " ";
        }
        

        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }   
}


void PalindromicPattern(int n){
    for (int row = 1; row <= n; row++)
    {
        for (int spc = 1; spc <= n-row; spc++)
        {
            cout << "  ";
        }
        
        // for (int j = 1; j <= (row*2)-1; j++)
        for (int j = row; j >= 1; j--)
        {
            cout << j << " ";
        }

        for (int k = 2; k <= row; k++)
        {
            cout << k << " ";
        }
        

        cout << endl;
    } 
}


void UniqueStarPattern(int n){
    // int c = n/2;
    for (int row_no = 1; row_no <= n; row_no++)
    {
        for (int spc = 1; spc <= n-row_no; spc++)
        {
            cout << "  ";
        }
        

        for (int cols = 1; cols <= row_no+(row_no-1); cols++)
        {
            cout << "*" << " ";
        }
    cout << endl;
    }

    for (int row_no = n; row_no >= 1; row_no--)
    {
        for (int spc = 1; spc <= n-row_no; spc++)
        {
            cout << "  ";
        }
        

        for (int cols = 1; cols <= row_no+(row_no-1); cols++)
        {
            cout << "*" << " ";
        }
    cout << endl;
    }  
}


void ZigZagPattern(int n){
    cout << "Not done yet";
    // int subSpc;
    for (int row_no = 1; row_no <= n; row_no++)
    {
        // subSpc = 1;
        for (int spc = 1; spc <= n-row_no; spc++)
        {
            cout << " ";
        }
        
        cout << "*";

        if(row_no > 1){
        for (int subSpc = 0; subSpc <= (row_no*2)-3; subSpc++)
        {
            cout << " ";
        }

        cout << "*";
        }


        for (int spc = 1; spc <= (n-row_no)+3; spc++)
        {
            cout << " ";
        }
        

        if(row_no != n){
            cout << "*";
        }

        if(row_no > 1){
        for (int subSpc = 1; subSpc <= (row_no*2)-3; subSpc++)
        {
            cout << " ";
        }

        cout << "*";
        }


        cout << endl;
    }
}
