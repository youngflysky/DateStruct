#include<stdio.h>
#include<malloc.h>
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	Stack Next;
};


Stack CreateStack();  // ��ʼ����ջ 
int IsEmpty(Stack S);  // �ж���ջ�Ƿ�Ϊ�� 
void Push(Stack S,ElementType item);  // ��ջ 
ElementType Pop(Stack S);  // ��ջ
 

// ��ʼ�� 
Stack CreateStack(){
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

// �ж��Ƿ�Ϊ�� 
int IsEmpty(Stack S){
	return (S->Next == NULL);
}

// ��ջ
void Push(Stack S,ElementType item){
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Data = item;
	// ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ��� 
	tmp->Next = S->Next;   
	S->Next = tmp;
} 

// ��ջ
ElementType Pop(Stack S){
	Stack First;
	ElementType TopVal;
	if(IsEmpty(S)){
		printf("��ջ��");
		return;
	}else{
		First = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ��� 
		S->Next = First->Next;  //�ѵ�һ��Ԫ�ش���ջɾ�� 
		TopVal = First->Data;   // ȡ����ɾ������ֵ 
		free(First);  // �ͷſռ� 
		return TopVal;
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
