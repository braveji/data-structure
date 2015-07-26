//图的邻接矩阵
/***************邻接矩阵*********
*********
********
**
*****               **************/
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#define  maxNum 50
#define  ini 9999

using namespace std;

struct graphMat
{
	int edgeNum,vertexNum;
	char vertex[maxNum];
	int graphMatrix[maxNum][maxNum];//下标表示边，值表示权重
};

void buildGraphMat(graphMat & graph)
{
	cout<<"build adjacent matrix Graph"<<endl;
	cout<<"input vertex num and edge num :"<<ends;
	cin >>graph.vertexNum>>graph.edgeNum;

	//initialise graph matrix
	for (int i=0;i<graph.vertexNum;++i)
		for (int j=0;j<graph.vertexNum;++j)
		{
			if (i==j)
				graph.graphMatrix[i][j] = 0;
			else
				graph.graphMatrix[i][j] = ini;
		}
	
	//intialise vertex matrix
	cout<<"intialise vertex matrix :"<<endl;
	for (int i=0;i<graph.vertexNum;++i)
	{
		cin >> graph.vertex[i];
	}

	//assignment matrix
	cout<<"input two vertex as a edge ,and than input a num as weight :"<<ends;
	int m,n,weight;
	for (int i=0;i<graph.edgeNum;++i)
	{
		cin>>m>>n>>weight;
		graph.graphMatrix[m-1][n-1] = weight;
		graph.graphMatrix[n-1][m-1] = weight;
	}
	return ;
}

//邻接矩阵貌似不需要析构函数

//deepth first search
void DFSDrive(graphMat & graph,vector<int> & visited,int pos)
{
	if(!visited[pos])
	{
		cout<<graph.vertex[pos]<<ends;
		visited[pos]=1;
		for (int i=0;i<graph.vertexNum;++i)
		{
			if (!visited[i] && graph.graphMatrix[pos][i]!=ini)
			{
				DFSDrive(graph,visited,i);
			}
		}
	}
}

void DFS(graphMat & graph)
{
	vector<int> visited(graph.vertexNum);
	cout<<"DFS of adjacent matrix :"<<endl;
	int start;
	cout<<"select a start vertex :"<<ends;
	cin >> start;
	--start;
	DFSDrive(graph,visited,start);
	cout<<endl;
	return ;
}

//breadth first search
void BFS(graphMat & graph)
{
	cout<<"BFS of adjacent matrix :"<<endl;
	cout<<"select a vertex to start :"<<ends;
	int start;
	cin >> start;
	--start;
	vector<int> visited(graph.vertexNum);
	queue<int> que;
	que.push(start);
	visited[start] =1;
	while(que.size())
	{
		int tmp = que.front();
		cout<<graph.vertex[tmp]<<ends;
		que.pop();
		for (int i=0;i<graph.vertexNum;++i)
		{
			if (!visited[i] && graph.graphMatrix[tmp][i]!=ini)
			{
				visited[i]=1;
				que.push(i);
			}
		}
	}
	cout<<endl;
}

//最小生成树----prime
void prime(graphMat & graph)
{
	cout<<"prime ---最小生成树"<<endl;
	cout<<"select a vertex to start :"<<ends;
	int start;
	cin >> start;
	--start;
	vector<int> dis(graph.vertexNum);
	vector<int> visited(graph.vertexNum);
	for (int i=0;i<graph.vertexNum;++i)
		dis[i] = graph.graphMatrix[start][i];
	visited[start]=1;//最小生成树的根
	cout<<graph.vertex[start]<<ends;

	for (int i=1;i<graph.vertexNum;++i)
	{
		//循环寻找下一个结点---求最小值
		int mini = ini+1,k=0;
		for(int j=0;j<graph.vertexNum;++j)
		{
			if (!visited[j] && dis[j]<mini)
			{
				mini = dis[j];
				k =j;
			}
		}
		visited[k]=1;
		cout<<graph.vertex[k]<<ends;

		for(int j=0;j<graph.vertexNum;++j)//若需要之前结点另当别论
		{
			if (!visited[j] && dis[j] > graph.graphMatrix[k][j])
			{
				dis[j]=graph.graphMatrix[k][j];
			}
		}
	}
	cout<<endl;
}

//dijkstra---最短路径
void dijkstra(graphMat & graph)
{
	cout<<"dijkstra--最短路径"<<endl;
	cout<<"input a start vertex to start:"<<ends;
	int start;
	cin >> start;
	--start;
	vector<int> visited(graph.vertexNum);
	vector<int> dis(graph.vertexNum);
	visited[start]=1;

	//initilise dis
	for (int i=0;i<graph.vertexNum;++i)
		dis[i] = graph.graphMatrix[start][i];

	for (int i=1;i<graph.vertexNum;++i)//剩下结点的最短距离
	{
		int mini = ini+1,k=0;
		for (int j=0;j<graph.vertexNum;++j)
		{
			if (!visited[j] && dis[j]<mini)
			{
				mini = dis[j];
				k =j;
			}
		}
		visited[k]=1;
		for (int j=0;j<graph.vertexNum;++j)
		{
			if (!visited[j] && dis[j]>mini + graph.graphMatrix[k][j])
				dis[j] = mini +graph.graphMatrix[k][j];
		}
	}
	cout<<"以"<<start+1<<"为起点到各个顶点的最短为 "<<endl;
	for(int i=0;i<graph.vertexNum;++i)
		cout<<dis[i]<<ends;
	cout<<endl;

}