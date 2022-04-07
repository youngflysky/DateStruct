#include<iostream>
#include<algorithm>
using namespace std;
void output(int A[],int N); 

// �ж��Ƿ���� 
bool judge(int A[],int B[],int N){
	for(int i=0;i<N;i++)
		if(A[i]!=B[i])
			return false;
	return true;
} 

// �������� 
bool Insertion_Sort(int A[],int B[],int N){
	for(int p=1;p<N;p++){
		int tmp = A[p];
		int k = p;
		for(;k>0 && tmp < A[k-1];k--)
			A[k] = A[k-1];
		A[k] = tmp;
		if(judge(A,B,N)){// �����ȣ�����һ��
			p++; 
			int tmp = A[p];
			int k = p;
			for(;k>0 && tmp < A[k-1];k--)
				A[k] = A[k-1];
			A[k] = tmp;
			return false;
		}
	}
	return true;
}

void PrecDown(int A[],int i,int N){
	int tmp = A[i]; // ȡ�õ�ǰ"��"
	int parent,child;
	for(parent=i;parent*2+1<N;parent = child){
		child = 2*parent +1;
		if((child!=N-1) && (A[child] < A[child+1]))
			child++;
		if(A[child] <= tmp)
			break;
		A[parent] = A[child];
	} 
	A[parent] = tmp;
}

// ������ 
bool Heap_Sort(int A[],int B[],int N){
	for(int i=N/2;i>=0;i--)
		PrecDown(A,i,N);
	for(int i=N-1;i>0;i--){
		swap(A[0],A[i]);
		PrecDown(A,0,i);
		if(judge(A,B,N)){  // �����ȣ�����һ�� 
			swap(A[0],A[--i]);
			PrecDown(A,0,i);
			return false;
		}
	}
	return true;
}

// ��� 
void output(int A[],int N){
	for(int i=0;i<N;i++){
		if(i)
			cout<<" ";
		cout<<A[i];
	}
}

int main(){
	int N;
	cin>>N;
	int A[N],tmpA[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
		tmpA[i] = A[i];
	}
	int B[N];
	for(int i=0;i<N;i++) 
		cin>>B[i];
	if(!Heap_Sort(tmpA,B,N)){  // ����Ƕ����� 
		cout<<"Heap Sort"<<endl;
		output(tmpA,N);
		return 0;
	}
	if(!Insertion_Sort(A,B,N)){  // ����ǲ������� 
		cout<<"Insertion Sort"<<endl;
		output(A,N);
		return 0;
	}
	return 0;
} 
