/** @brief The main text-based interface for the application
 * @author Julianna Venter
 * @date November 2022
 * TO-DO:
 * 1. Filler text in other classes for story-building (Done for now)
 * 2. Final debug-run
 * 3. deleting dynamic objects + text for that (Done)
 * 4. unit testing
 */


//functionality includes
#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <stdio.h>


using namespace std;

//file includes
#include "Historian.h" //originator, has memento included
#include "HistoryBook.h" //caretaker
#include "Kingdom.h"
#include "Economy.h"
#include "HealthyState.h"
#include "FailedState.h"
#include "UnstableState.h"
#include "Commander.h"
#include "Ambush.h"
#include "BattleField.h"
#include "Siege.h"
#include "Assassinate.h"
#include "Location.h"
#include "Weather.h"
#include "Topology.h"
#include "MasterOfCoin.h"
#include "sendRaven.h"

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
State* DuraState;
State* PreadoraState;
WarIndicators* warind = new WarIndicators();
Historian* Greg = new Historian();
HistoryBook* BookOfDura = new HistoryBook();
Treasury* t;
Raven* r;

//======================Unit testing===================================================

void RoninUnitTesting(){

}

void KeaUnitTesting(){

}

void SameetUnitTesting(){

}

void ThapeloUnitTesting(){

}

void MorganUnitTesting(){

}

void JuliannaUnitTesting(){

}


//=========================================================================================



/**
 * @brief the text introduction to the simulator's story
 */
void intro(){
    cout<<"A new dawn arrives and brings with it a red sky."<<endl;
    cout<<"You rule the great kingdom of Dura, which is in the midst of a great battle for the western"<<endl;
    cout<<"isles, the United Kingdoms of Preadora."<<endl;
    // cout<<"press Enter to continue...";
    // cin.ignore(numeric_limits<streamsize>::max(),'\n');

//    cout<<"┌┐ ┌─┐┌┬┐┌┬┐┬  ┌─┐  ┌─┐┌─┐┬─┐  ┌┬┐┬ ┬┌─┐"<<endl;
//    cout<<"├┴┐├─┤ │  │ │  ├┤   ├┤ │ │├┬┘   │ ├─┤├┤ "<<endl;
//    cout<<"└─┘┴ ┴ ┴  ┴ ┴─┘└─┘  └  └─┘┴└─   ┴ ┴ ┴└─┘"<<endl;
//
//    cout<<"██     ██ ███████ ███████ ████████ ███████ ██████  ███    ██     ██ ███████ ██      ███████ ███████ "<<endl;
////     delay(2);
//    cout<<"██     ██ ██      ██         ██    ██      ██   ██ ████   ██     ██ ██      ██      ██      ██      "<<endl;
//    // delay(2);
//    cout<<"██  █  ██ █████   ███████    ██    █████   ██████  ██ ██  ██     ██ ███████ ██      █████   ███████ "<<endl;
//    // delay(2);
//    cout<<"██ ███ ██ ██           ██    ██    ██      ██   ██ ██  ██ ██     ██      ██ ██      ██           ██ "<<endl;
//    // delay(2);
//    cout<<" ███ ███  ███████ ███████    ██    ███████ ██   ██ ██   ████     ██ ███████ ███████ ███████ ███████ "<<endl;


//     cout<<"press Enter to continue...";
//     cin.ignore(numeric_limits<streamsize>::max(),'\n');
}


/**
 * @brief creating the state, economy, kingdom and bannerman objects
 */
void populateVectors(){
    DuraState = new HealthyState();
    PreadoraState = new HealthyState();

    srand(time(0));
    int DuraCurrency = 100;
    srand(time(0));
    int PreadoraCurrency = 100;

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

/**
 * @brief text for if the user chooses to surrender
 */
void surrender(){
    cout<<"You have raised the white flag. Preadora is victorious."<<endl;
}

/**
 * @brief displays all enemy bannermen and lets the user choose which to fight
 */
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
    cout<<"chooseEnemy success"<<endl;
}

/**
 * @brief displays all bannermen and lets the user choose which will fight
 */
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
    cout<<"chooseFighter success"<<endl;
}

/**
 * @brief helper code for creating the location/wartheater/topology objects
 */
void DecoratorClientCode(WarTheatre* component) {
  component->sendScout();
}

