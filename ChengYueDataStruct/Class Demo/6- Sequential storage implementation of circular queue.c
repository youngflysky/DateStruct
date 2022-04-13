#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode{
	ElementType Data[MaxSize];
	int front;   // ��¼��ͷ 
	int rear;    // ��¼��β 
};

Queue CreateQueue();  // ��ʼ������ 
void AddQ(Queue Q,ElementType item);  //  ���
int IsFull(Queue Q); // �ж϶����Ƿ����� 
ElementType DeleteQ(Queue Q);  // ���� 
int IsEmpty(Queue Q); // �ж϶����Ƿ�Ϊ�� 

// ��ʼ�� 
Queue CreateQueue(){
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = -1;
	Q->rear = -1;
	return Q;
} 

// �ж϶����Ƿ�����
int IsFull(Queue Q){
 	return ((Q->rear+1) % MaxSize == Q->front);
}

// ��� 
void AddQ(Queue Q,ElementType item){
	if(IsFull(Q)){
		printf("������");
		return;
	}else{ 
		Q->rear = (Q->rear+1) % MaxSize;
		Q->Data[Q->rear] = item; 
	}
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(Queue Q){
	return (Q->front == Q->rear);
}
 
// ����
ElementType DeleteQ(Queue Q){
	if(IsEmpty(Q)){
		printf("���п�");
		return 0;
	}else{
		Q->front = (Q->front+1) % MaxSize;
		return Q->Data[Q->front];
	}
} 

int main(){
	Queue Q;
	Q = CreateQueue();
	AddQ(Q,3);
	printf("3���\n");
	AddQ(Q,5);
	printf("5���\n");
	AddQ(Q,11);
	printf("11���\n");
	printf("%d����\n",DeleteQ(Q));
	printf("%d����\n",DeleteQ(Q));
	return 0;
} 




