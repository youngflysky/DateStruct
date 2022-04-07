#include<queue>
#include<iostream> 
#define null -1
using namespace std;
struct TreeNode{
	int data;  // ��ֵ
	int left;  // ������ӽ�� 
	int right;   // ���Ҷ��ӽ�� 
}T[10];
//  ����������� 
int create(){
	int n;
	int root = 0;
	char left,right;
	cin>>n;
	if(!n)
		return null;
	for(int i=0;i<n;i++){
		T[i].data = i;
		cin>>left>>right;
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
		root +=i;
	}
	return root;
}
// ������� 
void LevelorderTraversal(int root){
	// �������� 
	queue<struct TreeNode> q;
	struct TreeNode t;
	bool flag = false;
	
	// �����Ϊ�գ�ֱ�Ӵ�ӡ 
	if(root == null){
		cout<<"-";
		return;	
	}
	q.push(T[root]);
	while(!q.empty()){
		t = q.front();  // �õ���ǰ����Ԫ�� 
		q.pop();  // ���� 
		if(t.left == null && t.right == null){  // ���ΪҶ�ӽ������ 
			if(flag)
				cout<<" ";
			else
				flag = true;
			cout<<t.data;	
		}
		if(t.left != null)  // ���������ӽ�㣬�������ӽ�� 
			q.push(T[t.left]);
		if(t.right != null)  // ������Ҷ��ӽ�㣬����Ҷ��ӽ�� 
			q.push(T[t.right]);
	}
} 
int main(){
	int root;
	root = create();
	LevelorderTraversal(root);
	return 0;
} 
