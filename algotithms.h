//1 分治法 2 回溯法 3 动态规划 4 贪心算法
/************ 算法设计技巧         *******/
//贪心算法----背包问题
//回溯法-----n皇后问题
//动态规划---
//分治法-----

#include <vector>

using namespace std;

//回溯法求解N皇后问题

//************判断当前位置是否可以放置皇后*****************
int isLegal(int row,int col, vector<int> &queen)
{
	  for (int i=0;i<row;++i)
	  {
		  if (queen[i]== col || abs(row-i)==abs(queen[i]-col))
		  {
			  return 0;
		  }
	  }
	  return 1;
}

//n皇后主程序
int queen(int n)
{
	vector<int> quee(n);
	for (int i=0;i<n;++i)
		quee[i] =-1;
	int row=0,col =0;
	int count=0;
	while(row<n)
	{
		while(col<n)
		{
			if (isLegal(row,col,quee))
			{
				quee[row]=col;
				col =0;
				break;
			}
			++col;
		}
		//if (col==n)//表明第row行没找见合适的位置放置皇后
		if (quee[row]==-1)
		{
			if (!row)//n皇后解法退出的条件
			{
				break;
			}
			row--;
			col = quee[row]+1;
			quee[row]=-1;
			continue;
		}
		if (row == n-1 )
		{
			count++;  //n皇后解法加1的条件
			//row--;
			col = quee[row]+1;
			quee[row]=-1;
			continue;;
		}
		++row;
	}
	return count;
}
//**********************************************************

//****************贪心算法---背包问题*****************