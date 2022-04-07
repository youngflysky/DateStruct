#include<iostream>
#include<cmath>
#define INF 100000 
#define MaxVertex 105
typedef int Vertex;
int G[MaxVertex][MaxVertex]; // ͼ
int dist[MaxVertex];  // ����
int path[MaxVertex];  // ·�� 
bool collected[MaxVertex];  // ��¼��� 
int N;  // ����
int D;  // һ������ 
struct Node{  // ��λ��
	int hor;  // ������
	int ver;  // ������ 
};
Node pos[MaxVertex];  // �������λ�� 
const double diameter=15;  // ֱ�� 
using namespace std;

// ������Ȩͼ 
// 0.�ж����ϰ�����ļ��� 
// 1.�жϸ������Ƿ�����
// 2.ת��Ϊͼ 

// ����������� 
double getLen(int x1,int y1,int x2,int y2){
	return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
}
// �ж������ܷ��ϰ� 
bool ashore(int x,int y){
	// �ֱ���㵱ǰ����밶�ߵľ���
	// ���� (x,50),(x,-50),(50,y),(-50,y) �ľ���  
	if(abs(x-50)<=D || abs(x+50)<=D || abs(y+50)<=D || abs(y-50)<=D)
		return true;
	return false;
}

// ȷ�������Ƿ�ȫ("���ϰ�") 
void getSafe(){
	for(int i=0;i<N;i++){
		// ���������λ�ú�"����"���� 
		// ��ͨ 
		if(ashore((pos[i].hor),(pos[i].ver))){
			G[N+1][i] = 1;
			G[i][N+1] = 1;
		}
	}
}

// ȷ����Щ�����ǿ��Ե�һ������ȥ�� 
void getJump(){
	for(int i=0;i<N;i++)
		// ���������λ�ú�"������"���ڣ���Ծ����+�뾶�� 
		if(getLen(pos[i].hor,pos[i].ver,0,0)<=D+diameter/2){
			G[N][i] = 1;
			G[i][N] = 1;
		}
}

// ��������� 
void getConn(){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			// �����������С��һ�����룬��˴���ͨ 
			if(i!=j && getLen(pos[i].hor,pos[i].ver,pos[j].hor,pos[j].ver)<=D){
				G[i][j] = 1;
				G[j][i] = 1;
			}
}

// ��ʼ�� 
void Init(){
	cin>>N>>D;
	int x,y;
	// ¼��λ�� 
	for(int i=0;i<N;i++){
		cin>>x>>y;
		pos[i].hor = x;
		pos[i].ver = y;
	}
	// 007 �㶥�㣬��Ҳ�㶥��
	// ��ʼ��ͼ��007��ͨ����� G[N]������ͨ����� G[N+1] 
	for(Vertex i=0;i<=N+1;i++){
		for(Vertex j=0;j<=N+1;j++)
			G[i][j] = INF;  // ��ʼ�����
		dist[i] = INF;  // ��ʼ������
		path[i] = -1;  // ��ʼ��·��
		collected[i] = false; // ��ʼ����¼״̬ 
	} 
	// ��ʼ����
	// ����ͨ��� 
	getSafe();
	// 007��ͨ��� 
	getJump();
	// ����˴���ͨ��� 
	getConn(); 
}


// ����δ��¼dist��С�ĵ�
Vertex FindMin(Vertex s){
	int min = INF;
	Vertex xb=-1;
	for(Vertex i=0;i<=N+1;i++)
		if(s!=i && !collected[i] && dist[i] < min){
			min = dist[i];
			xb = i;
		}
	return xb;
} 

// ��ʼ��Դ����Ϣ 
void InitSource(Vertex s){
	dist[s] = 0;
	collected[s] = true;
	for(Vertex i=0;i<=N+1;i++)
		if(G[s][i]!=INF){
			dist[i] = G[s][i];
			path[i] = s;
		}
}

void Dijkstra(Vertex s){
	InitSource(s);
	while(1){
		Vertex v = FindMin(s);
		if(v==-1)
			break;
		collected[v] = true;
		for(Vertex w=0;w<=N+1;w++)
			if(!collected[w] && G[v][w]!=INF)
				if(dist[v] + G[v][w] < dist[w]){
					dist[w] = dist[v] + G[v][w];
					path[w] = v;
				}
	}
} 

// ���·�� 
void outputPath(){
	// �����ͨ 
	
	
	if(dist[N+1] == INF){
		cout<<0<<endl;
		return;
	}
	Vertex v = path[N+1];
	cout<<dist[N+1]<<endl;
	while(v!=-1){
		cout<<pos[v].hor<<" "<<pos[v].ver<<endl;
		v = path[v];
	}
	
}

int main(){
	Init();
	Dijkstra(N);
	outputPath(); 
	return 0;
} 



