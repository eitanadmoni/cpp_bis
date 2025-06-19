#include "Complex.h"
#include <iostream>
using std::cout;

enum return_values
{
	SUCCESS,
	FAILURE,
};

/**
* Funcion to check the correctness of the complexNum class
* @return a value that represent the success/failure of the test
*/
int checkComplexClass() {
	if (!((ComplexNum(1, 5) * ComplexNum()) == ComplexNum(0, 0))) {
		cout << "Wrong number, num shold be: ";
		ComplexNum().printComplex();
		return FAILURE;
	}
	if (!(ComplexNum(4, 6) - ComplexNum(3, 6) == ComplexNum(1, 0))) {
		cout << "Wrong number, num shold be: ";
		ComplexNum(1, 0).printComplex();
		return FAILURE;
	}
	if (!(ComplexNum(4, 6) + ComplexNum(3, 6) == ComplexNum(7, 12))) {
		cout << "Wrong number, num shold be: ";
		ComplexNum(7, 12).printComplex();
		return FAILURE;
	}
	if (!(ComplexNum(4, 6) * ComplexNum(1, -2) == ComplexNum(16, -2))) {
		cout << "Wrong number, num shold be: ";
		ComplexNum(16, -2).printComplex();
		return FAILURE;
	}
	cout << "Success!";
	return SUCCESS;
}

int main() {
	return checkComplexClass();
}