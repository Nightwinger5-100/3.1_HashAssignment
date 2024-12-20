#pragma once
#include <iostream>
#include <list>
#include <cstring>

using namespace std;
class HashTable
{

	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertData(int key, string values);
	int hashKey(int data);
	void displayHashTable();
	bool findValue(int data);
	bool deleteData(int data);

};
