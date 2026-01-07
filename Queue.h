#pragma once
// #include "HuffmanNode.h"
class HuffmanNode;
class Queue
{
protected:
	HuffmanNode **arr;
	int maxSize;
	int currentSize;

public:
	Queue(int);
	virtual ~Queue();

	virtual void enqueue(HuffmanNode *) = 0;
	virtual HuffmanNode *dequeue() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
};

Queue::Queue(int s)
{
	maxSize = s;
	currentSize = 0;
	arr = new HuffmanNode *[s];
}

Queue::~Queue()
{
	delete[] arr;
}