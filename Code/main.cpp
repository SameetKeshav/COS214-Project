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
#include "Factory.h"
#include "FoodFac.h"
#include "MedicalFac.h"
#include "WeaponsFac.h"
#include "SupplyWagon.h"
#include "FoodWagon.h"
#include "MedicalWagon.h"
#include "WeaponWagon.h"
#include "Troop.h"

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
Treasury* tres;
Raven* myRaven;

//======================Unit testing===================================================
void DecoratorClientCode(WarTheatre* component) {
    component->sendScout();
}
void RoninUnitTesting(){
    Factory* myFactory1 = new FoodFac();
    Factory* myFactory2 = new MedicalFac();
    Factory* myFactory3 = new WeaponsFac();

    myFactory1->operation();
    myFactory2->operation();
    myFactory3->operation();

    SupplyWagon* OriginalFoodWagon = new FoodWagon();
    SupplyWagon* OriginalMedicalWagon = new MedicalWagon();
    SupplyWagon* OriginalWeaponWagon = new WeaponWagon();

    OriginalFoodWagon->setSup(myFactory1->getSupply());
    OriginalMedicalWagon->setSup(myFactory2->getSupply());
    OriginalWeaponWagon->setSup(myFactory3->getSupply());

    SupplyWagon* Foodwagons[5];
    SupplyWagon* Medicalwagons[5];
    SupplyWagon* Weaponwagons[5];

    for(int i =0; i<5;i++){
        Foodwagons[i]=OriginalFoodWagon->clone();
    }
    for(int i =0; i<5;i++){
        Medicalwagons[i]=OriginalMedicalWagon->clone();
    } for(int i =0; i<5;i++){
        Weaponwagons[i]=OriginalWeaponWagon->clone();
    }

    for(int i =0; i<5;i++){
        cout<<"Food Wagon "<<(i+1)<<": "<<Foodwagons[i]->getSupplies()->getAmount()<<endl;
    }
    for(int i =0; i<5;i++){
        cout<<"Medical Wagon "<<(i+1)<<": "<<Medicalwagons[i]->getSupplies()->getAmount()<<endl;
    } for(int i =0; i<5;i++){
        cout<<"Weapon Wagon "<<(i+1)<<": "<<Weaponwagons[i]->getSupplies()->getAmount()<<endl;
    }

    for(int i =0; i<5;i++){
        delete Foodwagons[i];
    }
    for(int i =0; i<5;i++){
        delete Medicalwagons[i];
    }
    for(int i =0; i<5;i++){
        delete Weaponwagons[i];
    }

    delete myFactory1;
    delete myFactory2;
    delete myFactory3;
}

void KeaUnitTesting(){
    srand(time(0));
    int stealth = 10 + (rand() % 100);

    Strategy* strat = new Ambush(stealth, Dura, Preadora, fighter, enemy, "Ambush", 10, 5, Greg, BookOfDura);


    cout << "------------ TESTING THE DECORATOR FUNCTIONALITY ------------" << endl;

    std::cout << "\n\nClient: I have a Default Theatre\n";
    WarTheatre* OriginalWarTheatre = new Location;
    OriginalWarTheatre->setVenue(OriginalWarTheatre->decideVenue(strat));
    DecoratorClientCode(OriginalWarTheatre);
    cout << "Default terrain difficulty: " << OriginalWarTheatre->getDifficulty() << endl;

    std::cout << "\n\nClient: Now I've got a Weather-Affected Theatre\n";
    WarTheatre* weatherEffect= new Weather(OriginalWarTheatre);
    weatherEffect->setDifficulty(OriginalWarTheatre->getDifficulty());
    DecoratorClientCode(weatherEffect);
    cout << "Adjusted Terrain Difficulty: " << weatherEffect->getDifficulty() << endl;

    std::cout << "\n\nClient: Now I've got a Topology-Affected Theatre\n";
    WarTheatre* topologyEffect = new Topology(weatherEffect);
    topologyEffect->setDifficulty(weatherEffect->getDifficulty());
    topologyEffect->setVenue(topologyEffect->decideVenue(strat));
    DecoratorClientCode(topologyEffect);
    cout << "Adjusted Terrain Difficulty: " << topologyEffect->getDifficulty() << endl;
    std::cout << "\n";

    delete OriginalWarTheatre;
    delete weatherEffect;
    delete topologyEffect;
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

    DuraEco = new Economy(DuraState, DuraCurrency);
    PreadoraEco = new Economy(PreadoraState, PreadoraCurrency);

    Dura = new Kingdom(DuraEco);
    Preadora = new Kingdom(PreadoraEco);

    Dura->add(new Commander("Stratham"));
    Dura->add(new Commander("Trudid"));
    Dura->add(new Commander("Mirefield"));
//    Dura->add(new Commander("Saker's Keep"));
//    Dura->add(new Commander("Breachmarsh"));

    Preadora->add(new Commander("Cirrane"));
    Preadora->add(new Commander("Bagger's Valley"));
    Preadora->add(new Commander("Marnmouth"));
//    Preadora->add(new Commander("Dry Gulch"));
//    Preadora->add(new Commander("Prin"));


}

