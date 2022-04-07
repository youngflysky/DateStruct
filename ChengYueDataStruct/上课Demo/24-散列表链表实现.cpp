#include<iostream>
#include<cstdlib>
#include<cmath>
#define MAXTABLESIZE 100000
typedef int Index;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode{   // ������ 
	ElementType Data;
	PtrToLNode Next;
}; 
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable;  // ɢ�б�
struct TblNode{
	int TableSize;   // �����󳤶� 
	List Heads;  // ָ������ͷ�������� 
}; 
using namespace std;

int NextPrime(int N){
	int p = (N%2)?(N+2):(N+1);   // �� tablesize ������� 
	int i;
	while(p <= MAXTABLESIZE){
		for(i = (int)sqrt(p);i>2;i--)
			if(!(p%i))
				break;
		if(i==2)  // �ҵ������� 
			break;
		p += 2; // ��һ������
	}
	return p;
}

// ������ϣ�� 
HashTable CreateTable( int TableSize){
	HashTable H;
	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(sizeof(struct TblNode) * H->TableSize);
	for(int i=0;i<H->TableSize;i++) 
		H->Heads[i].Next = NULL;  // ����ͷ��H->Heads[i] �ǲ��涫���� 
	return H;
}

// ������������ϣ���� 
Index Hash(	int TableSize,ElementType Key){
	return  Key%TableSize;
}

// ����
Position Find(HashTable H,ElementType Key){
	Position p;
	Index pos;
	
	pos = Hash(H->TableSize,Key); 
	p = H->Heads[pos].Next;  //�������ͷ 
	while(p && p->Data != Key)
		p = p->Next;
	return p;
} 

// ����
bool Insert(HashTable H,ElementType Key){
	Position p,NewCell;
	Index pos;
	
	p = Find(H,Key);
	if(!p){  // �ؼ���δ�ҵ������Բ��� 
		NewCell = (Position)malloc(sizeof(struct LNode));
		NewCell->Data = Key;
		pos = Hash(H->TableSize,Key);   // ��ʼɢ�б��ַ
		// ���������嵽��ǰ��
		NewCell->Next = H->Heads[pos].Next;
		H->Heads[pos].Next = NewCell;
		return true;
	}else{
		return false;
	}
}

void output(HashTable H){
	for(int i=0;i<H->TableSize;i++){
		cout<<i;
		List p = H->Heads[i].Next;  
		while(p){
			cout<<" "<<p->Data;
			p = p->Next;
		} 
		cout<<endl;
	}
}

void DestroyTable(HashTable H){
	Position P,tmp;
	for(int i=0;i<H->TableSize;i++){
		P = H->Heads[i].Next;
		while( P ){
			tmp = P->Next;
			free(P);
			P = tmp;
		}
	}
	free(H->Heads);
	free(H);
} 


int main(){
	HashTable H = CreateTable(9);
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		Insert(H,tmp);
	}
	output(H);
	DestroyTable(H);
	return 0;
}













