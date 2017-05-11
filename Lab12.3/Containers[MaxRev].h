#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
	int _info;
	struct Node *link;
}*top;

class CustStack
{
public:
	CustStack();
public:
	Node *push(Node*, int);
	Node *pop(Node*);
	void traverse(Node*);	
};
class CustDeque
{
private:
	Node* front;
	Node* rear;
	int count;

public:
	CustDeque();
	int Front();
	int Back();
	void InsertFront(int);
	int RemoveFront();
	void InsertBack(int);
	int RemoveBack();
	int Size();
	bool isEmpty();
};
class ÑustQueue
{
private:
	int data[MAX_SIZE];
	int front;
	int rear;
public:
	ÑustQueue();
	void Enqueue(int);
	int Dequeue();
	int Front();
	int Size();
	bool isEmpty();
};

class QueueOverFlowException
{
public:
	QueueOverFlowException();
};
class QueueEmptyException {};
class DequeEmptyException
{
public:
	DequeEmptyException();
};
