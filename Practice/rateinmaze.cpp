#include<iostream>
#include<vector>
using namespace std;

bool checkPath(vector <vector <int>>path,int x,int y,vector <vector <int>> visited,int n){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && path[x][y] == 1){
        return true;
    }
    else{
        return false;
    }
}

void findPath(vector <vector <int>> path,int x,int y,string output,vector <vector <int>> &visited,vector <string> &ans_path,int n){

    if(x == n-1 && y == n-1){
        ans_path.push_back(output);
        return ;
    };

    visited[x][y] = 1;

    int newX,newY;
    newX = x+1;
    newY = y;
    //Down
    if(checkPath(path,newX,newY,visited,n)){
        output.push_back('D'); 
        findPath(path,newX,newY,output,visited,ans_path,n);
        output.pop_back(); 
    } 


    newX = x;
    newY = y+1;
    //Right
    if(checkPath(path,newX,newY,visited,n)){
        output.push_back('R');
        findPath(path,newX,newY,output,visited,ans_path,n);
        output.pop_back();
    }
    
    newX = x;
    newY = y-1;
    //Left
    if(checkPath(path,newX,newY,visited,n)){
        output.push_back('L');
        findPath(path,newX,newY,output,visited,ans_path,n);
        output.pop_back();
    }

    newX = x-1;
    newY = y;
    //UP
    if(checkPath(path,newX,newY,visited,n)){
        output.push_back('U');
        findPath(path,newX,newY,output,visited,ans_path,n);
        output.pop_back();
    }

    visited[x][y] = 0;

}




int main(){

    vector <vector <int>> path = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int n = 4; // Number of rows and columns;
    vector <vector <int>> visited = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };


    vector <string> ans_path;
    string output = "";
    findPath(path,0,0,output,visited,ans_path,n);


    for(string str:ans_path){
        cout << str << endl;
    }


    return 0;
}