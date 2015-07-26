#include "handle.h"

using namespace std;


int main()
{
	int choose;
	while(1)
	{
		cout<<"选择调戏一种数据结构(选择0退出)："<<endl<<"1(单链表) 2(二叉查找树) 3(邻接矩阵图) 4(邻接表图)"<<ends<< 
			"5(七大排序)  6(双链表)"<<endl<<"7(数据栈) 8(队列) 9(循环链表) 10(哈希表) 11(字符串) 12(常用算法)"<<endl;
		cin >>choose;
		if (choose == 0)
			return 0;
		if (choose == 1)
			SLinkListHandle();
		if (choose == 2)
			BTreeHandle();
		if (choose == 3)
			graphMatHandle();
		if (choose == 4 )
			graphListHandle();
		if (choose == 5)
			sortHandle();
		if (choose == 6)
			DLinkListHandle();
		if (choose == 7)
			StackHandle();
		if (choose == 8)
			QueueHandle();
		if (choose == 9)
			CLinkListHandle1();
		if (choose == 10)
			hashTableHandle();
		if (choose == 11)
			stringHandle();
		if (choose == 12)
			algorithumsHandle();
		cout<<endl<<endl;
	}
	//return 0;
}