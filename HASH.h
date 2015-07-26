//��ϣ��//��ϣӳ��
//Ҫ�㣺�ؼ��֣�ת������Ȼ����ɢ�к�����ѡ�񣨳���ɢ�У��˷�ɢ�У�ȫ��ɢ�У�
//Ҫ�㣺��ײ�Ľ�������ӷ�������Ѱַ����

//���ӷ�
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

//��ϣ����ֵ���������롢ɾ��������

//ɢ�к���
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

//����ؼ��ֽ�ɢ�б�
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

//ɢ�б���ҹؼ���
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
		cout<<"�ؼ���"<<key<<"������ɢ�б���"<<endl;
	else cout<<"�ؼ���"<<key<<"��������ɢ�б���"<<endl;
}

//ɢ�б��ɾ���ؼ���
void deleteHashTable(HashTable & hashTable,const string & key)
{
	int pos = hashFoo(key);
	Table * node = hashTable.table[pos].next;//��һ�����
	Table *temp = &hashTable.table[pos];//ͷ���
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