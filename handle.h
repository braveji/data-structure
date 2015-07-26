#include <vector>
#include "slinklist.h"
#include "BtreeList.h"
#include "graphMat.h"
#include "graphList.h"
#include "sort.h"
#include "dlinklist.h"
#include "STACK.h"
#include "QUEUE.h"
#include "clinklist.h"
#include "STRING.h"
#include "HASH.h"
#include "algotithms.h"

using namespace std;

void SLinkListHandle()
{
	SLinkList head;
	buildSLinkList(head);
	traverSLinkList(head);
	cout<<"����ĳ���"<<SLinkListLen(head)<<endl;
	SLinkListInsert(head);
	traverSLinkList(head);
	cout<<"���������ĳ���"<<SLinkListLen(head)<<endl;
	SLinkListDelete(head);
	traverSLinkList(head);
	cout<<"ɾ��������ĳ���"<<SLinkListLen(head)<<endl;
	sortSLinkList(head);
	cout<<"����� "<<ends;
	traverSLinkList(head);
	reverseSLinkList(head);
	cout<<"���ú� "<<ends;
	traverSLinkList(head);
	destorySLinList(head);
}

void BTreeHandle()
{
	bTree  root;
	cout<<"�������������(������ʽ)"<<endl;
	cout<<"��������Ϣ����#������ǰ���"<<endl;
	buildBtreeList(root);
	cout<<"ǰ�����"<<endl;
	frontSearch(root);
	cout<<endl;
	cout<<"�������"<<endl;
	middleSearch(root);
	cout<<endl;
	cout<<"�������"<<endl;
	backSearch(root);
	cout<<endl;
	cout<<"�������Ϊ"<<btreeDeepth(root)<<endl;
	destroy(root);
}

void graphMatHandle()
{
	graphMat graph;
	buildGraphMat(graph);
	DFS(graph);
	BFS(graph);
	prime(graph);
	dijkstra(graph);
}

void graphListHandle()
{
	graphList graph;
	buildGraphList(graph);
	dfs(graph);
	bfs(graph);

	//kruskal�㷨
	kruskal(graph);
	deleteGraphList(graph);
}

void sortHandle()
{
	int arry[]={12,4,646,797,96,41,64,647,97,979,79,744,644,6447,978,766,1611,61,0,90};
	vector<int> arr(arry,arry+20);
	cout<<"ԭʼ���飺"<<endl;
	printArray(arr);

	shellSort(arr);
	mergeSort(arr);
	heapSort(arr);
	quickSort(arr);
	insertSort(arr);
	selectSort(arr);
	bubbleSort(arr);
}

void DLinkListHandle()
{
	DLinkList head;
	buildDLinkList(head);
	traverDLinkList(head);
	cout<<"����ĳ���Ϊ"<<DLinkListLen(head)<<endl;
	DLinkListInsert(head);
	cout<<"�����������ĳ���Ϊ"<<DLinkListLen(head)<<endl;
	DLinkListDelete(head);
	cout<<"ɾ����������ĳ���Ϊ"<<DLinkListLen(head)<<endl;
	sortDLinkList(head);
	reverseDLinklist(head);
	destroyDLinkList(head);
}

void StackHandle()
{
	Stack head = NULL;
	for (char data ='a';data<'g';++data)
	{
		stackPush(head,data);
	}
	traverStack(head);
	cout<<endl<<"ջ�ĳ���Ϊ��"<<stackLen(head)<<endl;
	cout<<"ջ������Ϊ��"<<stackTop(head)<<endl;
	cout<<"ɾ�����ݣ�"<<endl;
	for (int i=0;i<4;++i)
	{
		stackPop(head);
		traverStack(head);
		cout<<endl;
	}
	cout<<"ջ�ĳ���Ϊ��"<<stackLen(head)<<endl;
	StackDestroy(head);
}

void QueueHandle()
{
	Queue que = NULL;
	for (char data='a';data<'j';++data)
	{
		QueuePush(que,data);
	}
	traverQueue(que);
	cout<<"���г���Ϊ��"<<queueLen(que)<<endl;
	cout<<"���еĶ������ݣ�"<<queueTop(que)<<endl;
	for (int i=0;i<4;++i)
	{
		queuePop(que);
		traverQueue(que);
	}
	cout<<"���г���Ϊ��"<<queueLen(que)<<endl;
	queueDestroy(que);
}

void CLinkListHandle1()
{
	CLinkList head;
	buildCLinkList0(head);
	traverCLinkList(head);
	cout<<"����ĳ���Ϊ"<<CLinkListLen(head)<<endl;
	destroyCLinkList(head);
}

void stringHandle()
{
	char * p = "zengjiloveyou";
	String str(p);//Ĭ�Ϲ��캯��
	str.printString();//û��������������
	String temp(str);//�������캯��
	temp.printString();
	String str2;
	str2 = str;//��ֵ����
	str2.printString();
	string src = "zengjilovefengxue";
	string des = "love";
	int num = violentMatch(src,des);
	if (num>=0)
		cout<<src<<"��"<<des<<"ƥ����"<<num<<endl;
	else cout<<src<<"��"<<des<<"��ƥ��"<<endl;
	KMP(src,des);
	//str.~String();
	//str2.~String();
	//temp.~String();//Ϊʲô�˴������Զ�������������
}

void hashTableHandle()
{
	HashTable hashtable;
	iniHashTable(hashtable);
	insertHashTable(hashtable,"hello");
	insertHashTable(hashtable,"world");
	insertHashTable(hashtable,"ni");
	insertHashTable(hashtable,"hao");
	insertHashTable(hashtable,"zeng");
	insertHashTable(hashtable,"ji");
	insertHashTable(hashtable,"feng");
	insertHashTable(hashtable,"xue");
	cout<<"ɢ�б�Ĵ�СΪ"<<hashtable.size<<endl;
	deleteHashTable(hashtable,"ji");
	cout<<"ɢ�б�Ĵ�СΪ"<<hashtable.size<<endl;
	searchHashTable(hashtable,"feng");
	searchHashTable(hashtable,"ji");
	destroyHashTable(hashtable);
}

void algorithumsHandle()
{
	cout<<"��ѡ�������㷨��1��N�ʺ�����㷨��"<<endl;
	int num;
	cin >> num;
	if (num == 1)
	{
		int n;
		cout <<"��ѡ��ʺ����:"<<ends;
		cin >> n;
		cout<<n<<"�ʺ�Ľⷨ����Ϊ��"<<queen(n)<<endl;
	}

}
