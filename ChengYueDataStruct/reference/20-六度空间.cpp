#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define MaxVertex 10005
typedef int vertex;
typedef struct Node *AdjList;
struct Node{
	vertex Adjv;  // ��ǰ�±� 
	AdjList Next;  // ��һ�� 
};
AdjList G[MaxVertex];
bool visit[MaxVertex];  // �Ƿ���� 
int N;  // �����
int M;  // ���� 
using namespace std;

// ��ʼ������״̬ 
void InitVisit(){
	for(int i=1;i<=N;i++)
		visit[i] = false;
}

// ��ʼ�� 
void Init(){
	vertex v1,v2;
	AdjList NewNode;
	cin>>N>>M;
	// ��ʼ���㣬�� 1��N 
	for(int i=1;i<=N;i++){
		G[i] = (AdjList)malloc(sizeof(struct Node));
		G[i]->Adjv = i;
		G[i]->Next = NULL;
	}
	// ��ʼ���� 
	for(int i=0;i<M;i++){
		cin>>v1>>v2;
		NewNode = (AdjList)malloc(sizeof(struct Node));
		NewNode->Adjv = v2;
		NewNode->Next = G[v1]->Next;
		G[v1]->Next = NewNode;
		
		NewNode = (AdjList)malloc(sizeof(struct Node));
		NewNode->Adjv = v1;
		NewNode->Next = G[v2]->Next;
		G[v2]->Next = NewNode;
	}
}

int BFS(vertex v){
	queue<vertex> q;
	vertex tmp;
	int level = 0;
	int last = v;  // �ò����һ�η��ʵĽ�� 
	int tail = v;  // ÿ���ڱ�Ľ�� 
	AdjList node;
	visit[v] = true;
	int count = 1;  // ͳ�ƹ�ϵ�� 
	q.push(v);
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		// G[i]��һ�������Լ����±� 
		node = G[tmp]->Next;
		while(node){
			if(!visit[node->Adjv]){
				visit[node->Adjv] = true;
				q.push(node->Adjv);
				count++;
				tail = node->Adjv; // ÿ�θ��¸ý�� 
			}
			node = node->Next;
		} 
		// ����õ�ǰ�����������һ����� 
		if(tmp == last){  
			level++;    // ���� +1  
			last = tail;   // ���� last 
		}
		// �������˽��� 
		if(level==6)
		   break;
	}
	return count; 
} 


void output(double result,int i){
	printf("%d: %.2f%%\n",i,result);
}

void SDS(){
	int count;
	for(int i=1;i<=N;i++){
		// ÿ�γ�ʼ���������� 
		InitVisit(); 
		count = BFS(i);
		output((100.0*count)/N,i);
	}
}


int main(){
	Init();
	SDS();
	
	return 0;
} 
