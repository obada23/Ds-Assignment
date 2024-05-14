#pragma once
template <class Type>
class QueueADT {
public:
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
	virtual void addQueue(const Type& queueElement) = 0;
	virtual void deleteQueue() = 0;
};

