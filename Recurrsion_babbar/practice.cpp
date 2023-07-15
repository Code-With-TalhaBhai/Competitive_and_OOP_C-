#include <iostream>
#include <vector>
using namespace std;


bool isSafe(int x,int y,int n,vector <vector <int>> visited,vector <vector <int>> &m){
    // cout << "value x: " << x << endl;
    // cout << "value y: " << y << endl;
    // cout << "visited: " << visited[x][y] << endl;
    // cout << "main arr: " << m[x][y] << endl;

    if((x >= 0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
        // cout << "true working" << endl;
        return true;
    }
    else{
        // cout << "false working" << endl;
        return false;
    }
}


void solve(vector <vector <int>> &m,int n,vector<string> &ans,int x,int y,vector <vector <int>> visited,string path){
    // cout << "solve working" << endl;
    if(x == n-1 && y == n-1){
        // cout << "inner working";
        ans.push_back(path);
        return ;
    }

    visited[x][y] = 1;

    // Down
    int newX = x + 1;
    int newY = y;
    if(isSafe(newX,newY,n,visited,m)){
        path.push_back('D');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    // Left
    newX = x;
    newY = y - 1;
    if(isSafe(newX,newY,n,visited,m)){
        path.push_back('L');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    // Right
    newX = x;
    newY = y + 1;
    if(isSafe(newX,newY,n,visited,m)){
        path.push_back('R');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    // Up
    newX = x - 1;
    newY = y;
    if(isSafe(newX,newY,n,visited,m)){
        path.push_back('U');
        solve(m,n,ans,newX,newY,visited,path);
        path.pop_back();
    }

    visited[x][y] = 0;
    // cout << "visited ended" << endl;
}


vector <string> findPath(vector <vector <int>> &m,int n){
    vector<string> ans;
    int srcx=0;
    int srcy=0;

    if(m[0][0] == 0){
        return ans;
    }

    vector<vector<int>> visited = m;

    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    string path = "";
    solve(m,n,ans,srcx,srcy,visited,path); 
    // sort(ans.begin,ans.end());
    // for(string str:ans){
    //     cout << str << endl;
    // }

    return ans;
}


int main(){

    vector <vector <int>> m = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    // vector <vector <int>> m = {
    //     {1,0,0,0},
    //     {1,1,1,1},
    //     {1,1,0,1},
    //     {1,1,0,1}
    // };

    int n = m.size();

    // findPath(m,n);

    for(string str:findPath(m,n)){
        cout << str << " ";
    };

    cout << endl;

    return 0;
}   