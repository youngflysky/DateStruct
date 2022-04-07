#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define MaxSize 2005
using namespace std;
int value[MaxSize];
int BST[MaxSize];

// ���� n �������������������� 
int getLeftTreeSize(int n){
	int h =0;   // ����ý�������������Ĳ��� 
	int tmp = n+1;
	while(tmp!=1){
		tmp /=2;
		h++;
	}
	int x = n-pow(2,h)+1;   // ������һ����Ҷ������ 
	x = x<pow(2,h-1)?x:pow(2,h-1);   // ��Ҷ����������� 2^(h-1) 
	int L = pow(2,h-1)-1+x;   // �ý�����������������ĸ��� 
	return L;
}

// ��亯��
void fill(int left,int right,int root){
	int n = right - left + 1;  // ȷ����Χ����ֵ���� 
 	if(!n)
 		return;
 	int L = getLeftTreeSize(n);   // �ҵ�"ƫ����" 
 	BST[root] = value[left + L];    // ������ֵӦ���� ��߽�ֵ + ƫ���� 
 	int leftRoot = 2 * root + 1;   // ����ӽ��λ�ã����ڴ� 0 ��ʼ 
 	int rightRoot = leftRoot + 1;  // �Ҷ��ӽ��λ�� 
 	fill(left,left+L-1,leftRoot);  // �������ݹ� 
 	fill(left+L+1,right,rightRoot);   // �������ݹ� 
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>value[i];
	}
	// ��С�������� 
	sort(value,value+n);
	fill(0,n-1,0);
	for(int i=0;i<n;i++){
		if(i)
			cout<<" ";
		cout<<BST[i];
	}
	return 0;
} 
