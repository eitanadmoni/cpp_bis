#include <cmath>
#include <iostream>

enum error_code
{
    INPUT_WAS_NOT_A_NUMBER,
    INPUT_WAS_A_NEGATIVE_NUMBER,
    ERROR_WHILE_TAKING_SQRT,
};

enum return_values
{
    SUCCESS,
    ILLEGAL_INPUT = -1,
    SQRT_FAILURE = -2,
    GENERAL_FAILURE = -3,
};

// A function to print and return a given number
// @param num the number to calculate sqrt for
// @return num the number sqrt or error code if error was occured
float printSqrt(float num)
{
    float sqrt = 0;
    try
    {
        sqrt = std::sqrt(num); // calculating sqrt of the num
        std::cout << "sqrt of input is:  " << sqrt;
        return sqrt;
    }
    catch (...)
    {
        throw ERROR_WHILE_TAKING_SQRT;
    }
}

// function to get num from user and check it's legality
// @return num input number or error code
float getInputNum()
{
    float num = 0;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> num; // taking the number to calculate sqrt of from the user
    if (!std::cin)
    {
        throw INPUT_WAS_NOT_A_NUMBER;
    }
    if (num < 0) // sqrt can be taken just if num >= 0
    {
        throw INPUT_WAS_A_NEGATIVE_NUMBER;
    }
    return num;
}

// function to handke errors and print matching message
// @param errorCode code for which error was occured
// @return return_value for the main function 
int errorHandler(error_code errorCode)
{
    using std::cout;
    switch (errorCode)
    {
    case INPUT_WAS_NOT_A_NUMBER:
        cout << "Input must be a number!";
        return ILLEGAL_INPUT;
    case INPUT_WAS_A_NEGATIVE_NUMBER:
        cout << "Number must be positive!";
        return ILLEGAL_INPUT;
    case ERROR_WHILE_TAKING_SQRT:
        cout << "Error while taking sqrt";
        return SQRT_FAILURE;
    default:
        cout << "Undefined error";
        return GENERAL_FAILURE;
    }
}

int main()
{
    float num = 0;
    try
    {
        num = getInputNum();
        printSqrt(num);
    }
    catch (error_code errorCode)
    {
        return errorHandler(errorCode);
    }
    return SUCCESS;
}