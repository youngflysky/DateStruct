#include<iostream>
#include<cmath>
#include<stdlib.h>
#define MAXTABLESIZE 100000
#define NOTFIND -1
typedef int ElementType;
typedef enum{     // ��Ԫ��״̬ 
	Legitimate,Empty
} EntryType;   // �ֱ��Ӧ���кϷ�Ԫ�غ��п�λ 
typedef struct HashEntry Cell;
struct HashEntry{   // ��Ԫ�� 
	ElementType data;  // ��ֵ
	EntryType info;   // ��״̬ 
};
typedef struct HashTbl *HashTable;
struct HashTbl{  // ��ϣ��
	int TableSize;  // ��С 
	Cell *Cells;   // ���� 
};
using namespace std;

// ������������ϣ���� 
int Hash(int key,int p){
	return key%p;
}

// ������һ������ 
int NextPrime(int N){
	int p = N%2?N:N+1;
	int i;
	if(N<=2)
		return 2;
	else if(N<=3)
		return 3; 
	while(p <= MAXTABLESIZE){
		for(i=(int)sqrt(p);i>2;i--)
			if(!(p%i))   // �������� 
				break;
		if(i==2)  // �ҵ���
			break;
		p += 2; 
	}
	return p;
}

// ������ϣ�� 
HashTable CreateTable(int TableSize){
	HashTable H;
	H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize = NextPrime(TableSize);
	H->Cells = (Cell *)malloc(sizeof(struct HashEntry)*H->TableSize);
	for(int i=0;i<H->TableSize;i++)
		H->Cells[i].info = Empty;
	return H;	
}

//����
int Find(HashTable H,ElementType key){
	int NewPos,CurrentPos;
	int CNum = 0;  // ��¼��ͻ���� 
	CurrentPos = NewPos = Hash(key,H->TableSize);
	// �����ǰ״̬��Ϊ�գ���һֱ���ȣ�һֱ�� 
	while(H->Cells[NewPos].info != Empty && H->Cells[NewPos].data != key){
		CNum++;
		NewPos = (CurrentPos + CNum*CNum)%H->TableSize;
		if(CNum == H->TableSize/2) // û�ҵ�
			return NOTFIND;
	}
	return NewPos;
}

int Insert(HashTable H,ElementType key){
	int pos;
	pos = Find(H,key);
	if(pos==NOTFIND) // ���û�ҵ� 
		return NOTFIND;
	else if(H->Cells[pos].info != Legitimate){
		H->Cells[pos].info = Legitimate;
		H->Cells[pos].data = key;
	}
	return pos;
} 

int main(){
	HashTable H;
	int M,N;
	int key;
	cin>>M>>N;
	H = CreateTable(M);
	for(int i=0;i<N;i++){
		cin>>key;
		int pos = Insert(H,key);
		if(i)
			cout<<" ";
		if(pos==NOTFIND)
			cout<<"-";
		else
			cout<<pos;
	}
	return 0;
}

