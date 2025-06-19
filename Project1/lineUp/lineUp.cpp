#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <numeric>



using namespace std;

int main() {
	vector<int> my_vector = { 1, 2, 3, 4, 6, 10, 15, 20 }; // section 1
	cout << "Number of elements in vector that equal to 4: ";
	cout << count(my_vector.begin(), my_vector.end(), 4) << "\n"; // section 2
	cout << "Number of elements in vector that gratter than 4: ";
	cout << count_if(my_vector.begin(), my_vector.end(), binder2nd<greater<int> >(greater<int>(), 4)) << "\n"; // section 3
	my_vector.erase(remove_if(my_vector.begin(), my_vector.end(), binder2nd<less<int> >(less<int>(), 8)), my_vector.end()); // section 4
	cout << "Vector after removing any element that less then 8: ";
	copy(my_vector.begin(), my_vector.end(), ostream_iterator<int>(cout, " ")); // section 5
	vector<int> newVector; // section 6
	transform(my_vector.begin(), my_vector.end() - 1, my_vector.begin() + 1, back_inserter(newVector), minus<int>()); // section 7
	cout << "\ndifferentials vector: ";
	copy(newVector.begin(), newVector.end(), ostream_iterator<int>(cout, " "));	// section 8
	cout << "\nsum of differentials vector: ";
	cout << accumulate(newVector.begin(), newVector.end(), 0); // section 9
	return 0;
}
