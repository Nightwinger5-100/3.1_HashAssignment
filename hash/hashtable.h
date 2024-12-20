#pragma
#include<list>
#include<string>

using namespace std;

class HashTable
{
    int numkeys;
    list<string>* hashT;

public:
    HashTable(int numkeys);
    void insertData(const string& data);
    int hashKey(const string& data);
    void displayHashTable();
    unsigned int getHashedText(const string& data);
    bool findValue(const string& data);
    bool deleteData(const string& data);
    
};
