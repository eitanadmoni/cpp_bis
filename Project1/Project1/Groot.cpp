#include <iostream>
#include <cmath>


enum return_values
{
    SUCCESS = 0,
    FAILURE = -1,
};

float print_sqrt(float num) 
{
    //A function to print and return a given number, throwing error if occurs and return 1-
    
    float sqrt = 0;
    if (num < 0) // sqrt can be taken just if num >= 0
    {
        std::cout << "Num must be greater than 0!";
        return FAILURE;
    }
    try
    {
        sqrt = std::sqrt(num); // calculating sqrt of the num
        std::cout << "sqrt of input is:  " << sqrt;
        return sqrt;
    }
    catch (...) 
    {
        std::cout << "Error while taking sqrt from number, please enter a positive number";
        return FAILURE;
    }
}

int main()
{
    float num = 0;
    float sqrt = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num; // taking the number to calculate sqrt of from the user
    sqrt = print_sqrt(num);
    if (sqrt < 0) // if there is some problem in print_sqrt the value will be -1, else sqrt(num) that always >= 0
    {
        return FAILURE;
    }
    return SUCCESS;
}