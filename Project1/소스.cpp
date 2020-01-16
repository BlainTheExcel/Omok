#include <iostream>
#include <string.h>
using namespace std;

const int xy = 20;
int turn = 1;

void first_turn(int omok[][xy]);
void second_turn(int omok[][xy]);

void omok_change(int omok[][xy])
{
    int x = 1, y = 1;

    for (int k = 1; k <= 20; k++)
    {
        cout << "     " << k;
    }
    cout << "\n";

    for (int i = 0; i < xy; i++)
    {
        cout << x;
        if (x < 10) cout << "  |";
        else if (x >= 10) cout << " |";

        for (int j = 0; j < xy; j++)
        {
            cout << " " << omok[i][j] << " ";
        }
        cout << "\n";
        x++;
    }

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

    cout << "선수 1" << endl;
    while (true)
    {
        cout << "원하는 x 좌표 값 입력 : ";
        cin >> x;
        cout << "원하는 y 좌표 값 입력 : ";
        cin >> y;

        if (omok[y - 1][x - 1] == 2 || omok[y - 1][x - 1] == 1)
        {
            cout << "이미 선언된 곳입니다.\n";
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

    cout << "선수 2" << endl;
    while (true)
    {
        cout << "원하는 x 좌표 값 입력 : ";
        cin >> x;
        cout << "원하는 y 좌표 값 입력 : ";
        cin >> y;

        if (omok[y - 1][x - 1] == 2 || omok[y - 1][x - 1] == 1)
        {
            cout << "이미 선언된 곳입니다.\n";
            continue;
        }
        else
        {
            omok[y - 1][x - 1] = 2;
            break;
        }
    }
}

int main()
{
    int omok[xy][xy] = { 0 };

    omok_change(omok);
}