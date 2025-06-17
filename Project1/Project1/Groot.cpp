#include <iostream>

int main()
{
    float num = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;
    if (num < 0)
    {
        std::cout << "Num must be greater than 0!";
        return -1;
    }
    try
    {
        std::cout << "sqrt of input is:  " << std::sqrt(num);
    }
    catch (...)
    {
        std::cout << "Error while taking sqrt from number, please enter a positive number";
        return -1;
    }
    return 0;
}