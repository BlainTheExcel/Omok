#include <vector>
#include "Location.h"
#pragma once

using namespace std;

class Game
{
public:
	Game();
private:
	vector<vector<int>> board;
	bool turn;
	Location inputLocation();
	bool validateLocation(Location);
public:
	void drawBoard();
	bool checkWin();
	void changeTurn();
	bool getTurn();

	void playTurn();
	void turnPlayer2();

	void setRock(Location);
};

