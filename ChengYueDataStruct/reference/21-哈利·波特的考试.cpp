/*#include<iostream>
#define MaxVertex 105
#define INF 100000
typedef int Vertex;
int G[MaxVertex][MaxVertex];  // ͼ 
int N;  // �����������㣩 
int M;  // �����������ߣ� 
int dist[MaxVertex][MaxVertex];  // ����
bool collected[MaxVertex][MaxVertex];  // ѡ��״̬ 
using namespace std;

// ��ʼ�� 
void build(){
	Vertex v1,v2;
	int w;
	cin>>N>>M;
	for(Vertex i=1;i<=N;i++){
		for(Vertex j=1;j<=N;j++){ 
			G[i][j] = 0;   // ��ʼ��ͼ
			dist[i][j] = INF;  // ��ʼ������
			collected[i][j] = false;  // ��ʼѡ��״̬ 
		}
		dist[i][0] = INF;  // ���⽫ÿ��Դ���һ�������ʼ�� INF 
	}
	for(int i=0;i<M;i++){
		cin>>v1>>v2>>w;
		G[v1][v2] = w; 
		G[v2][v1] = w;
	}
} 

// ����δ��ѡ�еĶ����о�����С��һ�� 
Vertex FindMin(Vertex s){
	Vertex min = 0;
	for(Vertex i = 1;i<=N;i++)
		if(i!=s && dist[s][i] < dist[s][min] && !collected[s][i])
			min = i;
	return min; 
}

int FindMax(Vertex s){
	int max = 0;
	for(Vertex i = 1;i<=N;i++)
		if(max < dist[s][i])
			max = dist[s][i];
	return max;
}

// ����Դ����룬�Ҹõ���Χ�����״̬ 
void prepare(Vertex s){
	dist[s][s] = 0;
	collected[s][s] = true;
	for(Vertex i=1;i<=N;i++)
		if(G[s][i])
			dist[s][i] = G[s][i];
} 

int Dijkstra(Vertex s){
	prepare(s);  // ׼�� 
	while(1){
		Vertex v = FindMin(s);
		if(!v)
			break;
		collected[s][v] = true;
		for(Vertex w=1;w<=N;w++)
			if(G[v][w] && !collected[s][w])
				if(dist[s][v] + G[v][w] < dist[s][w])
					dist[s][w] = dist[s][v] + G[v][w];
	} 
	// �ҵ��Լ����ѱ�����ﳤ�� 
	return FindMax(s);
}

int main(){
	build();
	int min = INF;
	int xb = 0;
	int max;
	for(Vertex s=1;s<=N;s++){
		max = Dijkstra(s);
		if(max < min){ 
			min = max;
			xb = s; 
		} 
		if(min==INF){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<xb<<" "<<min<<endl;
	return 0;
}*/



#include<iostream>
#define MaxVertex 105
#define INF 100000
typedef int Vertex;
int G[MaxVertex][MaxVertex];  // ͼ 
int N;  // �����������㣩 
int M;  // �����������ߣ� 
int dist[MaxVertex][MaxVertex];  // ����
using namespace std;

// ��ʼ�� 
void build(){
	Vertex v1,v2;
	int w;
	cin>>N>>M;
	for(Vertex i=1;i<=N;i++)
		for(Vertex j=1;j<=N;j++)
			G[i][j] = INF;   // ��ʼ��ͼ
	for(int i=0;i<M;i++){
		cin>>v1>>v2>>w;
		G[v1][v2] = w; 
		G[v2][v1] = w;
	}
}

void Floyd(){
	// ��ʼ�� dist ���� 
	for(Vertex i=1;i<=N;i++)
		for(Vertex j=1;j<=N;j++) 
			dist[i][j] = G[i][j];
	for(Vertex k=1;k<=N;k++)
		for(Vertex i=1;i<=N;i++)
			for(Vertex j=1;j<=N;j++)
				if(dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}

// ����ÿ��Դ�㵽����������ֵ 
int FindMax(Vertex s){
	int max = 0;
	for(Vertex i=1;i<=N;i++)
		if(s!=i && max < dist[s][i])
			max = dist[s][i];
	return max;
}

// ����ÿ��Դ�㵽����������ֵ����С�ľ��� 
void FindMin(){
	int ItemMax;
	int min = INF;
	int animal; 
	for(Vertex i=1;i<=N;i++){
		ItemMax = FindMax(i);
		if(ItemMax == INF){
			cout<<0<<endl;
			return;
		}
		if(ItemMax < min){ 
			min = ItemMax;
			animal = i;
		}
	}
	cout<<animal<<" "<<min<<endl;
}

int main(){
	build();
	Floyd();
	FindMin();
	return 0;
}

