/*#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef int Vertex; 
typedef int DataType; 
typedef int weightType;  

typedef struct ENode *ptrToENode;
struct ENode{  // �� 
	Vertex V1,V2;    // �����<V1,V2> 
	weightType Weight;  // Ȩ�� 
};
typedef ptrToENode Edge;

typedef struct AdjVNode *ptrToAdjVNode;
struct AdjVNode{  // �ڽӱ���Ԫ�� 
	Vertex AdjV;  // �ڽӵ��±� 
	weightType Weight;  // Ȩֵ 
	ptrToAdjVNode Next;  // ��һ�� 
};

typedef struct VNode{  // �ڽӱ�ͷ 
	ptrToAdjVNode FirstEdge;  // ��ÿ������ָ��
	DataType Data;  // �������� 
}AdjList[MaxVertexNum];

typedef struct GNode *ptrToGNode;
struct GNode{  // ͼ 
	int Nv;  // ����
	int Ne;  // ���� 
	AdjList G; // �ڽӱ� 
}; 
typedef ptrToGNode LGraph;

// ��ʼ�� 
LGraph create(int VertexNum){
	Vertex v,w;
	LGraph Graph;
	
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;  // ��ʼ����
	Graph->Ne = 0;   // ��ʼ����
	
	// ÿ���ߵ� FirstEdge ָ�� NULL 
	for(v=0;v<Graph->Nv;v++)
		Graph->G[v].FirstEdge = NULL;
	return Graph;
}


// ����һ���ߵ��ڽӱ�Ķ���ָ��֮�� 
void InsertEdge(LGraph Graph,Edge E){
	ptrToAdjVNode newNode; 
	
	            //   �����<V1,V2> 
	// Ϊ V2 �����µĽ�� 
	newNode = (ptrToAdjVNode)malloc(sizeof(struct AdjVNode));
	newNode->AdjV = E->V2;
	newNode->Weight = E->Weight;
	
	// �� V2 ���뵽�ڽӱ�ͷ 
	newNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = newNode;
	
	          //   ��Ϊ����ͼ�������<V2,V1>
	newNode = (ptrToAdjVNode)malloc(sizeof(struct AdjVNode));
	newNode->AdjV = E->V1;
	newNode->Weight = E->Weight;
	
	newNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = newNode;
} 

// ��ͼ
LGraph BuildGraph(){
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	scanf("%d",&Nv);
	Graph = create(Nv);
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne != 0){
		for(i=0;i<Graph->Ne;i++){
			E = (Edge)malloc(sizeof(struct ENode));
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}
	return Graph;
} 

// ��ӡ 
void print(LGraph Graph){
	Vertex v;
	ptrToAdjVNode tmp;
	for(v=0;v<Graph->Nv;v++){
		tmp = Graph->G[v].FirstEdge;
		printf("%d ",v);
		while(tmp){
			printf("%d ",tmp->AdjV);
			tmp = tmp->Next;
		}
		printf("\n");
	}
}

int main(){
	LGraph Graph;
	Graph = BuildGraph();
	print(Graph);
	return 0;
}*/ 

#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef struct AdjVNode *AdjList;
struct AdjVNode{
	int weight;  // Ȩֵ 
  	int adjv;   // �±� 
	AdjList next;  // ���һ�� 
};
AdjList Graph[MaxVertexNum];
int Ne,Nv;

// ��ͼ
void BuildGraph(){
	int i;
	int v1,v2,w;
	AdjList NewNode;
	scanf("%d",&Nv);
	for(i=0;i<Nv;i++){
		Graph[i] = (AdjList)malloc(sizeof(struct AdjVNode));
		Graph[i]->adjv = i;
		Graph[i]->next = NULL;
	}
	scanf("%d",&Ne);
	for(i=0;i<Ne;i++){
		scanf("%d %d %d",&v1,&v2,&w);
		NewNode = (AdjList)malloc(sizeof(struct AdjVNode));
		NewNode->adjv = v1;
		NewNode->weight = w;
		
		NewNode->next = Graph[v2]->next;
		Graph[v2]->next = NewNode;
		
		NewNode = (AdjList)malloc(sizeof(struct AdjVNode));
		NewNode->adjv = v2;
		NewNode->weight = w;
		
		NewNode->next = Graph[v1]->next;
		Graph[v1]->next = NewNode;
	}
} 

void print(){
	AdjList tmp;
	int i;
	for(i=0;i<Nv;i++){
		tmp = Graph[i];
		while(tmp){
			printf("%d ",tmp->adjv);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

int main(){
	
	BuildGraph();
	print();
	return 0;
}

