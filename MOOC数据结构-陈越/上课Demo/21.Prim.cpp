#include<iostream>
#include<vector>
#define INF 100000
#define MaxVertex 105
typedef int Vertex; 
int G[MaxVertex][MaxVertex];
int parent[MaxVertex];   // ���鼯 
int dist[MaxVertex]; // ���� 
int Nv;    // ��� 
int Ne;    // �� 
int sum;  // Ȩ�غ� 
using namespace std; 
vector<Vertex> MST;  // ��С������ 

// ��ʼ��ͼ��Ϣ 
void build(){
	Vertex v1,v2;
	int w;
	cin>>Nv>>Ne;
	for(int i=1;i<=Nv;i++){
		for(int j=1;j<=Nv;j++)
			G[i][j] = 0;  // ��ʼ��ͼ 
		dist[i] = INF;   // ��ʼ������
		parent[i] = -1;  // ��ʼ�����鼯 
	}
	// ��ʼ����
	for(int i=0;i<Ne;i++){
		cin>>v1>>v2>>w;
		G[v1][v2] = w;
		G[v2][v1] = w;
	}
}

// Prim�㷨ǰ�ĳ�ʼ�� 
void IniPrim(Vertex s){
	dist[s] = 0;
	MST.push_back(s);
	for(Vertex i =1;i<=Nv;i++)
		if(G[s][i]){
			dist[i] = G[s][i];
			parent[i] = s;
		} 
}

// ����δ��¼��dist��С�ĵ� 
Vertex FindMin(){
	int min = INF;
	Vertex xb = -1;
	for(Vertex i=1;i<=Nv;i++)
		if(dist[i] && dist[i] < min){ 
			min = dist[i];
			xb = i;
		}
	return xb;
}

void output(){
	cout<<"����¼˳��"<<endl; 
	for(Vertex i=1;i<=Nv;i++)
		cout<<MST[i]<<" ";
	cout<<"Ȩ�غ�Ϊ��"<<sum<<endl; 
	cout<<"��������Ϊ��"<<endl; 
	for(Vertex i=1;i<=Nv;i++)
		cout<<parent[i]<<" ";
}

void Prim(Vertex s){
	IniPrim(s);
	while(1){
		Vertex v = FindMin();
		if(v == -1)
			break;
		sum += dist[v];
		dist[v] = 0;
		MST.push_back(v);
		for(Vertex w=1;w<=Nv;w++)
			if(G[v][w] && dist[w])
				if(G[v][w] < dist[w]){
					dist[w] = G[v][w];
					parent[w] = v;
				}
	}
}


int main(){
	build();
	Prim(1);
	output();
	return 0;
} 
