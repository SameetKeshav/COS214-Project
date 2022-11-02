#include "Weather.h"

Weather::Weather(WarTheatre* myTheatre) : Conditions(){
    // TODO - implement Weather::Weather
    //throw "Not yet implemented";

    srand(time(0));
    int val = rand() % 60 + 1; //between 1 and 60
    val -= 10;

    // cout<< "val: " << val << endl;

    //deciding on rain
    if (val%2 != 0)
        makeItRain();
    else rain = false;

    //setting SP
    if (val < 40)
        setWindSpeed(val);
    else setWindSpeed(50);

    //setting temp
    setTemp(val);
}

int Weather::calcEffect() {
    // TODO - implement Weather::calcEffect
    throw "Not yet implemented";
    //NOTE: Come back for bannerman changes.

    //rain
    if(rain)
    {
        setDifficulty(getDifficulty()+10);
    }

    //temp
    if(temp > -10 || temp <= 10)
    {
        setDifficulty(getDifficulty()+5);
    }
    else if(temp > 10 || temp <= 20)
    {
        setDifficulty(getDifficulty()+3);
    }
    else if(temp > 20 || temp < 30)
    {
        setDifficulty(getDifficulty()+5);
    }
    else
    {
        setDifficulty(getDifficulty()+7);
    }

    //windspeed
    if(rain)
    {
        int rVAL = 10;
        setDifficulty(getDifficulty()+((windspeed + rVAL)/temp)) ;
        cout<< "val: " << getDifficulty() << endl;
    }
    else
    {
        setDifficulty(getDifficulty()+(windspeed/temp)) ;
        cout<< "val: " << getDifficulty() << endl;
    }

    return  getDifficulty();

}

void Weather::setTemp(double t) {
    temp = t;
}

void Weather::makeItRain() {
    rain = true;
}

void Weather::setWindSpeed(int WP) {
    windspeed = WP;
}

void Weather::sendScout()
{
    calcEffect();
}

//void Weather::weatherReport() {
//     String output = "The weather at the venue is as follows: \n ;
//      cout << output << "Temp: " << temp << "\nRain: " << rain << "\nWS: " << windspeed << "\n-----------------" <<endl;
//}
