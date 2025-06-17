#include <iostream>

#define SIZE_OF_BOARD 11

void print_multiplication(int num)
{
    // function to print the multiplication board from 1 to num
    int i, j = 0;
    std::cout << "Multiplication table up to  " << num << ":" << std::endl;
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= num; j++)
        {
            std::cout << " " << i * j << "  ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_multiplication(SIZE_OF_BOARD);
    return 0;
}