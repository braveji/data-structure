//单链表
#include <iostream>
#include <vector>
using namespace std;

struct nodeSList
{
	char data;
	nodeSList * next;
};
typedef nodeSList* SLinkList;

/******链表的操作********
***1 链表的建立*******
***2 链表的销毁*******
***3 链表的长度*******
***4 链表的插入*******
***5 链表的删除*******
***6 链表的排序*******
***7 链表的逆置*******
***8 链表的遍历******/

void buildSLinkList(SLinkList & head)
{
	//建立带头结点的链表
	cout<<"建立链表："<<endl;
	head =  new nodeSList;
	head ->next = NULL;

	//建立链表
	char data;
	SLinkList current = head;
	cout<<"输入结点信息，以#结束！"<<endl;
	while(cin >> data && data != '#')
	{
		SLinkList temp = new nodeSList;
		temp -> data = data;
		//头插法
// 		temp->next  =head->next;
// 		head->next =temp;

		//尾插法
		temp ->next = current->next;
		current->next = temp;
		current = temp;
	}
}

//链表的销毁
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

//链表的长度
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

//链表的插入
SLinkList SLinkListInsert(SLinkList head)
{
	cout<<"链表的插入"<<endl;
	cout<<"输入链表插入的位置和值："<<ends;
	unsigned pos;
	char data;
	cin >>pos >> data;
	if (pos<1 || pos >SLinkListLen(head)+1)
	{
		cout<<"插入位置错误！"<<endl;
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

//链表的删除
SLinkList SLinkListDelete(SLinkList head)
{
	cout<<"链表的删除"<<endl;
	cout<<"选择删除的结点位置"<<endl;
	unsigned pos;
	cin >> pos;
	if (pos <1 || pos > SLinkListLen(head))
	{
		cout<<"输入结点无效！！！"<<endl;
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


//链表的排序
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

//链表的逆置
void reverseSLinkList(SLinkList head)//头插法逆置
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

//链表的遍历
void traverSLinkList(SLinkList head)
{
	cout<<"链表的遍历："<<endl;
	SLinkList current = head->next;
	while(current)
	{
		cout<<current->data<<ends;
		current = current->next;
	}
	cout<<endl;
}