/**
 * @brief text for if the user chooses to surrender
 */
void surrender(){
    cout<<"===================================================================="<<endl;
    cout<<"You have raised the white flag. Preadora is victorious."<<endl;
    cout<<"===================================================================="<<endl;
}

/**
 * @brief displays all enemy bannermen and lets the user choose which to fight
 */
void chooseEnemy(){
    cout<<"===================================================================="<<endl<<endl;
    list<Bannerman*> PreadoraBannermen = Preadora->getKingdom();
    cout<<"Chose which enemy you would like to attack:"<<endl<<endl;


    for (int i=0; i<PreadoraBannermen.size(); i++){

        list<Bannerman*>::iterator it = PreadoraBannermen.begin();
        advance(it, i);
        Bannerman* curr = *it; //curr = bannerman

        cout<< i << ": " << curr->getName() <<endl;
        cout<<"HP: " << curr->getHP() <<endl;

        list<Bannerman*> PreadoraTroops = curr->getTroops();

        cout<<"HP of Squadron 1: " << PreadoraTroops.front()->getHP() <<endl;
        cout<<"HP of Squadron 2: " << PreadoraTroops.back()->getHP() <<endl;

        cout<<"Damage that this Bannerman can inflict: "<<curr->getDamage()<<endl;
        cout<<"Allegiance that this bannerman has to the enemy: "<<curr->getFavour()<<"/10"<<endl<<endl;
    }
    cout<<"Name your chosen bannerman: ";
    int c;
    cin>>c;

    if (c > PreadoraBannermen.size()-1 || c < 0){
        chooseEnemy();
        return;
    }

    list<Bannerman*>::iterator itr = PreadoraBannermen.begin();
    advance(itr, c);
    cout<<"here"<<endl;
    enemy = *itr;
    cout<<"You chose to attack: "<<enemy->getName()<<endl;
}

/**
 * @brief displays all bannermen and lets the user choose which will fight
 */
void chooseFighter(){
    cout<<"===================================================================="<<endl<<endl;
    list<Bannerman*> DuraBannermen = Dura->getKingdom();
    cout<<"Chose which bannerman will fight for you:"<<endl;
    
    for (int i=0; i<DuraBannermen.size(); i++){

        list<Bannerman*>::iterator it = DuraBannermen.begin();
        advance(it, i);
        Bannerman* curr = *it; //curr = bannerman

        cout<< i << ": " << curr->getName() <<endl;
        cout<<"HP: " << curr->getHP() <<endl;

        list<Bannerman*> DuraTroops = curr->getTroops();

        cout<<"HP of Squadron 1: " << DuraTroops.front()->getHP() <<endl;
        cout<<"HP of Squadron 2: " << DuraTroops.back()->getHP() <<endl;

        cout<<"Damage that this Bannerman can inflict: "<<curr->getDamage()<<endl<<endl;
        cout<<"Allegiance that this bannerman has to you: "<<curr->getFavour()<<"/10"<<endl<<endl;
    }
    cout<<"Name your chosen bannerman: ";
    int c = 0;
    cin>>c;
    if (c > DuraBannermen.size()-1 || c < 0){
        chooseFighter();
        return;
    }


    list<Bannerman*>::iterator itr = DuraBannermen.begin();
    advance(itr, c);
    
    fighter = *itr;
    cout<<"You chose to have "<<fighter->getName()<<" as your fighter."<<endl;

    Factory* myFactory1 = new FoodFac();
    Factory* myFactory2 = new MedicalFac();
    Factory* myFactory3 = new WeaponsFac();

    myFactory1->operation();
    myFactory2->operation();
    myFactory3->operation();

    SupplyWagon* OriginalFoodWagon = new FoodWagon();
    SupplyWagon* OriginalMedicalWagon = new MedicalWagon();
    SupplyWagon* OriginalWeaponWagon = new WeaponWagon();

    OriginalFoodWagon->setSup(myFactory1->getSupply());
    OriginalMedicalWagon->setSup(myFactory2->getSupply());
    OriginalWeaponWagon->setSup(myFactory3->getSupply());

    SupplyWagon** supplies = new SupplyWagon * [3];
    supplies[0] = new FoodWagon();
    supplies[1] = new WeaponWagon();
    supplies[2] = new MedicalWagon();

    myRaven = new sendRaven(supplies, fighter);
}

