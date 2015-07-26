//牛逼的递归。。。要点：判断结点是否有效
#include <iostream>

using namespace std;

struct NodeTree 
{
	char data;
	NodeTree  * lchild;
	NodeTree  * rchild;
};

typedef NodeTree * bTree;

void buildBtreeList(bTree &node)
{
	char data;
	cin >> data;
	if (data == '#')
	{
		node = NULL;
	}
	else
	{
		node = new NodeTree ;
		node->data = data;
		buildBtreeList(node->lchild);
		buildBtreeList(node->rchild);
	}
}

void frontSearch(bTree node)
{
	if (node)
	{
		cout<<node->data;
		frontSearch(node->lchild);
		frontSearch(node->rchild);
	}
}

void middleSearch(bTree node)
{
	if (node)
	{
		middleSearch(node->lchild);
		cout<<node->data;
		middleSearch(node->rchild);

	}
}

void backSearch(bTree node)
{
	if (node)
	{
		backSearch(node->lchild);
		middleSearch(node->rchild);
		cout<<node->data;
	}
}

void destroy(bTree root)
{
	if (root)
	{
		if (root->lchild)
			destroy(root->lchild);
		if (root->rchild)
			destroy(root->rchild);
		delete root;
		root = NULL;
	}
}

//二叉树的深度
int btreeDeepth(bTree root)
{
	if (!root)
		return 0;
	int i,j;
	if (root->lchild)
		i = btreeDeepth(root->lchild);
	else 
		i=0;
	if (root->rchild)
		j = btreeDeepth(root->rchild);
	else 
		j=0;
	return i>j?i+1:j+1;
}