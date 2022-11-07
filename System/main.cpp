
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
    cout << "TESTING OBSERVER" << endl << endl;

    SupplyWagon** supps = new SupplyWagon * [3];
    supps[0] = new FoodWagon();
    supps[1] = new WeaponWagon();
    supps[2] = new MedicalWagon();

    Bannerman* b = new Commander("Sameet");

    Raven* raven = new sendRaven(supps, b);
    b->setWeapons(5);
    b->setMedical(5);
    b->setFood(5);
    cout << "Amount of Weapons Before: " << b->getWeapons() << endl;
    cout << "Amount of Food Before: " << b->getFood() << endl;
    cout << "Amount of Medical Before: " << b->getMedical() << endl << endl;
    cout << "Calling Update: " << endl << endl;
    raven->update();
    cout << "Amount of Weapons - Expected: 100, Actual: " << b->getWeapons() << endl;
    cout << "Amount of Food - Expected: 100, Actual: " << b->getFood() << endl;
    cout << "Amount of Medical - Expected: 100, Actual: " << b->getMedical() << endl;
}

void ThapeloUnitTesting(){

}

void MorganUnitTesting(){
    int goodStealth=85;
    int badStealth=25;
    int hcurrency=100,ucurrency=55,fcurrency=-1;
    
    State* TestHealthyState=new HealthyState();
    State* TestUnstableState=new UnstableState();
    State* TestFailedState=new FailedState();
    Treasury* externTres1=new MasterOfCoin(nullptr, nullptr, nullptr);
    Treasury* externTres2=new MasterOfCoin(nullptr, nullptr, nullptr);
    Treasury* externTres3=new MasterOfCoin(nullptr, nullptr, nullptr);
    Economy* TestHealthyEco = new Economy(TestHealthyState,hcurrency);
    TestHealthyEco->setTreasury(externTres1);
    Economy* TestUnstableEco = new Economy(TestUnstableState,ucurrency);
    TestUnstableEco->setTreasury(externTres2);
    Economy* TestFailedEco = new Economy(TestFailedState,fcurrency);
    TestFailedEco->setTreasury(externTres3);
    cout<<"========================================TEST FOR STATE PATTERN======================================="<<endl;
    cout<<"HealthyEconomy getState() should return \"is healthy\": "<<TestHealthyEco->getState()->getState()<<endl;
    cout<<"UnstableEconomy getState() should return \"is unstable\": "<<TestUnstableEco->getState()->getState()<<endl;
    cout<<"FailedEconomy getState() should return \"has failed\": "<<TestFailedEco->getState()->getState()<<endl<<endl;

    TestHealthyEco->removeCurrency(2);
    cout<<"HealthyEconomy removeCurrency(2) should have just reduced currency by 2 so getcurrency() should return 98 : "<<TestHealthyEco->getCurrency()<<endl;
    TestUnstableEco->removeCurrency(2);
    cout<<"UnstableEconomy removeCurrency(2) should have just reduced currency by 2 so getcurrency() should return 53 : "<<TestUnstableEco->getCurrency()<<endl;
    TestFailedEco->removeCurrency(2);
    cout<<"FailedEconomy removeCurrency(2) should have just reduced currency by 2 so getcurrency() should return -3 : "<<TestFailedEco->getCurrency()<<endl<<endl;

    TestHealthyEco->decreaseCurrency();
    cout<<"HealthyEconomy decreaseCurrency() should decrease currency to 73: "<<TestHealthyEco->getCurrency()<<", and state should still return \"is healthy\":"<<TestHealthyEco->getState()->getState()<<endl;
    TestHealthyEco->decreaseCurrency();
    cout<<"HealthyEconomy decreaseCurrency() should decrease currency to 48: "<<TestHealthyEco->getCurrency()<<", and state should return \"is unstable\" if SetState() works:"<<TestHealthyEco->getState()->getState()<<endl;
    TestUnstableEco->decreaseCurrency();
    cout<<"UnstableEconomy decreaseCurrency() should decrease currency to 18: "<<TestUnstableEco->getCurrency()<<", and state should still return \"is unstable\":"<<TestUnstableEco->getState()->getState()<<endl;
    TestUnstableEco->decreaseCurrency();
    cout<<"UnstableEconomy decreaseCurrency() should decrease currency to -17: "<<TestUnstableEco->getCurrency()<<", and state should print out \"State is bankrupt, cannot decrease currency\":"<<TestUnstableEco->getState()->getState()<<endl;
    TestUnstableEco->decreaseCurrency();
    cout<<"FailedEconomy decreaseCurrency() should print out \"State is bankrupt, cannot decrease currency\": "<<TestFailedEco->getCurrency()<<endl<<endl;


    delete TestHealthyEco;
    TestHealthyEco = new Economy(TestHealthyState,hcurrency);
    TestHealthyEco->setTreasury(externTres1);
    TestHealthyEco->SetState();
    cout<<"HealthyEconomy SetState() should change state to a lower state \"UnstableState\" or return a \"nullpointer\" string: "<<TestHealthyEco->getState()->getState()<<endl;
    delete TestUnstableEco;
    TestUnstableEco = new Economy(TestUnstableState,ucurrency);
    TestUnstableEco->setTreasury(externTres2);
    TestUnstableEco->SetState();
    cout<<"UnstableEconomy SetState() should change state to a lower state \"FailedState\" or return a \"nullpointer\" string: "<<TestUnstableEco->getState()->getState()<<endl;
    delete TestFailedEco;
    TestFailedState=new FailedState();
    TestFailedEco = new Economy(TestFailedState,fcurrency);
    TestFailedEco->setTreasury(externTres3);
    TestFailedEco->SetState();
    cout<<"FailedEconomy SetState() should change state to a lower state or return a \"nullpointer\" string: "<<TestFailedEco->getState()<<endl<<endl;

    delete TestHealthyState;
    delete TestUnstableState;
    delete TestFailedState;
    delete TestHealthyEco;
    delete TestUnstableEco;
    delete TestFailedEco;
    cout<<"========================================TEST FOR STRATEGY PATTERN======================================="<<endl;

    TestHealthyState=new HealthyState();
    TestHealthyEco = new Economy(TestHealthyState,hcurrency);
    State* eTestHealthyState=new HealthyState();
    Economy* eTestHealthyEco = new Economy(eTestHealthyState,hcurrency);
    Bannerman* externfighter1=new Commander("externCommander1");
    Bannerman* externfighter2=new Commander("externCommander2");
    Kingdom* externKingdom1=new Kingdom(TestHealthyEco);
    Kingdom* externKingdom2=new Kingdom(eTestHealthyEco);
    externKingdom1->add(externfighter1);
    externKingdom2->add(externfighter2);

    State* TestHealthyState1=new HealthyState();
    Economy* TestHealthyEco1 = new Economy(TestHealthyState1,hcurrency);
    State* eTestHealthyState1=new HealthyState();
    Economy* eTestHealthyEco1 = new Economy(eTestHealthyState1,hcurrency);
    Bannerman* externfighter11=new Commander("externCommander11");
    Bannerman* externfighter21=new Commander("externCommander21");
    Kingdom* externKingdom11=new Kingdom(TestHealthyEco1);
    Kingdom* externKingdom21=new Kingdom(eTestHealthyEco1);
    externKingdom11->add(externfighter11);
    externKingdom21->add(externfighter21);

    State* TestHealthyState2=new HealthyState();
    Economy* TestHealthyEco2 = new Economy(TestHealthyState2,hcurrency);
    State* eTestHealthyState2=new HealthyState();
    Economy* eTestHealthyEco2 = new Economy(eTestHealthyState2,hcurrency);
    Bannerman* externfighter12=new Commander("externCommander12");
    Bannerman* externfighter22=new Commander("externCommander22");
    Kingdom* externKingdom12=new Kingdom(TestHealthyEco2);
    Kingdom* externKingdom22=new Kingdom(eTestHealthyEco2);
    externKingdom12->add(externfighter12);
    externKingdom22->add(externfighter22);

    State* TestHealthyState3=new HealthyState();
    Economy* TestHealthyEco3 = new Economy(TestHealthyState3,hcurrency);
    State* eTestHealthyState3=new HealthyState();
    Economy* eTestHealthyEco3 = new Economy(eTestHealthyState3,hcurrency);
    Bannerman* externfighter13=new Commander("externCommander13");
    Bannerman* externfighter23=new Commander("externCommander23");
    Kingdom* externKingdom13=new Kingdom(TestHealthyEco3);
    Kingdom* externKingdom23=new Kingdom(eTestHealthyEco3);
    externKingdom13->add(externfighter13);
    externKingdom23->add(externfighter23);
    
    SupplyWagon** externsupplies = new SupplyWagon * [3];
    externsupplies[0] = new FoodWagon();
    externsupplies[1] = new WeaponWagon();
    externsupplies[2] = new MedicalWagon();

    Raven* externRaven = new sendRaven(externsupplies, externfighter1);
    externfighter1->attach(externRaven);
    Raven* externRaven1 = new sendRaven(externsupplies, externfighter11);
    externfighter11->attach(externRaven1);
    Raven* externRaven2 = new sendRaven(externsupplies, externfighter12);
    externfighter12->attach(externRaven2);
    Raven* externRaven3 = new sendRaven(externsupplies, externfighter13);
    externfighter13->attach(externRaven3);

    Strategy* TestAmbushStrategy=new Ambush(goodStealth, externKingdom1, externKingdom2, externfighter1, externfighter2, "Ambush", 10, 5, Greg, BookOfDura);
    Strategy* TestBattleFieldStrategy=new BattleField(externKingdom11, externKingdom21, externfighter11, externfighter21, "Battlefield", 5, 5, Greg, BookOfDura);
    Strategy* TestSiegeStrategy=new Siege(goodStealth, externKingdom12, externKingdom22, externfighter12, externfighter22, "Siege", 5, 5, Greg, BookOfDura);
    Strategy* TestAssassinStrategy=new Assassinate(goodStealth, true, externKingdom13, externKingdom23, externfighter13, externfighter23, "Assassinate", 5, 5, Greg, BookOfDura);
    Treasury* externTres=new MasterOfCoin(TestHealthyEco, externRaven, TestAmbushStrategy);
    TestHealthyEco->setTreasury(externTres);
    externTres1=new MasterOfCoin(TestHealthyEco1, externRaven1, TestBattleFieldStrategy);
    TestHealthyEco1->setTreasury(externTres1);
    externTres2=new MasterOfCoin(TestHealthyEco2, externRaven2, TestSiegeStrategy);
    TestHealthyEco2->setTreasury(externTres2);
    externTres3=new MasterOfCoin(TestHealthyEco3, externRaven3, TestAssassinStrategy);
    TestHealthyEco3->setTreasury(externTres3);

    TestAmbushStrategy->setTreasury(externTres);
    TestBattleFieldStrategy->setTreasury(externTres1);
    TestSiegeStrategy->setTreasury(externTres2);
    TestAssassinStrategy->setTreasury(externTres3);

    cout<<"Ambush getStrategyName should return \"Ambush\": "<<TestAmbushStrategy->getStrategyName()<<endl;
    cout<<"BattleField getStrategyName should return \"BattleField\": "<<TestBattleFieldStrategy->getStrategyName()<<endl;
    cout<<"Siege getStrategyName should return \"Siege\": "<<TestSiegeStrategy->getStrategyName()<<endl;
    cout<<"Assassin getStrategyName should return \"Assassin\": "<<TestAssassinStrategy->getStrategyName()<<endl<<endl;

    cout<<"Ambush getMyBannerman() should return \"externCommander1\": "<<TestAmbushStrategy->getMyBannerman()->getName()<<endl;
    cout<<"BattleField getMyBannerman() should return \"externCommander1\": "<<TestBattleFieldStrategy->getMyBannerman()->getName()<<endl;
    cout<<"Siege getMyBannerman() should return \"externCommander1\": "<<TestSiegeStrategy->getMyBannerman()->getName()<<endl;
    cout<<"Assassin getMyBannerman() should return \"externCommander1\": "<<TestAssassinStrategy->getMyBannerman()->getName()<<endl<<endl;

    cout<<"Ambush getEneMyBannerman() should return \"externCommander2\": "<<TestAmbushStrategy->getEnemyBannerman()->getName()<<endl;
    cout<<"BattleField getEneMyBannerman() should return \"externCommander2\": "<<TestBattleFieldStrategy->getEnemyBannerman()->getName()<<endl;
    cout<<"Siege getEneMyBannerman() should return \"externCommander2\": "<<TestSiegeStrategy->getEnemyBannerman()->getName()<<endl;
    cout<<"Assassin getEneMyBannerman() should return \"externCommander2\": "<<TestAssassinStrategy->getEnemyBannerman()->getName()<<endl<<endl;

    
    cout<<"Ambush attack() should return boolean 0 or 1 after strategy commets:"<<TestAmbushStrategy->attack(externKingdom1->getAlly("externCommander1"),externKingdom2->getAlly("externCommander2"))<<endl;
    cout<<"BattleField attack() should return boolean 0 or 1 after strategy commets:"<<TestBattleFieldStrategy->attack(externKingdom11->getAlly("externCommander11"),externKingdom21->getAlly("externCommander21"))<<endl;
    cout<<"Siege attack() should return boolean 0 or 1 after strategy commets:"<<TestSiegeStrategy->attack(externKingdom12->getAlly("externCommander12"),externKingdom22->getAlly("externCommander22"))<<endl;
    cout<<"Assassin attack() should return boolean 0 or 1 after strategy commets:"<<TestAssassinStrategy->attack(externKingdom13->getAlly("externCommander13"),externKingdom23->getAlly("externCommander23"))<<endl<<endl;

    delete TestAmbushStrategy;
    delete TestBattleFieldStrategy;
    delete TestSiegeStrategy;
    delete TestAssassinStrategy;
    delete externTres;
    delete externTres1;
    delete externTres2;
    delete externTres3;
    delete externRaven;
    delete externRaven1;
    delete externRaven2;
    delete externRaven3;
    for (int i = 0; i < 3; i++)
    {
        delete externsupplies[i];
    }
    delete [] externsupplies;
    
}

