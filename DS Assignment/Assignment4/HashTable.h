#pragma once 
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template <typename T>
class HashTable {
public:
    void insert(int hashIndex, const T& rec);
    bool search(int& hashIndex, const T& rec) const;
    bool isItemAtEqual(int hashIndex, const T& rec) const;
    T retrieve(int hashIndex) const;
    void remove(int hashIndex, const T& rec);
    void print() const;
    HashTable(int size = 101);
    ~HashTable();
    HashTable(const HashTable<T>& other);
    HashTable<T>& operator=(const HashTable<T>& other);
private:
    T* HTable;       
    int* indexStatusList;   
    int length;             
    int HTSize;              
};

template <typename T>
void HashTable<T>::insert(int hashIndex, const T& rec) {
    int pCount = 0;
    int inc = 1;

    while (this->indexStatusList[hashIndex] == 1 && this->HTable[hashIndex] != rec && pCount < HTSize / 2) {
        pCount++;
        hashIndex = (hashIndex + inc) % this->HTSize;
        inc = (inc + 2) % this->HTSize; 
    }

    if (this->indexStatusList[hashIndex] != 1) {
        this->HTable[hashIndex] = rec;
        this->indexStatusList[hashIndex] = 1;
        this->length++;
    }
    else if (this->HTable[hashIndex] == rec)
        cerr << "Error: No duplicates are allowed." << endl;
    else
        cerr << "Error: The table is full. " << "Unable to resolve the collision." << endl;
}

template <typename T>
bool HashTable<T>::search(int& hashIndex, const T& rec) const {
    int pCount = 0;
    int inc = 1;

    while (this->indexStatusList[hashIndex] != 0 && this->HTable[hashIndex] != rec && pCount < HTSize / 2) {
        pCount++;
        hashIndex = (hashIndex + inc) % this->HTSize;
        inc = (inc + 2) % this->HTSize;
    }
    return (this->indexStatusList[hashIndex] == 1 && this->HTable[hashIndex] == rec);
}

template <typename T>
bool HashTable<T>::isItemAtEqual(int hashIndex, const T& rec) const {
    return (this->HTable[hashIndex] == rec);
}

template <typename T>
T HashTable<T>::retrieve(int hashIndex) const {
    if (this->indexStatusList[hashIndex] == 1)
        return this->HTable[hashIndex];
    else
        return "";
}

template <typename T>
void HashTable<T>::remove(int hashIndex, const T& rec) {
    bool found = search(hashIndex, rec);

    if (found) {
        this->indexStatusList[hashIndex] = -1;
        this->length--;
    }
    else
        cerr << "The item to be deleted is not in the list." << endl;
}

template <typename T>
void HashTable<T>::print() const {
    for (int i = 0; i < this->HTSize; i++)
        if (this->indexStatusList[i] != 0){
            cout << "(" << i << ", " << this->indexStatusList[i] << ", " << HTable[i] << " ) ,";
        } 
    cout << endl;
}

template <typename T>
HashTable<T>::HashTable(int size) {
    assert(size > 0);

    this->HTable = new T[size];
    this->indexStatusList = new int[size];
    this->length = 0;
    this->HTSize = size;

    for (int i = 0; i < size; i++)
        this->indexStatusList[i] = 0;
}

template <typename T>
HashTable<T>::~HashTable() {
    delete[] this->HTable;
    delete[] this->indexStatusList;
}

int hashFunction(const string& str, int HTSize) {
    int sum = 0;
    char c ;
    for (int i = 0; i < str.length(); i++) {
        c= str[i];
        sum += static_cast<int>(c);
    }

    return sum % HTSize;
}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& other) {
    this->length = other.length;
    this->HTSize = other.HTSize;
    
    this->HTable = new T[this->HTSize];
    this->indexStatusList = new int[this->HTSize];
    
    for (int i = 0; i < this->HTSize; i++) {
        this->HTable[i] = other.HTable[i];
        this->indexStatusList[i] = other.indexStatusList[i];
    }
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable& other) {
    if (this != &other) { 
        delete[] this->HTable;
        delete[] this->indexStatusList;
        
        this->length = other.length;
        this->HTSize = other.HTSize;
        
        this->HTable = new T[this->HTSize];
        this->indexStatusList = new int[this->HTSize];
        
        for (int i = 0; i < this->HTSize; i++) {
            this->HTable[i] = other.HTable[i];
            this->indexStatusList[i] = other.indexStatusList[i];
        }
    }
    return *this;
}

template <typename T>
void testCopyConstructor(const HashTable<T>& o) {
    
    HashTable<T> copyHT(o);
    cout << "Copy Constructor :-" << endl;
    cout << "---------------------  " << endl;
    cout << "Original:" << endl;
    o.print();

    cout << "\nCopy:" << endl;
    copyHT.print();
    cout << endl;

}

void testAssignmentOperator(const HashTable<string>& T) {
    HashTable<string> copyHT; 
    copyHT = T;
    cout << "Assignment Operator :-" << endl;
    cout << "---------------------  " << endl;
    cout << "\nOriginal:" << endl;
    T.print();

    cout << "\nCopy:" << endl;
    copyHT.print();

    cout << endl;

}


