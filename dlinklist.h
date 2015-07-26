//双链表
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

// 1 链表的建立
// 2 链表的销毁
// 3 链表的插入
// 4 链表的删除
// 5 链表的长度
// 6 链表的排序
// 7 链表的逆置
// 8 链表的遍历

DLinkList buildDLinkList(DLinkList & head)
{
	cout<<"创建双链表，请输入结点信息，以#结束："<<endl;
	//不带头结点
	char data;
	//初始化第一个结点
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
	//初始化剩余的结点
	DLinkList node,current = head;
	while(cin>>data && data!='#')
	{
		node = new DListNode;
		node ->data = data;
		//头插法
// 		node ->prev = NULL;
// 		node->next = head;
// 		head->prev = node;
// 		head = node;//更新用于下一次插入

		//尾插法
		node->next = current->next;
		node ->prev = current;
		current->next = node;
		current = node;//更新用于下一次插入
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
	cout<<"正向遍历"<<endl;
	while(current)
	{
		cout<<current->data<<ends;
		last = current;
		current = current->next; 
	}
	cout<<endl<<"反向遍历"<<endl;
	while(last)
	{
		cout<<last->data<<ends;
		last = last->prev;
	}
	cout<<endl;
}

DLinkList DLinkListInsert(DLinkList &head)
{
	cout<<"双链表的插入，请选择插入的位置：大于等于1小于等于"<<DLinkListLen(head)<<ends<<
		",插入的信息 :"<<ends;
	int pos,len = DLinkListLen(head);
	char data;
	cin >> pos >> data;
	if (pos <1 || pos >len)
		return head;
	//选定插入位置后的结点 ，往前插
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
	cout<<"删除结点，请选择删除的结点位置："<<endl;
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

//链表的排序
DLinkList sortDLinkList(DLinkList &head)
{
	cout<<"链表的冒泡排序 : "<<endl;
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

//链表的逆置
DLinkList reverseDLinklist(DLinkList &head)
{
	cout<<"链表的逆置："<<endl;
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
		//头插法
		current->next =head;
		current->prev = NULL;
		head ->prev = current;

		head = current;
		current = temp;
	}
	traverDLinkList(head);
	return head;
}
