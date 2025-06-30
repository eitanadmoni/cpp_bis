#pragma once

class ComplexNum
{
public:
	/**
	* Empty builder for ComplexNum class, bulid a zero complex number
	* @return A ComplexNum item item
	*/
	ComplexNum();
	/**
	* Builder for ComplexNum class
	* @param1 a coefficient for the real part of the number
	* @param1 b coefficient for the imagionary part of the number
	* @return A ComplexNum item item
	*/
	ComplexNum(int a, int b);

	/**
	* A ComplexNum's method to get the real part of the number
	* @return real part of the complex number
	*/
	int getReal() const;
	
	/**
	* A ComplexNum's method to get the imagionary part of the number
	* @return real part of the complex number
	*/
	int getImagionary() const;

	/**
	* A ComplexNum's method to set the real part of the number
	* @param1 a coefficient to set for the real part of the complex number
	*/
	void setReal(int a);
	
	/**
	* A ComplexNum's method to set the imagionary part of the number
	* @param1 a coefficient to set for the imagionary part of the complex number
	*/
	void setImagionary(int b);

	/**
	* A ComplexNum's + opereation to add 2 complex numbers
	* @param1 a complex number to add to the current number
	* @return A new complex number that is the addition of the 2 numbers
	*/
	ComplexNum operator+(const ComplexNum& other) const;

	/**
	* A ComplexNum's - opereation to subtract 2 complex numbers
	* @param1 a complex number to subtruct from the current number
	* @return A new complex number that is the subtraction of the 2 numbers
	*/
	ComplexNum operator-(const ComplexNum& other) const;

	/**
	* A ComplexNum's * opereation to multiply 2 complex numbers
	* @param1 a complex number to multiply to the current number
	* @return A new complex number that is the multiplication of the 2 numbers
	*/
	ComplexNum operator*(const ComplexNum& other) const;

	/**
	* A ComplexNum's ++ opereation to compare 2 complex numbers
	* @param1 a complex number to compare to the current number
	* @return A boolian value of the comparison
	*/
	bool operator==(const ComplexNum& other) const;

	/**
	* A ComplexNum's method that prints the number
	*/
	void printComplex();


private:
	int m_real; // The real part of the number
	int m_imagionary; // The imagionary part of the number
};