#include <iostream>
#include <cmath>
using std::cout;
using std::sqrt;

/* function to check if given integer is prime, the func returns true or false
	the func iteratng all numbers from 1 to sqrt(num), if the num isn't prime, there is
	at least 1 number in that range that divides it */

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

/**
* Function to fill a given array with number of first primes, according to parameter
* @param arrPointer pointer to integers array to fill with primes
* @param numOfPrimes number of first primes to fill the array with
*/
void primeArrayFill(int* arrPointer, int numOfPrimes) {
	int alreadyFilled = 0;
	int numToCheck = 1;
	while (alreadyFilled < numOfPrimes) {
		if (isPrime(numToCheck)) {
			arrPointer[alreadyFilled] = numToCheck;
			alreadyFilled += 1;
		}
		numToCheck += 1;
	}
}


int main() {
	int primesArr[30] = { 0 };
	primeArrayFill(primesArr, 30);
	for (int i = 0; i < 30; i++) {
		cout << primesArr[i] << " ";
	}
	return 0;
}