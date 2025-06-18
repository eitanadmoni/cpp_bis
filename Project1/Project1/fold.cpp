#include <iomanip>
#include <iostream>

using std::cout;
using std::left;
using std::setw;

const int success = 0;
/**
Function to calculate the number of digits in some number
@param num the number to calculate it's num of digits
*/
int digitsNum(int num)
{
    int digits = 0;
    while (num != 0)
    {
        num /= 10;
        digits += 1;
    }
    return digits;
}

/**
Function to print the multiplication board from 1 to boardSize
@param board_size the size of the multiplication board to print
*/
void printMultiplication(int boardSize)
{
    int cellSize = digitsNum(boardSize * boardSize) + 1;
    cout << "Multiplication table up to  " << boardSize << ":\n";
    for (int row = 1; row <= boardSize; row++)
    {
        for (int col = 1; col <= boardSize; col++)
        {
            cout << setw(cellSize) << left << row * col;
        }
        cout << "\n"; // new row of the board
    }
}

int main()
{
    const int boardSize = 11;
    printMultiplication(boardSize);
    return success;
}