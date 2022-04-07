#include<iostream>
#include<queue>
#include<vector> 
#define MaxVertex 1005
typedef int Vertex;
using namespace std;
int N;  // ���� 
int M;  // �� 
int parent[MaxVertex];   // ���鼯
struct Node{
	Vertex v1;
	Vertex v2;
	int weight;
	// ��������� 
	bool operator < (const Node &a) const
	{
		return weight>a.weight;
	}
}; 
priority_queue<Node> q;  // ��С�� 
vector<Node> MST; // ��С������ 
int sum;

// ��ʼ��ͼ��Ϣ 
void build(){
	Vertex v1,v2;
	int w;
	cin>>N>>M;
	for(int i=1;i<=N;i++){ 
		parent[i] = -1;
	} 
	// ��ʼ����
	for(int i=0;i<M;i++){
		cin>>v1>>v2>>w;
		struct Node tmpE;
		tmpE.v1 = v1;
		tmpE.v2 = v2;
		tmpE.weight = w;
		q.push(tmpE); 
	}
	sum = 0;
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
	x1 = Find(x1);
	x2 = Find(x2);
	if(parent[x1] < parent[x2]){
		parent[x1] += parent[x2];
		parent[x2] = x1;
	}else{
		parent[x2] += parent[x1];
		parent[x1] = x2;
	}
} 

void Kruskal(){
	while(MST.size()!=M-1 && !q.empty()){
		Node E = q.top();    // ��С�ѣ�����Ȩ����С�� 
		q.pop();   
		if(Find(E.v1) != Find(E.v2)){ // �ж��Ƿ�����ͬһ���� 
			sum += E.weight;
			Union(E.v1,E.v2);    // �� 
			MST.push_back(E);
		}
	}
}


int main(){
	build();
	Kruskal();
	// ͼ��ͨ 
	if(MST.size()==N-1)
		cout<<sum;
	else 
		cout<<-1;
	return 0;
} 


