#include <iostream>
#define maxSize 100

using namespace std;

//建立顺序表；
typedef struct
{
	int date[maxSize];
	int length; 
}Sqlist;

//建表函数
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

//1、查找指定指定元素或位置
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

//2、将步骤1中找出的位置上及以后的元素往后移动一个位置，然后将
//x放到腾出的位置上
void insertElem(Sqlist &L,int x)//??C++引用的使用方法？？
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

//3、删除指定位置元素，并将被删除元素赋值给e
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

