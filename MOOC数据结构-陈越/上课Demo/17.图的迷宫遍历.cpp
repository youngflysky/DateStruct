#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define col 12
#define row 10
int Graph[row][col];  // ���ͼ 
bool visit[row][col];  // �����״̬ 
int times[row][col];   // ����ʴ��� 
typedef struct Node *coordinate;
struct Node{    // ���� 
	int hor; // ������ 
	int ver; // ������ 
};
using namespace std;

// ��ʼ��ͼ 
void Init(){
	int tmp[row][col]= {{1,1,1,0,1,1,1,0,1,1,1,0},
				        {1,0,1,1,0,0,1,0,1,0,0,0},
				        {1,0,0,0,1,0,0,0,1,0,1,1},
				        {1,0,1,1,1,1,1,1,1,0,0,1},
				        {0,0,1,0,0,1,0,1,1,1,1,0},
				        {1,1,1,0,1,1,0,0,0,1,1,1},
				        {1,1,0,1,1,1,1,0,0,1,0,0},
				        {0,0,0,1,0,0,1,0,1,0,1,1},
				        {0,1,1,0,1,1,1,0,1,0,1,0},
				        {0,0,0,0,0,1,1,0,1,0,1,1}};
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++){
			times[i][j] = 1000;  // ��ʼ���ɴ�������С���� 
			Graph[i][j] = tmp[i][j];
			if(Graph[i][j])  // Ϊ 1 ���Է��� 
				visit[i][j] = true;
			else
				visit[i][j] = false;
		}
}


// ��ʼ������ 
coordinate create(int i,int j){
	coordinate C = (coordinate)malloc(sizeof(struct Node));
	C->hor = i;
	C->ver = j;
	return C;
}

int min(int t1,int t2){
	return t1<t2?t1:t2;
}

// ���� �����ϡ����ҡ��ҡ����¡��¡����¡��� �˸�λ�� 

int x[] = {-1,-1,-1,0,1,1,1,0};
int y[] = {-1,0,1,1,1,0,-1,-1};
void BFS(){
	queue<coordinate> q;
	coordinate tmp;
	// �������� 
	tmp = create(0,0);
	visit[0][0] = false;
	times[0][0] = 0;
	q.push(tmp);
	while(!q.empty()){
		 // ȡ�������е��±�Ͳ��� 
		 coordinate nowNode = q.front();
		 int xx = nowNode->hor;
		 int yy = nowNode->ver;
		 int nowtimes = times[xx][yy];
		 q.pop();  // ���� 
		 // �õ�����Χ�˸�������� 
		 for(int i=0;i<8;i++){
		 	int newx = xx + x[i];
		 	int newy = yy + y[i];
		 	// ����ڷ�Χ�� 
		 	if((newx>=0 && newx<row) &&(newy>=0 && newy<col) && visit[newx][newy] ){ 
		 		visit[newx][newy] = false;  // ����״̬ 
	 			tmp = create(newx,newy);   
	 			times[newx][newy] = min(times[newx][newy],nowtimes+1);  // ���²��� 
	 			q.push(tmp);  // ��� 
		 	}
		 }
	}
}
int main(){
	Init();
	BFS();
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			if(times[i][j]==1000)
				printf(" -1");
			else 
				printf("%3d",times[i][j]);
		printf("\n");
	}
	return 0;
}
