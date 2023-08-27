#include<iostream>
// #include<ofstream> // Create and write file
// #include <ifstream> // Read File
#include<fstream> // Combination of read and write

using namespace std;

int main(){
    string my_text;
    // ifstream MyReadFile("file.txt");
    fstream readfile;
    readfile.read("Myfile.txt");

    while(getline (MyReadFile,my_text)){
        cout << my_text;
    }


    return 0;
}