#include "Complex.h"
#include <iostream>
using std::cout;


ComplexNum::ComplexNum(int a, int b) : m_real(a), m_imagionary(b)
{} // Initializer List so the block is empty

ComplexNum::ComplexNum() : ComplexNum(0, 0)
{} // Initializer List so the block is empty

int ComplexNum::getReal() const {
	return m_real;
}
int ComplexNum::getImagionary() const {
	return m_imagionary;
}
void ComplexNum::setReal(int a) {
	m_real = a;
}
void ComplexNum::setImagionary(int b) {
	m_imagionary = b;
}

ComplexNum ComplexNum::operator+(const ComplexNum& other) const {
	return ComplexNum(this->getReal() + other.getReal(), this->getImagionary() + other.getImagionary());
}
ComplexNum ComplexNum::operator-(const ComplexNum& other) const {
	return ComplexNum(this->getReal() - other.getReal(), this->getImagionary() - other.getImagionary());
}
ComplexNum ComplexNum::operator*(const ComplexNum& other) const {
	int newReal = (this->getReal() * other.getReal()) - (this->getImagionary() * other.getImagionary());
	int newImg = (this->getReal() * other.getImagionary()) + (this->getImagionary() * other.getReal());
	return ComplexNum(newReal, newImg);
}
bool ComplexNum::operator==(const ComplexNum& other) const {
	return ((this->getReal() == other.getReal()) && (this->getImagionary() == other.getImagionary()));
}

void ComplexNum::printComplex() {
	cout << "Complex number is: " << this->getReal() << " + " << this->getImagionary() << "i\n";
}
