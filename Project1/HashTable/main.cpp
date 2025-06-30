#include <iostream>
#include "HashTable.h"
#include "hashException.h"
#include <string>
#include <array>
#include <unordered_set>

using std::tuple;
using std::array;
using std::cout;
using std::cerr;
using std::hash;
using std::string;
using std::get;


enum return_values
{
	SUCCESS,
	FAILURE,
};



int checkHashTable() {
	HashTable first_table = HashTable(5);
	HashTable second_table = HashTable(5);
	tuple<string, int> a_tup = { "a", 2 };
	tuple<string, int> c_tup = { "c", 12 };
	first_table.addPair( "a", 2 );
	first_table.addPair("b", 5);
	first_table.addPair("c", 12);
	second_table.addPair("f", 33);
	second_table.addPair("e", 24);
	HashTable sum_table = first_table + second_table;
	if (first_table.checkIfExists("b") != true) {
		cout << "Fail to find inserted key 'b'\n";
		return FAILURE;
	}
	if (first_table.getNumOfItems() != 3) {
		cout << "Found wrong number of arguments in the first table\n";
		return FAILURE;
	}
	if (second_table.getNumOfItems() != 2) {
		cout << "Found wrong number of arguments in the second table\n";
		return FAILURE;
	}
	if (first_table.findItemByKey("a") != a_tup) {
		cout << "Failed to find item of {a, 2} by key\n";
		return FAILURE;
	}
	if (first_table.findItemByValue(12) != c_tup) {
		cout << "Failed to find item of {c, 12} by value\n";
		return FAILURE;
	}
	/*for (int i = 0; i < 5; i++) {
		cout << "Sum table: \n";
		cout << get<0>(sum_table.getTable()[i]) << ", " << get<1>(sum_table.getTable()[i]) << ", " << get<2>(sum_table.getTable()[i]) << "\n";
		
	}
	for (int i = 0; i < 5; i++) {
		cout << "first: \n";
		cout << get<0>(first_table.getTable()[i]) << ", " << get<1>(first_table.getTable()[i]) << ", " << get<2>(first_table.getTable()[i]) << "\n";
	}
	for (int i = 0; i < 5; i++) {
		cout << "sec: \n";
		cout << get<0>(second_table.getTable()[i]) << ", " << get<1>(second_table.getTable()[i]) << ", " << get<2>(second_table.getTable()[i]) << "\n";
	}*/
	if (sum_table.getNumOfItems() != 5) {
		cout << "Wrong number of arguments in the sum table\n";
		return FAILURE;
	}

	first_table += second_table;

	if (first_table.getNumOfItems() != 5) {
		cout << "Wrong number if arguments after adding second table to first table\n";
		return FAILURE;
	}

	if (first_table != sum_table) {
		cout << "Operation += doesn't equal to + operation\n";
		return FAILURE;
	}

	first_table.deleteItem("a");

	if (first_table.getNumOfItems() != 4) {
		cout << "Wrong number of arguments after deleting item\n";
		return FAILURE;
	}

	try
	{
		first_table.findItemByKey("a");
		if (true) {
			cout << "Deleted item steel in table\n";
			return FAILURE;
		}
	}
	catch (const HashException& exception)
	{
		if (exception.getError() != "There is no such key in the table") {
			cout << "Wrong error while trying to find deleted item\n";
			return FAILURE;
		}
	}

	cout << "All checks have succeeded!\n";
	return SUCCESS;
}

int main() {
	try {
		return checkHashTable();
	}
	catch (const HashException& exception) {
		cerr << "An exception occurred: " << exception.getError() << "\n";
		return FAILURE;
	}
}