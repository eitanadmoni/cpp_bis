#include <iostream>

int main()
{
    int num = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;
    if (num < 0)
    {
        std::cout << "Num must be greater than 0!";
        return 0;
    }
    std::cout << "sqrt of input is:  " << std::sqrt(num);
    return 0;
}