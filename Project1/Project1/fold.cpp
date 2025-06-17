#include <iostream>

int main()
{
    int i, j = 0;
    std::cout << "Multiplication table up to 11: " << std::endl;
    for (i = 1; i <= 11; i++)
    { 
        for (j = 1; j <= 11; j++)
        {
            std::cout << i * j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}