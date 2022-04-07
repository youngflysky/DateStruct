#include<queue>
#include<iostream>
#include<vector>
#include<map>
#define INF -100000
#define MaxVertex 1005
int G[MaxVertex][MaxVertex];
int Indegree[MaxVertex];  // ��� 
int value[MaxVertex];  // ��ֵ 
int N;  // ��ֵ
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;   // ������С�� 
map<int,int> m;

// ����� 
void Insert(){
	for(int i=0;i<N;i++){ 
		if(0 <= value[i]){
			m.insert(pair<int,int>(value[i],i));   // ���±���ֵ��ӳ���ϵ 
			int remainder = value[i]%N;  // ���� 
			if(remainder==i)
				Indegree[i] = 0;
			else if(remainder != i){
				Indegree[i] = (i - remainder < 0)?(i - remainder + N):(i - remainder);
				for(int j=remainder;j!=i;j=(j+1)%N)
					G[j][i] = 1;
			}
		}
	}
}

// ��ʼ��ͼ 
void build(){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			G[i][j] = INF;
	Insert();
}

// �������� 
void TopSort(){
	for(int i=0;i<N;i++)
		if(!Indegree[i] && 0 < value[i])
			q.push(value[i]);
	bool flag = true;
	while(!q.empty()){
		int tmpValue = q.top(); 
		int v = m[tmpValue];  // �һ��±� 
		q.pop();
		if(flag)
			flag = false;
		else
			cout<<" ";
		cout<<tmpValue;
		for(int w=0;w<N;w++)
			if(G[v][w]!=INF){  // �����ͨ 
				if(--Indegree[w]==0)
					q.push(value[w]);
			}
	}
}


int main(){
	cin>>N;
	int i=0;
	for(int i=0;i<N;i++)
		cin>>value[i];
	build();

	TopSort();
	return 0;
}
