#include<iostream>
#include<malloc.h>
typedef struct AVLNode *AVLTree;
struct AVLNode{
	int data;     // ��ֵ 
	AVLTree left;  // ������ 
	AVLTree right;  // ������ 
	int height;  // ���� 
};
using namespace std;

// �������ֵ 
int Max(int a,int b){
	return a>b?a:b;
}

// �������ߣ��������� -1 
int getHeight(AVLTree A){
	return A==NULL?-1:A->height;
}

// LL����
// �� B ���������ڳ����Ҹ� A �����������ٽ� A �ҵ� B ����������ȥ 
AVLTree LLRotation(AVLTree A){
	/*
			A	
		   /
		  B
	     /
	    C
	*/
	// ��ʱ���ڵ��� A 
	AVLTree B = A->left;  // B Ϊ A ��������  
	A->left = B->right;   // B ������������ A ���������� 
	B->right = A;     //  A ���� B ���������� 
	A->height = Max(getHeight(A->left),getHeight(A->right)) + 1;
	B->height = Max(getHeight(B->left),A->height) + 1;
	return B;  // ��ʱ B Ϊ������� 
	/*
		B
	   / \
	  C   A 
	*/
}

// RR����
AVLTree RRRotation(AVLTree A){
	/*
			A	
		     \
		      B
	          \ 
	           C
	*/
	// ��ʱ���ڵ��� A 
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = Max(getHeight(A->left),getHeight(A->right)) + 1;
	B->height = Max(getHeight(B->left),A->height) + 1;
	return B;  // ��ʱ B Ϊ������� 
	/*
		B
	   / \
	  A   C 
	*/
}

// LR˫�� 
AVLTree LRRotation(AVLTree A){
	/*
		A
	   /
	  B
	   \
	   C
	*/
	// �� RR ����
	A->left = RRRotation(A->left);
	/*
	*/
	// �� LL ���� 
	return LLRotation(A);
}

// RL˫��
AVLTree RLRotation(AVLTree A){
	// �� LL ����
	A->right = LLRotation(A->right);
	// �� RR ���� 
	return RRRotation(A); 
}

AVLTree Insert(AVLTree T,int x){
	if(!T){  // ����ý��Ϊ�գ���ʼ����� 
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
		T->height = 0;
	}else{  // ����Ϊ�գ� 
		if(x < T->data){  // ������ 
			T->left = Insert(T->left,x);
			if(getHeight(T->left)-getHeight(T->right)==2){  // ������������������߶Ȳ�Ϊ 2 
				if(x < T->left->data)  // LL ���� 
					T = LLRotation(T); 
				else if(T->left->data < x)  // LR˫��
					T = LRRotation(T); 
			}
		}else if(T->data < x){
			T->right = Insert(T->right,x);
			if(getHeight(T->right)-getHeight(T->left)==2){
				if(x < T->right->data)  // RL ˫�� 
					T = RLRotation(T); 
				else if(T->right->data < x)  // RR����
					T = RRRotation(T); 
			}
		}
	}
	//�������� 
	T->height = Max(getHeight(T->left),getHeight(T->right)) + 1;
	return T;
} 


int main(){
	AVLTree T=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		T = Insert(T,tmp);
	}
	cout<<T->data;
	return 0;
}
