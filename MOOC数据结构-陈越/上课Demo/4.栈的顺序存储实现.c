#include<stdio.h>
#include<malloc.h> 
#define MaxSize 100   // ��ջԪ�ص������� 
typedef int ElementType; // ElementType ��ʱ����Ϊ int ���� 
typedef struct SNode *Stack;
struct SNode{
	ElementType Data[MaxSize];   // �洢��ջԪ��
	int Top;  // ��¼ջ��Ԫ���±� 
}; 

Stack CreateStack();  // ��ʼ����ջ 
int IsFull(Stack S); // �ж϶�ջ�Ƿ����� 
int IsEmpty(Stack S);   // �ж϶�ջ�Ƿ�Ϊ�� 
void Push(Stack S,ElementType item);   // ��ջ 
ElementType Pop(Stack S);   // ��ջ 

// ��ʼ����ջ 
Stack CreateStack(){
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Top = -1;
	return S;
} 

// �Ƿ����� 
int IsFull(Stack S){
	return (S->Top == MaxSize-1);
}

// �Ƿ�Ϊ�� 
int IsEmpty(Stack S){
	return (S->Top == -1); 
} 

// ��ջ 
void Push(Stack S,ElementType item){
	if(IsFull(S)){   // Top �� 0 ��ʼ 
		printf("��ջ��");
		return;
	}else{
		S->Top++;   // ջ��Ԫ�ؼ�һ 
		S->Data[S->Top] = item;   // �Ž����� 
		return;
	}
}

// ��ջ
ElementType Pop(Stack S){
	if(IsEmpty(S)){
		printf("��ջ��");
		return;
	}else{
		ElementType val = S->Data[S->Top];  //ȡ������ 
		S->Top--;  // ջ��Ԫ�ؼ�һ 
		return val;
	}
}
int main(){
	Stack S;
	S = CreateStack();
	printf("5��ջ\n");
	Push(S,5);
	printf("7��ջ\n");
	Push(S,7);
	printf("66��ջ\n");
	Push(S,66);
	printf("%d��ջ\n",Pop(S));
	printf("%d��ջ\n",Pop(S));
	return 0;
}









