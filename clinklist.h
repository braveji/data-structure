//ѭ������
//ѭ������0���͡�6����
//1 ����ж������Ƿ��л���
//

#include <iostream>

using namespace std;

struct CLinkListNode
{
	char data;
	CLinkListNode * next;
};

typedef CLinkListNode * CLinkList;

CLinkList buildCLinkList0(CLinkList & head)
{
	cout<<"����ѭ������"<<endl<<"��������Ϣ����#����: "<<ends;
	char data;
	cin >> data;
	if (data == '#')
	{
		return head;
	}
	head = new CLinkListNode;
	head->data = data;
	head ->next = head;
	CLinkList current = head;

	while(cin >> data && data!='#')
	{
		CLinkList node = new CLinkListNode;
		node ->data = data;

		//β�巨
		node ->next = current->next;
		current->next = node;

		current = node;
	}
	return head;
}

void traverCLinkList(CLinkList head)
{
	cout<<"����ѭ������"<<endl;
	cout<<head->data<<ends;
	CLinkList current = head->next;
	while(current != head)
	{
		cout<<current->data<<ends;
		current = current->next;
	}
	cout<<endl;
}

int CLinkListLen(CLinkList head)
{
	int len=0;
	if (!head)
	{
		return len;
	}
	CLinkList current = head->next;
	len++;
	while(current!=head)
	{
		len++;
		current = current->next;
	}
	return len;
}

void destroyCLinkList(CLinkList head)
{
	if (!head)
	{
		return ;
	}
	CLinkList current = head->next,temp;
	delete head;
	while(current!=head)
	{
		temp =current->next;
		delete current;
		current = temp;
	}
}


//����6��������
