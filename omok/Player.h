#pragma once
#include "Location.h"
class Player
{
private:
	Location currentLocation;
	std::string name;

	void inputLocation();

public:
	Player(std::string);
	~Player();

	void setCurrentLocation(int, int);
	void turn();
	//void setName(std::string);
	std::string getName();
};
