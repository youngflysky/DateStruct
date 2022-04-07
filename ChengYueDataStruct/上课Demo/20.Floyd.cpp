#include<iostream>
#include<stdlib.h>
#define INF 1000000
#define MaxVertex 100
typedef int Vertex;
int G[MaxVertex][MaxVertex];
int dist[MaxVertex][MaxVertex];  // ���� 
int path[MaxVertex][MaxVertex];  // ·�� 
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
			G[i][j] = INF;
	cin>>Ne;
	// ��ʼ����
	for(int i=0;i<Ne;i++){
		cin>>v1>>v2>>w;
		G[v1][v2] = w;  
		G[v2][v1] = w;
	}
}

void Floyd(){
	for(Vertex i=1;i<=Nv;i++)
		for(Vertex j=1;j<=Nv;j++){
			dist[i][j] = G[i][j];
			path[i][j] = -1;
		}
	for(Vertex k=1;k<=Nv;k++)
		for(Vertex i=1;i<=Nv;i++)
			for(Vertex j=1;j<=Nv;j++)
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
} 

void output(){
	for(Vertex i=1;i<=Nv;i++){ 
		for(Vertex j=1;j<=Nv;j++)
			cout<<dist[i][j]<<" ";	
		cout<<endl;
	}
	cout<<endl;
	for(Vertex i=1;i<=Nv;i++){ 
		for(Vertex j=1;j<=Nv;j++)
			cout<<path[i][j]<<" ";	
		cout<<endl;
	}
}


int main(){
	build();
	Floyd();
	output();
	return 0;
}
