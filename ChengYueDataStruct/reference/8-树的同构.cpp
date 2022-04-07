#include<iostream>
#include<malloc.h>
#define null -1
using namespace std;
struct TreeNode{
	char data;    // ��ֵ 
	int left;   // ���������±� 
	int right;  // ���������±� 
}T1[10],T2[10];
// ���ظ���� 
int create(struct TreeNode T[]){
	int n;
	int root = 0;
	char left,right;
	cin>>n;
	if(!n)
		return null;
	for(int i=0;i<n;i++){
		cin>>T[i].data>>left>>right;
		if(left=='-')
			T[i].left = null;
		else{
			T[i].left = left-'0';
			root -= T[i].left;
		}
		if(right=='-')
			T[i].right = null;
		else{
			T[i].right = right-'0';
			root -= T[i].right;
		}
		// 0 �ۼӵ� n-1 
		root +=i;	
	}
	return root;
}
// �ж��Ƿ�ͬ��
bool judge(int R1,int R2){
	if(R1 == null && R2 == null)   // ��Ϊ�� 
		return true;
	if(R1 == null && R2 != null || R1 != null && R2 == null)    // һ��Ϊ�գ�һ����Ϊ��
		return false;
	if(T1[R1].data != T2[R2].data)   // ֵ��ͬ
		return false;
	if((T1[R1].left != null && T2[R2].left != null )&&(T1[T1[R1].left].data == T2[T2[R2].left].data))  // ����Ӳ�Ϊ����ֵ���
		return judge(T1[R1].left,T2[R2].left) && judge(T1[R1].right,T2[R2].right);
	else   // ����Ӳ�Ϊ����ֵ����  ���� ĳһ�������Ϊ�� 
		return judge(T1[R1].right,T2[R2].left) && judge(T1[R1].left,T2[R2].right);
} 
int main(){
	int R1,R2;
	R1 = create(T1);
	R2 = create(T2);
	if(judge(R1,R2))
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
} 
