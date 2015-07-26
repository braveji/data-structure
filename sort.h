//�˴�����
/**********�����㷨***********
*********data:2015.07.13******
*********@author:braveji******
*****************************/
#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> & arr)
{
	//cout<<"��ӡ����"<<endl;
	for (unsigned i=0;i<arr.size();++i)
		cout<<arr[i]<<ends;
	cout<<endl;
}

//ð������---��������
void bubbleSort(vector<int> & arr)
{
	unsigned len = arr.size();
	for (unsigned i=0;i<len;++i)
		for (unsigned j=0;j<len-i-1;++j)
			if (arr[j]>arr[j+1])
				swap(arr[j],arr[j+1]);
	cout<<"ð������"<<endl;
	printArray(arr);
}

//ѡ������--ѡ����Ӧ�����ֵ(��Сֵ)���ڶ�Ӧλ��
void selectSort(vector<int> & arr)
{
	unsigned len = arr.size();
	for (unsigned i=0;i<len;++i)
	{
		int maxN= arr[0];
		int k=0;
		for (unsigned j=0;j<len-i;++j)
		{
			if (arr[j]>maxN)
			{
				maxN = arr[j];
				k = j;
			}
		}
		swap(arr[k],arr[len-i-1]);
	}
	cout<<"ѡ������"<<endl;
	printArray(arr);
}

//��������--������λ����ǰ����
void insertSort(vector<int> & arr)
{
	unsigned len = arr.size();
	for(unsigned i=0;i<len;++i)
		for (int j=i;j>0;--j)
		{
			if (arr[j]<arr[j-1])
				swap(arr[j],arr[j-1]);
			else break;
		}
	cout<<"��������"<<endl;
	printArray(arr);
}

//ϣ����������
void shellSort(vector<int> & arr)
{
	int len = arr.size();
	int step = len/2;
	for(int i=step;i>=1;i/=2)
	{
		for (int j=i;j<len;++j)
		{
			for (int k=j;k>=0;k-=i)////����fuck д����k=-i;
			{
				if (k-i>=0 && arr[k]<arr[k-i])
				{
					swap(arr[k],arr[k-i]);
				}
				else break;
			}
		
// 			int temp = arr[j];
// 			int k;
// 			for (k = j; k-i >= 0 && arr[k-i] > temp; k-=i)
// 			{
// 				arr[k] = arr[k-i];
// 			}
// 			arr[k] = temp;
		}
	}
	cout<<"ϣ������"<<endl;
	printArray(arr);
}

//�鲢����---���η�
void mergeDrive(vector<int> & arr, vector<int> &tmp, int start, int end)
{
	if (end-start<1)
	{
// 		if (arr[end]<arr[start])
// 			swap(arr[end],arr[start]);
		return ;
	}
	int middle = (start+end)/2;
	mergeDrive(arr,tmp,start,middle);
	mergeDrive(arr,tmp,middle+1,end);
	int j=start,k = middle+1,m = start;
	while(j<=middle && k<=end) 
	{
		if (arr[j]<=arr[k]) tmp[m++] = arr[j++];
		else tmp[m++] = arr[k++];
	}
	while(j<=middle) tmp[m++] = arr[j++];
	while(k<=end) tmp[m++] = arr[k++];
	//�鲢��������ڴ˴���ԭ��������
	for (int i=start;i<=end;++i)
	{
		arr[i] =tmp[i];
	}
	return ;
}
void mergeSort(vector<int> & arr)
{
	int len = arr.size();
	vector<int> tmp(len);
	mergeDrive(arr,tmp,0,len-1);
	//��ǰ�治����ֻ���ڴ˴����� �����ԭ����һ������Ҫ�õ���һ������Ľ��
// 	for (int i=0;i<len;++i)
// 	{
// 		arr[i] =tmp[i];
// 	}
	cout<<"�鲢����"<<endl;
	printArray(arr);
}

//������---������---����
void downFilter(vector<int> & arr,int pos,int len)
{
	int k = pos;
	for(int i =pos*2+1;i<len;i= i*2+1)
	{
		if (i+1<len && arr[i+1]>arr[i])
			++i;
		//if (arr[k]>arr[i])
		if (arr[k]<arr[i])
		{
			swap(arr[k],arr[i]);
			k =i;
		}
		else break;
	}
}
void buildHeap(vector<int> & arr)
{
	int len = arr.size();
	for (int i=arr.size()/2;i>=0;--i)
	{
		downFilter(arr,i,len);
	}
}
void heapSort(vector<int> & arr)
{
	buildHeap(arr);
	int len = arr.size()-1;
	swap(arr[0],arr[len]);
	for (unsigned i=1;i<arr.size();++i)
	{
		downFilter(arr,0,len);
		--len;
		swap(arr[0],arr[len]);
	}
	cout<<"������"<<endl;
	printArray(arr);
}

//��������---�����㷨--
int median3(vector<int> & arr,int start,int end)
{
	int middle = (start+end)/2;
	if (arr[start]>arr[middle]) swap(arr[start],arr[middle]);
	if (arr[start]>arr[end]) swap(arr[start],arr[end]);
	if (arr[middle]>arr[end]) swap(arr[middle],arr[end]); 
	int tmp =arr[middle];
	swap(arr[middle],arr[end-1]);
	return tmp;
}
void quickDrive(vector<int> & arr,int start,int end)
{
	if (end-start<2)
	{
		if(arr[end]<arr[start])
			swap(arr[end],arr[start]);
		return ;
	}
	//ע��˳�򡣡���������
	int middle = median3(arr,start,end);
	int i=start+1,j=end-1;
	while(1)
	{
		while (arr[i]<middle) ++i;
		while (arr[j]>middle) --j;
		if (i<j)
			swap(arr[i],arr[j]);
		else break;
	}
	int tmp = (start+end)/2;
	quickDrive(arr,start,tmp);
	quickDrive(arr,tmp+1,end);
}
void quickSort(vector<int> & arr)
{
	int len = arr.size();
	quickDrive(arr,0,len-1);
	cout<<"��������"<<endl;
	printArray(arr);
}

//Ͱ����̫��˿


