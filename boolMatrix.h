#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

class BoolMatrix
{
public:
    BoolMatrix();

    bool get(int row, int col) const;
    void set(int row, int col, bool value);

    int getNumberOfRows() const;
    int getNumberOfCols() const;

    bool isIndexOnGrid(int row, int col) const;
    int getNumberOfTrueElementsInRow(int row) const;
    int getNumberOfTrueElementsInCol(int col) const;
    int getTotalNumberOfTrueElements() const;

    int getNumberOfNeighbors(int row, int col) const;
    std::string toString() const;

private:
    static const int NUM_ROWS = 19; //The static keyword is needed to intialize the array size properly.
    static const int NUM_COLS = 19; //Static means that the member variable will be created only once and placed in one location in memory. All references to this variable will point to that single place, meaning multiple objects will all share the same member variable (aka. static storage).

    bool boolMatrix[NUM_ROWS][NUM_COLS];
};

#endif