/**
 * @brief helper code for creating the location/wartheater/topology objects
 */


/**
 * @brief lets the user choose the strategy and calls the attack method
 */
void goAttack(){
    int stealth;
    list<Bannerman*> DT = fighter->getTroops();
    bool alive = DT.front()->assassin;
    cout<<"===================================================================="<<endl<<endl;
    cout<<"Choose your strategy of attack: "<<endl;
    if (alive){
        cout<<"1: Battle Field      2: Siege      3: Ambush      4: Send Assassin"<<endl;
    }else{
        cout<<"1: Battle Field      2: Siege      3: Ambush"<<endl;
    }


    int b;
    cin>>b;

    switch (b)
    {
    case 1:
        strategy = " go to the Battle Field";
        strat = new BattleField(Dura, Preadora, fighter, enemy, "BattleField", 5, 5, Greg, BookOfDura);
        break;

    case 2:
        strategy = " stage a Seige";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Siege(stealth, Dura, Preadora, fighter, enemy, "Siege", 5, 5, Greg, BookOfDura);
        break;

    case 3:
        strategy = " Ambush the enemy";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Ambush(stealth, Dura, Preadora, fighter, enemy, "Ambush", 5, 5, Greg, BookOfDura);
        break;

    case 4:
        strategy = " send an Assassin";
        srand(time(0));
        stealth = 10 + (rand() % 100);
        strat = new Assassinate(stealth, true, Dura, Preadora, fighter, enemy, "Assassination", 10, 5, Greg, BookOfDura);
        DT.front()->assassin = false;
        DT.back()->assassin = false;
        break;

    default:
        goAttack();
    }
    cout<<"===================================================================="<<endl<<endl;
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

    tres = new MasterOfCoin(DuraEco, myRaven, strat);
//    WarIndicators* w = new WarIndicators(tres);
    fighter->attach(myRaven);
    fighter->setTreasury(tres);
    strat->setTreasury(tres);

    WarTheatre* OriginalWarTheatre = new Location;
    OriginalWarTheatre->setVenue(OriginalWarTheatre->decideVenue(strat));
    DecoratorClientCode(OriginalWarTheatre);

    WarTheatre* weatherEffect= new Weather(OriginalWarTheatre);
    weatherEffect->setDifficulty(OriginalWarTheatre->getDifficulty());
    DecoratorClientCode(weatherEffect);

    WarTheatre* topologyEffect = new Topology(weatherEffect);
    topologyEffect->setDifficulty(weatherEffect->getDifficulty());
    topologyEffect->setVenue(topologyEffect->decideVenue(strat));
    DecoratorClientCode(topologyEffect);
    strat->setTreasury(tres); //added by Morgan
    DuraEco->setTreasury(tres); //added by Morgan

    cout<<"===================================================================="<<endl<<endl;

    strat->attack(fighter, enemy);

}

/**
 * @brief text for if user won the war
 */
void WarWon(){
    cout<<"===================================================================="<<endl;
    cout<<"The enemy has been defeated! All the land under the Kingdoms of Preadora are now under your rule! Long live Dura!"<<endl;
    cout<<"===================================================================="<<endl;
}

/**
 * @brief text for if user lost the war
 */
void WarLost(){
    cout<<"===================================================================="<<endl;
    cout<<"Preadora's bannermen have overwhelmed your forces and have been crowned victorious after these long battles. Dura is under her rule."<<endl;
    cout<<"===================================================================="<<endl;
}

/**
 * @brief loop that checks the status of the battle, updates the user of the kingdom's state and initiates attacks
 */
void WarLoop(){
    while (attack){
        State* state = DuraState;
        if (DuraEco->getState()->getState() == "has failed" || PreadoraEco->getState()->getState() == "has failed"){
            attack = false;
        }
        if (Dura->getSize() <= 0 || Preadora->getSize() <= 0){
            attack = false;
        }
        cout<<"===================================================================="<<endl<<endl;
        cout<<"Here is the latest news from your council:"<<endl;
        cout<<"You have " << Dura->getSize() << " Bannermen standing at your side."<<endl;
        cout<<"The state of your economy " + DuraEco->getState()->getState() << " with the great banks valuing the kingdom's "<<endl;
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
            chooseEnemy();
            chooseFighter();
            goAttack();
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
                return;
            }
        }
    }
    if (PreadoraEco->getState()->getState() == "has failed" || Preadora->getSize() <= 0){
        WarWon();
    }else if (DuraEco->getState()->getState() == "has failed" || Dura->getSize() <= 0){
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