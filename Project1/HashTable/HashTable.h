#pragma once
#include <tuple>
#include <string>

class HashTable 
{
public:
	/**
	* Builder for HashTable class
	* @param1 size the size of the hash table
	* @return An HashTable item 
	*/
	HashTable(int size);

	/**
	* HashTable method to get the size of the table
	* @return int value of the size
	*/
	int getSize();
	
	/**
	* HashTable method to get the table
	* @return pointer to array of tuple(string, int, int) that represent the table
	*/
	std::tuple<std::string, int, int>* getTable();

	/**
	* HashTable method to get the number of arguments in the table
	*/
	int getNumOfItems();

	/**
	* HashTable method to set new table to the HaseTable class
	* @param table a pointer to the new table 
	*/
	void setTable(std::tuple<std::string, int, int>* table);

	/**
	* HashTable method to set a specific item to the table
	* @param pair an item to set in the table
	* @param place an int that represent the place in the table to put the item
	*/
	void setTableItem(std::tuple<std::string, int, int> pair, int place);

	/**
	* HashTable method to set number of items that in the table
	* @param num the number of items to set to the table
	*/
	void setNumOfItems(int num);

	/**
	* HashTable method to add item to the table
	* @param key the key of the item
	* @param value the value of the item
	*/
	void addPair(std::string key, int value);

	/**
	* HashTable method to find an item by its key
	* @param key the key of the item we need to find
	* @return a tuple(string, int) of the item
	*/
	std::tuple<std::string, int> findItemByKey(std::string key);

	/**
	* HashTable method to delete an item by its key
	* @param key the key of the item to delete
	*/
	void deleteItem(std::string key);

	/**
	* HashTable method to find an item by a value
	* @param value the value of the item we need to find
	* @return a tuple(string, int) of the item
	*/
	std::tuple<std::string, int> findItemByValue(int value);

	/**
	* HashTable method to check if some key is exists in the table
	* @param key the key of the item to find
	* @return boolean value of the existence
	*/
	bool checkIfExists(std::string key);

	/**
	* HashTable method of the operator + to do addition of 2 HashTables
	* @param other a HashTable to add to self
	* @return an HashTable that represent the addition 
	*/
	HashTable operator+(HashTable& other);

	/*
	** HashTable method of the operator += to add other HashTable to current HashTable
	* @param other a HashTable to add to the current HashTable
	*/
	void operator+=(HashTable& other);

	/**
	* HashTable method of the operator == to compare 2 HashTables
	* @param other HashTable to compare to currnt HashTable
	* @return boolean value of the comparison
	*/
	bool operator==(HashTable& other);

	/**
	* HashTable method of the operator != to check diffrence between 2 HashTables
	* @param other HashTable to compare to currnt HashTable
	* @return boolean value of the difference
	*/
	bool operator!=(HashTable& other);

private:

	std::tuple<std::string, int, int>* m_table; // A pointer to the hash table
	int m_tableSize; // The size of the table
	int m_numOfItems; // Number of items in the table
};