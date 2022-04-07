#include<iostream>
#include<queue>
#include <algorithm>
#define MaxVertex 105
#define INF 100000
typedef int Vertex;
using namespace std;
int N; // ��
int M;  // ��
int G[MaxVertex][MaxVertex];  
int Earliest[MaxVertex];  // �������ʱ�� 
int latest[MaxVertex];  // �������ʱ�� 
int Indegree[MaxVertex]; // ��� 
int Outdegree[MaxVertex];  // ���� 
int Max;   // �ʱ�� 

// ��ʼ��ͼ 
void build(){
	Vertex v1,v2,w;
	cin>>N>>M;
	for(Vertex i=1;i<=N;i++)
		for(Vertex j=1;j<=N;j++)
			G[i][j] = INF;
	for(int i=0;i<M;i++){
		cin>>v1>>v2>>w;
		G[v1][v2] = w;  // ����ͼ 
		Indegree[v2]++;  // ���+1
		Outdegree[v1]++;  // ����+1 
	}
}

// ���Ƶõ���������ʱ�� 
void GetLastest(){
	
}

// ���������ҵ������Ŀ���ʱ�� 
bool TopSort(){
	int cnt = 0;
	queue<Vertex> q;
	// ���Ϊ0������� 
	for(Vertex i=1;i<=N;i++)
		if(!Indegree[i]){ 
			q.push(i);
			Earliest[i] = 0;
		} 
	while(!q.empty()){
		Vertex v = q.front();
		q.pop();
		cnt++;
		for(Vertex w=1;w<=N;w++)
			if(G[v][w]!=INF){ 
				if(Earliest[w] < Earliest[v]+G[v][w])  //�����Χ��ʱ�����������ʱ�� 
					Earliest[w] = max(Earliest[w],Earliest[v]+G[v][w]);
				if(--Indegree[w]==0)
					q.push(w);
			} 
	}
	if(cnt!=N)
		return false;
	else{ 
		// Ҳ��ֹһ���յ� 
		Max = 0;
		for(Vertex i=1;i<=N;i++)
			if(Max < Earliest[i])
				Max = Earliest[i];
		return true;
	}
		
}

int main(){
	build();
	if(!TopSort())
		cout<<0;
	else{
		cout<<Max<<endl;
		
	}
	return 0;
}


