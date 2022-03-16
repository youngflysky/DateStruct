#include<stdio.h>
#include<malloc.h> 
#include<vector> 
#include<queue>
#include<algorithm>
typedef struct TreeNode *BinTree;
struct TreeNode{
	int Data;  // ��ֵ 
	BinTree Left;    // ����ӽ�� 
	BinTree Right;   // �Ҷ��ӽ�� 
};
BinTree CreatBinTree();   // ����һ��������
bool IsEmpty(BinTree BT);  // �ж��� BT �Ƿ�Ϊ�� 
void PreOrderTraversal(BinTree BT);   // ���������������
void InOrderTraversal(BinTree BT);    // �������������� 
void PostOrderTraversal(BinTree BT);  // ������������Ҹ� 
using namespace std;
typedef struct SNode *Stack;
struct SNode{
	BinTree Data;
	Stack Next;
};


Stack CreateStack();  // ��ʼ����ջ 
int IsEmpty(Stack S);  // �ж���ջ�Ƿ�Ϊ�� 
void Push(Stack S,BinTree item);  // ��ջ 
BinTree Pop(Stack S);  // ��ջ
 

// ��ʼ�� 
Stack CreateStack(){
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

// �ж��Ƿ�Ϊ�� 
int IsEmpty(Stack S){
	return (S->Next == NULL);
}

// ��ջ
void Push(Stack S,BinTree item){
	Stack tmp;
	tmp = (Stack)malloc(sizeof(struct SNode));
	tmp->Data = item;
	// ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ��� 
	tmp->Next = S->Next;   
	S->Next = tmp;
} 

// ��ջ
BinTree Pop(Stack S){
	Stack First;
	BinTree TopVal;
	if(IsEmpty(S)){
		printf("��ջ��");
		return 0;
	}else{
		First = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ��� 
		S->Next = First->Next;  //�ѵ�һ��Ԫ�ش���ջɾ�� 
		TopVal = First->Data;   // ȡ����ɾ������ֵ 
		free(First);  // �ͷſռ� 
		return TopVal;
	}
} 

BinTree Insert(int Data){
	BinTree BT;
	BT =  (BinTree)malloc(sizeof(struct TreeNode));
	BT->Data = Data;
	BT->Left = NULL;
	BT->Right = NULL;
	return BT;
}

// ��ʼ�������� 
BinTree CreatBinTree(){
	BinTree BT;
	BT =  (BinTree)malloc(sizeof(struct TreeNode));
	BT->Data = 1;
	BT->Left = Insert(2);
	BT->Right = Insert(3);
	BT->Left->Left = Insert(4);
	BT->Left->Right = Insert(6);
	BT->Left->Right->Left = Insert(5);
	BT->Right->Left = Insert(7);
	BT->Right->Right = Insert(9);
	BT->Right->Left->Right = Insert(8);
	return BT;
}


// �ж����Ƿ�Ϊ��
/*bool  IsEmpty(BinTree BT){
}*/

// ����
/*void  PreOrderTraversal(BinTree BT){
	if(BT){
		printf("%d",BT->Data);  // ��ӡ�� 
		PreOrderTraversal(BT->Left);  // ���������� 
		PreOrderTraversal(BT->Right);  // ���������� 
	}
} */

// ����ǵݹ� 
void PreOrderTraversal(BinTree BT){
	BinTree T = BT;
	Stack S = CreateStack();  // ��������ʼ����ջ S
	while(T || !IsEmpty(S)){  // ������Ϊ�ջ��ջ���� 
		while(T){     
			Push(S,T);    // ѹջ����һ�������ý�� 
			printf("%d",T->Data);  // ���ʽ��
			T = T->Left;   // ���������� 
		}
		if(!IsEmpty(S)){  // ����ջ���� 
			T = Pop(S);    // ��ջ���ڶ��������ý�� 
			T = T->Right;  // �����ҽ�� 
		}
	} 
} 

// ����ݹ� 
/*void InOrderTraversal(BinTree BT){
	if(BT){
		InOrderTraversal(BT->Left);  // ���������� 
		printf("%d",BT->Data);  // ��ӡ�� 
		InOrderTraversal(BT->Right);  // ���������� 
	} 
} */

// ����ǵݹ�
void InOrderTraversal(BinTree BT){
	BinTree T = BT;
	Stack S = CreateStack();  // ��������ʼ����ջ S
	while(T || !IsEmpty(S)){  // ������Ϊ�ջ��ջ���� 
		while(T){     
			Push(S,T);    // ѹջ
			T = T->Left;   // ���������� 
		}
		if(!IsEmpty(S)){  // ����ջ���� 
			T = Pop(S);    // ��ջ
			printf("%d",T->Data);  // ���ʽ��
			T = T->Right;  // �����ҽ�� 
		}
	} 
} 

// ����
/*void PostOrderTraversal(BinTree BT){
	if(BT){
		PostOrderTraversal(BT->Left);  // ���������� 
		PostOrderTraversal(BT->Right);  // ���������� 
		printf("%d",BT->Data);  // ��ӡ�� 
	} 
} */ 

// ������� 
void PostOrderTraversal(BinTree BT){
	BinTree T = BT;
	Stack S = CreateStack();  // ��������ʼ����ջ S
	vector<BinTree> v;
	Push(S,T);
	while(!IsEmpty(S)){  // ������Ϊ�ջ��ջ���� 
		T = Pop(S);
		v.push_back(T);
		if(T->Left)
			Push(S,T->Left);
		if(T->Right)
			Push(S,T->Right);
	}
	reverse(v.begin(),v.end());  // ��ת 
	for(int i=0;i<v.size();i++)
		printf("%d",v[i]->Data);
} 

// ��α���
void LevelOrderTraversal(BinTree BT){
	queue<BinTree> q;
	BinTree T;
	if(!BT)
		return;
	q.push(BT);  // BT ��� 
	while(!q.empty()){
		T = q.front();  // ���ʶ���Ԫ�� 
		q.pop();  // ����
		printf("%d",T->Data);
		if(T->Left)
			q.push(T->Left);
	 	if(T->Right)
	 		q.push(T->Right);
	}
}
// ���Ҷ�ӽ��
void  FindLeaves(BinTree BT){
	if(BT){
		if( !BT->Left && !BT->Right)
			printf("%d",BT->Data);  // ��ӡҶ�ӽ��
		FindLeaves(BT->Left);  // ���������� 
		FindLeaves(BT->Right);  // ���������� 
	}
} 

// �����߶�
int  GetHeight(BinTree BT){
	int hl,hr,maxh;
	if(BT){
		hl = GetHeight(BT->Left);  // ���������߶� 
		hr = GetHeight(BT->Right);  // ���������߶� 
		maxh = (hl>hr)?hl:hr;
		return maxh+1;  // ��ǰ���߶�Ϊ�����������ĸ߶�+1 
	}else
		return 0;
} 
int main(){
	BinTree BT,ST;
	BT = CreatBinTree();
	printf("���������");
	PreOrderTraversal(BT);
	printf("\n���������");
	InOrderTraversal(BT);
	printf("\n���������");
	PostOrderTraversal(BT);
	printf("\n��α�����");
	LevelOrderTraversal(BT);
	printf("\n���Ҷ�ӽ��:"); 
	FindLeaves(BT);
	printf("\n������ĸ߶ȣ�%d",GetHeight(BT));
	return 0;
}
































