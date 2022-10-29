#include "Weather.h"

Weather::Weather(int val) {
	// TODO - implement Weather::Weather
	//throw "Not yet implemented";

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
        difficulty += 10;
    }

    //temp
    if(temp > -10 || temp <= 10)
    {
        difficulty += 5;
    }
    else if(temp > 10 || temp <= 20)
    {
        difficulty += 3;
    }
    else if(temp > 20 || temp < 30)
    {
        difficulty += 5;
    }
    else
    {
        difficulty += 7;
    }

    //windspeed
    if(rain)
    {
        int rVAL = 10;
        difficulty += (windspeed + rVaL)/temp;
    }
    else
    {
        difficulty += windspeed/temp;
    }

}

void Weather::setTemp(double t) {
    temp = t;
}

void Weather::makeItRain() {
    rain = true;
}

void Weather::setWindSpeed() {
    windspeed = WP;
}

//void Weather::weatherReport() {
//     String output = "The weather at the venue is as follows: \n ;
//      cout << output << "Temp: " << temp << "\nRain: " << rain << "\nWS: " << windspeed << "\n-----------------" <<endl;
//}