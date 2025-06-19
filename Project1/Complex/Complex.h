#pragma once

class ComplexNum
{
public:
	ComplexNum();
	ComplexNum(int a, int b);
	int getReal() const;
	int getImagionary() const;

	void setReal(int a);
	void setImagionary(int b);

	ComplexNum operator+(const ComplexNum& other) const;
	ComplexNum operator-(const ComplexNum& other) const;
	ComplexNum operator*(const ComplexNum& other) const;
	bool operator==(const ComplexNum& other) const;

	void printComplex();


private:
	int m_real;
	int m_imagionary;
};