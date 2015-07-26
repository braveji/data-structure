//栈---特点：先进后出(相当于链表的头插法)
#include <iostream>
using namespace std;

struct StackNode
{
	char data;
	StackNode * next;
};

typedef StackNode* Stack;

Stack stackPush(Stack &head,char data)
{
	Stack node = new StackNode;
	node ->data = data;
	node ->next = head;
	head = node;
	return head;
}

char stackTop(Stack head)
{
	return head->data;
}

int stackLen(Stack head)
{
	int len=0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return len;
}

Stack stackPop(Stack & head)
{
	Stack top = head;
	if (!head)
	{
		return head;
	}
	head = head->next;
	delete top;
	return head;
}

void traverStack(Stack head)
{
	while(head)
	{
		cout<<head->data<<ends;
		head = head->next;
	}
}

void StackDestroy(Stack head)
{
	Stack temp;
	while(head)
	{
		temp =head->next;
		delete head;
		head = temp;
	}
}