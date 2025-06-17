#include <iomanip>
#include <iostream>
#include <sstream>

#define SIZE_OF_BOARD 11
#define SIZE_OF_CELL 4

/**
Function to print the multiplication board from 1 to boardSize
@param board_size the size of the multiplication board to print
*/
void print_multiplication(int boardSize)
{
    int row, col = 0;
    std::cout << "Multiplication table up to  " << boardSize << ":" << std::endl;
    for (row = 1; row <= boardSize; row++)
    {
        for (col = 1; col <= boardSize; col++)
        {
            std::cout << std::setw(SIZE_OF_CELL) << std::left << row * col;
        }
        std::cout << "\n"; // new row of the board
    }
}

int main()
{
    print_multiplication(SIZE_OF_BOARD);
    return 0;
}