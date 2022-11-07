#ifndef WEATHER_H
#define WEATHER_H
#include "Conditions.h"
#include <ctime>

/**@brief concrete decorator A.
 * This is the class implements climate effects to the war location. Inherits from Conditions  class
 * @author Keabetswe Mothapo
 * @date October 2022
 */

class Weather:public Conditions{

private:
    /**Value of the temperature at the venue*/
	double temp;

    /**Boolean to indicate whether it is raining or not*/
	bool rain;

    /**Value of the wind speed at the venue*/
	int windspeed;

public:
    /**@brief Costructor of the weather object
     * @param val - recieves a generated value which will be used for setters in this class*/
	Weather(WarTheatre* myTheatre);

    /**@brief the function that uses the weather components to create a wholistc effect on bannermen
     *@returns returns the adjusted difficulty value*/
	int calcEffect();

    /**@brief setter for the temperature variable
     * @param t - the value used to set the temp*/
    void setTemp(double t);

    /**@brief setter for the rain variable
     * makes the boolean variable true*/
    void makeItRain();

    /**@brief setter for the windspeed variable
     * @param SP - the value used to set the wind speed*/
    void setWindSpeed(int SP);
    
    /**@brief displays the weather conditions of the location*/
	void weatherReport(); //ask Jules
    
    /**@brief calls the calEffect function and affects bannermen*/
    void sendScout();
};

#endif
