#include <iostream>
#include <cstdlib>
#include "HashTable.h"

using namespace std;

int main() {
    cout << endl;
    int hashTableSize = 101;

    int k = hashFunction("Ahmad", hashTableSize);
    cout << k << endl<< endl;

    HashTable<string> ht(hashTableSize); 

    int id = hashFunction("apple", hashTableSize);
    ht.insert(id, "apple");

    ht.insert(hashFunction("linux", hashTableSize), "linux");
    ht.insert(hashFunction("mac", hashTableSize), "mac");
    ht.insert(hashFunction("white", hashTableSize), "white");
    ht.insert(hashFunction("pen", hashTableSize), "pen");
    ht.insert(hashFunction("data", hashTableSize), "data");
    ht.insert(hashFunction("lemon", hashTableSize), "lemon");
    ht.insert(hashFunction("red", hashTableSize), "red");
    ht.insert(hashFunction("mango", hashTableSize), "mango");
    ht.insert(hashFunction("blackforest", hashTableSize), "blackforest");

    int hashIndex1 = hashFunction("mango", hashTableSize);
    if (ht.search(hashIndex1, "mango")) {
        cout << "Found: " << ht.retrieve(hashIndex1) << endl;
    } else {
        cout << "Not found: mango" << endl;
    }

    int hashIndex2 = hashFunction("lemon", hashTableSize);
    if (ht.search(hashIndex2, "lemon")) {
        cout << "Found: " << ht.retrieve(hashIndex2) << endl;
    } else {
        cout << "Not found: lemon" << endl;
    }

    int hashIndex3 = hashFunction("pizza", hashTableSize);
    if (ht.search(hashIndex3, "pizza")) {
        cout << "Found: " << ht.retrieve(hashIndex3) << endl;
    } else {
        cout << "Not found: pizza" << endl;
    }
    cout << endl;

    testCopyConstructor(ht);
    testAssignmentOperator(ht); 

    return 0;
}

