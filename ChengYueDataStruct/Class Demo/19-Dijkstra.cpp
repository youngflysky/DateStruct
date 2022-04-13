#include<iostream>
#include<stdlib.h>
#define Inf 1000000
#define Init -1
#define MaxVertex 100
typedef int Vertex;
int G[MaxVertex][MaxVertex];
int dist[MaxVertex];  // ���� 
int path[MaxVertex];  // ·�� 
int collected[MaxVertex];  // ����¼���� 
int Nv;   // ���� 
int Ne;   // �� 
using namespace std;

// ��ʼ��ͼ��Ϣ 
void build(){
	Vertex v1,v2;
	int w;
	cin>>Nv;
	// ��ʼ��ͼ 
	for(int i=1;i<=Nv;i++)
		for(int j=1;j<=Nv;j++)
			G[i][j] = 0;
	// ��ʼ��·�� 
	for(int i=1;i<=Nv;i++)
		path[i] = Init;
	// ��ʼ������
	for(int i=0;i<=Nv;i++)
		dist[i] = Inf;
	// ��ʼ����¼��� 
	for(int i=1;i<=Nv;i++)
		collected[i] = false;
	cin>>Ne;
	// ��ʼ����
	for(int i=0;i<Ne;i++){
		cin>>v1>>v2>>w;
		G[v1][v2] = w;  // ����ͼ 
	}
}

// ��ʼ�������·����Ϣ 
void crate(Vertex s){
	dist[s] = 0;
	collected[s] = true;
	for(int i=1;i<=Nv;i++)
		if(G[s][i]){
			dist[i] = G[s][i];
			path[i] = s;
		}
}

// ����δ��¼������dist��С��
Vertex FindMin(Vertex s){
	int min = 0;  // ֮ǰ�صذ� dist[0] ��ʼ��Ϊ������ 
	for(Vertex i=1;i<=Nv;i++)
		if(i != s && dist[i] < dist[min] && !collected[i])
			min = i;
	return min;
}


void Dijkstra(Vertex s){
	crate(s); 
	while(true){
		Vertex V = FindMin(s);   // �ҵ� 
		if(!V)
			break;
		collected[V] = true;  //��¼
		for(Vertex W=1;W<=Nv;W++)
			if(!collected[W] && G[V][W]){  // ���δ����¼
				if(dist[V] + G[V][W] < dist[W]){
					dist[W] = G[V][W] + dist[V];
					path[W] = V;
				}
			}
	}
}

void output(){
	for(int i=1;i<=Nv;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	for(int i=1;i<=Nv;i++)
		cout<<path[i]<<" ";
	cout<<endl;
}


int main(){
	build();
	Dijkstra(1);
	output();
	return 0;
}