/**
 * @brief lets the user choose the strategy and calls the attack method
 */
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
        strat = new BattleField(Dura, Preadora, fighter, enemy, "BattleField", 10, 5, Greg, BookOfDura);
        break;

    case 2:
        strategy = " stage a Seige";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Siege(stealth, Dura, Preadora, fighter, enemy, "BattleField", 10, 5, Greg, BookOfDura);
        break;

    case 3:
        strategy = " Ambush the enemy";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Ambush(stealth, Dura, Preadora, fighter, enemy, "BattleField", 10, 5, Greg, BookOfDura);
        break;

    case 4:
        strategy = " send an Assassin";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Assassinate(stealth, true, Dura, Preadora, fighter, enemy, "BattleField", 10, 5, Greg, BookOfDura);
        break;

    default:
        goAttack();
    }

    //send scout
    cout<<"A scout has been sent to the enemies location. We await news."<<endl;
//    delay(1);
    cout<<".";
//    delay(1);
    cout<<".";
//    delay(1);
    cout<<"."<<endl;
//    delay(1);
    cout<<"A raven from the scout has returned! Here is the news: "<<endl;


    WarTheatre* OriginalWarTheatre = new Location();
    OriginalWarTheatre->decideVenue(strat);
    DecoratorClientCode(OriginalWarTheatre);
    WarTheatre* weatherEffect= new Weather(OriginalWarTheatre);
    DecoratorClientCode(weatherEffect);
    WarTheatre* topologyEffect = new Topology(weatherEffect);
    DecoratorClientCode(topologyEffect);
 
    strat->attack(fighter, enemy);

}

/**
 * @brief text for if user won the war
 */
void WarWon(){
    cout<<"The enemy has been defeated! All the land under the Kingdoms of Preadora are now under your rule! Long live Dura!"<<endl;
}

/**
 * @brief text for if user lost the war
 */
void WarLost(){
    cout<<"Preadora's bannermen have overwhelmed your forces and have been crowned victorious after these long battles. Dura is under her rule."<<endl;
}

/**
 * @brief loop that checks the status of the battle, updates the user of the kingdom's state and initiates attacks
 */
void WarLoop(){
    while (attack){
        State* state = DuraState;
        if (state->getState() == "has failed" || PreadoraState->getState() == "has failed"){
            attack = false;
        }
        if (Dura->getSize() <= 0 || Preadora->getSize() <= 0){
            attack = false;
        }
        cout<<"Here is the latest news from your council:"<<endl;
        cout<<"You have " << Dura->getSize() << " Bannermen standing at your side."<<endl;
        cout<<"The state of your economy " + state->getState() << " with the great banks valuing the kingdom's "<<endl;
        cout<<"riches at " << DuraEco->getCurrency() << " gold daras." << endl; //stops working at currency

        if (attack == false){
            cout<<"The long battle has ended."<<endl;
            break;
        }else{
            cout<<"Do you wish to launch an attack on Preadora?(y/n)"<<endl;
        }
        
        char choice;
        cin>>choice;
        if (choice == 'y'){
//            chooseEnemy();
//            chooseFighter();
//            goAttack();
             cout<<"WarLoop successful"<<endl;
             attack = false;
        }if (choice == 'n'){
            cout<<"By choosing not to attack Preadora you will have to raise the white flag of surender."<<endl<<"Do you agree?(y/n)"<<endl;
            char surr;
            cin>>surr;
            if (surr == 'y'){
                surrender();
                attack = false;
                break;
            }
            if (surr == 'n'){
                WarLoop();
            }
        }
    }
    if (PreadoraState->getState() == "has failed" || Preadora->getSize() <= 0){
        WarWon();
    }else if (DuraState->getState() == "has failed" || Dura->getSize() <= 0){
        WarLost();
    }

}

/**
 * @brief main function, calls other functions
 * @return no compilation errors
 */
int main(){

    intro();
    populateVectors();
    WarLoop();

//    RoninUnitTesting();
//    KeaUnitTesting();
//    SameetUnitTesting();
//    ThapeloUnitTesting();
//    MorganUnitTesting();
//    JuliannaUnitTesting();

    //deletes
//    delete Dura;
//    delete DuraEco;
//    delete Preadora;
//    delete PreadoraEco;
//    delete enemy;
//    delete fighter;
//    delete strat;
//    delete DuraState;
//    delete PreadoraState;
//    delete warind;
//    delete Greg;
//    delete BookOfDura;
//    delete t;
//    delete r;

    return 0;
}