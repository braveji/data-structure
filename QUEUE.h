//队列---先进先出(相当于尾插法)
#include <iostream>

using namespace std;

struct QueueNode
{
	char data;
	QueueNode * next;
};

typedef QueueNode * Queue;

Queue QueuePush(Queue & que,char data)
{
	Queue node = new QueueNode;
	node ->data = data;
	node ->next = NULL;
	if (!que)
	{
		que = node;
		return que;
	}
	Queue current = que;
	while(current->next)
	{
		current = current->next;
	}
	Queue &temp = current->next;//特别注意值传递和引用传递
	temp = node;
	//current->next = node;
	return que;
}

void traverQueue(Queue que)
{
	while(que)
	{
		cout<<que->data<<ends;
		que = que->next;
	}
	cout<<endl;
}

char queueTop(Queue que)
{
	return que->data;
}

Queue queuePop(Queue &que)
{
	if (!que)
	{
		return que; 
	}
	Queue temp = que;
	que = que->next;
	delete temp;
	return que;
}

int queueLen(Queue que)
{
	int len=0;
	while(que)
	{
		len++;
		que = que->next;
	}
	return len;
}

void queueDestroy(Queue que)
{
	while(que)
	{
		Queue temp = que->next;
		delete que;
		que = temp;
	}
}