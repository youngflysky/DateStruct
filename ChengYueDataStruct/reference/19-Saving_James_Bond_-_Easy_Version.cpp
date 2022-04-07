#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<queue> 
#define MaxVertex 105
struct Node{  // �������±� 
	int hor;   // ������ 
	int ver;  // ������
	bool visit;  // �Ƿ񱻷���
	bool safe;  // �Ƿ����ϰ� 
	bool jump;  // ��һ���ܷ�����ȥ 
};
int N;   // ������ 
int D;   // ��Ծ����
bool isSafe;  // �Ƿ��ϰ� 
Node G[MaxVertex];
using namespace std;
const double diameter=15;

// ����������� 
double getLen(int x1,int y1,int x2,int y2){
	return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
}

// ����������ܷ񵽰��� 
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
		if(ashore((G[i].hor),(G[i].ver)))
			G[i].safe = true; // �������Ϊ true
		else
			G[i].safe = false; 
	}
}

// ȷ����Щ�����ǿ��Ե�һ������ȥ�� 
void getJump(){
	for(int i=0;i<N;i++){
		// ���������λ�ú�"������"���ڣ���Ծ����+�뾶�� 
		if(getLen(G[i].hor,G[i].ver,0,0)<=D+diameter/2)
			G[i].jump = true;
		else
			G[i].jump = false;
	}
}

// ��ʼ�� 
void Init(){
	cin>>N>>D;
	int x,y;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		G[i].hor = x;
		G[i].ver = y;
		G[i].visit = false;
	}
	getSafe();
	getJump();
	isSafe = false;
}
/*
void DFS(int v){
	if(G[v].safe){ 
		isSafe = true;
		return;
	} 
	G[v].visit = true;
	for(int i=0;i<N;i++){
		// �������С�� D����δ������������
		if(getLen(G[v].hor,G[v].ver,G[i].hor,G[i].ver)<=D && !G[i].visit)
			DFS(i);
	}
}
*/
void BFS(int v){
	queue<Node> q;
	Node tmp;
	G[v].visit = true;
	// ��һֻ������� 
	q.push(G[v]);
	while(!q.empty()){
		tmp = q.front();
		q.pop();
		// ���ϰ� 
		if(tmp.safe){
			isSafe = true;
			return;
		}
		for(int i=0;i<N;i++){
			// �������С�� D����δ������������
			if(getLen(tmp.hor,tmp.ver,G[i].hor,G[i].ver)<=D && !G[i].visit){
				G[i].visit = true;
				q.push(G[i]);
			}
		}
	}
}

// �������е�һ�������������� 
void listCompoent(){
	for(int i=0;i<N;i++)
		if(G[i].jump){
		//	DFS(i); 
			BFS(i);
		}
	if(isSafe)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}


int main(){
	Init();
	listCompoent();
	return 0;
}
