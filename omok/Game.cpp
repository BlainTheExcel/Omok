#include "Game.h"
#include <iostream>

Game::Game() :
	turn(true)
{
	board = vector<vector<int>>(16, vector<int>(16, 0));
}

Location Game::inputLocation()
{
	int x = 0, y = 0;
	cout << "  원하는 x 좌표 값 입력 : ";
	cin >> x;
	cout << "  원하는 y 좌표 값 입력 : ";
	cin >> y;
	return Location(x, y);
}

bool Game::validateLocation(Location location)
{
	return board[location.y][location.x]==0;
}

void Game::drawBoard()
{
	system("cls");

	//int x = 1, y = 1;
	//cout << "\n       ";
	//for (int k = 1; k <= 16; k++)
	//{
	//	if (k < 10) cout << k << "  ";
	//	else if (k >= 10) cout << k << " ";
	//}
	cout << "\n    ┌───────────────────────────────" << endl;

	for (vector<int> vec : board) {
		/*if (x < 10)
		{*/
		cout << "    │";
		/*}
		else if (x >= 10)
		{
			cout << "  " << x;
			cout << " │";
		}*/
		for (int n : vec) {
			switch (n)
			{
			case 0:
				cout << "┼" << " ";
				break;
			case 1:
				cout << "○";
				break;
			case 2:
				cout << "●";
				break;
			default:
				break;
			}
		}
		cout << endl;
		//x++;
	}
}

bool Game::checkWin()
{
	return false;
}

void Game::changeTurn()
{
	turn = !turn;
}

bool Game::getTurn()
{
	return turn;
}

void Game::playTurn()
{
	Location location;
	do {
		location = inputLocation();
	} while (!validateLocation(location));

	setRock(location);
}

void Game::turnPlayer2()
{
}

void Game::setRock(Location location)
{
	if (turn)
		board[location.y][location.x] = 1;
	else
		board[location.y][location.x] = 2;
}
