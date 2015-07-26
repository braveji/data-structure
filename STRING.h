//�ַ���
#include <string.h>
#include <string>
#include <vector>

using namespace std;
class String
{
public:
	
	String(const char * p = NULL);//���캯��
	~String();//��������
	String(const String & str);//�������캯��
	String& operator=(const String & str);//��ֵ���캯��Ϊʲô���ص�������
	void printString();
private:
	char * data;
};

//�ַ���ģʽƥ��

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

//������������

void String::printString()
{
	cout<<data<<endl;
}

//����ģʽƥ���㷨
int violentMatch(string & src,string & des)//�ж�Դ�����Ƿ���Ŀ�Ĵ�
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

//KMP ģʽƥ��
//����ģʽ���Ļ���λ��
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

void KMP(string & src,string & des)//����Դ��λ�ò����ݣ�ֻ����ģʽ��
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
		cout<<src<<"ƥ��"<<des<<"��"<<i-j<<endl;
	}
	else cout<<src<<"��ƥ��"<<des<<endl;
}