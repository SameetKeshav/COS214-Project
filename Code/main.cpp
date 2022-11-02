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
#include "Ambush.h"
#include "BattleField.h"
#include "Siege.h"
#include "Assassinate.h"
#include "Location.h"

//variables;
Kingdom* Dura;
Economy* DuraEco;
Kingdom* Preadora;
Economy* PreadoraEco;
bool attack = true;
Bannerman* enemy;
Bannerman* fighter;
string strategy;
Strategy* strat;


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

    Economy* DuraEco = new Economy(DuraState, DuraCurrency);
    Economy* PreadoraEco = new Economy(PreadoraState, PreadoraCurrency);

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

void chooseEnemy(){
    list<Bannerman*> PreadoraBannermen = Preadora->getKingdom();
    cout<<"Chose which enemy you would like to attack:"<<endl;
    
    for (int i=0; i<PreadoraBannermen.size(); i++){

        list<Bannerman*>::iterator it = PreadoraBannermen.begin();
        advance(it, i);
        Bannerman* curr = *it; //curr = bannerman

        cout<< i << ": " << curr->getName() <<endl;
        cout<<"HP: " << curr->getHP() <<endl;

        list<Bannerman*> PreadoraTroops = curr->getTroops();
        list<Bannerman*>::iterator a = PreadoraTroops.begin();
        list<Bannerman*>::iterator b = PreadoraTroops.begin();
        advance(b, 1);
        Bannerman* troop1 = *a;
        Bannerman* troop2 = *b;
        
        cout<<"HP of Squadren 1: " << troop1->getHP() <<endl;
        cout<<"HP of Squadren 2: " << troop2->getHP() <<endl;

        cout<<"Damage that this Bannerman can inflict: "<<curr->getDamage()<<endl<<endl;
    }
    int c;
    cin>>c;
    if (c > PreadoraBannermen.size() || c < 0){
        chooseEnemy();
    }

    list<Bannerman*>::iterator itr = PreadoraBannermen.begin();
    advance(itr, c-1);
    
    enemy = *itr;
}

void chooseFighter(){
    list<Bannerman*> DuraBannermen = Dura->getKingdom();
    cout<<"Chose which enemy you would like to attack:"<<endl;
    
    for (int i=0; i<DuraBannermen.size(); i++){

        list<Bannerman*>::iterator it = DuraBannermen.begin();
        advance(it, i);
        Bannerman* curr = *it; //curr = bannerman

        cout<< i << ": " << curr->getName() <<endl;
        cout<<"HP: " << curr->getHP() <<endl;

        list<Bannerman*> DuraTroops = curr->getTroops();
        list<Bannerman*>::iterator a = DuraTroops.begin();
        list<Bannerman*>::iterator b = DuraTroops.begin();
        advance(b, 1);
        Bannerman* troop1 = *a;
        Bannerman* troop2 = *b;
        
        cout<<"HP of Squadren 1: " << troop1->getHP() <<endl;
        cout<<"HP of Squadren 2: " << troop2->getHP() <<endl;

        cout<<"Damage that this Bannerman can inflict: "<<curr->getDamage()<<endl<<endl;
    }
    int c;
    cin>>c;
    if (c > DuraBannermen.size() || c < 0){
        chooseEnemy();
    }
    
    list<Bannerman*>::iterator itr = DuraBannermen.begin();
    advance(itr, c-1);
    
    enemy = *itr;
}

void goAttack(){
    int stealth;

    cout<<"Choose your strategy of attack: "<<endl;
    cout<<"1: Battle Field      2: Seige      3: Ambush      4: Send Assassin"<<endl;
    int b;
    cin>>b;

    switch (b)
    {
    case 1:
        strategy = " go to the Battle Field";
        strat = new BattleField(Dura, Preadora, fighter, enemy, "BattleField", 10, 5);
        break;

    case 2:
        strategy = " stage a Seige";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Siege(stealth, Dura, Preadora, fighter, enemy, "BattleField", 10, 5);
        break;

    case 3:
        strategy = " Ambush the enemy";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Ambush(stealth, Dura, Preadora, fighter, enemy, "BattleField", 10, 5);
        break;

    case 4:
        strategy = " send an Assassin";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Assassinate(stealth, true, Dura, Preadora, fighter, enemy, "BattleField", 10, 5);
        break;

    default:
        goAttack();
    }

    WarTheatre* loc = new Location();
    loc->sendScout();

}



void WarWon(){

}

void WarLost(){
    
}


void WarLoop(){
    while (attack){
        State* state = DuraEco->getState();
        if (state->getState() == "has failed" || PreadoraEco->getState()->getState() == "has failed"){
            attack = false;
            break;
        }
        cout<<"Here is the latest news from your council:"<<endl;
        cout<<"You have " << Dura->getSize() << "Bannermen standing at your side.";
        cout<<"The state of your economy " + state->getState() << " with the great banks valuing the kingdom's "<<endl;
        cout<<"riches at " << DuraEco->getCurrency() << " gold daras." << endl;
        cout<<"Do you wish to launch an attack on Preadora?(y/n)"<<endl;
        char choice;
        cin>>choice;
        if (choice == 'y'){
            chooseEnemy();
            chooseFighter();
            goAttack();
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
    if (PreadoraEco->getState()->getState() == "has failed"){
        WarWon();
    }else if (DuraEco->getState()->getState() == "has failed"){
        WarLost();
    }

}
/// @brief main functionality for simulation
/// @return no complications in compilation
int main(){

    intro();
    populateVectors();
    


    return 0;
}