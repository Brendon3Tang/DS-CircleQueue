#pragma once
#include<iostream>
using namespace std;

const int CIR_QUEUE_SIZE = 100;

template<class DataType>
class CirQueue
{
private:
	DataType* data;
	int front, rear, arrSize,queueSize;
public:
	CirQueue();

	CirQueue(int size);

	~CirQueue();

	bool enQueue(DataType storedData);

	bool deQueue(DataType &storedData);

	bool getFront(DataType &storedData);

	bool isEmpty();

	bool isFull();

	void clearQueue();

	void displayQueue();

	int queueLength();

};