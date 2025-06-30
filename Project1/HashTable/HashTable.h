#pragma once
#include <tuple>
#include <string>

class HashTable 
{
public:
	HashTable(int size);
	int getSize();
	std::tuple<std::string, int, int>* getTable();
	int getNumOfItems();
	void setTable(std::tuple<std::string, int, int>* table);
	void setTableItem(std::tuple<std::string, int, int> pair, int place);
	void setNumOfItems(int num);
	void addPair(std::string key, int value);
	std::tuple<std::string, int> findItemByKey(std::string key);
	void deleteItem(std::string key);
	int numOfItems();
	std::tuple<std::string, int> findItemByValue(int value);
	bool checkIfExists(std::string key);
	HashTable operator+(HashTable& other);
	void operator+=(HashTable& other);
	bool operator==(HashTable& other);
private:
	std::tuple<std::string, int, int>* m_table;
	int m_tableSize;
	int m_numOfItems;
};