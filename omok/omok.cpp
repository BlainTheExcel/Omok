#include <iostream>
#include <string.h>
#include <vector>
#include "Player.h"
#include "Game.h"
using namespace std;

const int xy = 16;
int turn = 1;

void first_turn(int omok[][xy]);
void second_turn(int omok[][xy]);

void omok_change(int omok[][xy])
{
	vector<vector<int>> v(16, vector<int>(16, 0));
	int x = 1, y = 1;

	cout << "\n       ";
	for (int k = 1; k <= 16; k++)
	{
		if (k < 10) cout << k << "  ";
		else if (k >= 10) cout << k << " ";
	}
	cout << "\n       ──────────────────────────────────────────────" << endl;

	v[0][0] = 1;
	v[0][1] = 2;
	v[1][1] = 1;

	for (vector<int> vec : v) {
		if (x < 10)
		{
			cout << "   " << x;
			cout << " │";
		}
		else if (x >= 10)
		{
			cout << "  " << x;
			cout << " │";
		}
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
		x++;

	}

	//for (int i = 0; i < xy; i++)
	//{

	//	if (x < 10)
	//	{
	//		cout << "   " << x;
	//		cout << " │";
	//	}
	//	else if (x >= 10)
	//	{
	//		cout << "  " << x;
	//		cout << " │";
	//	}

	//	for (int j = 0; j < xy; j++)
	//	{
	//		//cout << " " << omok[i][j] << " ";
	//		switch (j)
	//		{
	//		case 0:
	//			cout << "○";
	//			break;
	//		case 7:
	//			cout << "●";
	//			break;
	//		default:
	//			cout << "┼" << " ";
	//			break;
	//		}
	//	}
	//	cout << "\n";
	//	x++;
	//}

	if (turn == 1)
	{
		first_turn(omok);
		turn++;
		system("cls");
		omok_change(omok);
	}
	else if (turn == 2)
	{
		second_turn(omok);
		turn--;
		system("cls");
		omok_change(omok);
	}
}

void first_turn(int omok[][xy])
{
	int x, y;

	cout << "\n  선수 1" << endl;
	while (true)
	{
		cout << "  원하는 x 좌표 값 입력 : ";
		cin >> x;
		cout << "  원하는 y 좌표 값 입력 : ";
		cin >> y;

		if (omok[y - 1][x - 1] == 2 || omok[y - 1][x - 1] == 1)
		{
			cout << "  이미 선언된 곳입니다.\n";
			continue;
		}
		else
		{
			omok[y - 1][x - 1] = 1;
			break;
		}
	}
}

void second_turn(int omok[][xy])
{
	int x, y;

	cout << "\n  선수 2" << endl;
	while (true)
	{
		cout << "  원하는 x 좌표 값 입력 : ";
		cin >> x;
		cout << "  원하는 y 좌표 값 입력 : ";
		cin >> y;

		if (omok[y - 1][x - 1] == 2 || omok[y - 1][x - 1] == 1)
		{
			cout << "  이미 선언된 곳입니다.\n";
			continue;
		}
		else
		{
			omok[y - 1][x - 1] = 2;
			break;
		}
	}
}

void cal(int omok[][xy])
{
	static int ex1 = 0, ex2 = 0, ex3 = 0, ex4 = 0;
	for (int i = 0; i < xy; i++)
	{
		for (int j = 0; j < xy; j++)
		{
			if (omok[i][j] == 1)
			{
				if (omok[i - 1][j + 1] == 1)
				{
					if (omok[i - 2][j + 2] == 1 && omok[i - 3][j + 3] == 1 && omok[i - 4][j + 4] == 1)
					{

					}
				}
				else if (omok[i][j + 1] == 1)
				{
					if (omok[i][j + 2] == 1 && omok[i][j + 3] == 1 && omok[i][j + 4] == 1)
					{

					}
				}
				else if (omok[i + 1][j + 1] == 1)
				{
					if (omok[i + 2][j + 2] == 1 && omok[i + 3][j + 3] == 1 && omok[i + 4][j + 4] == 1)
					{

					}
				}
				else if (omok[i - 1][j] == 1)
				{
					if (omok[i - 2][j] == 1 && omok[i - 3][j] == 1 && omok[i - 4][j] == 1)
					{

					}
				}
			}

		}
	}
}

int main()
{
	Game omok;
	omok.drawBoard();

	while (true) {
		omok.playTurn();
		omok.drawBoard();
		if (omok.checkWin())
			break;
		omok.changeTurn();
	}

	//Player player1 = Player("이채호");
	//Player player2 = Player("최성운");
	//player2.setCurrentLocation(1, 2);
	//int omok[xy][xy] = { 0 };
	//omok_change(omok);
}