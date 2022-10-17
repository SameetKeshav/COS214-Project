#ifndef WEATHER_H
#define WEATHER_H

class Weather : Conditions {

private:
	double temp;
	bool rain;
	int windspeed;

public:
	Weather();

	int calcEffect();
};

#endif
