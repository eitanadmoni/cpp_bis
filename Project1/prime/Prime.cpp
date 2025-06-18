#include <iostream>
#include <cmath>


/* function to check if given integer is prime, the func returns true or false
	the func iteratng all numbers from 1 to sqrt(num), if the num isn't prime, there is
	at least 1 number in that range that divides it */

bool is_prime(unsigned int num)
{	
	using std::sqrt;
	int num_sqrt = sqrt(num);
	if (num == 1) {
		return false; // 1 is not a prime number
	}
	for (int i = 2; i <= num_sqrt; i++) { // looping all the numbers from 2 to sqrt(num) to check primarity
		if (num % i == 0) { // checking if the current number divide num
			return false;
		}
	}
	return true;
}

int main() {
	using std::cout;
	int num_to_check = 31;
	cout << "primarity check: " << "\n";
	if (is_prime(num_to_check)) {
		cout << num_to_check << " is prime" << "\n";
	}
	else {
		cout << num_to_check << " isn't prime" << "\n";
	}
	return 0;
}