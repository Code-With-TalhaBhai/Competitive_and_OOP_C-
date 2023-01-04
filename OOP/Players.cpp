#include<iostream>
using namespace std;


class Player{
    public:
        static int player_no; // Static Property
        string name;
        int health;
        char level;
        bool alive;
        static string game_name;

    // Default Constructor   
    Player(){
        cout << "construcotr sowrkign";
            cout << endl;
    }


    // Paremetrized Constructor
    Player(string name,int health,char level,bool alive){
        this->name = name;
        this->health = health;
        this->level = level;
        this->alive = alive;
        player_no++;
    }

    // Copy Constructor
    // Player(Player& p){
    //     this->name = p.name;
    //     this->health = p.health;
    //     this->level = p.level;
    //     this->alive = p.alive;
    //     cout << "Copy Constructor Running" << endl;
    // }


    void print(){
        cout << "Player No: " << this->player_no << endl;
        cout << "Name: " << this->name << endl;
        cout << "Health: " << this->health << endl;
        cout << "Level: " << this->level << endl;
        cout << "Alive: " << this->alive << endl;
    }

    // Static Functions or Methods can only access Static Properties
    // Static doesn't use (this) keyword as it is pointer to objects attribute and Static has direct relation with Class
    int static getPlayerNo(){
        return player_no;
    };

    string static getGameName(){
        return game_name;
    }

    ~Player(){
        cout << "Destructure called finally" << endl;
    }

};
