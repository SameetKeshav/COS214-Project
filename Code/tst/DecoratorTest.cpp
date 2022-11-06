
#include<Historian.h> //originator, has memento included
#include<HistoryBook.h> //caretaker
#include<Kingdom.h>
#include<Economy.h>
#include<HealthyState.h>
#include<FailedState.h>
#include<UnstableState.h>
#include<Commander.h>
#include<Ambush.h>
#include<BattleField.h>
#include<Siege.h>
#include<Assassinate.h>
#include<Location.h>
#include<Weather.h>
#include<Topology.h>
#include<MasterOfCoin.h>
#include<sendRaven.h>
#include<Factory.h>
#include<FoodFac.h>
#include<MedicalFac.h>
#include<WeaponsFac.h>
#include<SupplyWagon.h>
#include<FoodWagon.h>
#include<MedicalWagon.h>
#include<WeaponWagon.h>
#include<Troop.h>

#include "gtest/gtest.h"

void DecoratorClientCode(WarTheatre* component) {
    component->sendScout();
}

TEST(DecoratorTestSuite, getHP){
    Kingdom* Dura;
    Economy* DuraEco;
    Kingdom* Preadora;
    Economy* PreadoraEco;
    bool attack = true;
    Bannerman* enemy;
    Bannerman* fighter;
    string strategy;
    State* DuraState;
    State* PreadoraState;
    WarIndicators* warind = new WarIndicators();
    Historian* Greg = new Historian();
    HistoryBook* BookOfDura = new HistoryBook();
    Treasury* tres;
    Raven* myRaven;
    
    srand(time(0));
    int stealth = 10 + (rand() % 100);

    Strategy* strat = new Ambush(stealth, Dura, Preadora, fighter, enemy, "Ambush", 10, 5, Greg, BookOfDura);


    cout << "------------ TESTING THE DECORATOR FUNCTIONALITY ------------" << endl;

    WarTheatre* OriginalWarTheatre = new Location;
    OriginalWarTheatre->setVenue(OriginalWarTheatre->decideVenue(strat));
    DecoratorClientCode(OriginalWarTheatre);
    EXPECT_EQ(OriginalWarTheatre->getDifficulty(),1);
}