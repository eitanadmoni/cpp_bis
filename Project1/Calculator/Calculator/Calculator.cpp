#include <iostream>
#include <string>
#include <string_view>
#include "Calculator.h"

using std::cout;
using std::string;

enum return_values
{
	SUCCESS,
	CALCULATOR_FAILURE = -1,
};

/**
* Builder for CalculateException class
* @param string that describe the error
* @return A CalculateException item
*/
CalculateException::CalculateException(string error) : m_error{ error } {}

/**
* CalculateException method to get the error massege
* @return Exception massege
*/
const string& CalculateException::getError() const { return m_error; }

/**
* Calculator's method to add 2 numbers
* @param firstNum first number of the addition
* @param secondNum second number of the addition
* @return result of the calculation
*/

double Calculator::add(double firstNum, double secondNum) {
	return firstNum + secondNum;
}

/**
* Calculator's method to subtract 2 numbers
* @param firstNum first number of the subtraction
* @param secondNum second number of the subtraction
* @return result of the calculation
*/
double Calculator::subtract(double firstNum, double secondNum) {
	return firstNum - secondNum;
}

/**
* Calculator's method to multiply 2 numbers
* @param firstNum first number of the multiplication
* @param secondNum second number of the multiplication
* @return result of the calculation
*/
double Calculator::multiply(double firstNum, double secondNum) {
	return firstNum * secondNum;
}

/**
* Calculator's method to divide 2 numbers
* @param firstNum first number of the division
* @param secondNum second number of the division
* @return result of the calculation
*/
double Calculator::divide(double firstNum, double secondNum) {
	if (secondNum == 0) {
		throw CalculateException{ "Division by zero" };
	}
	return firstNum / secondNum;
}

/**
* A Calculator's method to apply operation between 2 numbers
* @param firstNum first number to apply operation at
* @param op operation to apply
* @param secondNum second number to apply operation at
* @return result of the calculation
*/
double Calculator::calculate(double firstNum, char op, double secondNum) {
	switch (op)
	{
	case '+':
		return add(firstNum, secondNum);
	case '-':
		return subtract(firstNum, secondNum);
	case '*':
		return multiply(firstNum, secondNum);
	case '/':
		return divide(firstNum, secondNum);
	default:
		throw CalculateException{ "Invalid operator" };
	}
}

int main() {
	Calculator calc;
	try {
		cout << calc.calculate(4, '*', 5);
	}
	catch (const CalculateException& exception) {
		std::cerr << "A calculate exception occurred: " << exception.getError() << "\n";
		return CALCULATOR_FAILURE;
	}
	return SUCCESS;
}

