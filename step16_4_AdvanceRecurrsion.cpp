#include <iostream>
using namespace std;

void recurrsion1(string str,string ans){
    if(str.length() == 0){
        // cout << endl;
        cout << ans << endl;
        // cout << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        // cout << str << endl;
        // cout << ans << endl;
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        // cout << i << ". " << "\"" << ch << "\"" << " " << "\"" << ros << "\"" << endl;
        // cout << ans << endl;
        // cout << ans+ch << endl;
        recurrsion1(ros,ans+ch);
    }
}

int recurrsion2(int start,int end){
    // cout << start << " " << end << endl;
    if(start == end){
        return 1;
    }
    if(start > end){
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += recurrsion2(start+i,end);
    }
    
    return count;
}



void solve1(){
    string str = "ABC";
    recurrsion1(str,"");
}


int solve2(){
    int startPt,endPt;
    cin >> startPt >> endPt;

    return recurrsion2(startPt,endPt);
}


int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        // solve1();
        // cout << endl;

        cout << "Case #" << i << ": " << solve2() << endl;
    }

    return 0;
}