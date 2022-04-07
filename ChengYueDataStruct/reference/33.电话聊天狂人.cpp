#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
#define MAXTABLESIZE 1000000
using namespace std;
typedef string ElementType;
typedef struct LNode *List;
struct LNode{  // ������ 
	ElementType number;  // �绰���� 
	int Count;  // ���� 
	List Next;   
};

typedef struct HashTbl *HashTable;
struct HashTbl{   // ��ϣ�� 
	int TableSize;  // ��ϣ���С
	List Heads;   // ͷ��� 
}; 

// ������������ϣ���� 
int Hash(int key,int p){
	return key%p;
}
 
int NextPrime(int N){
	int p = (N%2)?N+2:N+1;
	int i;
	while(p <= MAXTABLESIZE){
		for(i = (int)sqrt(1.0*p);i>2;i--)
			if(!(p%i))   // �������� 
				break;  
		if(i==2)  // �ҵ��� 
			break; 
		p += 2;  // ȥ���¸����� 
	}
	return p; 
}

// ��ʼ����ϣ�� 
HashTable CreateTable(int TableSize){
	HashTable H;
	H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize = NextPrime(TableSize);
	
	// �ṹ���к��ַ������붯̬�����ַ�ռ� 
	H->Heads = new LNode[H->TableSize];
	for(int i=0;i<H->TableSize;i++){
		H->Heads[i].Next = NULL;
		H->Heads[i].Count = 0; 
	}
	return H;
} 

// ���� 
List Find(HashTable H,ElementType key){
	List p;
	int pos;
	// �Ե绰���������λɢ��
	pos = Hash(atoi(key.substr(6,5).c_str()),H->TableSize);

	p = H->Heads[pos].Next;
	while(p && key != p->number)
		p = p->Next;
	return p;
}

// ���� 
bool Insert(HashTable H,ElementType key){
	List p,NewCell;
	int pos;
	p = Find(H,key);
	if(!p){   // pΪ�� 
		
		NewCell = new LNode();
		NewCell->number = key;
		NewCell->Count = 1;   
		pos = Hash(atoi(key.substr(6,5).c_str()),H->TableSize);  // �ҵ�ɢ�е�ַ 
	
		// ���½����뵽����ͷ 
		NewCell->Next = H->Heads[pos].Next; 
		H->Heads[pos].Next = NewCell;
		return true;
	}else{
		p->Count++;   // �Ѿ����ڣ�����+1 
		return false;
	}
}

void ScanAndOutput(HashTable H){
	List p; 
	int MaxCnt=0;  // ���ͨ������ 
	string Minphone; // ��С���� 
	int PCnt=0;   // �������� 
	// ɨ������ 
	for(int i=0;i<H->TableSize;i++){
		p = H->Heads[i].Next;
		while(p){
			if(MaxCnt < p->Count){
				MaxCnt = p->Count;
				Minphone = p->number;
				PCnt = 1;
			}else if( p->Count == MaxCnt ){
				if(p->number < Minphone )
					Minphone = p->number;
				PCnt++;
			} 
			p = p->Next; 
			
		}
	}
	cout<<Minphone<<" "<<MaxCnt;
	if(1 < PCnt)
		cout<<" "<<PCnt;
}

int main(){
	HashTable H;
	int N;
	ElementType key;
	cin>>N;
	H = CreateTable(2*N);
	for(int i=0;i<N;i++){
		cin>>key;		Insert(H,key);
		cin>>key;		Insert(H,key);
	}
	ScanAndOutput(H);
	return 0;
} 
