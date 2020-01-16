#include <iostream>
#include "Player.h"

using namespace std;

void Player::inputLocation()
{
	int x = 0, y = 0;
	cout << "  원하는 x 좌표 값 입력 : ";
	cin >> x;
	cout << "  원하는 y 좌표 값 입력 : ";
	cin >> y;
	setCurrentLocation(x, y);
}

Player::Player(std::string name) :
	currentLocation(Location(0, 0)),
	name(name) {

}

Player::~Player() {

}


void Player::setCurrentLocation(int x, int y) {
	currentLocation = Location(x, y);
}

void Player::turn() {
	inputLocation();
}

//void Player::setName(std::string name)
//{
//	this->name = name;
//}

std::string Player::getName()
{
	return this->name;
}
