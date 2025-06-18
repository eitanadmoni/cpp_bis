#include <iostream>
#include <cmath>

using std::sqrt;
using std::cout;

const int success = 0;

/**
 *function to check if given integer is prime
 * @param num positive integer to check if is prime
 * @return boolian value of the primarity of the number
 */

bool isPrime(unsigned int num)
{	
	int numSqrt = sqrt(num);
	if (num == 1) {
		return false; // 1 is not a prime number
	}
	for (int i = 2; i <= numSqrt; i++) { // looping all the numbers from 2 to sqrt(num) to check primarity
		if (num % i == 0) { // checking if the current number divide num
			return false;
		}
	}
	return true;
}

int main() {
	int numToCheck = 31;
	cout << "primarity check: " << "\n";
	if (isPrime(numToCheck)) {
		cout << numToCheck << " is prime" << "\n";
	}
	else {
		cout << numToCheck << " isn't prime" << "\n";
	}
	return success;
}