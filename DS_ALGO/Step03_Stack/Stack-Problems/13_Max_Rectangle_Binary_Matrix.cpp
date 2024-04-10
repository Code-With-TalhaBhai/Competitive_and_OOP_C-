#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MAX 100

// heights -> histogram
// n -> size
int largest_area_histogram(vector<int> heights,int n){
    int max_area = -1;
    stack<int> S1;

    S1.push(-1);
    vector<int> prevSmaller(n);
    for (int i = 0; i < n; i++)
    {
        int curr =  heights[i];
        // if(curr == 0){
        //     prevSmaller[i] = -1;
        //     S1.push(i);
        // }

        while(S1.top() != -1 && heights[S1.top()]>=curr){
            S1.pop();
        }

        prevSmaller[i]  = S1.top();
        S1.push(i);
    }

    
    vector<int> nextSmaller(n);
    stack<int> S2;
    S2.push(-1);
    for (int i = n-1; i >= 0; i--)
    {
        int curr = heights[i];
        // if(curr == 0){
        //     nextSmaller[i] = -1;
        //     S2.push(i);
        // }

        while(S2.top() != -1 && heights[S2.top()]>=curr){
            S2.pop();
        }
        nextSmaller[i] = S2.top();
        S2.push(i);
    }
    
    for (int i = 0; i < n; i++)
    {
        int p_small = prevSmaller[i];
        int n_small = nextSmaller[i];
        if(n_small == -1){
            n_small = n;
        }

        int width = n_small - p_small -1;
        int length = heights[i];
        int area = width*length;
        if(max_area<area){
            max_area = area;
        }
    }
    return max_area;
}



int maxArea(int M[MAX][MAX], int n, int m) {
    vector<int> histogram(m,0);
    int latest_area,max_area = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(M[i][j] == 0){
                histogram[j] = 0;
            }
            else{
                histogram[j] = histogram[j] + M[i][j];
            }
        }
        latest_area = largest_area_histogram(histogram,m);
        if(max_area<latest_area){
            max_area = latest_area;
        } 
    }
    return max_area;
}



int main(){

    int M1[MAX][MAX]={
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };

    int M2[MAX][MAX] = {
    {1,0,1,0,0},
    {1,0,1,1,1},
    {1,1,1,1,1},
    {1,0,0,1,0}
    };

    int M3[MAX][MAX] = {
        {1,1,1},
        {1,0,1},
        {0,0,0},
        {1,1,0}
    };


    int M4[MAX][MAX] = {
        {1,1,1,1,1},
        {0,1,0,0,0}
    };

    cout << "The max rectangle is binary matrix is: " << maxArea(M1,4,4) << endl;
    cout << "The max rectangle is binary matrix is: " << maxArea(M2,4,4) << endl;
    cout << "The max rectangle is binary matrix is: " << maxArea(M3,4,3) << endl;
    cout << "The max rectangle is binary matrix is: " << maxArea(M4,2,5) << endl;

    return 0;
}