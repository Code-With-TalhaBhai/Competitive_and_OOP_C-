#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool knows(vector<vector<int>> M,int i,int j){
    if(M[i][j]){
        return true;
    }
    else{
        return false;
    }
}


int celebrity(vector<vector<int>> M,int N){
    stack<int> S;

    // Pushing all rows in the stack
    for (int i = 0; i < N; i++)
    {
        S.push(i);
    }

    // check possible celebrity row
    // Two conditions are there:
    // 1. No body knows each other 
    // 2. Everybody knows celebrity
    while(S.size()>1){
        int a = S.top();
        S.pop();

        int b = S.top();
        S.pop();

        if(knows(M,a,b)){
            S.push(b);
        }else{
            S.push(a);
        }
    }
    
    int candidate = S.top();

    int zero_count_in_row = 0;
    for (int i = 0; i < N; i++)
    {
        if(M[candidate][i] == 0){
            zero_count_in_row++;
        }
    }

    if(zero_count_in_row != N){
        return -1;
    }

    int one_count_in_col = 0;
    for (int i = 0; i < N; i++)
    {
        if(M[i][candidate]){
            one_count_in_col++;
        }
    }
    
    if(one_count_in_col != N-1){
        return -1;
    }

    return candidate;
}


int main(){
        int N = 3;
        vector<vector<int>> M(N);
        M = {
            {0,1,0},
            {0,0,0}, 
            {0,1,0}
        };

        int L = 2;
        vector<vector<int>> O(L);
        O = {
        {0,1},
        {1,0}
        };

        // Return -1 if there is no celebrity in the party
        cout << "The celebrity in the party is at: " << celebrity(M,N) << endl;
        cout << "The celebrity in the party is at: " << celebrity(O,L) << endl;

    return 0;
}