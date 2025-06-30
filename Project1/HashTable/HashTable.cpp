#include "HashTable.h"
#include "hashException.h"
#include <string>
#include <unordered_set>


using std::tuple;
using std::string;
using std::hash;
using std::get;


HashTable::HashTable(int size) {
	m_tableSize = size;
	m_table = new tuple<string, int, int>[size];
	for (int i = 0; i < size; i++) {
		m_table[i] = {"" , NULL, NULL};
	}
	m_numOfItems = 0;
}


tuple<string, int, int>* HashTable::getTable() {
	return m_table;
}


int HashTable::getSize() {
	return m_tableSize;
}


int HashTable::getNumOfItems() {
	return this->m_numOfItems;
}


void HashTable::setTable(std::tuple<std::string, int, int>* table) {
	std::tuple<std::string, int, int>* prevTable = this->getTable();
	this->m_table = table;
	delete[] prevTable;
}


void HashTable::setTableItem(tuple<string, int, int> pair, int place) {
	this->getTable()[place] = pair;
}


void HashTable::setNumOfItems(int num) {
	this->m_numOfItems = num;
}


void HashTable::addPair(string key, int value) {
	int hashValue = hash<string>{}(key) % this->getSize();
	tuple<string, int, int> pair = { key, value, 1 };
	if (get<2>(this->getTable()[hashValue]) == 0) {
		this->setNumOfItems(this->getNumOfItems() + 1);
	}
	this->setTableItem(pair, hashValue);
}


tuple<string, int> HashTable::findItemByKey(string key) {
	int hashValue = hash<string>{}(key) % this->getSize();
	tuple<string, int, int> pair = this->getTable()[hashValue];
	string keyInPlace = get<0>(pair); 
	if (keyInPlace == key) {
		return { get<0>(pair), get<1>(pair) };
	}
	else {
		throw HashException("There is no such key in the table"); 
	}
}


void HashTable::deleteItem(string key) {
	int hashValue = hash<string>{}(key) % this->getSize();
	tuple<string, int, int> pair = this->getTable()[hashValue];
	string keyInPlace = get<0>(pair); 
	if (keyInPlace == key) {
		this->getTable()[hashValue] = { "", NULL, NULL};
		this->setNumOfItems(this->getNumOfItems() - 1);
	}
}


tuple<std::string, int> HashTable::findItemByValue(int value) {
	for (int i = 0; i < this->getSize(); i++) {
		tuple<std::string, int, int> hashPairInPlace = this->getTable()[i];
		if (get<1>(hashPairInPlace) == value) {
			return { get<0>(hashPairInPlace), get<1>(hashPairInPlace) };
		}
	}
	throw HashException("There is no item with that value!");
}


bool HashTable::checkIfExists(std::string key) {
	int hashValue = hash<string>{}(key) % this->getSize();
	if (get<0>(this->getTable()[hashValue]) == key) {
		return true;
	}
	return false;
}


HashTable HashTable::operator+(HashTable& other) {
	int numOfItems = 0;
	int size = this->getSize();
	HashTable newHash = HashTable(size);
	if (this->getSize() != other.getSize()) {
		throw HashException("Different size of tables!"); 
	}
	for (int i = 0; i < size; i++) {
		if (get<2>(other.getTable()[i]) == 1)
		{
			newHash.setTableItem(other.getTable()[i], i);
			newHash.setNumOfItems(newHash.getNumOfItems() + 1);

		}
		else if (get<2>(this->getTable()[i]) == 1) {
			newHash.setTableItem(this -> getTable()[i], i);
			newHash.setNumOfItems(newHash.getNumOfItems() + 1);

		}

	}

	return newHash;
}


void HashTable::operator+=(HashTable& other) {
	int numOfNewItems = 0;
	if (this->getSize() != other.getSize()) {
		throw HashException("Different size of tables!");
	}
	for (int i = 0; i < this->getSize(); i++) {
		if (get<2>(other.getTable()[i]) == 1)
		{
			if (get<2>(this->getTable()[i]) == 0) {
				numOfNewItems += 1;
			}
			this->setTableItem(other.getTable()[i], i);
		}
	}
	this->setNumOfItems(this->getNumOfItems() + numOfNewItems);
}


bool HashTable::operator==(HashTable& other) {
	if (this->getSize() != other.getSize()) {
		return false;
	}
	for (int i = 0; i < this->getSize(); i++) {
		if (this->getTable()[i] != other.getTable()[i]) {
			return false;
		}
	}
	return true;
}

bool HashTable::operator!=(HashTable& other) {
	return !(this->operator==(other));
}
