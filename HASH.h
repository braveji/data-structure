//哈希表//哈希映射
//要点：关键字（转换成自然数）散列函数的选择（除法散列，乘法散列，全域散列）
//要点：碰撞的解决（链接法，开放寻址法）

//链接法
#include <string>
#include <iostream>
#define  maxSize 51
using namespace std;
struct Table
{
	string value;
	Table * next;
};

struct HashTable
{
	Table table[maxSize];
	int size;
};

//哈希表的字典操作：插入、删除、查找

//散列函数
int hashFoo(string str)
{
	int key =0;
	for (unsigned i=0;i<str.size();++i)
	{
		key = key + str[i]-'a';
	}
	return key%maxSize;
}

void iniHashTable(HashTable & hashTable)
{
	for (int i=0;i<maxSize;++i)
	hashTable.table[i].next=NULL;
	hashTable.size=0;
}

//插入关键字进散列表
void insertHashTable(HashTable & hashTable,const string & key)
{
	int pos = hashFoo(key);
	Table * node = new Table;
	node->value = key;
	node->next = NULL;
	Table * temp = &hashTable.table[pos], *temp2;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
	}
	temp2->next = node;
	hashTable.size++;
}

//散列表查找关键字
void searchHashTable(HashTable & hashTable,const string & key)
{
	int pos = hashFoo(key);
	int flag =0;
	Table * current = hashTable.table[pos].next;
	while(current)
	{
		if (current->value == key)
		{
			flag=1;
			break;
		}
		current = current->next;
	}
	if (flag)
		cout<<"关键字"<<key<<"存在于散列表中"<<endl;
	else cout<<"关键字"<<key<<"不存在于散列表中"<<endl;
}

//散列表的删除关键字
void deleteHashTable(HashTable & hashTable,const string & key)
{
	int pos = hashFoo(key);
	Table * node = hashTable.table[pos].next;//第一个结点
	Table *temp = &hashTable.table[pos];//头结点
	while(node)
	{
		//temp = node;
		if (node->value == key)
		{
			break;
		}
		temp = node;
		node = node->next;
	}
	temp->next = node ->next;
	delete node;
	hashTable.size--;
}

void destroyHashTable(HashTable & hashTable)
{
	for (int i=0;i<maxSize;++i)
	{
		Table * node = hashTable.table[i].next;
		Table * temp = & hashTable.table[i];
		temp->next=NULL;
		while(node)
		{
			temp = node->next;
			delete node;
			node = temp;
		}
	}
}