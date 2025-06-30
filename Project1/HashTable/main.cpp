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


/**
* Function to delete the array of a given hash table
* @parm hashTable hash table class to delete his array 
*/
void deleteArray(HashTable hashTable) {
	delete[] hashTable.getTable();
}


/**
* Funcion to check the correctness of the HashTable class
* @return a value that represent the success/failure of the test
*/
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
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}
	if (first_table.getNumOfItems() != 3) {
		cout << "Found wrong number of arguments in the first table\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}
	if (second_table.getNumOfItems() != 2) {
		cout << "Found wrong number of arguments in the second table\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}
	if (first_table.findItemByKey("a") != a_tup) {
		cout << "Failed to find item of {a, 2} by key\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}
	if (first_table.findItemByValue(12) != c_tup) {
		cout << "Failed to find item of {c, 12} by value\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}
	
	if (sum_table.getNumOfItems() != 5) {
		cout << "Wrong number of arguments in the sum table\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}

	first_table += second_table;

	if (first_table.getNumOfItems() != 5) {
		cout << "Wrong number if arguments after adding second table to first table\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}

	if (first_table != sum_table) {
		cout << "Operation += doesn't equal to + operation\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}

	first_table.deleteItem("a");

	if (first_table.getNumOfItems() != 4) {
		cout << "Wrong number of arguments after deleting item\n";
		deleteArray(first_table);
		deleteArray(second_table);
		deleteArray(sum_table);
		return FAILURE;
	}

	try
	{
		first_table.findItemByKey("a");
		if (true) {
			cout << "Deleted item steel in table\n";
			deleteArray(first_table);
			deleteArray(second_table);
			deleteArray(sum_table);
			return FAILURE;
		}
	}
	catch (const HashException& exception)
	{
		if (exception.getError() != "There is no such key in the table") {
			cout << "Wrong error while trying to find deleted item\n";
			deleteArray(first_table);
			deleteArray(second_table);
			deleteArray(sum_table);
			return FAILURE;
		}
	}

	cout << "All checks have succeeded!\n";
	deleteArray(first_table);
	deleteArray(second_table);
	deleteArray(sum_table);
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