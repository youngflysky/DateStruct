#include <iostream>
#include <cstdlib>
using namespace std;

//1������������ڵ�
typedef struct LNode
{
	int date;
	struct LNode* next;
}LNode;

//2������������(β�巨��
void createLinkListR(LNode* &head)
{
	head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	LNode *p=NULL,*r=head;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		p=(LNode*)malloc(sizeof(LNode));
		cin>>p->date;
		r->next=p;
		r=p;
	}
}

//3��������������ͷ�巨
void createLinkListH(LNode* &head)
{
	head=(LNode*)malloc(sizeof(LNode));
	head->next=NULL;
	LNode *p;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		p=(LNode*)malloc(sizeof(LNode));
		cin >> p->date;
		p->next=head->next;
		head->next=p;
	}
}

//��һ���а�˳���ӡ�������е�����Ԫ��
void printList(LNode *head)
{
	LNode* p=head->next;
	while(p)
	{
		cout << p->date << "  ";
		p=p->next;
	}
	cout << endl;
}


int main()
{
	LNode* head1;
	LNode* head2;
	createLinkListR(head1);
	createLinkListH(head2);
	printList(head1);
	printList(head2);
	
	return 0;
}

