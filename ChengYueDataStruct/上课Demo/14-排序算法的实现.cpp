#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath> 
#define NumSize 20
int A[NumSize];
using namespace std;

// ��������� 
void Random(){
	for(int i=0;i<NumSize;i++)
		A[i] = rand()%NumSize+1;
}

// ��� 
void output(){
	for(int i=0;i<NumSize;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

// ð������
void Bubble_sort(int N){
	for(int p = N-1;p>=0;p--){    // �ܹ� n-1 �� 
		bool flag = false;     
		for(int j=0;j<p;j++){  // һ������ 
			if(A[j+1] < A[j]){
				swap(A[j],A[j+1]);
				flag = true;
			}
		}
		if(!flag)   // ���ȫ���޽��������Դ˴������� 
			break;
	}
} 

// �������� 
void Insertion_sort(int A[],int N){
	for(int p = 1;p<N;p++){
		int tmp = A[p];   // ȡ��һ���� 
		int j = p;
		for(;tmp<A[j-1] && j > 0;j--)  // �ҵ�������ʺϵ�λ�� 
			A[j] = A[j-1];  // ���ڡ���λ�� 
		A[j] = tmp;  //  �Ѻ��ʴ�С�������� 
	} 
}

// ԭʼϣ������ 
void shell_sort(int N){
	for(int D=N/2;D>0;D/=2){
		for(int p=D;p<N;p+=D){
			int tmp = A[p];
			int j = p;
			for(;j>=D && tmp<A[j-D] ;j-=D)  // j>=D ��ǰ����ΪҲ�� A[j-D]�Ѿ�Խ�� 
				A[j] = A[j-D];
			A[j] = tmp;
		}
	}
} 

// Hibbard��������ϣ������ 
void Hibbard_shell_sort(int N){
	int add[]={32767,16383,8191,4095,2047,1023,511,255,127,63,31,15,7,3,1,0};
	int i=0;
	for(int D=add[i];D>0;D=add[++i]){
		for(int p=D;p<N;p++){
			long tmp = A[p];
			int k=p;
			for(;k>=D && tmp<A[k-D] ;k-=D) // j>=D ��ǰ����ΪҲ�� A[j-D]�Ѿ�Խ�� 
				A[k] = A[k-D];
			A[k] = tmp;
		}
	}
}

// Sedgewick��������ϣ������
void Sedgewick_shell_sort(int N){
	int add[]= {587521,260609,146305,64769,36289,16001,8929,3905,2161,929,505,209,109,41,19,5,1,0};
	int i=0;
	for(int D=add[i];D>0;D=add[++i]){
		for(int p=D;p<N;p++){
			long tmp = A[p];
			int k = p;
			for(;k>=D && tmp<A[k-D];k-=D)
				A[k] = A[k-D];
			A[k] = tmp;
		}
	} 
}

/********************������ʼ******************************/ 
// ���������� 
void PrecDown(int i,int N){
	int child,parent;
	int tmp = A[i];  // �õ���ǰ"��"����ֵ
	// �±�� 0 ��ʼ��ע�������Χ�͸��ӽ��֮��Ĺ�ϵ 
	for(parent = i;parent*2+1<=N-1;parent = child){
		child = 2*parent + 1;  
		if((child!=N-1) && (A[child] < A[child+1])) // ѡ���� 
			child++;
		if(A[child] <= tmp)
			break;
		A[parent] = A[child];
	}
	A[parent] = tmp;
}

void swap(int &a,int &b){
	int t =a;
	a = b;
	b = t;
}

// ������
void Heap_sort(int N){
	// buildHeap 
	for(int i=N/2;i>=0;i--) 
		PrecDown(i,N);
	for(int i=N-1;i>0;i--){
		swap(A[0],A[i]);
		PrecDown(0,i);
	} 
} 
/*******************���������******************************/ 


/********************�鲢���򣨵ݹ飩��ʼ******************************/ 
// �鲢����ʵ�� 
void Merge(int A[],int tmpA[],int L,int R,int RightEnd){
	// L = �����ʼλ�ã�R = �ұ���ʼλ�ã�RightEnd = �ұ��յ�λ�� 
	int LeftEnd = R-1;   // ����յ�λ�� 
	int tmp = L;   //  ��Ž���Ŀ�ʼλ�� 
	int NumElements = RightEnd - L + 1;  // �鲢���� 
	while(L<=LeftEnd && R<=RightEnd){
		if(A[L] <= A[R])
			tmpA[tmp++] = A[L++];
		else
			tmpA[tmp++] = A[R++];
	}
	// �����ʣ 
	while(L<=LeftEnd)
		tmpA[tmp++] = A[L++];
	// �ұ���ʣ 
	while(R<=RightEnd)
		tmpA[tmp++] = A[R++];
	//  ���ؽ�� 
	for(int i=0;i<NumElements;i++,RightEnd--)
		A[RightEnd] = tmpA[RightEnd];
} 

// ���� 
void Msort(int A[],int tmpA[],int L,int RightEnd){
	// L = �����ʼλ�ã�RightEnd = �ұ��յ�λ�� 
	// �������Ԫ�� 
	if( L < RightEnd){
		int center = (L+RightEnd)/2;
		Msort(A,tmpA,L,center);  // ���� 
		Msort(A,tmpA,center+1,RightEnd);  // �Ұ��
		Merge(A,tmpA,L,center+1,RightEnd);  // center+1 ���ұ���� 
	}
} 
/*
// �鲢���򣨵ݹ飩 
void Merge_sort(int A[],int N){
	int tmpA[N];
	Msort(A,tmpA,0,N-1);
}*/

/********************�鲢���򣨵ݹ飩����******************************/ 

/********************�鲢���򣨷ǵݹ飩����******************************/ 

void Merge1(int A[],int tmpA[],int L,int R,int RightEnd){
	// L = �����ʼλ�ã�R = �ұ���ʼλ�ã�RightEnd = �ұ��յ�λ�� 
	int LeftEnd = R-1;   // ����յ�λ�� 
	int tmp = L;   //  ��Ž���Ŀ�ʼλ�� 
	int NumElements = RightEnd - L + 1;  // �鲢���� 
	while(L<=LeftEnd && R<=RightEnd){
		if(A[L] <= A[R])
			tmpA[tmp++] = A[L++];
		else
			tmpA[tmp++] = A[R++];
	}
	// �����ʣ 
	while(L<=LeftEnd)
		tmpA[tmp++] = A[L++];
	// �ұ���ʣ 
	while(R<=RightEnd)
		tmpA[tmp++] = A[R++];
} 
void Merge_pass(int A[],int tmpA[],int N,int length){
	// length = ��ǰ�������г���
	int i;
	for(i=0;i<=N-2*length;i+=length*2)
		Merge1(A,tmpA,i,i+length,i+2*length-1);
	if(i+length<N)
		Merge1(A,tmpA,i,i+length,N-1);
	else
		for(int j=i;j<N;j++)
			tmpA[j] = A[j];
}

void Merge_sort(int A[],int N){
	int length = 1;
	int tmpA[N];
	while(length<N){
		Merge_pass(A,tmpA,N,length);
		length *=2;
		Merge_pass(tmpA,A,N,length);
		length *=2;
	}
} 
/********************�鲢���򣨷ǵݹ飩����******************************/ 

/*********************��������ʼ*******************************************/ 

// �����Ԫ 
int GetPivot(int L,int R){
	int center = (L+R)/2;
	// ����  A[L] < A[center] < A[R] 
	if(A[R] < A[center])
		swap(A[R],A[center]);
	if(A[R] < A[L])
		swap(A[R],A[L]);
	if(A[center] < A[L])
		swap(A[L],A[center]);
	// ����Ԫ���� R-1 
	swap(A[center],A[R-1]);
	return A[R-1];
}

// ����ʵ�� 
void Quicksort(int Left,int Right){
	int cutoff = 100;
	if( cutoff <= Right-Left){
		int Pivot = GetPivot(Left,Right);
		int i = Left;
		int j = Right-1;
		while(1){
			while(A[++i] < Pivot);
			while(A[--j] > Pivot);
			if(i < j)
				swap(A[i],A[j]);
			else
				break;
		}
		swap(A[i],A[Right-1]);
		Quicksort(Left,i-1);
		Quicksort(i+1,Right);
	}else
		Insertion_sort(A+Left,Right-Left+1);
}

void Quick_sort(int N){
	Quicksort(0,N-1);
}
/*********************�����������************************/ 

/*********************Ͱ����ʼ********************/ 
void Bucket_Sort(int N){
	int count[1000];
	// ��Χ���Ͱ�Ͷ��� 
	for(int i=0;i<1000;i++){
		count[i] = 0;
	}
	// ÿ��ֵ����Ͱ�� 
	for(int i=0;i<N;i++)
		count[A[i]]++;
	// �ռ� 
	for(int i=0;i<N;i++)
		if(count[i]){
			for(int j=0;j<count[i];j++)
				cout<<i<<" ";
		}
}

/*********************Ͱ����ʼ******************/ 

int main(){
	Random(); // ��������� 
	output();  // �������Ԫ�� 
//	Bubble_sort(NumSize);   // ð������ 
//	Insertion_sort(NumSize);   // �������� 
//	shell_sort(NumSize);   // ϣ������  
//	Heap_sort(NumSize);   // ������ 
//	Merge_sort(A,NumSize);   // �鲢���� 
//	Hibbard_shell_sort(NumSize);	
//	Sedgewick_shell_sort(NumSize);
//	Quick_sort(NumSize);
	Bucket_Sort(NumSize);
//	output(); 
	return 0;
}







