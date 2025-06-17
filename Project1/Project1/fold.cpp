#include <iomanip>
#include <iostream>
#include <sstream>

#define SIZE_OF_BOARD 11

void print_multiplication(int num)
{
    // function to print the multiplication board from 1 to num
    int i, j = 0;
    std::cout << "Multiplication table up to  " << num << ":" << std::endl;
    for (i = 1; i <= num; i++) // runing all numbers in the range and print the multiplication
    {
        for (j = 1; j <= num; j++)
        {
            std::cout << std::setw(4) << std::left << i * j;
        }
        std::cout << "\n"; // new row of the board
    }
}

int main()
{
    print_multiplication(SIZE_OF_BOARD);
    return 0;
}