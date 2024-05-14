#pragma once

#include <cassert>
#include <iostream>
#include "QueueADT.h"

using namespace std;

template <class Type>
class ArrayQueue : public QueueADT<Type> {
public:
	const ArrayQueue<Type>& operator=(const ArrayQueue<Type>&);
	bool isEmpty() const;
	bool isFull() const;
	void initializeQueue();
	Type  front() const;
	Type  back() const;
	void addQueue(const Type& queueElement);
	void deleteQueue();
	ArrayQueue(int queueSize = 100);
	ArrayQueue(const ArrayQueue<Type>& otherQueue);
	~ArrayQueue();
	void deQueue();
private:
	int maxSize;
	int count;
	int qFront;
	int qRear;
	Type* list;
};

template <class Type>
bool ArrayQueue<Type>::isEmpty() const {
	return (count == 0);
}

template <class Type>
bool ArrayQueue<Type>::isFull() const {
	return (count == maxSize);
}

template <class Type>
void ArrayQueue<Type>::initializeQueue() {
	qFront = 0;
	qRear = maxSize - 1;
	count = 0;
}

template <class Type>
Type ArrayQueue<Type>::front() const {
	assert(!isEmpty());
	return list[qFront];
}

template <class Type>
Type ArrayQueue<Type>::back() const {
	assert(!isEmpty());
	return list[qRear];
}

template <class Type>
void ArrayQueue<Type>::addQueue(const Type& newElement) {
	if (!isFull()) {
		qRear = (qRear + 1) % maxSize;
		count++;
		list[qRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
}

template <class Type>
void ArrayQueue<Type>::deleteQueue() {
	if (!isEmpty()) {
		count--;
		qFront = (qFront + 1) % maxSize;
	}
	else
		cout << "Cannot remove from an empty queue " << endl;
}

template <class Type>
ArrayQueue<Type>::ArrayQueue(int size) {
	if (size <= 0) {
		cout << "Size of the array to hold the queue must " << "be positive. " << endl;
		cout << "Creating an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;

	qFront = 0;
	qRear = maxSize - 1;
	count = 0;
	list = new Type[maxSize];
}

template <class Type>
ArrayQueue<Type>::~ArrayQueue() {
	delete[] list;
}

template <class Type>
const ArrayQueue<Type>& ArrayQueue<Type>::operator=(const ArrayQueue& otherQueue) {
	return otherQueue;
}

template <class Type>
ArrayQueue<Type>::ArrayQueue(const ArrayQueue<Type>& otherQueue) {
}
template <class Type>
void ArrayQueue<Type>::deQueue()
{
	if (!isEmpty()) {
		cout << this->list[this->qFront];
		this->count--;
		this->qFront = (this->qFront + 1) % this->maxSize;
	}

	else
		cout << "Cannot remove from an empty queue " << endl;

	
}




