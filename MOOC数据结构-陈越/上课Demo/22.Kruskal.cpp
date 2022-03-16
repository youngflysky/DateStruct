#include<iostream>
#include<string>
#include<vector>
#include<queue>
#define INF 100000
#define MaxVertex 105
typedef int Vertex; 
int G[MaxVertex][MaxVertex];
int parent[MaxVertex];   // ���鼯��С������ 
int Nv;    // ��� 
int Ne;    // �� 
int sum;  // Ȩ�غ� 
using namespace std; 
struct Node{
	Vertex v1;
	Vertex v2;
	int weight; // Ȩ�� 
	// ��������������� 
	bool operator < (const Node &a) const
	{
		return weight>a.weight;
	}
};
vector<Node> MST;  // ��С������ 
priority_queue<Node> q;   // ��С�� 

// ��ʼ��ͼ��Ϣ 
void build(){
	Vertex v1,v2;
	int w;
	cin>>Nv>>Ne;
	for(int i=1;i<=Nv;i++){
		for(int j=1;j<=Nv;j++)
			G[i][j] = 0;  // ��ʼ��ͼ
		parent[i] = -1;
	}
	// ��ʼ����
	for(int i=0;i<Ne;i++){
		cin>>v1>>v2>>w;
		struct Node tmpE;
		tmpE.v1 = v1;
		tmpE.v2 = v2;
		tmpE.weight = w;
		q.push(tmpE); 
	}
}

//  ·��ѹ������ 
int Find(int x){
	if(parent[x] < 0)
		return x;
	else
		return parent[x] = Find(parent[x]);
} 

//  ���ȹ鲢 
void Union(int x1,int x2){
	if(parent[x1] < parent[x2]){
		parent[x1] += parent[x2];
		parent[x2] = x1;
	}else{
		parent[x2] += parent[x1];
		parent[x1] = x2;
	}
} 

void Kruskal(){
	// ��С�������ı߲��� Nv-1 ���һ��б� 
	while(MST.size()!= Nv-1 && !q.empty()){
		Node E = q.top();  // ����С��ȡ��һ��Ȩ����С�ı�
		q.pop(); // ���������� 
		if(Find(E.v1) != Find(E.v2)){  // ����������Ƿ���ͬһ���� 
			sum += E.weight; 
			Union(E.v1,E.v2);     // ������ 
			MST.push_back(E);
		}
	}
	
} 


void output(){
	cout<<"����¼˳��"<<endl; 
	for(Vertex i=0;i<Nv;i++)
		cout<<MST[i].weight<<" ";
	cout<<"Ȩ�غ�Ϊ��"<<sum<<endl; 
	for(Vertex i=1;i<=Nv;i++)
		cout<<parent[i]<<" ";
	cout<<endl;
}


int main(){
	build();
	Kruskal();
	output();
	return 0;
} 
