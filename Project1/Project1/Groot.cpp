#include <iostream>

#define SUCCESS 0
#define FAILURE -1


int print_sqrt(float num)
{
    if (num < 0)
    {
        std::cout << "Num must be greater than 0!";
        return FAILURE;
    }
    try
    {
        std::cout << "sqrt of input is:  " << std::sqrt(num);
    }
    catch (...)
    {
        std::cout << "Error while taking sqrt from number, please enter a positive number";
        return FAILURE;
    }
    return SUCCESS;
}

int main()
{
    float num = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num;
    return print_sqrt(num);
}