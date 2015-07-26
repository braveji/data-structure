//邻接链表
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
	int end;//边的顶点位置
	int weight;//边的权重
	Edge * next;//指向下一条边
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
	cout<<"创建邻接表图:"<<endl;
	cout<<"输入图的顶点个数和边个数: "<<ends;
	cin >>graph.vertexNum>>graph.edgeNum;

	//初始化顶点信息
	cout<<"输入顶点信息: "<<ends;
	for (int i=0;i<graph.vertexNum;++i)
	{
		cin >> graph.vertex[i].data;
		graph.vertex[i].first=NULL;
	}

	//初始化边的信息
	int m,n,weight;
	cout<<"输入边的信息，两个端点和权值："<<ends;
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

//链表的销毁
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

//邻接表的深度优先搜索
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
	cout<<"邻接表的深度优先搜索:"<<endl;
	vector<int> visited(graph.vertexNum);
	cout<<"选择遍历的起始顶点:"<<ends;
	int start;
	cin >> start;
	start--;
	dfs_drive(graph,visited,start);
	cout<<endl;
}

//邻接表的广度优先遍历
void bfs(graphList & graph)
{
	cout<<"邻接表的广度优先遍历:"<<endl;
	cout<<"选择遍历的起点："<<ends;
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

//最小生成树----kruskal算法
struct EDGE 
{
	int first,end;
	int weight;
};

void kruskal(graphList & graph)
{
	int num = graph.edgeNum;
	vector<EDGE> edge(num);
	// 初始化边
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
	//对边按照权重大小进行排序
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
	//判断是否形成环---确定每个顶点所能访问的最远的结点
	vector<int> last(num2);
	//初始化--一个个离散点
	for (int i=0;i<num2;++i)
		last[i] = i;
	//更新---不能形成闭环
	for(int i=0;i<num;++i)
	{
		EDGE temp= edge[i];
		int  n1 = temp.first,n2=temp.end;
		if (last[n1] == last[n2])
		{
			continue;
		}
		cout<<"加入以"<<temp.first+1<<"和"<<temp.end+1<<"为端点的边,其权重为"<<temp.weight<<endl;
		//last[temp.first] = last[temp.end];
		//若两个顶点连通，则这两个顶点连通的最远的顶点应该连通
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