#pragma once
#include <string>

class Calculator {
public:
	/**
	* A Calculator's method to apply operation between 2 numbers
	* @param firstNum first number to apply operation at
	* @param op operation to apply
	* @param secondNum second number to apply operation at
	* @return result of the calculation
	*/
	static double calculate(double firstNum, char op, double secondNum);

private:
	/**
	* Calculator's method to add 2 numbers
	* @param firstNum first number of the addition
	* @param secondNum second number of the addition
	* @return result of the calculation
	*/
	static double add(double firstNum, double secondNum);

	/**
	* Calculator's method to subtract 2 numbers
	* @param firstNum first number of the subtraction
	* @param secondNum second number of the subtraction
	* @return result of the calculation
	*/
	static double subtract(double firstNum, double secondNum);

	/**
	* Calculator's method to multiply 2 numbers
	* @param firstNum first number of the multiplication
	* @param secondNum second number of the multiplication
	* @return result of the calculation
	*/
	static double multiply(double firstNum, double secondNum);

	/**
	* Calculator's method to divide 2 numbers
	* @param firstNum first number of the division
	* @param secondNum second number of the division
	* @return result of the calculation
	*/
	static double divide(double firstNum, double secondNum);
};

