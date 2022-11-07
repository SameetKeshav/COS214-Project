#include "Weather.h"

Weather::Weather(WarTheatre* myTheatre) : Conditions(myTheatre){
	srand(time(0));
    int val = rand() % 60 + 1; //between 1 and 60
    val -= 10;
 
    //deciding on rain
    if (val%2 != 0)
        makeItRain();
    else rain = false;

    //setting SP
    if (val < 40)
        setWindSpeed(val+10);
    else setWindSpeed(50);

    //setting temp
    setTemp(val);
    //this->sendScout();
}

int Weather::calcEffect() {

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
    if(rain == true)
    {
        int rVAL = 10;
        setDifficulty(getDifficulty()+((windspeed + rVAL)/temp)) ;
       
    }
    else
    {
        setDifficulty(getDifficulty()+(windspeed/temp)) ;
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
	weatherReport();
	calcEffect();
	
}

void Weather::weatherReport() {
    string outR = "";
    string output = "\t-----------------\nThe weather at the venue is as follows:\n";
    if (rain) outR = "True";
    else outR = "False";

    cout << output << "Temp: " << temp << "\nRain: " << outR << "\nWindSpeed: " << windspeed << "\n\t-----------------" <<endl;
}
