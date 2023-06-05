#include <iostream>
#include<array>
#include<vector>
using namespace std;


int main(){

    // STL --> ARRAY
    // cout << "Array Starting" << endl;
    // array<int,4> arr = {1,2,3,4};

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << endl;
    // }

    // cout << endl;

    // cout << "Size: " << arr.size() << endl; // size
    // cout << "Empty: " << arr.empty() << endl; // checking whether arr empty or not
    // cout << "First element: " << arr.front() << endl; // Getting first element
    // cout << "Last element: " << arr.back() << endl; // Getting last element

    // cout << "Array ending;" << endl << endl;


    // STL ---> VECTOR
    cout << "Vector starting" << endl;

    vector<int> v;

    cout << "Capacity of vector is: " << v.capacity() << endl;
    cout << "Size of vector is: " << v.size() << endl;

    // For adding element in vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(int i:v){ //iterate through vector
        cout << i << " ";
    }
    cout << endl;

    cout << "Getting first element: " << v.front() << endl; 
    cout << "Getting last element: " << v.back() << endl;

    cout << "Element at 2 index: " << v.at(2) << endl;
    cout << "Size of vector is: " << v.size() << endl;
    cout << "Capacity of vector is: " << v.capacity() << endl;


    v.push_back(5);
    v.push_back(6);

    cout << "Before vector pop" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    
    cout << "Size of vector before clear is: " << v.size() << endl;
    v.clear();
    cout << "Size of vector after clear is: " << v.size() << endl;
    cout << "Next vector starting" << endl;

    // Next Vector
    vector <int> v1(5,3); //Vector with 5 elements and all are initialized with 3
    for(int i:v1){
        cout << i << " ";
    }
    cout << endl;

    // Copying vector
    vector <int> v2(v1);
    for(int i:v2){
        cout << i << " ";
    }
    cout << endl;


}