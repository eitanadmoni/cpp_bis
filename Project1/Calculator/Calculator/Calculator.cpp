#include "Calculator.h"
#include "CalculateException.h"

double Calculator::add(double firstNum, double secondNum) {
	return firstNum + secondNum;
}

double Calculator::subtract(double firstNum, double secondNum) {
	return firstNum - secondNum;
}

double Calculator::multiply(double firstNum, double secondNum) {
	return firstNum * secondNum;
}

double Calculator::divide(double firstNum, double secondNum) {
	if (secondNum == 0) {
		throw CalculateException{"Division by zero"};
	}
	return firstNum / secondNum;
}


double Calculator::calculate(double firstNum, char op, double secondNum) {
	switch (op)
	{
	case '+':
		return Calculator::add(firstNum, secondNum);
	case '-':
		return Calculator::subtract(firstNum, secondNum);
	case '*':
		return Calculator::multiply(firstNum, secondNum);
	case '/':
		return Calculator::divide(firstNum, secondNum);
	default:
		throw CalculateException{ "Invalid operator" };
	}
}

