//字符串
#include <string.h>
#include <string>
#include <vector>

using namespace std;
class String
{
public:
	
	String(const char * p = NULL);//构造函数
	~String();//析构函数
	String(const String & str);//拷贝构造函数
	String& operator=(const String & str);//赋值构造函数为什么返回的是引用
	void printString();
private:
	char * data;
};

//字符串模式匹配

String::String(const char * p)
{
	if (!p)
	{
		data = new char[1];
		*data = '\0';
		return ;
	}
	int len = strlen(p);
	data = new char[len+1];
	strcpy(data,p);
	//data[len]='\0';
}

String::~String()
{
	delete [] data;
}

String::String (const String & str)
{
	int len = strlen(str.data);
	data = new char [len+1];
	strcpy(data,str.data);
	//data[len] = '\0';
}

String& String::operator=(const String & str)
{
	if (this == & str)
	{
		return *this;
	}
	delete [] data;
	int len = strlen(str.data);
	data = new char [len+1];
	strcpy(data,str.data);
	//data[len] = '\0';
	return *this;
}

//重载输出运算符

void String::printString()
{
	cout<<data<<endl;
}

//暴力模式匹配算法
int violentMatch(string & src,string & des)//判断源串中是否有目的串
{
	int i=0,j=0;
	int lenSrc = src.size();
	int lenDes = des.size();
	while(i<lenSrc && j<lenDes)
	{
		//temp = i;
		if (src[i] == des[j])
		{
			++i;++j;
		}
		else
		{
			i= i-j+1;
			j=0;
		}
	}
	if (j == lenDes)
	{
		return i-j;
	}
	else return -1;
}

//KMP 模式匹配
//构建模式串的回溯位置
void buildNext(string & des,vector<int> & next)
{
	next[0]=-1,next[1]=0;
	int len = next.size();
	int i=0,j=1;
	while(j<len-1)
	{
		if (i==-1 || des[j]==des[i])
		{
			++i;++j;
			//next[j] = next[j-1]+1;
			next[j] = i;
			//++i;++j;
		}
		else
		{
			i = next[i];
		}
	}
}

void KMP(string & src,string & des)//保持源串位置不回溯，只回溯模式串
{
	int len1 = src.size();
	int len2 = des.size();
	vector<int> next(len2);
	buildNext(des,next);
	int i=0,j=0;
	while (i<len1 && j<len2)
	{
		if (j==-1 || src[i]==des[j])
		{
			++i;++j;
		}
		else
			j = next[j];
	}
	if (j==len2)
	{
		cout<<src<<"匹配"<<des<<"于"<<i-j<<endl;
	}
	else cout<<src<<"不匹配"<<des<<endl;
}