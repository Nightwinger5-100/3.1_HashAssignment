#include <iostream>
#include <list>
#include <cstring>
#include "hashtable.h"
using namespace std;

//checks each list to make sure it has at least 1 index
bool HashTable::isEmpty() const
{
	int sum{};
		for (int i{}; i < this->hashGroups; i++)
		{
			sum += table[i].size();

			if (sum)
			{
				return true;
			}
		}

		if (!sum)
		{
			return false;
		}
}

void HashTable::insertData(int key, string value)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (; bItr != end(cell); bItr++)
	{
		if (bItr-> first == key)
		{
			keyExists = true;
			bItr->second = value;
			cout << "value exits value replaced" << endl;
		}
	}

	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}
}

bool HashTable::deleteData(int key)
{
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "value removed" << endl;
			return true;
		}
	}

	if (!keyExists)
	{
		cout << "oitem not found" << endl;
		return false;
	}
}

void HashTable::displayHashTable()
{
	for (int i{}; i < hashGroups; i++)
	{
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (bItr; bItr != table[i].end(); bItr++)
		{
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
}

int HashTable::hashKey(int key)
{
	return key % hashGroups;
}

