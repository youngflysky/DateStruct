#include<cstdio>
#define MaxSize 10005
typedef int SetType; 
using namespace std;
// ��ʼ�� 
void Init(SetType s[],int n){
	for(int i=0;i<n;i++)
		s[i] = -1;
}

// ���� 
int Find(SetType s[],int x){
	if(s[x] < 0)  // �����Ѿ��Ǹ� 
		return x;
	else  // 1. �ҵ���  2. �Ѹ���� x �ĸ����  3.�ٷ��ظ� 
		return s[x] = Find(s,s[x]);
} 

// ��
void Union(SetType s[],int x1,int x2){
	// x1 ��ģ���󣬸������� 
	if(s[x1] < s[x2]){
		s[x1] += s[x2];    //  �����ϲ�����ģ��� 
		s[x2] = x1;   // x2 �ҵ� x1 �� 
	}else{
		s[x2] += s[x1];   //  �����ϲ�����ģ��� 
		s[x1] = x2;
	}
} 

//����
void Input_connection(SetType s[]){
	int x1,x2;
	scanf("%d %d",&x1,&x2);
	int root1 = Find(s,x1-1);  // �������±��ֵ���±����ֵ�� 1 
	int root2 = Find(s,x2-1);
	if(root1 != root2)
		Union(s,root1,root2);
}

//�������
void check_connection(SetType s[]){
	int x1,x2;
	scanf("%d %d",&x1,&x2);
	int root1 = Find(s,x1-1);
	int root2 = Find(s,x2-1);
	if(root1 == root2)
		printf("yes\n");
	else
		printf("no\n");
} 

// �������
void check_network(SetType s[],int n){
	int counter = 0;
	for(int i=0;i<n;i++)
		if(s[i] < 0)
			counter++;
	if(counter == 1)
		printf("The network is connected.");
	else
		printf("There are %d components.",counter);
}


int main(){
	int n;
	char in;
	scanf("%d",&n); 
	SetType s[MaxSize];
	Init(s,n);
	do{
		getchar();  // ����ÿ�ζ�����Ļس� 
		scanf("%c",&in);
		switch(in){
			case 'I':Input_connection(s);break;
			case 'C':check_connection(s);break;
			case 'S':check_network(s,n);break;
		}		
	}while(in != 'S');

	return 0;
} 
