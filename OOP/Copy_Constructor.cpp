#include <iostream>
#include "Players.cpp" // import export
using namespace std;

    int Player:: player_no; // VIP: Static Initialization should be outside of main() function
    string Player:: game_name = "TEkken 3";

int main(){

    Player p1("Paul",90,'H',true);
    cout << endl;
    // Can be accessed with objects but NOT RECOMMENDED
    cout << "Game Name is: " << p1.game_name << endl;
    // Recommended with Direct-Class Calling with SRO(Scope Resolution Operator)
    cout << "Game Name is: " << Player::game_name << endl;
    cout <<"Player No is: " << Player:: player_no << endl;
    cout << endl;
    // Other way
    cout << endl;
    cout << Player::getPlayerNo() << endl;
    cout << Player::getGameName() << endl;
    cout << endl;
    p1.print();
    cout << endl;

    Player c2("Bryan",23,'M',false);
    c2.print();


    // Copy Constructor -> Copy value of p1 to p2
    // Without Custom-Self Copy-Constructor, Default Copy Constructor runs and create Shallow Copy of Constructor

    Player p2(p1);
    p2.print();
    cout << endl;
    // p2.name = "Law";
    p2.health = 10;
    p2.print();
    cout << endl << endl;
    p1.print();

    // Custom-Self Copy Constructor creates Deep Copy
    // Player p3(p2);
    // p3.alive = 0;
    // p3.print();


    // Shallow Copy(Default-BuiltIn) ----> Creates copy with its pointers along with its memory addresses
    // Deep Copy(Custom-Self Constructor) -----> Creates copy of value inside constructor not its memory address

    return 0;
}