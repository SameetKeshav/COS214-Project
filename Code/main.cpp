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

//variables;
Kingdom* Dura;
Kingdom* Preadora;


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

/// @brief main functionality for simulation
/// @return no complications in compilation
int main(){

    intro();
    populateVectors();
    //State design pattern test
    //State* good=new HealthyState();
    //Economy* SA=new Economy(good,53);
    //SA->decreaseCurrency();
    //while (SA->getCurrency()>0)
    //{
        //SA->decreaseCurrency();
    //}
    //delete SA;
    //------------------------------//


    return 0;
}