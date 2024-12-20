#pragma once
#include <iostream>
#include "hashtable.h"
#include <cstdlib>
#include <list>
#include <chrono>
#include <cstring>

int main()
{
	//number of indexs for the linked lists
	HashTable strHashT(7);

	//start time for the lists to be created
	auto start = std::chrono::high_resolution_clock::now();

	//the strings that will be added into the hash
	strHashT.insertData("Street Fighter");
	strHashT.insertData("Tekken");
	strHashT.insertData("Mortal Kombat");
	strHashT.insertData("Super Smash Bros.");
	strHashT.insertData("Soulcalibur");
	strHashT.insertData("Guilty Gear");
	strHashT.insertData("Dragon Ball FighterZ");
	strHashT.insertData("Injustice");
	strHashT.insertData("BlazBlue");
	strHashT.insertData("King of Fighters");

	//end the timer once the loop is done adding items
	auto end = std::chrono::high_resolution_clock::now();

	//calculate and print that difference
	std::chrono::duration<double> elapsed = end - start;
	std::cout << " HT 1000 Elapsed time: " << elapsed.count() << " seconds" << std::endl;

	//display each index in the hash
	strHashT.displayHashTable();

	//if SF exists in the one of the hash lists
	if (strHashT.findValue("Street Fighter"))
	{
		//print the hash string for street fighter
		cout << "It's hash text is: " << strHashT.getHashedText("Street Fighter") << endl;;

		//find and remove Street fighter from the hash
		strHashT.deleteData("Street Fighter");

		//display each index in the hash after the SF removal
		strHashT.displayHashTable();
	}
	//if SF doesn't exist in the hash...
	else
	{
		cout << "Street fighter doesn't exist!" << endl;
	}

	return 0;
}