#include <iostream>
#include <cmath>


#define NUM_TO_CHECK 31

bool is_prime(int num)
{
	/*function to check if given integer is prime, the func returns true or false
	the func iteratng all numbers from 1 to sqrt(num), if the num isn't prime, there is
	at least 1 number in that range that divides it */

	int i = 0;
	bool prime = true;
	float sqrt = 0;
	sqrt = std::sqrt(num);
	if (num == 1) {
		return false; // 1 is not a prime number
	}
	for (i = 2; i <= (int)sqrt; i++) { // looping all the numbers from 2 to sqrt(num) to check primarity
		if (num % i == 0) { // checking if the current number divide num
			prime = false;
		}
	}
	return prime;
}

int main() {
	std::cout << "primarity check: " << std::endl;
	if (is_prime(NUM_TO_CHECK)) {
		std::cout << NUM_TO_CHECK << " is prime" << std::endl;
	}
	else {
		std::cout << NUM_TO_CHECK << " isn't prime" << std::endl;
	}
	return 0;
}