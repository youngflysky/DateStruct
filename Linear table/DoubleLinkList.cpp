/*********************************************************************
    程序名:双链表的操作
    日期: 2022-03-05 10:28
    说明: 
*********************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;


//1、双链表节点的创建
typedef struct DNode
{
	int date;
	struct DNode *prior;
	struct DNode *next;
}DNode;

//2、尾插法建立双链表
void createDlistR(DNode *&L)
{
	L=(DNode*)malloc(sizeof(DNode));
	L->prior=NULL;
	L->next=NULL; 
	int n;
	cin >> n;
	DNode* p=NULL,*r=L;
	for(int i=0;i<n;i++)
	{
		p=(DNode*)malloc(sizeof(DNode));
		cin >> p->date;
		p->next=r->next;
		r->next=p;
		p->prior=r;
		r=p;		
	}
}

//3、头插法建立双链表
void createDlistH(DNode *&L)
{
	L=(DNode*)malloc(sizeof(DNode));
	L->prior=NULL;
	L->next=NULL; 
	int n;
	cin >> n;
	DNode* s=NULL;
	for(int i=0;i<n;i++)
	{
		s=(DNode*)malloc(sizeof(DNode));
		cin >> s->date;
		if(L->next)
		{
			s->next=L->next;
			s->next->prior=s;
			L->next=s; 
			s->prior=L;	
		}
		else
		{
			s->next=NULL;
			s->prior=L;
			L->next=s;
		}	
	}
}

//4、查找特定值的节点，找到则返回节点指针，否则返回NULL
DNode* findNode(DNode* L,int x)
{
	DNode* p=L->next;
	while(p)
	{
		if(x==p->date)
		{
			break;
		}
		p=p->next;
	}
	return p;
	
}

//5、在节点p后插入节点s
void insertDNode(DNode *&p,DNode *&s)
{
	s->next=p->next;
	p->next=s;
	s->prior=p;
	s->next->prior=s;
	
}

//6、删除节点p的后继节点
void deleteDNode(DNode *&p)
{	
	DNode *q=p->next;
	p->next=q->next;
	q->next->prior=p;
	free(q);
}



//打印双链表
void printDlist(DNode* L)
{
	DNode* p=L->next;
	while(p)
	{
		cout << p->date << ' ';
		p=p->next;
	}
	cout << endl;
	
}
int main()
{
	DNode *Lr,*Lh;
	createDlistR(Lr);
	createDlistH(Lh);
	printDlist(Lr);
	printDlist(Lh);
	return 0;
}
