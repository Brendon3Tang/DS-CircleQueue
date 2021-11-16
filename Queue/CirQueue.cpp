#include "CirQueue.h"

template<class DataType>
CirQueue<DataType>::CirQueue()
{
	this->data = new DataType[CIR_QUEUE_SIZE];
	this->front = -1;
	this->rear = -1;
	this->queueSize = 0;
}

template<class DataType>
CirQueue<DataType>::CirQueue(int size)
{
	this->arrSize = size;
	this->data = new DataType[this->arrSize];
	this->front = -1; // front is always at one place ahead of the frist item in the queue.
	this->rear = -1; // rear is alaways at the palce of the last item
	this->queueSize = 0;
}

template<class DataType>
CirQueue<DataType>::~CirQueue()
{
	delete[] data;
	for (int i = 0; i < this->arrSize; i++)
	{
		data[i] = NULL;
	}
}

template<class DataType>
bool CirQueue<DataType>::enQueue(DataType storedData)
{
	// if the queue is full, return false since we can not enqueue any item
	if (isFull())
		return false;

	//if it's not full, we enqueue
	this->rear = (this->rear + 1) % this->arrSize; //we put the rear-ptr to the latest place (use modulo since it is a circle queue, once we 
												   // reach the bound of the array, we go back to the head of the array.)
	data[this->rear] = storedData;// put the data into the queue
	//cout << "data is:" << data[this->rear] << endl;
	queueSize++; //increase the queue size
	return true;
}

template<class DataType>
bool CirQueue<DataType>::deQueue(DataType& storedData)
{
	// if the queue is empty, return false since we can not dequeue any item
	if (isEmpty())
		return false;

	//dequeue....
	this->front = (this->front + 1) % this->arrSize;//move the front-ptr to the place of the first data in array so that we can 
													//give it to the parameter that will be returned later.
	storedData = data[front];//let the parameter that we will return later get the value of the first data in the array.
	queueSize--; //decrease the size of the queue
	return true; //suscessfully dequeue, so return true.
}

template<class DataType>
bool CirQueue<DataType>::getFront(DataType& storedData)
{
	int i;
	if (isEmpty())
		return false;
	i = (this->front + 1) % this->arrSize;// similiar to the dequeue, except we dont change the value of the front-ptr.
	storedData = data[i];
	//cout << "test:frontÊÇ£º" << storedData << endl;
	return true;
}

template<class DataType>
bool CirQueue<DataType>::isEmpty()
{
	/*if ((this->front == this->rear))
		return true;
	return false;*/

	if (queueSize == 0)
		return true;
	return false;
}

template<class DataType>
bool CirQueue<DataType>::isFull()
{
	/*if ((this->rear + 1) % this->arrSize == this->front)
		return true;
	return false;*/

	if (queueSize == arrSize)
		return true;
	return false;
}

template<class DataType>
void CirQueue<DataType>::clearQueue()
{
	this->queueSize = 0;
}

template<class DataType>
void CirQueue<DataType>::displayQueue()
{
	int index = 0;
	index = front + 1;

	cout << "The queue is: " << endl;
	for(int i =0; i < queueSize; i++)
	{
		cout << data[index] << " ";
		index = (index + 1) % this->arrSize;
	}
	cout << endl;
}

template<class DataType>
int CirQueue<DataType>::queueLength()
{
	return queueSize;
}

int main()
{
	CirQueue<int> cq(5);
	int item = 0;

	//test isEmpty() function when it is empty
	cout << "is empty? : " << cq.isEmpty() << endl; 

	////enqueue 200 300 400 500 600. And 700(out of the index)
	cq.enQueue(200); 
	cq.enQueue(300);
	// test isFull() function when it is not full
	cout << "is full? : " << cq.isFull() << endl; 
	cq.enQueue(400);
	cq.enQueue(500);
	cq.enQueue(600);
	cq.enQueue(700); // fail to execute since the array has been full

	//test display function
	cq.displayQueue();

	cout << "queue length is: " << cq.queueLength() << endl; // test length function

	if(cq.getFront(item)) // test getFront function 
		cout << "the front is: " << item << endl;

	//test isEmpty() function when it is not empty
	cout << "is empty? : " << cq.isEmpty() << endl; 
	// test isFull() function when it is full
	cout << "is full? : " << cq.isFull() << endl;

	//test deQueue function to dequeue 200 300 400 500 600 
	int dequeueTimes = cq.queueLength() + 1;
	for (int i = 0; i < dequeueTimes; i++)
	{
		if (cq.deQueue(item))
			cout << "dequeue: " << item << endl;
		else
			cout << "the queue is empty" << endl;
	}

	//test clear queue function
	cq.enQueue(123456);
	cout << "then length of the queue is: " << cq.queueLength() <<endl;
	cq.clearQueue();
	cout << "after cleaning, the queue length is: " << cq.queueLength() << endl;

	return 0;
}