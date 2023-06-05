#include <iostream>
using namespace std;


int main(){

    // Left right angle;
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    

    // Pyramid   
    int n = 5;
    int sp = n;
    for (int line = 1; line <= n; line++)
    {
        for (int space = 1; space <= sp; space++)
        {
            cout << " ";
        }

        sp--;

        for (int star = 1; star <= (line*2)-1; star++)
        {
            cout << "*";
        }
        cout << endl;
    }


    int q = 6;
    for (int i = q; i >= 1; i--)
    {
        for (int j=1; j <= i; j++)
        {
            cout << j << " "; 
        }
        cout << endl;
    }
    

    // Invert Pyramid

   // *******  n=4, star=7
   //  *****   n=3, star=5
   //   ***    n=2, star=3
   //    *     n=1, star=1
    

    int t = 5;
    int b = 1;
    for (int i = t; i > 0; i--)
    {
        for (int space = 1; space < b; space++)
        {
            cout << " ";
        }
        b++;
        
        for (int star = 1; star <= (i*2)-1; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    




    return 0;
}