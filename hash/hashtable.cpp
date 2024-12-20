#include <iostream>
#include "hashtable.h"
#include <cstdlib>
#include <list>
#include <string>

using namespace std;

//creates the hash list
HashTable::HashTable(int numkeys)
{
	//this references something created inside the header(in this case numkeys)
	//takes the parameter numkeys and assigns it as the number of keys in the hashtable(hashtable.h)
	this->numkeys = numkeys;
	//create a new list that takes in int items, with the size of numkets
	hashT = new list<string>[numkeys];
}

//insert the string into one of the hash lists
void HashTable::insertData(const string& data)
{
	//get the value to add to the Hashtable
	int dataKey = hashKey(data);
	//push the item into the end of the hashT list, located at the index of datakey
	hashT[dataKey].push_back(data);

}

//gets the value of the string and returns the value of its remainder divided by numkeys
int HashTable::hashKey(const string& data)
{
	unsigned int hashVal = 0; //unsigned prevents the number from being negative

	//for each character inside the string
	for (char ch : data)
	{
		//multiply hash by 37 + that char value, and set hash to that value
		hashVal = 37 * hashVal + ch;
	}

	//return the remainder of the data value divided by the number of keys value
	return hashVal % numkeys;
}

//display every value in each list
void HashTable::displayHashTable()
{
	//for each list of items
	for (int i = 0; i < numkeys-1; i++)
	{
		//this is the current index
		cout << i << ": ";
		//auto x : = automatically assign x from...
		//essentially set x = to each value inside the list at the i index
		for (auto x : hashT[i])
		{
			//output the value
			cout << "-->" << x;
		}
		cout << "\n";
	}
}

//gets the string as a hash number
unsigned int HashTable::getHashedText(const string& data) //unsigned prevents the number from being negative
{
	unsigned long hash = 0; //long helps avoid overflow
	//for each char inside the string
	for (char c : data) 
	{
		//multiply hash by 31 + that char value, and set hash to that value
		hash = (hash * 31 + c);
	}

	//return the hash text
	return hash % UINT_MAX; //% UINT_MAX helps avoid overflow
}

//tries to find a string value
bool HashTable::findValue(const string& data)
{
	//get the value to search for inside the Hashtable
	int dataKey = hashKey(data);
	//bool for the while loop
	bool found = false;
	//iterator allows a value to iterate(move) through a list
	//creates i as a value to loop and identify values within the hashtable's list
	list <string>::iterator i;
	//the list will begin iterating at the numkey list of datakey
	i = hashT[dataKey].begin();

	//when the item isn't yet found, and it's not the end of the list
	while (!found && i != hashT[dataKey].end())
	{
		//pointer to i because it is a iterator
		//if i is the same value and the value to find
		cout << *i << endl;
		cout << data << endl;

		//if the value is found
		if (*i == data)
		{
			cout << "Found " << data << endl;
			return true;
		}
		//otherwise...
		else
		{
			//go to the next index
			i++;
		}
	}

	//if i hasn't reached the end of the list...
	if (i != hashT[dataKey].end())
	{
		return true;
	}
	//if the end of the list has been reached then...
	else
	{
		cout << "Couldn't find the item..." << endl;
		return false;
	}
}

//tries to find and remove a string value from the hash
bool HashTable::deleteData(const string& data)
{
	//get the value to search for and delete inside the Hashtable
	int dataKey = hashKey(data);
	//bool for the while loop
	bool found = false;
	//creates i as a value to loop and identify values within a hashtable
	list <string>::iterator i;
	i = hashT[dataKey].begin();

	//when the item isn't yet found, and it's not the end of the list
	while (!found && i != hashT[dataKey].end())
	{
		//pointer to i because it is a iterator
		//if i is the same value and the value to find
		if (*i == data)
		{
			//stops the loop
			found = true;
		}
		else
		{
			//go to the next index
			i++;
		}
	}

	//if i hasn't reached the end of the list yet
	if (i != hashT[dataKey].end())
	{
		cout << data << " has been found and removed" << endl;
		//deletes value of data key from the htable @ i
		hashT[dataKey].erase(i);
		return true;
	}
	//if the end of the list has been reached then...
	else
	{
		cout << "Couldn't find the item..." << endl;
		return false;
	}
}


