//˫����
#include <vector>
#include <iostream>
using namespace std;

struct DListNode
{
	char data;
	DListNode * prev;
	DListNode * next;
};

typedef DListNode * DLinkList;

// 1 ����Ľ���
// 2 ���������
// 3 ����Ĳ���
// 4 �����ɾ��
// 5 ����ĳ���
// 6 ���������
// 7 ���������
// 8 ����ı���

DLinkList buildDLinkList(DLinkList & head)
{
	cout<<"����˫��������������Ϣ����#������"<<endl;
	//����ͷ���
	char data;
	//��ʼ����һ�����
	cin >> data;
	if(data=='#')
	{
		head = NULL;
		return head;
	}
	head = new DListNode;
	head->data = data;
	head->next = NULL;
	head->prev = NULL;
	//��ʼ��ʣ��Ľ��
	DLinkList node,current = head;
	while(cin>>data && data!='#')
	{
		node = new DListNode;
		node ->data = data;
		//ͷ�巨
// 		node ->prev = NULL;
// 		node->next = head;
// 		head->prev = node;
// 		head = node;//����������һ�β���

		//β�巨
		node->next = current->next;
		node ->prev = current;
		current->next = node;
		current = node;//����������һ�β���
	}
	return head;
}

void  destroyDLinkList(DLinkList head)
{
	DLinkList current= head;
	while (current)
	{
		DLinkList temp = current ->next;
		delete current;
		current = temp;
	}
}

int DLinkListLen(DLinkList head)
{
	int len =0;
	DLinkList current = head;
	while(current)
	{
		++len;
		current = current->next;
	}
	return len;
}

void traverDLinkList(DLinkList head)
{
	DLinkList current = head,last;
	cout<<"�������"<<endl;
	while(current)
	{
		cout<<current->data<<ends;
		last = current;
		current = current->next; 
	}
	cout<<endl<<"�������"<<endl;
	while(last)
	{
		cout<<last->data<<ends;
		last = last->prev;
	}
	cout<<endl;
}

DLinkList DLinkListInsert(DLinkList &head)
{
	cout<<"˫����Ĳ��룬��ѡ������λ�ã����ڵ���1С�ڵ���"<<DLinkListLen(head)<<ends<<
		",�������Ϣ :"<<ends;
	int pos,len = DLinkListLen(head);
	char data;
	cin >> pos >> data;
	if (pos <1 || pos >len)
		return head;
	//ѡ������λ�ú�Ľ�� ����ǰ��
	DLinkList node = new DListNode;
	node ->data = data;
	DLinkList current = head;
	if(pos>=1 && pos <=len)
	{
		for (int i=1;i<pos;++i)
			current = current->next;
		DLinkList prev = current->prev;
		node->prev = prev;
		if (prev)
			prev->next = node;
		else head = node;

		node ->next = current;
		if (current)
			current->prev = node;
	}
	traverDLinkList(head);
	return head;
}

DLinkList DLinkListDelete(DLinkList &head)
{
	cout<<"ɾ����㣬��ѡ��ɾ���Ľ��λ�ã�"<<endl;
	int pos,len = DLinkListLen(head);
	cin >>pos;
	if (pos<1 || pos >len)
	{
		return head;
	}
	DLinkList current= head; 
	for (int i=1;i<pos;++i)
	{
		current = current->next;
	}
	DLinkList prev = current->prev;
	DLinkList next = current ->next;

	if (prev)
	{
		prev->next = next;
	}
	else head = next;
	if (next)
	{
		next->prev = prev;
	}
	traverDLinkList(head);
	return head;
}

//���������
DLinkList sortDLinkList(DLinkList &head)
{
	cout<<"�����ð������ : "<<endl;
	int len = DLinkListLen(head);
	for (int i=0;i<len;++i)
	{
		DLinkList temp1 = head;
		DLinkList temp2 = head->next;
		for (int j=0;j<len-i-1;++j)
		{
			if (temp1->data > temp2->data)
			{
				swap(temp2->data,temp1->data);
			}
			temp1 = temp2;
			temp2 = temp2->next;
		}
	}
	traverDLinkList(head);
	return head;
}

//���������
DLinkList reverseDLinklist(DLinkList &head)
{
	cout<<"��������ã�"<<endl;
	int len = DLinkListLen(head);
	if (len < 2)
	{
		return head;
	}
	DLinkList current = head->next;
	head->next = NULL;
	DLinkList temp;
	while(current)
	{
		temp = current->next;
		//ͷ�巨
		current->next =head;
		current->prev = NULL;
		head ->prev = current;

		head = current;
		current = temp;
	}
	traverDLinkList(head);
	return head;
}
