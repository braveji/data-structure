//1 ���η� 2 ���ݷ� 3 ��̬�滮 4 ̰���㷨
/************ �㷨��Ƽ���         *******/
//̰���㷨----��������
//���ݷ�-----n�ʺ�����
//��̬�滮---
//���η�-----

#include <vector>

using namespace std;

//���ݷ����N�ʺ�����

//************�жϵ�ǰλ���Ƿ���Է��ûʺ�*****************
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

//n�ʺ�������
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
		//if (col==n)//������row��û�Ҽ����ʵ�λ�÷��ûʺ�
		if (quee[row]==-1)
		{
			if (!row)//n�ʺ�ⷨ�˳�������
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
			count++;  //n�ʺ�ⷨ��1������
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

//****************̰���㷨---��������*****************