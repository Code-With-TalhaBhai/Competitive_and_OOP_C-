#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector <vector<int>> &m, vector <vector <int>> visited,int newX,int newY,int n){
    // if((newX >= 0 && newY >= 0) && (newX < n && newY < n) && visited[newX][newY] == 0 && m[newX][newY] == 1){
    // if(newX >= 0 && newY >= 0 && newX < n && newY < n && visited[newX][newY] == 0 && m[newX][newY] == 1){
    if((newX >= 0 && newX<n) && (newY >=0 && newY < n) && visited[newX][newY] == 0 && m[newX][newY] == 1){
        return true;
    }
    else{
        return false;
    }
}



void rate_in_maze(vector <vector <int>> &m,vector <string> &ans,vector <vector <int>>visited,string path,int srcx,int srcy,int n){
    // Reached ending point
    if(srcx == n-1 && srcy == n-1){
    // if(srcx == n-2 ){
        ans.push_back(path);
        return;
    }

    visited[srcx][srcx] = 1;
    // 4 choices D R L U
 
    // DOWN
    int newX = srcx + 1;
    int newY = srcy;
    if(isSafe(m,visited,newX,newY,n)){
        path.push_back('D');
        rate_in_maze(m,ans,visited,path,newX,newY,n);
        path.pop_back();
    }


    // RIGHT
    newX = srcx;
    newY = srcy + 1;
    if(isSafe(m,visited,newX,newY,n)){
        path.push_back('R');
        rate_in_maze(m,ans,visited,path,newX,newY,n);
        path.pop_back();
    }


    // LEFT
    newX = srcx;
    newY = srcy - 1;
    if(isSafe(m,visited,newX,newY,n)){
        path.push_back('L');
        rate_in_maze(m,ans,visited,path,newX,newY,n);
        path.pop_back();
    }



    // UP
    newX = srcx - 1;
    newY = srcy;
    if(isSafe(m,visited,newX,newY,n)){
        path.push_back('U');
        rate_in_maze(m,ans,visited,path,newX,newY,n);
        path.pop_back();
    }

    visited[srcx][srcy] = 0;

};


vector <string> solve1(){

    vector <string> ans;
    vector <vector <int>> m = {
        {1,0,0,1},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int srcx = 0;
    int srcy = 0;

    if(m[0][0] == 0){ // If starting point is closed then there is no entry. Hence, empty
        return ans;
    }


    vector <vector <int>> visited = m; // equal-to-m just to give size

    int n = m.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
        
    }    

    string path = "";

    rate_in_maze(m,ans,visited,path,srcx,srcy,n);

    // for(vector<int> i:visited){
    //     for(int j:i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // };

    // return {"a","b","c"};

    for(string i:ans){
        cout << i << " ";
    }

    return ans;

}


int main(){
    
    // cout << "The discovered path is: ";
    // for(string i:solve1()){
    //     cout << i << " ";
    // }
    solve1();
    cout << endl;

    return 0;
}