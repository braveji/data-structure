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
	cout<<"链表的长度"<<SLinkListLen(head)<<endl;
	SLinkListInsert(head);
	traverSLinkList(head);
	cout<<"插入后链表的长度"<<SLinkListLen(head)<<endl;
	SLinkListDelete(head);
	traverSLinkList(head);
	cout<<"删除后链表的长度"<<SLinkListLen(head)<<endl;
	sortSLinkList(head);
	cout<<"排序后 "<<ends;
	traverSLinkList(head);
	reverseSLinkList(head);
	cout<<"逆置后 "<<ends;
	traverSLinkList(head);
	destorySLinList(head);
}

void BTreeHandle()
{
	bTree  root;
	cout<<"建立二叉查找树(链表形式)"<<endl;
	cout<<"输入结点信息，以#结束当前结点"<<endl;
	buildBtreeList(root);
	cout<<"前序遍历"<<endl;
	frontSearch(root);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	middleSearch(root);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	backSearch(root);
	cout<<endl;
	cout<<"树的深度为"<<btreeDeepth(root)<<endl;
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

	//kruskal算法
	kruskal(graph);
	deleteGraphList(graph);
}

void sortHandle()
{
	int arry[]={12,4,646,797,96,41,64,647,97,979,79,744,644,6447,978,766,1611,61,0,90};
	vector<int> arr(arry,arry+20);
	cout<<"原始数组："<<endl;
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
	cout<<"链表的长度为"<<DLinkListLen(head)<<endl;
	DLinkListInsert(head);
	cout<<"插入结点后链表的长度为"<<DLinkListLen(head)<<endl;
	DLinkListDelete(head);
	cout<<"删除结点后链表的长度为"<<DLinkListLen(head)<<endl;
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
	cout<<endl<<"栈的长度为："<<stackLen(head)<<endl;
	cout<<"栈顶数据为："<<stackTop(head)<<endl;
	cout<<"删除数据："<<endl;
	for (int i=0;i<4;++i)
	{
		stackPop(head);
		traverStack(head);
		cout<<endl;
	}
	cout<<"栈的长度为："<<stackLen(head)<<endl;
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
	cout<<"队列长度为："<<queueLen(que)<<endl;
	cout<<"队列的顶部数据："<<queueTop(que)<<endl;
	for (int i=0;i<4;++i)
	{
		queuePop(que);
		traverQueue(que);
	}
	cout<<"队列长度为："<<queueLen(que)<<endl;
	queueDestroy(que);
}

void CLinkListHandle1()
{
	CLinkList head;
	buildCLinkList0(head);
	traverCLinkList(head);
	cout<<"链表的长度为"<<CLinkListLen(head)<<endl;
	destroyCLinkList(head);
}

void stringHandle()
{
	char * p = "zengjiloveyou";
	String str(p);//默认构造函数
	str.printString();//没有重载输出运算符
	String temp(str);//拷贝构造函数
	temp.printString();
	String str2;
	str2 = str;//赋值运算
	str2.printString();
	string src = "zengjilovefengxue";
	string des = "love";
	int num = violentMatch(src,des);
	if (num>=0)
		cout<<src<<"和"<<des<<"匹配于"<<num<<endl;
	else cout<<src<<"和"<<des<<"不匹配"<<endl;
	KMP(src,des);
	//str.~String();
	//str2.~String();
	//temp.~String();//为什么此处不能自动调用析构函数
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
	cout<<"散列表的大小为"<<hashtable.size<<endl;
	deleteHashTable(hashtable,"ji");
	cout<<"散列表的大小为"<<hashtable.size<<endl;
	searchHashTable(hashtable,"feng");
	searchHashTable(hashtable,"ji");
	destroyHashTable(hashtable);
}

void algorithumsHandle()
{
	cout<<"请选择如下算法：1（N皇后回溯算法）"<<endl;
	int num;
	cin >> num;
	if (num == 1)
	{
		int n;
		cout <<"请选择皇后个数:"<<ends;
		cin >> n;
		cout<<n<<"皇后的解法个数为："<<queen(n)<<endl;
	}

}
