#include "Weather.h"

Weather::Weather() {
	// TODO - implement Weather::Weather
	//throw "Not yet implemented";

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
    //come back


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
//
//}