void JuliannaUnitTesting(){

    State* TestState = new HealthyState();

    Economy* TestEco = new Economy(TestState, 100);

    Kingdom* TestKingdom = new Kingdom(TestEco);

    TestKingdom->add(new Commander("Stratham"));
    TestKingdom->add(new Commander("Trudid"));
    TestKingdom->add(new Commander("Mirefield"));


    list<Bannerman*> s = TestKingdom->getKingdom();


    Historian* Thom = new Historian();
    HistoryBook* Book = new HistoryBook();

    Bannerman* myBannerman = s.front();

    Thom->setAlly(myBannerman);
    Book->add(Thom->Store());

    TestKingdom->remove(myBannerman);

    cout<<"The commanders are losing faith in your cause. "<<myBannerman->getName()<<" has defected to the other side."<<endl;

    Bannerman* returned = Thom->restoreAlly(Book->getAlly());
    TestKingdom->add(returned);
    cout<<returned->getName()<<"'s commander asks yor forgiveness and joins your fight once again."<<endl;


}


//=========================================================================================



/**
 * @brief the text introduction to the simulator's story
 */
void intro(){
    cout<<"A new dawn arrives and brings with it a red sky."<<endl;
    cout<<"You rule the great kingdom of Dura, which is in the midst of a great battle for the western"<<endl;
    cout<<"isles, the United Kingdoms of Preadora."<<endl;
     cout<<"press Enter to continue...";
     cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout<<" _                     _                  "<<endl;
    cout<<"|_) _ _|__|_ |  _    _|_ _  __   _|_|_  _ "<<endl;
    cout<<"|_)(_| |_ |_ | (/_    | (_) |     |_| |(/_"<<endl;

    cout<<" __          __       _                     _____     _     "<<endl;

    cout<<" \\ \\        / /      | |                   |_   _|   | |          "<<endl;
    cout<<"  \\ \\  /\\  / /__  ___| |_ ___ _ __ _ __      | |  ___| | ___  ___ "<<endl;
    cout<<"   \\ \\/  \\/ / _ \\/ __| __/ _ \\ '__| '_ \\     | | / __| |/ _ \\/ __|"<<endl;
    cout<<"    \\  /\\  /  __/\\__ \\ ||  __/ |  | | | |   _| |_\\__ \\ |  __/\\__ \\"<<endl;
    cout<<"     \\/  \\/ \\___||___/\\__\\___|_|  |_| |_|  |_____|___/_|\\___||___/"<<endl;



     cout<<"press Enter to continue...";
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
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

        cout<<"Damage that this Bannerman can inflict: "<<curr->getDamage()<<endl;
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
        strat = new BattleField(Dura, Preadora, fighter, enemy, "Battlefield", 5, 5, Greg, BookOfDura);
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
        strat = new Assassinate(stealth, true, Dura, Preadora, fighter, enemy, "Assassinate", 5, 5, Greg, BookOfDura);
        DT.front()->assassin = false;
        DT.back()->assassin = false;
        break;

    default:
        goAttack();
        return;
    }

    cout<<strat->getStrategyName()<<endl;


    cout<<"===================================================================="<<endl<<endl;
    //send scout
    cout<<"A scout has been sent to the enemies location. We await news."<<endl;
    cout<<"..."<<endl;
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
            cout<<"By choosing not to attack Preadora you will have to raise the white flag of surrender."<<endl<<"Do you agree?(y/n)"<<endl;
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


    return 0;
}