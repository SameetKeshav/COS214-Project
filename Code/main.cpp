//functionality includes
#include <iostream>
#include <limits>
#include <vector>
// #include <dos.h>

using namespace std;

//file includes
#include "Historian.h" //originator, has memento includeded
#include "HistoryBook.h" //caretaker

//variables;
vector<Bannerman*> Bannermen;
vector<Bannerman*> EnemyBannermen;


/// @brief collapsable function for into text generation
void intro(){
    cout<<"A new dawn arrives and brings with it a red sky."<<endl;
    cout<<"You rule the great kingdom of Dura, which is in the midst of a great battle for the western"<<endl;
    cout<<"isles, the United Kingdoms of Preadora."<<endl;
    cout<<"press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout<<"┌┐ ┌─┐┌┬┐┌┬┐┬  ┌─┐  ┌─┐┌─┐┬─┐  ┌┬┐┬ ┬┌─┐"<<endl;
    cout<<"├┴┐├─┤ │  │ │  ├┤   ├┤ │ │├┬┘   │ ├─┤├┤ "<<endl;
    cout<<"└─┘┴ ┴ ┴  ┴ ┴─┘└─┘  └  └─┘┴└─   ┴ ┴ ┴└─┘"<<endl;

    cout<<"██     ██ ███████ ███████ ████████ ███████ ██████  ███    ██     ██ ███████ ██      ███████ ███████ "<<endl;
    // delay(2);
    cout<<"██     ██ ██      ██         ██    ██      ██   ██ ████   ██     ██ ██      ██      ██      ██      "<<endl;
    // delay(2);
    cout<<"██  █  ██ █████   ███████    ██    █████   ██████  ██ ██  ██     ██ ███████ ██      █████   ███████ "<<endl;
    // delay(2);
    cout<<"██ ███ ██ ██           ██    ██    ██      ██   ██ ██  ██ ██     ██      ██ ██      ██           ██ "<<endl;
    // delay(2);
    cout<<" ███ ███  ███████ ███████    ██    ███████ ██   ██ ██   ████     ██ ███████ ███████ ███████ ███████ "<<endl;


    cout<<"press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

/// @brief populating the vectors of our and the enemy bannermen
void populateVectors(){
    //need to give values and names in constructor
    Bannermen.push_back(new Bannerman());
    Bannermen.push_back(new Bannerman());
    Bannermen.push_back(new Bannerman());
    Bannermen.push_back(new Bannerman());
    Bannermen.push_back(new Bannerman());
    EnemyBannermen.push_back(new Bannerman());
    EnemyBannermen.push_back(new Bannerman());
    EnemyBannermen.push_back(new Bannerman());
    EnemyBannermen.push_back(new Bannerman());
    EnemyBannermen.push_back(new Bannerman());
}

/// @brief main functionality for simulation
/// @return no complications in compilation
int main(){

    intro();
    populateVectors();
    


    return 0;
}