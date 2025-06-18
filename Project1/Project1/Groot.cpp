#include <cmath>
#include <iostream>

using std::cout;
using std::sqrt;
using std::cin;

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

// function to handke errors and print matching message
// @param errorCode code for which error was occured
// @return return_value for the main function
int errorHandler(error_code errorCode)
{
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

// A function to print and return a given number
// @param num the number to calculate sqrt for
// @return num the number sqrt or error code if error was occured
float printSqrt(float num)
{
    float num_sqrt = 0;
    try
    {
        num_sqrt = sqrt(num); // calculating sqrt of the num
        cout << "sqrt of input is:  " << num_sqrt;
        return num_sqrt;
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
    cout << "Enter a number: \n";
    cin >> num; // taking the number to calculate sqrt of from the user
    if (!cin)
    {
        throw INPUT_WAS_NOT_A_NUMBER;
    }
    if (num < 0) // sqrt can be taken just if num >= 0
    {
        throw INPUT_WAS_A_NEGATIVE_NUMBER;
    }
    return num;
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