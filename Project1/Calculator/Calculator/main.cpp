#include <iostream>
#include "Calculator.h"
#include  "CalculateException.h"
#include <string>

using std::cout;
using std::cerr;

enum return_values
{
	SUCCESS,
	CALCULATOR_FAILURE,
	EXCEPTION_FAILURE,
};

int check_calculator() {
	if (Calculator::calculate(4, '+', 5) != 9) {
		cout << "Calculator failed in equation 4 + 5 \n";
		return CALCULATOR_FAILURE;
	}
	else if (Calculator::calculate(2, '-', 10) != -8) {
		cout << "Calculator failed in equation 2 - 8 \n";
		return CALCULATOR_FAILURE;
	}
	else if (Calculator::calculate(0, '*', 10000) != 0) {
		cout << "Calculator failed in equation 0 * 10000 \n";
		return CALCULATOR_FAILURE;
	}
	else if (Calculator::calculate(10, '/', 345) != (10.0/345.0)) {
		cout << "Calculator failed in equation 10 / 34567\n";
		return CALCULATOR_FAILURE;
	}
	cout << "All calculation succeeded!";
	return SUCCESS;
}

int main() {
	try {
		return check_calculator();
	}
	catch (const CalculateException& exception) {
		cerr << "A calculate exception occurred: " << exception.getError() << "\n";
		return CALCULATOR_FAILURE;
	}
}
