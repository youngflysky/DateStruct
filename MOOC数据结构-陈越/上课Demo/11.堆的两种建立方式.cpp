#include<iostream>
#include<malloc.h>
const int MinData = -100000;  // �ڱ�ֵ
const int MaxSize = 1005;   // ������ 
using namespace std;
typedef struct HeapStruct *Heap;
struct HeapStruct{
	int *data;   // ��ֵ������ 
	int size;   // ��ǰԪ�ظ��� 
	int capacity;  // ������� 
};

// ��ʼ����
Heap Create(){
	Heap H;
	H = (Heap)malloc(sizeof(struct HeapStruct));
	H->data = (int *)malloc(sizeof(int) * (MaxSize+1));
	H->size = 0;
	H->capacity = MaxSize;
	H->data[0] = MinData;
	return H;
} 

// �������ƶѵ�"ɾ������" 
void sort(Heap H,int i){
	int child,parent;
	int tmp = H->data[i];  // �õ���ǰ"������ֵ" 
	for(parent = i;parent*2<=H->size;parent = child){
		child = 2 * parent;
		if((child!=H->size) && (H->data[child+1] < H->data[child]))
			child++;
		if(H->data[child] >= tmp)
			break;
		else
			H->data[parent] = H->data[child]; 
	}
	H->data[parent] = tmp;
}
// ����
void adjust(Heap H){
	int i= H->size/2;
	for(;i>0;i--){
		// ��ÿ���к��ӽ��Ľ����Ϊ����㣬�����������ж����� 
		sort(H,i);
	}
} 

// ���� 
void bl(Heap H){
	for(int i=1;i<=H->size;i++){
		cout<<H->data[i]<<" ";
	}
	cout<<endl;
}


int main(){
	Heap H;
	H = Create();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>H->data[++H->size];
	adjust(H);
	bl(H); 
	return 0;
}

/*
#include<iostream>
#include<malloc.h>
const int MinData = -100000;  // �ڱ�ֵ
const int MaxSize = 1005;   // ������ 
using namespace std;
typedef struct HeapStruct *Heap;
struct HeapStruct{
	int *data;   // ��ֵ������ 
	int size;   // ��ǰԪ�ظ��� 
	int capacity;  // ������� 
};

// ��ʼ����
Heap Create(){
	Heap H;
	H = (Heap)malloc(sizeof(struct HeapStruct));
	H->data = (int *)malloc(sizeof(int) * (MaxSize+1));
	H->size = 0;
	H->capacity = MaxSize;
	H->data[0] = MinData;
	return H;
} 

// ����
void Insert(Heap H,int x){
	int i = ++H->size;  // ָ���������һ�� 
	for(;H->data[i/2]>x;i/=2)
		H->data[i] = H->data[i/2];
	H->data[i] = x;
} 

// ���� 
void bl(Heap H){
	for(int i=1;i<=H->size;i++)
		cout<<H->data[i];
}

int main(){
	Heap H;
	H = Create();
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		Insert(H,t);
	}
	bl(H);
	return 0;
} 
*/ 
