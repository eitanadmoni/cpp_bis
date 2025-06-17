#include <iostream>

#define NUM_TO_CHECK 31

bool is_prime(int num)
{
	int i = 0;
	bool prime = true;
	if (num == 1) {
		return false;
	}
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			prime = false;
		}
	}
	return prime;
}

int main() {
	std::cout << "primary check: " << std::endl;
	if (is_prime(NUM_TO_CHECK)) {
		std::cout << NUM_TO_CHECK << " is prime" << std::endl;
	}
	else {
		std::cout << NUM_TO_CHECK << " isn't prime" << std::endl;
	}
	return 0;
}