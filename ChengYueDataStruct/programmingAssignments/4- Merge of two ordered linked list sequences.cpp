#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Merge( List L1, List L2 )
{
	PtrToNode  p1 = L1->Next, p2 = L2->Next;
	PtrToNode L;
	L = (PtrToNode)malloc(sizeof(struct Node));
	PtrToNode p = L;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->Data <= p2->Data)
		{
			p->Next = p1;
			p1 = p1->Next;
		}
		else
		{
			p->Next = p2;
			p2 = p2->Next;
		}
		p = p->Next;
	}
	if (p1 != NULL)
	{
		p->Next = p1;
	}
	else if (p2 != NULL)
	{
		p->Next = p2;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}

















