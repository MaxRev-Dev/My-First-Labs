#include "Containers[MaxRev].h"
const int MAX_SIZE = 100;

CustStack::CustStack()
{
	top = NULL;
}
Node * CustStack::push(Node *top, int item)
{
	Node *tmp;
	tmp = new (struct  Node);
	tmp->_info = item;
	tmp->link = top;
	top = tmp;
	return top;
}
Node * CustStack::pop(Node *top)
{
	Node *tmp;
	if (top == NULL) {
		cout << "Stack is empty";
	}
	else {
		tmp = top;
		cout << "Element Popped" << tmp->_info << endl;
		top = top->link;
		free(top);
	}
	return top;
}
void CustStack::traverse(Node *)
{
	Node *ptr;
	ptr = top;
	if (top == NULL)
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Stack elements :" << endl;
		while (ptr != NULL)
		{
			cout << ptr->_info << endl;
			ptr = ptr->link;
		}
	}
}

CustDeque::CustDeque()
{
	front = NULL;
	rear = NULL;
	count = 0;
}
void CustDeque::InsertFront(int element)
{
	// Create a new node
	Node* tmp = new Node();
	tmp->data = element;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (isEmpty()) {
		// Add the first element
		front = rear = tmp;
	}
	else {
		// Prepend to the list and fix links
		tmp->next = front;
		front->prev = tmp;
		front = tmp;
	}

	count++;
}
int CustDeque::RemoveFront()
{
	if (isEmpty()) {
		throw new DequeEmptyException();
	}

	int ret = front->data;

	Node* tmp = front;
	if (front->next != NULL)
	{
		front = front->next;
		front->prev = NULL;
	}
	else
	{
		front = NULL;
	}
	count--;
	delete tmp;

	return ret;
}
void CustDeque::InsertBack(int element)
{
	Node* tmp = new Node();
	tmp->data = element;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (isEmpty()) {
		front = rear = tmp;
	}
	else {
		rear->next = tmp;
		tmp->prev = rear;
		rear = tmp;
	}

	count++;
}
int CustDeque::RemoveBack()
{
	if (isEmpty()) {
		throw new DequeEmptyException();
	}

	int ret = rear->data;

	Node* tmp = rear;
	if (rear->prev != NULL)
	{
		rear = rear->prev;
		rear->next = NULL;
	}
	else
	{
		rear = NULL;
	}
	count--;
	delete tmp;

	return ret;
}
int CustDeque::Front()
{
	if (isEmpty())
		throw new DequeEmptyException();

	return front->data;
}
int CustDeque::Back()
{
	if (isEmpty())
		throw new DequeEmptyException();

	return rear->data;
}
int CustDeque::Size()
{
	return count;
}
bool CustDeque::isEmpty()
{
	return count == 0 ? true : false;
}
DequeEmptyException::DequeEmptyException()
{
	cout << "Deque empty" << endl;
}

ÑustQueue::ÑustQueue()
{
	front = -1;
	rear = -1;
}
void ÑustQueue::Enqueue(int element)
{
	if (Size() == MAX_SIZE - 1)
		throw new QueueOverFlowException();

	data[rear] = element;

	rear = ++rear % MAX_SIZE;
}
int ÑustQueue::Dequeue()
{
	if (isEmpty())
		throw new QueueEmptyException();

	int ret = data[front];

	front = ++front % MAX_SIZE;

	return ret;
}
int ÑustQueue::Front()
{
	if (isEmpty())
		throw new QueueEmptyException();

	return data[front];
}
int ÑustQueue::Size()
{
	return abs(rear - front);
}
bool ÑustQueue::isEmpty()
{
	return (front == rear) ? true : false;
}

QueueOverFlowException::QueueOverFlowException()
{
	cout << "Queue overflow" << endl;
}
QueueEmptyException::QueueEmptyException()
{
	cout << "Queue empty" << endl;
}
