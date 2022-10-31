//functionality includes
#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
// #include <dos.h>

using namespace std;

//file includes
#include "Historian.h" //originator, has memento includeded
#include "HistoryBook.h" //caretaker
#include "Kingdom.h"
#include "Economy.h"
#include "HealthyState.h"
#include "FailedState.h"
#include "UnstableState.h"
#include "Commander.h"
#include "Troop.h"
<<<<<<< Updated upstream
=======
#include "Ambush.h"
#include "BattleField.h"
#include "Siege.h"
#include "Assassinate.h"
#include "Location.h"
>>>>>>> Stashed changes

//variables;
Kingdom* Dura;
Economy* DuraEco;
Kingdom* Preadora;
Economy* PreadoraEco;
bool attack = true;
<<<<<<< Updated upstream
=======
Bannerman* enemy;
Bannerman* fighter;
string strategy;
Strategy* strat;
>>>>>>> Stashed changes


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
    State* DuraState = new HealthyState();
    State* PreadoraState = new HealthyState();

    srand(time(0));
    int DuraCurrency = 10000000 + (rand() % 1000000000);
    srand(time(0));
    int PreadoraCurrency = 10000000 + (rand() % 1000000000);

    DuraEco = new Economy(DuraState, DuraCurrency);
    PreadoraEco = new Economy(PreadoraState, PreadoraCurrency);

    Dura = new Kingdom(DuraEco);
    Preadora = new Kingdom(PreadoraEco);
    
    Dura->add(new Commander("Stratham"));
    Dura->add(new Commander("Trudid"));
    Dura->add(new Commander("Mirefield"));
    Dura->add(new Commander("Saker's Keep"));
    Dura->add(new Commander("Breachmarsh"));

    Preadora->add(new Commander("Cirrane"));
    Preadora->add(new Commander("Bagger's Valley"));
    Preadora->add(new Commander("Marnmouth"));
    Preadora->add(new Commander("Dry Gulch"));
    Preadora->add(new Commander("Prin"));

}

void surrender(){
    cout<<"You have raised the white flag. Preadora is victorious."<<endl;
}

<<<<<<< Updated upstream
=======
void chooseEnemy(){
    vector<Bannerman*> PreadoraBannermen = Preadora->getKingdom();
    cout<<"Chose which enemy you would like to attack:"<<endl;
    for (int i=0; i<PreadoraBannermen.size(); i++){
        cout<< i + ": " + PreadoraBannermen[i]->getName()<<endl;
        cout<<"HP: " + PreadoraBannermen[i]->getHP()<<endl;
        vector<Bannerman*> PreadoraTroops = PreadoraBannermen[i]->getTroops();
        cout<<"HP of Squadren 1: " + PreadoraTroops[0]->getHP()<<endl;
        cout<<"HP of Squadren 2: " + PreadoraTroops[1]->getHP()<<endl;
        cout<<"Damage that this Bannerman can inflict: "<<PreadoraBannermen[i]->getDamage()<<endl<<endl;
    }
    int c;
    cin>>c;
    if (c > PreadoraBannermen.size() || c < 0){
        chooseEnemy();
    }
    enemy = PreadoraBannermen[c];
}

void chooseFighter(){
    vector<Bannerman*> DuraBannermen = Dura->getKingdom();
    cout<<"Chose your fighter"<<endl;
    for (int i=0; i<DuraBannermen.size(); i++){
        cout<< i + ": " + DuraBannermen[i]->getName()<<endl;
        cout<<"HP: " + DuraBannermen[i]->getHP<<endl;
        vector<Bannerman*> DuraTroops = DuraBannermen[i].getTroops();
        cout<<"HP of Squadren 1: " + DuraTroops[0]->getHP()<<endl;
        cout<<"HP of Squadren 2: " + DuraTroops[1]->getHP()<<endl;
        cout<<"Damage that this Bannerman can inflict: "<<DuraBannermen[i]->getDamage()<<endl<<endl;
    }
    int a;
    cin>>a;
    if (a > DuraBannermen.size() || a < 0){
        chooseFighter();
    }
    fighter = DuraBannermen[a];
}



void goAttack(){
    cout<<"Choose your strategy of attack: "<<endl;
    cout<<"1: Battle Field      2: Seige      3: Ambush      4: Send Assassin"<<endl;
    int b;
    cin>>b;

    switch (b)
    {
    case 1:
        strategy = " go to the Battle Field";
        strat = new BattleField(10, 5);
        break;

    case 2:
        strategy = " stage a Seige";
        srand(time(0));
        int stealth = 10 + (rand() % 100);
        strat = new Siege(stealth, 10, 5);
        break;

    case 3:
        strategy = " Ambush the enemy";
        srand(time(0));
        int stealth = 10 + (rand() % 100);
        strat = new Ambush(stealth, 10, 5);
        break;

    case 4:
        strategy = " send an Assassin";
        srand(time(0));
        int stealth = 10 + (rand() % 100);
        strat = new Assassinate(stealth, true, 10, 5);
        break;

    default:
        goAttack();
    }

    WarTheatre* loc = new Location();
    loc->sendScout();

}

>>>>>>> Stashed changes
void WarLoop(){
    while (attack){
        cout<<"Here is the latest news from your council:"<<endl;
        cout<<"You have " + Dura->getSize() + "Bannermen standing at your side.";
        State* state = DuraEco->getState();
        cout<<"The state of your economy " + state->getState() << "with the great banks valuing the kingdom's"<,endl;
        cout<<"riches at " + DuraEco->getCurrency() + " gold daras." << endl;
        cout<<"Do you wish to launch an attack on Preadora?(y/n)"<<endl;
        char choice;
        cin>>choice;
        if (choice == 'y'){
<<<<<<< Updated upstream

=======
            chooseEnemy();
            chooseFighter();
            goAttack();
>>>>>>> Stashed changes
        }if (choice == 'n'){
            cout<<"By choosing not to attack Preadora you will have to raise the white flag of surender."<<endl<<"Do you agree?(y/n)"<<endl;
            char surr;
            cin>>surr;
            if (surr == 'y'){
                surrender();
            }
            if (surr == 'n'){
                WarLoop();
            }
        }
    }
}

/// @brief main functionality for simulation
/// @return no complications in compilation
int main(){

<<<<<<< Updated upstream
    intro();
    populateVectors();
    WarLoop();

=======
    // intro();
    // populateVectors();
    // WarLoop();
    cout<<"success"<<endl;
>>>>>>> Stashed changes

    return 0;
}