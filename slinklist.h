//������
#include <iostream>
#include <vector>
using namespace std;

struct nodeSList
{
	char data;
	nodeSList * next;
};
typedef nodeSList* SLinkList;

/******����Ĳ���********
***1 ����Ľ���*******
***2 ���������*******
***3 ����ĳ���*******
***4 ����Ĳ���*******
***5 �����ɾ��*******
***6 ���������*******
***7 ���������*******
***8 ����ı���******/

void buildSLinkList(SLinkList & head)
{
	//������ͷ��������
	cout<<"��������"<<endl;
	head =  new nodeSList;
	head ->next = NULL;

	//��������
	char data;
	SLinkList current = head;
	cout<<"��������Ϣ����#������"<<endl;
	while(cin >> data && data != '#')
	{
		SLinkList temp = new nodeSList;
		temp -> data = data;
		//ͷ�巨
// 		temp->next  =head->next;
// 		head->next =temp;

		//β�巨
		temp ->next = current->next;
		current->next = temp;
		current = temp;
	}
}

//���������
void  destorySLinList(SLinkList head)
{
	SLinkList current = head,temp;
	while (current)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
}

//����ĳ���
unsigned SLinkListLen(SLinkList head)
{
	unsigned len =0;
	SLinkList current = head->next;
	while(current)
	{
		len++;
		current = current->next;
	}
	return len ;
}

//����Ĳ���
SLinkList SLinkListInsert(SLinkList head)
{
	cout<<"����Ĳ���"<<endl;
	cout<<"������������λ�ú�ֵ��"<<ends;
	unsigned pos;
	char data;
	cin >>pos >> data;
	if (pos<1 || pos >SLinkListLen(head)+1)
	{
		cout<<"����λ�ô���"<<endl;
		return head;
	}
	pos--;
	SLinkList current = head;
	for (unsigned i=0;i<pos;++i)
		current = current->next;
	SLinkList temp = new nodeSList;
	temp->data = data;
	temp ->next = current->next;
	current ->next = temp;
	return head;
}

//�����ɾ��
SLinkList SLinkListDelete(SLinkList head)
{
	cout<<"�����ɾ��"<<endl;
	cout<<"ѡ��ɾ���Ľ��λ��"<<endl;
	unsigned pos;
	cin >> pos;
	if (pos <1 || pos > SLinkListLen(head))
	{
		cout<<"��������Ч������"<<endl;
		return head;
	}
	--pos;
	SLinkList current = head;
	for (unsigned i=0;i<pos;++i)
		current = current->next;
	SLinkList temp1 = current->next;
	current->next = temp1->next;
	delete temp1;
	temp1 = NULL;
	return head;
}


//���������
void sortSLinkList(SLinkList head)
{
	unsigned len = SLinkListLen(head);
	if (len < 2)
		return;
	for (unsigned i=0;i<len;++i)
	{
		SLinkList temp1 = head->next;
		SLinkList temp2 = temp1->next;
		for(unsigned j=0;j<len-1-i;++j)
		{
			if (temp1->data > temp2->data)
			{
				char data = temp1->data;
				temp1->data = temp2->data;
				temp2->data = data;
			}
			temp1 = temp2;
			temp2 = temp2->next;
		}
	}
	return ;
}

//���������
void reverseSLinkList(SLinkList head)//ͷ�巨����
{
	unsigned len = SLinkListLen(head);
	if (len < 2)
		return ;
	SLinkList current = head->next->next,temp = head->next;
	temp->next = NULL;
	while (current)
	{
		temp = current->next;
		current->next = head->next;
		head->next = current;

		current = temp;
	}
}

//����ı���
void traverSLinkList(SLinkList head)
{
	cout<<"����ı�����"<<endl;
	SLinkList current = head->next;
	while(current)
	{
		cout<<current->data<<ends;
		current = current->next;
	}
	cout<<endl;
}