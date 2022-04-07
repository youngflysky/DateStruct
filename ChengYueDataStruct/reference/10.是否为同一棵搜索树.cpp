#include<iostream>
#include<string>
#include<malloc.h>
using namespace std;
typedef struct TreeNode *BinTree;
struct TreeNode{
	int data;  // ��ֵ
	BinTree left;  // ������
	BinTree right; // ������ 
};

// ����һ����� 
BinTree Insert(int x,BinTree BST){
	if(!BST){   // ������Ϊ�գ����������� 
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->data = x;
		BST->left = NULL;
		BST->right = NULL;
	}else{  //  �����㲻Ϊ�� 
		if(x < BST->data)  // ��� x �ȵ�ǰ����ֵС 
			BST->left = Insert(x,BST->left);  // �ݹ鵽���������� 
		else if(BST->data < x)  // ��� x �ȵ�ǰ����ֵ�� 
			BST->right = Insert(x,BST->right);   // �ݹ鵽����������
		// �����ȣ�ʲôҲ���� 
	}
	return BST;
}

// ǰ����� 
void  PreOrderTraversal(BinTree BST,string &s){
	if(BST){
		 
		PreOrderTraversal(BST->left,s);  // ���������� 
		s += BST->data+'0';  // �����ֵ������ַ���
		PreOrderTraversal(BST->right,s);  // ���������� 
	}
}

int main(){
	int n,l;
	int tmp;
	cin>>n>>l;
	while(n){  // �� n ��Ϊ����ѭ�� 
		BinTree InitBST = NULL;
		string Initstr;
		// ÿ�������� n l �ĳ�ʼ�������� 
		for(int i=0;i<n;i++){
			cin>>tmp;
			InitBST = Insert(tmp,InitBST);
		}
		// Initstr ��¼��ʼ���������γɵ��������������� 
		// ˼��Ϊʲô���������¼�� 
		PreOrderTraversal(InitBST,Initstr);
		
		// �� l �� 
		for(int i=0;i<l;i++){
			BinTree BST = NULL;
			string str;
			for(int j=0;j<n;j++){
				cin>>tmp;
				BST = Insert(tmp,BST);
			}
			// ÿ�еĲ������в���һ�������� str ��¼���������� 
			PreOrderTraversal(BST,str);
			
			// �ٽ���ʼ���к�ÿ�β������в�����ֵ���жԱ� 
			if(str == Initstr)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		cin>>n>>l;
	}
	return 0;
}
