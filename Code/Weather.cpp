#include "Weather.h"

<<<<<<< Updated upstream
Weather::Weather(int val) {
	// TODO - implement Weather::Weather
	//throw "Not yet implemented";

=======
Weather::Weather(WarTheatre* myTheatre) : Conditions(myTheatre){
	srand(time(0));
    int val = rand() % 60 + 1; //between 1 and 60
    val -= 10;
 
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
	// TODO - implement Weather::calcEffect
	throw "Not yet implemented";
    //NOTE: Come back for bannerman changes.
=======
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
        difficulty += 3;
=======
       setDifficulty(getDifficulty()+3);
>>>>>>> Stashed changes
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
    if(rain == true)
    {
        int rVAL = 10;
<<<<<<< Updated upstream
        difficulty += (windspeed + rVaL)/temp;
    }
    else
    {
        difficulty += windspeed/temp;
    }

    return  difficulty;
=======
        setDifficulty(getDifficulty()+((windspeed + rVAL)/temp)) ;
       
    }
    else
    {
        setDifficulty(getDifficulty()+(windspeed/temp)) ;
    }
    
    return  getDifficulty();
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
//void Weather::weatherReport() {
//     String output = "The weather at the venue is as follows: \n ;
//      cout << output << "Temp: " << temp << "\nRain: " << rain << "\nWS: " << windspeed << "\n-----------------" <<endl;
//}
=======
void Weather::sendScout()
{
	weatherReport();
	calcEffect();
	
}

void Weather::weatherReport() {
     string output = "-----------------\nThe weather at the venue is as follows:\n ";
      cout << output << "Temp: " << temp << "\nRain: " << rain << "\nWS: " << windspeed << "\n-----------------" <<endl;
}
>>>>>>> Stashed changes
