//�ڽ�����
/******************     ******
********
***********
*********               ****/
#include <vector>
#include <iostream>
#include <queue>
#define maxnum 50

using namespace std;

struct Edge
{
	int end;//�ߵĶ���λ��
	int weight;//�ߵ�Ȩ��
	Edge * next;//ָ����һ����
};

struct Vertex
{
	char data;
	Edge * first;
};

struct graphList
{
	Vertex vertex[maxnum];
	int vertexNum,edgeNum;
};

void buildGraphList(graphList & graph)
{
	cout<<"�����ڽӱ�ͼ:"<<endl;
	cout<<"����ͼ�Ķ�������ͱ߸���: "<<ends;
	cin >>graph.vertexNum>>graph.edgeNum;

	//��ʼ��������Ϣ
	cout<<"���붥����Ϣ: "<<ends;
	for (int i=0;i<graph.vertexNum;++i)
	{
		cin >> graph.vertex[i].data;
		graph.vertex[i].first=NULL;
	}

	//��ʼ���ߵ���Ϣ
	int m,n,weight;
	cout<<"����ߵ���Ϣ�������˵��Ȩֵ��"<<ends;
	for (int i=0;i<graph.edgeNum;++i)
	{
		cin >>m>>n>>weight;
		m--;n--;
		Edge * temp = new Edge;
		temp->end = n;
		temp->weight = weight;
		temp->next = graph.vertex[m].first;
		graph.vertex[m].first = temp;

		Edge * temp2 = new Edge;
		temp2->end = m;
		temp2->weight = weight;
		temp2->next = graph.vertex[n].first;
		graph.vertex[n].first= temp2;
	}
}

//���������
void deleteGraphList(graphList & graph)
{
	for (int i=0;i<graph.vertexNum;++i)
	{
		Edge * temp1 = graph.vertex[i].first,*temp2;
		while(temp1)
		{
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}
	}
}

//�ڽӱ�������������
void dfs_drive(graphList & graph,vector<int> & visited,int pos)
{
	if (!visited[pos])
	{
		visited[pos]=1;
		cout<<graph.vertex[pos].data<<ends;
		for (int i=0;i<graph.vertexNum;++i)
		{
			if (!visited[i])
			{
				dfs_drive(graph,visited,i);
			}
		}
	}
}
void dfs(graphList & graph)
{
	cout<<"�ڽӱ�������������:"<<endl;
	vector<int> visited(graph.vertexNum);
	cout<<"ѡ���������ʼ����:"<<ends;
	int start;
	cin >> start;
	start--;
	dfs_drive(graph,visited,start);
	cout<<endl;
}

//�ڽӱ�Ĺ�����ȱ���
void bfs(graphList & graph)
{
	cout<<"�ڽӱ�Ĺ�����ȱ���:"<<endl;
	cout<<"ѡ���������㣺"<<ends;
	int start;
	cin >> start;
	start--;
	vector<int> visited(graph.vertexNum);
	queue<int> que;
	que.push(start);
	visited[start]=1;
	cout<<graph.vertex[start].data<<ends;
	while(que.size())
	{
		int pos = que.front();
		que.pop();
		Edge * temp = graph.vertex[pos].first;
		while(temp)
		{
			if (!visited[temp->end])
			{
				visited[temp->end] =1;
				cout<<graph.vertex[temp->end].data<<ends;
				que.push(temp->end);
			}
			temp = temp->next;
		}
	}
	cout<<endl;
}

//��С������----kruskal�㷨
struct EDGE 
{
	int first,end;
	int weight;
};

void kruskal(graphList & graph)
{
	int num = graph.edgeNum;
	vector<EDGE> edge(num);
	// ��ʼ����
	int k=0,num2= graph.vertexNum,j=0;
	while(k < num2)
	{
		Edge * temp = graph.vertex[k].first;
		while(temp)
		{
			if (temp->end > k)
			{
				edge[j].first=k;
				edge[j].end = temp->end;
				edge[j].weight = temp->weight;
				++j;
			}
			temp =temp->next;
		}
		++k;
	}
	//�Ա߰���Ȩ�ش�С��������
	for (int i=0;i<num;++i)
	{
		for (int j=0;j<num-1-i;++j)
		{
			if (edge[j].weight>edge[j+1].weight)
			{
				int temp = edge[j].weight;
				edge[j].weight = edge[j+1].weight;
				edge[j+1].weight = temp;

				temp = edge[j].first;
				edge[j].first = edge[j+1].first;
				edge[j+1].first = temp;

				temp = edge[j].end;
				edge[j].end = edge[j+1].end;
				edge[j+1].end = temp;
			}
		}
	}
	//�ж��Ƿ��γɻ�---ȷ��ÿ���������ܷ��ʵ���Զ�Ľ��
	vector<int> last(num2);
	//��ʼ��--һ������ɢ��
	for (int i=0;i<num2;++i)
		last[i] = i;
	//����---�����γɱջ�
	for(int i=0;i<num;++i)
	{
		EDGE temp= edge[i];
		int  n1 = temp.first,n2=temp.end;
		if (last[n1] == last[n2])
		{
			continue;
		}
		cout<<"������"<<temp.first+1<<"��"<<temp.end+1<<"Ϊ�˵�ı�,��Ȩ��Ϊ"<<temp.weight<<endl;
		//last[temp.first] = last[temp.end];
		//������������ͨ����������������ͨ����Զ�Ķ���Ӧ����ͨ
		while(last[n1]!=n1)
			n1 = last[n1];
		while(last[n2]!=n2)
			n2 = last[n2];
		if (n1>n2)
			last[n2] =n1;
		else last[n1] =n2;
		//last[temp.end] = 1;
	}
}