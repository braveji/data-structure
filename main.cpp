#include "handle.h"

using namespace std;


int main()
{
	int choose;
	while(1)
	{
		cout<<"ѡ���Ϸһ�����ݽṹ(ѡ��0�˳�)��"<<endl<<"1(������) 2(���������) 3(�ڽӾ���ͼ) 4(�ڽӱ�ͼ)"<<ends<< 
			"5(�ߴ�����)  6(˫����)"<<endl<<"7(����ջ) 8(����) 9(ѭ������) 10(��ϣ��) 11(�ַ���) 12(�����㷨)"<<endl;
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