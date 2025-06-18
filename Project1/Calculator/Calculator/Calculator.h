#include <string>

using std::string;

class Calculator {
public:
	double calculate(double firstNum, char op, double secondNum);

private:
	double add(double firstNum, double secondNum);
	double subtract(double firstNum, double secondNum);
	double multiply(double firstNum, double secondNum);
	double divide(double firstNum, double secondNum);
}; 

class CalculateException
{
private:
	string m_error;

public:
	CalculateException(string error);

	const string& getError() const;
};
