#ifndef WEATHER_H
#define WEATHER_H

class Weather : public Conditions {

private:
	double temp;
	bool rain;
	int windspeed;

public:
	Weather();

	int calcEffect();

    void setTemp(double t);
    void makeItRain();
    void setWindSpeed(int SP);
    //void weatherReport(); ask Jules
};

#endif
