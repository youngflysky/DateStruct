#include <iostream>
#define maxSize 100

using namespace std;

//����˳���
typedef struct
{
	int date[maxSize];
	int length; 
}Sqlist;

//������
int creatList(Sqlist &L)
{
	cin >> L.length;
	if(L.length>maxSize)
	{
		return 0;
	}
	for(int i=0;i<L.length;i++)
	{
		cin >> L.date[i];
	}
	return 1;
}

//1������ָ��ָ��Ԫ�ػ�λ��
int findElem(Sqlist L,int x)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(x<L.date[i])
		{
			return i;
		}
	}
	return i;
 } 

//2��������1���ҳ���λ���ϼ��Ժ��Ԫ�������ƶ�һ��λ�ã�Ȼ��
//x�ŵ��ڳ���λ����
void insertElem(Sqlist &L,int x)//??C++���õ�ʹ�÷�������
{
	int p,i;
	p=findElem(L,x);
	for(i=L.length-1;i>=p;i--)
	{
		L.date[i+1]=L.date[i];
	}
	L.date[p]=x;
	(L.length++);
}

//3��ɾ��ָ��λ��Ԫ�أ�������ɾ��Ԫ�ظ�ֵ��e
void deleteElem(Sqlist &L,int x,int &e)
{
	int p,i;
	p=findElem(L,x);
	e=L.date[p];
	for(i=p;i<L.length-1;i++)
	{
		L.date[i]=L.date[i+1];
	}
	(L.length--);
}

int main()
{
	Sqlist L;
	creatList(L);
	int x;
	cin >> x;
	insertElem(L,x);
	for(int i=0;i<L.length;i++)
	{
		cout << L.date[i]<<endl;
	}

	return 0;
}

