#include "HashTable.h"
#include <cstddef>
#include <functional>
#include <iomanip>
#include <iostream>
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
	string keyInPlace = get<0>(pair); // TODO: what if there is no item in this place?
	if (keyInPlace == key) {
		return { get<0>(pair), get<1>(pair) };
	}
	else {
		throw "There is no such key in the table"; // TODO: change to class of errors
	}
}


void HashTable::deleteItem(string key) {
	int hashValue = hash<string>{}(key) % this->getSize();
	tuple<string, int, int> pair = this->getTable()[hashValue];
	string keyInPlace = get<0>(pair); // TODO: what if there is no item in this place?
	if (keyInPlace == key) {
		this->getTable()[hashValue] = { "", NULL, NULL};
		this->setNumOfItems(this->getNumOfItems() - 1);
	}
}


int HashTable::numOfItems() {
	return this->getNumOfItems();
}


tuple<std::string, int> HashTable::findItemByValue(int value) {
	for (int i = 0; i < this->getSize(); i++) {
		tuple<std::string, int, int> hashPairInPlace = this->getTable()[i];
		if (get<1>(hashPairInPlace) == value) {
			return { get<0>(hashPairInPlace), get<1>(hashPairInPlace) };
		}
	}
	throw "There is no item with that value!";
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
	HashTable newHash = HashTable(this->getSize());
	tuple<string, int, int>* newTable = new tuple<string, int, int>[this->getSize()];
	if (this->getSize() != other.getSize()) {
		throw "Different size of tables!"; //TODO: class of exceptions
	}
	for (int i = 0; i < this->getSize(); i++) {
		if (get<2>(other.getTable()[i]) == 1)
		{
			newTable[i] = other.getTable()[i];
			numOfItems += 1;
		}
		else if (get<2>(this->getTable()[i]) == 1) {
			newTable[i] = this->getTable()[i];
			numOfItems += 1;
		}
		else {
			newTable[i] = { "", NULL, NULL };
		}
	}
	newHash.setTable(newTable);
	newHash.setNumOfItems(numOfItems);
	return newHash;
}


void HashTable::operator+=(HashTable& other) {
	int numOfNewItems = 0;
	if (this->getSize() != other.getSize()) {
		throw "Different size of tables!"; //TODO: class of exceptions
	}
	for (int i = 0; i < this->getSize(); i++) {
		if (get<2>(other.getTable()[i]) == 1)
		{
			if (get<2>(this->getTable()[i]) == 1) {
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