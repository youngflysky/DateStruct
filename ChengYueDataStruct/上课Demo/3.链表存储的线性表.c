#include<stdio.h>
#include<malloc.h>
typedef int ElementType; // ElementType �ɶ���Ϊ��������
typedef struct LNode *List;
struct LNode{
	ElementType Data;   //������ 
	List Next;   // ��һ������ĵ�ַ 
}; 
List L;

List MakeEmpty(); //��ʼ������ 
int Length(List L);  // �Ա�������ķ����������� 
List FindKth(int K,List L);  // ����Ų��� 
List Find(ElementType X,List L);  // ��ֵ���� 
List Insert(ElementType X,int i,List L);  //�� X ���뵽�� i-1(i>0) �����֮�� 
List Delete(int i,List L); // ɾ���� i(i>0) ����� 
void Print(List L); // �������Ԫ�� 

// ��ʼ������ 
List MakeEmpty(){
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	return L;
}

//��� 
int Length(List L){
	List p = L;
	int len=0;
	while(p){  // �� p ��Ϊ�� 
		p = p->Next;
		len++;
	}
	return len;
} 

// ������� 
List FindKth(int K,List L){
	List p = L;
	int i = 1;  //�� 1 ��ʼ 
	while(p && i<K){
		p = p->Next;
		i++;
	}
	if(i == K)    // �ҵ��� 
		return p;
	else    // δ�ҵ� 
		return NULL;
} 

// ��ֵ����  
List Find(ElementType X,List L){
	List p = L;
	while(p && p->Data!=X)
		p = p->Next;
	// �ҵ��ˣ����� p
	// δ�ҵ������� NULL����ʱ p ���� NULL 
	return p;   
} 

/* ����
1. �� s ָ��һ���µĽ��
2. �� p ָ������ĵ� i-1 ����� 
3. s->Next = p->Next���� s ����һ�����ָ�� p ����һ����� 
4. p->Next = s���� p ����һ����Ϊ s   */
List Insert(ElementType X,int i,List L){
	List p,s;
	if(i == 1){     // �½������ڱ�ͷ 
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = L;
		return s;     //����Ľ��Ϊͷ��� 
	}
	p = FindKth(i-1,L);   // �ҵ��� i-1 �����
	if(!p){   // �� i-1 ����㲻���� 
		printf("������");
		return NULL;
	}else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;   //�� s ����һ�����ָ�� p ����һ����� 
		p->Next = s;   // �� p ����һ����Ϊ s
		return L;
	}
}

/* ɾ��
1. �� p ָ������ĵ� i-1 ����� 
2. �� s ָ��Ҫ��ɾ���ĵĵ� i �����
3. p->Next = s->Next��p ָ��ָ�� s ����
4. free(s)���ͷſռ� 
*/
List Delete(int i,List L){
	List p,s;
	if(i==1){   //���Ҫɾ��ͷ��� 
		s = L;
		if(L)   // �����Ϊ�� 
			L = L->Next;
		else
			return NULL;
		free(s);   // �ͷű�ɾ����� 
		return L; 
	}
	p = FindKth(i-1,L);    // ���ҵ� i-1 �����
	if(!p || !(p->Next)){     // �� i-1 ����� i ����㲻���� 
		printf("������");
		return NULL;
	}else{
		s = p->Next;    // s ָ��� i ����� 
		p->Next = s->Next;  //������ɾ�� 
		free(s);  // �ͷű�ɾ����� 
		return L;
	}
}

// �������Ԫ�� 
void Print(List L){
	List t;
	int flag = 1;
	printf("��ǰ����Ϊ��");
	for(t = L;t;t =t->Next){
		printf("%d  ",t->Data);
		flag = 0;
	}
	if(flag)
		printf("NULL");
	printf("\n"); 
}

int main(){
	L = MakeEmpty();
	Print(L);
	L = Insert(11,1,L);
	L = Insert(25,1,L);
	L = Insert(33,2,L);
	L = Insert(77,3,L);
	Print(L);
	printf("��ǰ������Ϊ��%d\n",Length(L));
	printf("��ʱ�����еڶ�������ֵ�ǣ�%d\n",FindKth(2,L)->Data);
	printf("����22�Ƿ��ڸ������У�");
	if(Find(22,L))
		printf("�ǣ�\n");
	else
		printf("��\n");
	printf("����33�Ƿ��ڸ������У�");
	if(Find(33,L))
		printf("�ǣ�\n");
	else
		printf("��\n");
	L = Delete(1,L);
	L = Delete(3,L);
	printf("----------ɾ����-----\n"); 
	Print(L);
	return 0;
} 
