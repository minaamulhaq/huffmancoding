#pragma once
#include <iostream>
#include "HuffmanNode.h"
class HuffmanNode;

using namespace std;
class myQueue
{
    HuffmanNode **arr;
    int maxSize;
    int currentSize;

public:
    myQueue(int);
    ~myQueue();
    void enqueue(HuffmanNode *);
    HuffmanNode *dequeue();
    bool isFull();
    bool isEmpty();
};


inline myQueue::myQueue(int s)
{
    maxSize = s;
    currentSize = 0;
    arr = new HuffmanNode *[s];
}

inline void myQueue::enqueue(HuffmanNode *n)
{
    if (isFull())
        return;

    int i = currentSize - 1;
    while (i >= 0 && arr[i]->getFrequency() > n->getFrequency())
    {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = n;
    currentSize++;
}

inline bool myQueue::isFull()
{
    return currentSize == maxSize;
}

inline bool myQueue::isEmpty()
{
    return currentSize == 0;
}

inline HuffmanNode *myQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
        return nullptr;
    }

    HuffmanNode *temp = arr[0];

    for (int i = 0; i < currentSize - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    currentSize--;
    return temp;
}

inline myQueue::~myQueue()
{
    for (int i = 0; i < currentSize; i++)
        delete arr[i];

    delete[] arr;
}

// #endif