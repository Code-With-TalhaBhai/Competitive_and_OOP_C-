#include <iostream>
#include<string>
using namespace std;


string recurrsion1(string str,int start,int end,int len){

    // 1st Method
    if(start == len/2){
        return str;
    }

    char tmp;
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;

    return recurrsion1(str,start+1,end-1,len);
}


string recurrsion2(string str,int index){

    index = str.find("pi");
    if(index == -1){
        return str;
    }

    str.erase(index,2);
    str.insert(index,"3.14"); 


    return recurrsion2(str,index+4);
}


string recurrsion4(string str,int start,int end,int length){

    if(start-1 == length){
        return str;
    }

    end = str.find(str[start],end);
    if(end == -1){
        start++;
        end = start+1;
    }
    else{
        str.erase(end,1);
    }
    return recurrsion4(str,start,end,str.length());
}

string recurrsion5(string str,int index,int len,int count){
    if(index == len){
        for (int i = 0; i < count; i++)
        {
            str.append("x");
        } 
        return str;
    }

    if(str[index] == 'x' || str[index] == 'X'){
        str.erase(index,1);
        count++;
    }
    else{
       index++;
    }

    return recurrsion5(str,index,len,count);

}

// (abc)
// a
// b
// c
// a b
// b c
// a c
// a b c
void recurrsion6(string str,string ans){
    if(str.length() == 0){
        cout << ans << endl;
        return ;
    }


    char ch = str[0];
    string ros = str.substr(1); // Return whole string after 1 element

    recurrsion6(ros,ans);
    recurrsion6(ros,ans+ch);
}



void combinations(string str1,string str2,int idx1,int idx2){
    cout << str1[idx1] << str2[idx2] << endl;

    if(idx2 == str2.length()-1){
        if((idx1 == str1.length()-1)){
            return;
        }
        idx1++;
        idx2 = 0;
    }
    else{
        idx2++;
    }

        combinations(str1,str2,idx1,idx2);

}


// Print all possible words from phone digits
void recurrsion7(string str){
string keypad[] = {"","./","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string str1 = keypad[(str[0]-'0')];
    string str2 = keypad[(str[1]-'0')];

    combinations(str1,str2,0,0);

}

// Reverse String using recurrsion
string solve1(){
    int start = 0;
    string str;
    cin >> str;
    int len = str.length();
    return recurrsion1(str,start,len-1,len);
}

// Replace pi with 3.14
string solve2(){
    int index = 0;
    string str = "pippxxppiixipi";
    return recurrsion2(str,index);
}


// Remove Duplicate characters from string (e.g "aaaabbbeeecdddd" to "abecd")
string solve4(){
    int startIndex = 0;
    int endIndex = 1;
    string str;
    cin >> str;
    return recurrsion4(str,startIndex,endIndex,str.length());
}

// Put all x at the end of string
string solve5(){
    int iter = 1;
    int startIndex = 0;
    // string str = "axxbdxxcefxhix";
    string str;
    cin >> str;
    int len = str.length();
    return recurrsion5(str,startIndex,len,0);
}

// Put all substring of strings
void solve6(){
    string str;
    cin >> str;
    recurrsion6(str,"");
}

void solve7(){
    string str;
    cin >> str;
    recurrsion7(str);
}


int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": " << solve1() << endl;
        // cout << "Case #" << i << ": " << solve2() << endl;
        // cout << "Case #" << i << ": " << solve4() << endl;
        // cout << "Case #" << i << ": " << solve5() << endl;
        cout << "Case #" << i << ": ";
        //  solve6();
         solve7();
         cout << endl;
    }

    return 0;
}