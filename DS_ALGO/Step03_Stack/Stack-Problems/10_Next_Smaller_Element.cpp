#include<iostream>
#include<vector>
#include<stack>
using namespace std;


vector<int> nextSmallerElement1(vector<int> vect,int size){
    vector<int> ans;
    int min;
    for(int i=0; i<size; i++){
        min = vect[i];
        for (int j=i; j<size; j++)
        {
            if(min>vect[j]){
                min = vect[j];
                break;
            }
        }

        if(min == vect[i]){
            ans.push_back(-1);
        }
        else{
            ans.push_back(min);
        }
    }
    return ans;
}



vector<int> nextSmallerElement2(vector<int> vect,int size){
    vector<int> ans;
    int min;
    int j;
    for (int i = size-1; i >= 0; i--)
    {
        min = vect[i];
        j = i;
        while(j<size){
            if(min>vect[j]){
                min = vect[j];
                break;
            }
            j++;
        }
        if(vect[i]==min){
            ans.insert(ans.begin(),-1);
        }
        else{
            ans.insert(ans.begin(),min);
        }
    }
    return ans;
}


vector<int> nextSmallerElement3(vector<int> vect,int size){
    vector<int> ans;
    stack<int> S;
    S.push(-1);
    for (int i = size-1; i >= 0; i--)
    {
       int curr = vect[i];
       while(S.top()>=curr){
        S.pop();
       }
       vect[i] = S.top();
       S.push(curr);
    }
    return vect;
}


int main(){

    vector<int>v = {8,3,1,6,2,9,3};
    // vector<int>v = {2,1,4,3};
    cout << "Original Array" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;
    cout << "Next Smaller Element Vector1" << endl;
    for(int i:nextSmallerElement1(v,v.size())){
        cout << i << " ";
    }

    cout << endl;
    cout << "Next Smaller Element Vector2" << endl; // Optimized
    for(int i:nextSmallerElement2(v,v.size())){
        cout << i << " ";
    }

    // With Stack
    cout << endl;
    cout << "Next Smaller Element Vector3" << endl; // Optimized
    for(int i:nextSmallerElement3(v,v.size())){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}