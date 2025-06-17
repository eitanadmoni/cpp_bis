#include <cmath>
#include <iostream>


float print_sqrt(float num)
{
    // A function to print and return a given number, throwing error if occurs and return 1-
    float sqrt = 0;
    try
    {
        sqrt = std::sqrt(num); // calculating sqrt of the num
        std::cout << "sqrt of input is:  " << sqrt;
        return sqrt;
    }
    catch (...)
    {
        throw "Error while taking sqrt from number, please enter a positive number";
    }
}

float get_input_num()
{
    // function to get num from user and check it's legality
    float num = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num; // taking the number to calculate sqrt of from the user
    if (!std::cin)
    {
        throw "Input must be a number!";
    }
    if (num < 0) // sqrt can be taken just if num >= 0
    {
        throw "Num must be greater than 0!";
    }
    return num;
}

int main()
{
    float num = 0;

    num = get_input_num();
    print_sqrt(num);
    return 0;
}