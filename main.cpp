#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "boolMatrix.h"
#include "bot.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void printGrid(BoolMatrix& baduk);
void goToCoord(int, int);
void moveDown(int x, int& y, BoolMatrix baduk);
void moveUp(int x, int& y, BoolMatrix baduk);
void moveLeft(int& x, int y, BoolMatrix baduk);
void moveRight(int& x, int y, BoolMatrix baduk);
void cursorHandle(int x, int y, BoolMatrix baduk);
char xComponent(int x);
int yComponent(int y, const int yBound);

void updatePositionAlert(int x, int y, const int yBound);
void updateCoordinateAlert(int x, int y);

bool stoneIsDead(int x, int y, BoolMatrix baduk);

int main()
{
    BoolMatrix baduk;

    int menu_object = 0, run, countX = 9, countY = 9;
    bool isRunning = true;
    printGrid(baduk);
    while (isRunning)
    {
        const int _NUM_ROWS = baduk.getNumberOfRows();
        const int _NUM_COLS = baduk.getNumberOfCols();

        //ai turn

        system("pause>nul");

        if (GetAsyncKeyState(VK_DOWN) && countY < _NUM_ROWS)
        {
            moveDown(countX, countY, baduk);
            updateCoordinateAlert(countX, countY);
            updatePositionAlert(countX, countY, _NUM_ROWS);
            continue;
        }
        if (GetAsyncKeyState(VK_UP) && countY > 1)
        {
            moveUp(countX, countY, baduk);
            updateCoordinateAlert(countX, countY);
            updatePositionAlert(countX, countY, _NUM_ROWS);
            continue;
        }
        if (GetAsyncKeyState(VK_LEFT) && countX > 2)
        {
            moveLeft(countX, countY, baduk);
            updateCoordinateAlert(countX, countY);
            updatePositionAlert(countX, countY, _NUM_ROWS);
            continue;
        }
        if (GetAsyncKeyState(VK_RIGHT) && countX <= _NUM_COLS)
        {
            moveRight(countX, countY, baduk);
            updateCoordinateAlert(countX, countY);
            updatePositionAlert(countX, countY, _NUM_ROWS);
            continue;
        }
        if (GetAsyncKeyState(VK_RETURN)) //user hits enter
        {
            baduk.set(countX - 2, countY - 2, true);
            std::cout << "*";
        }
        if (GetAsyncKeyState(VK_ESCAPE)) //exits the program
        {
            return 0;
        }
    }
    return 0;
}

void printGrid(BoolMatrix& baduk)
{
    std::cout << baduk.toString();
}

void goToCoord(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void moveDown(int x, int& y, BoolMatrix baduk)
{
    cursorHandle(x, y, baduk);
    y++;
    goToCoord(x, y);
    std::cout << "0";
}

void moveUp(int x, int& y, BoolMatrix baduk)
{
    cursorHandle(x, y, baduk);
    y--;
    goToCoord(x, y);
    std::cout << "0";
}

void moveLeft(int& x, int y, BoolMatrix baduk)
{
    cursorHandle(x, y, baduk);
    x--;
    goToCoord(x, y);
    std::cout << "0";
    goToCoord(9, 1);
}

void moveRight(int& x, int y, BoolMatrix baduk)
{
    cursorHandle(x, y, baduk);
    x++;
    goToCoord(x, y);
    std::cout << "0";
}

void cursorHandle(int x, int y, BoolMatrix baduk)
{
    goToCoord(x, y);
    if (baduk.get(x - 2, y - 2))
        std::cout << "*";
    else
        std::cout << "-";
}

char xComponent(int x)
{
    char xComp;
    switch (x) {
    case 2:
        xComp = 'A'; break;
    case 3:
        xComp = 'B'; break;
    case 4:
        xComp = 'C'; break;
    case 5:
        xComp = 'D'; break;
    case 6:
        xComp = 'E'; break;
    case 7:
        xComp = 'F'; break;
    case 8:
        xComp = 'G'; break;
    case 9:
        xComp = 'H'; break;
    case 10:
        xComp = 'J'; break;
    case 11:
        xComp = 'K'; break;
    case 12:
        xComp = 'L'; break;
    case 13:
        xComp = 'M'; break;
    case 14:
        xComp = 'N'; break;
    case 15:
        xComp = 'O'; break;
    case 16:
        xComp = 'P'; break;
    case 17:
        xComp = 'Q'; break;
    case 18:
        xComp = 'R'; break;
    case 19:
        xComp = 'S'; break;
    case 20:
        xComp = 'T'; break;
    }
    return xComp;
}

int yComponent(int y, const int yBound)
{
    return (yBound - 1) - (y - 1);
}

void updatePositionAlert(int x, int y, const int yBound)
{
    goToCoord(23, 3); std::cout << "                ";
    goToCoord(23, 3); std::cout << xComponent(x) << yComponent(y, yBound);
}

void updateCoordinateAlert(int x, int y)
{
    goToCoord(23, 1); std::cout << "                ";
    goToCoord(23, 1); std::cout << x << " " << y << std::endl;
}

bool stoneIsDead(int x, int y, BoolMatrix baduk)
{
    return baduk.getNumberOfNeighbors >= 4;
}