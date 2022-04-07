#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
#include<malloc.h>
using namespace std;
typedef struct TreeNode *Tree;
struct TreeNode{
	string data;
	Tree left;   // ������ 
	Tree right;  // ������ 
};
// ��ʼ��һ������� 
Tree create(){
	Tree T;
	T = (Tree)malloc(sizeof(struct TreeNode));
	T->left = NULL;
	T->right = NULL;
	return T; 
}

// ��������������������� 
Tree restore(Tree T){
	int n;
	string str;
	stack<Tree> s;
	Tree node = T;
	bool flag = false;
	string value;
	scanf("%d\n",&n);
	// ���ڵ㸳ֵ 
	getline(cin,str);
	value = str.substr(5);  // �ӵ������ʼ��ȡ
	node->data = value;
	// �������ջ 
	s.push(node); 
	for(int i=1;i<2*n;i++){
		getline(cin,str);
		if(str=="Pop"){// ����� pop ����
			node = s.top();
			s.pop(); 
		}else{   // push
			value = str.substr(5);  // �ӵ������ʼ��ȡ
			Tree tmp = create();
			tmp->data = value;
			if(!node->left){// �������ӿգ��½���������� 
				node->left = tmp;
				node = node->left; 
			}else if(!node->right){  // ����Ҷ��ӿգ��½������Ҷ��� 
				node->right = tmp;
				node = node->right;
			}
			s.push(tmp);
		}
	}
	return T;
}

// ����ݹ����
void bl(Tree T,bool &flag){
	if(T){
		bl(T->left,flag);
		bl(T->right,flag);
		if(!flag)
			flag = true;
		else
			cout<<" ";
		cout<<T->data;
	}
} 
int main(){
	Tree T;
	bool flag = false;
	string str;
	T = create();
	T = restore(T);
	bl(T,flag);
	return 0;
} 
