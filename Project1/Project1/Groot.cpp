#include <cmath>
#include <iostream>

enum error_code
{
    NOT_NUM,
    NEGATIVE,
    SQRT_ERR,
};

enum return_values
{
    SUCCESS,
    FAILURE = -1,
};
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
        throw SQRT_ERR;
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
        throw NOT_NUM;
    }
    if (num < 0) // sqrt can be taken just if num >= 0
    {
        throw NEGATIVE;
    }
    return num;
}

int main()
{
    float num = 0;
    using std::cout;
    try
    {
        num = get_input_num();
        print_sqrt(num);
    
    }
    catch (error_code errorCode)
    {
        switch (errorCode)
        {
        case NOT_NUM:
            cout << "Input must be a number!";
            return FAILURE;
        case NEGATIVE:
            cout << "Number must be positive!";
            return FAILURE;
        case SQRT_ERR:
            cout << "Error while taking sqrt";
            return FAILURE;
        default:
            cout << "Undefined error";
            return FAILURE;
        }
    }
    return SUCCESS;
}