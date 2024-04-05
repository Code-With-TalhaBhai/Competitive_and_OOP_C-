#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

void printStack(stack<int> S){
    while(!S.empty()){
        cout << "Element is: " << S.top() << endl;
        S.pop();
    }
}

int findMinimumCost(string str) {
    stack<char> S;
    if(str.length()%2==1){
            return -1; // Not valid
        }

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
       
            if (!S.empty() && ((S.top() == '{' && ch == '}'))) {
                S.pop();
            }
            else{
                S.push(ch);
            }

    }
        int open_brc,close_brc,count;
        open_brc = close_brc = count = 0;
        while(!S.empty()){
            if(S.top()=='{'){
                open_brc++;
            }
            else if(S.top()=='}'){
                close_brc++;
            }
            S.pop();
        }
        
        count = (open_brc+1)/2 + (close_brc+1)/2;

        return count;
}


int main(){

    string str1 = "{{{}";
    string str2 = "{{}{}}";
    string str3 = "{{{{";
    string str4 = "{}}{}}";

    cout << "The minimum cost is: " << minimum_bracket_reversal(str1) << endl;
    cout << "The minimum cost is: " << minimum_bracket_reversal(str2) << endl;
    cout << "The minimum cost is: " << minimum_bracket_reversal(str3) << endl;
    cout << "The minimum cost is: " << minimum_bracket_reversal(str4) << endl;

    return 0;
}