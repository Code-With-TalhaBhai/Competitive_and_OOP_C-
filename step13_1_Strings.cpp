#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    string str;
    string str1(5,'n');
    string str2 = "Talha bhai";
    cin >> str;
    cout << str << endl; // Without space printing input
    cout << str1 << endl;
    cout << str2 << endl;


    string gtr; 
    getline(cin,gtr);
    cout << gtr << endl; // With space printing


    // Append function
    string q = "fam";
    string w = "ily";

    q.append(w);
    // q.append("s");
    q.append(1,'s');
    cout << q << endl;


    // Concatenate without changing variable value
    string a = "MoM";
    string b = "Dad";
    cout << a + " & " + b + " both I Love You" << endl;


    // Particular character
    string t = "jfkdas";
    cout << t[5] << endl;


    // CLEAR function to clear all string
    string z = "fjkds sd afjskd fi dsf s";
    z.clear();
    cout << z << endl;

    // COMPARE function to compare two strings
    string q1 = "qwe";
    string q2 = "abc";
    string check = q2.compare(q1) > 0? "Letter is greater" : "Letter is smaller";
    cout << check<< endl;


    // EMPTY functions in string
    string r1 = "werre";
    r1.clear();

    if(r1.empty()){
        cout << "String is empty" << endl;
    }
    else{
        cout << "String is not empty" << endl;
    }
    cout << endl;


    //  ERASE function to erase characters from string
    string b1 = "Gooooooooooooooooooood Morning";
    b1.erase(3,18); // erase(starting index,number of elements)
    cout << b1 << endl;
    cout << endl;

    // FIND function to find characters in string
    string f1 = "checking";
    cout << f1.find("ing") << endl; // Returns index with first match charcter
    cout << endl;

    // INSERT function to insert characters between string and LENGTH function
    string ist = "TK";
    cout << ist.size() << endl;
    cout << ist.length() << endl; // size() and length() function are same;
    ist.insert(1,"alha ");
    ist.insert(7,"halid ");
    cout << ist << endl;
    cout << ist.length() << endl;
    cout << endl;


    // SUBSTR() function to get substr of string;
    string g3 = "Good AfterNoon";
    cout << g3.substr(1) << endl; // Starting after 1 element to the rest
    cout << g3.substr(5,5) << endl; // substr(index,no. of elements)
    cout << g3.substr(5,g3.length()-5) << endl; // substr(index,no. of elements)
    cout << endl;

    // STOI() function to convert string to number
    string y4 = "5223";
    int x = stoi(y4);
    cout << x << " " << x+5 << endl;
    cout << endl;


    // TO_STRING() function to convert int to string;
    int wer = 523;
    cout << to_string(wer) + "4" << endl; // Not adding concatenating
    cout << endl;


    // SORT() function to sort string (NOTE: Must include header file <algorithm>)
    string az1 = "jskafweriocxwerjkniveaqzpksdnvir";
    sort(az1.begin(),az1.end()); // Sort original variable 
    cout << az1 << endl; // begin and end are starting and ending index of string
    cout << endl;

    return 0;
}