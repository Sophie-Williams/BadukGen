#include "boolMatrix.h"
#include <sstream>

BoolMatrix::BoolMatrix()
{
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            boolMatrix[i][j] = false;
        }
    }
    //boolMatrix[9][9] = true;
}

int BoolMatrix::getNumberOfRows() const
{
    // Return the total number of rows in your 2D array
    return NUM_ROWS;
}

int BoolMatrix::getNumberOfCols() const
{
    // Return the total number of columns in your 2D array
    return NUM_COLS;
}

bool BoolMatrix::isIndexOnGrid(int row, int col) const
{
    // Return true if the position at row and col is within the bounds of your 2D array and false otherwise
    if ((row <= NUM_ROWS && row > 0) || (col <= NUM_COLS && col > 0))
        return true;
    else
        return false;
}

bool BoolMatrix::get(int row, int col) const
{
    // Returns the boolean value at the given position of your 2D array
    if (isIndexOnGrid(row, col) && boolMatrix[row][col])
        return true;
    else
        return false;
}

void BoolMatrix::set(int row, int col, bool value)
{
    // Sets the value to either true or false at a given position in your 2 dimensional array
    if (isIndexOnGrid(row, col))
        boolMatrix[row][col] = value;

}

int BoolMatrix::getNumberOfTrueElementsInRow(int row) const
{
    // Returns the total number of true elements at a given row
    int trueElementsInRow = 0;
    for (int j = 0; j < NUM_COLS; j++)
    {
        if (get(row, j))
            trueElementsInRow++;
    }
    return trueElementsInRow;
}

int BoolMatrix::getNumberOfTrueElementsInCol(int col) const
{
    // Returns the total number of true elements at a given col
    int trueElementsInCol = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        if (get(i, col))
            trueElementsInCol++;
    }
    return trueElementsInCol;
}

int BoolMatrix::getTotalNumberOfTrueElements() const
{
    // Returns the total number of true values in your 2 dimensional array
    int totalNumberOfTrueElements = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (get(i, j))
                totalNumberOfTrueElements++;
        }
    }
    return totalNumberOfTrueElements;
}

int BoolMatrix::getNumberOfNeighbors(int row, int col) const
{
    // Returns the number of immediate true values that surrounds the given position on your 2 dimensional array
    if (!isIndexOnGrid(row, col))
        throw std::exception("Index out of bounds");
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (isIndexOnGrid(i, j) && get(i, j))
            {
                count++;
            }
        }
    }
    if (get(row, col)) // We don't want to count given position as a neighbor
    {
        count--;
    }
    return count;
}

std::string BoolMatrix::toString() const
{
    // Returns the string representation of the grid. You do not need to write the body for this function.
    std::ostringstream outputStringStream;
    outputStringStream << "  ";

    outputStringStream << 'A' << 'B' << 'C' << 'D' << 'E' << 'F' << 'G' << 'H' << 'J' << 'K' << 'L' << 'M' << 'N' << 'O' << 'P' << 'Q' << 'R' << 'S' << 'T';

    outputStringStream << std::endl;
    for (int i = NUM_ROWS - 1; i >= 0; i--)
    {
        outputStringStream << std::setw(2) << i % 100;
        for (int j = NUM_COLS - 1; j >= 0; j--)
        {
            if (boolMatrix[i][j] == true)
            {
                outputStringStream << "*";
            }
            else
            {
                outputStringStream << "-";
            }
        }
        outputStringStream << std::endl;
    }
    return outputStringStream.str();
}