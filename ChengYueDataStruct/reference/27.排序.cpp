#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 

// ð������ 
void Bubble_sort(long A[],int N){
	for(int i=0;i<N-1;i++){  // N-1��ð��
		bool flag = false;  // ��֤�Ƿ񽻻��� 
		for(int j=0;j<N-i-1;j++){
			if(A[j+1] < A[j]){
				flag = true; 
				swap(A[j],A[j+1]);
			}
		} 
		// �Ѿ����� 
		if(!flag)  
			break; 
	} 
} 

// ��������
void Insertion_sort(long A[],int N){
	for(int i=1;i<N;i++){  // ��һ���Ѿ����� 
		long tmp = A[i];
		int j=i;
		for(;tmp<A[j-1] && j>0;j--)
			A[j] = A[j-1];
		A[j] = tmp;
	}
}

// ԭʼϣ������ 
void shell_sort(long A[],int N){
	for(int D=N/2;D>0;D/=2){
		for(int p=D;p<N;p++){
			long tmp = A[p];
			int k=p;
			for(;k>=D && tmp<A[k-D] ;k-=D) // j>=D ��ǰ����ΪҲ�� A[j-D]�Ѿ�Խ�� 
				A[k] = A[k-D];
			A[k] = tmp;
		}
	}
} 

// Hibbard��������ϣ������ 
void Hibbard_shell_sort(long A[],int N){
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
// Sedgewick�������й�ϣ���� 
void Sedgewick_shell_sort(long A[],int N){
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

/***************������ʼ***************/

// ���������� 
void PrecDown(long A[],int i,int N){
	int parent,child;
	long tmp = A[i];
	// �� 0 ��ʼ�棬���Թ�ϵ�б仯 
	for(parent = i;parent*2+1<N;parent = child){
		child = parent*2+1;
		if((child!=N-1) && (A[child] < A[child+1]))
			child++;
		if(A[child] <= tmp)
			break;
		else
			A[parent] = A[child];
	}
	A[parent] = tmp;
}

// ������ 
void Heap_sort(long A[],int N){
	// �ȵ��������� 
	for(int i=N/2;i>=0;i--)
		PrecDown(A,i,N);
	for(int i=N-1;i>0;i--){
		swap(A[0],A[i]); // ÿ�ΰѵ�ǰ���Ѹ�Ԫ��ѡ����� 
		PrecDown(A,0,i);  // �ٴε������� 
	}
} 

/***************���������***************/

/***************stl������ʼ***************/
priority_queue<long,vector<long>,less<long> > q; // ����һ������ 

void STL_Heap_sort(long A[],int N){
	// ���ݶ������� 
	for(int i=0;i<N;i++)
		q.push(A[i]);
	// ���γ��� 
	for(int i=N-1;i>=0;i--){
		A[i] = q.top();
		q.pop();
	}
} 
/***************stl���������***************/

/***************�ݹ�鲢����ʼ***************/
/*
// �鲢ʵ�� 
void Merge(long A[],long tmpA[],int L,int R,int RightEnd){
	// L = ���Ԫ�ؿ�ʼλ�� ��R = �ұ�Ԫ�ؿ�ʼλ�� ��RightEnd = �ұ߽����յ�λ��
	int NumSize = RightEnd-L+1; // Ԫ�ظ���
	int LeftEnd = R-1;  // ���Ԫ���յ�λ��
	int tmp = L;  // tmp ���鿪ʼλ�� 
	while( L <= LeftEnd && R <= RightEnd ){
		if(A[L] <= A[R]) // ��С��������ѡС�� 
			tmpA[tmp++] = A[L++];
		else
			tmpA[tmp++] = A[R++];
	} 
	// Ҳ����û���� 
	while( L <= LeftEnd )
		tmpA[tmp++] = A[L++];
	// Ҳ���ұ�û���� 
	while( R <= RightEnd)
		tmpA[tmp++] = A[R++];
	// �ٵ��� A ,tmp��ʱ�Ѿ�Խ�磬����Ҫ�ȼ����� 
	for(int i=0;i<NumSize;i++)
		A[RightEnd--] = tmpA[--tmp];
}

// ���� 
void Msort(long A[],long tmpA[],int L,int RightEnd){
	if(L < RightEnd){
		int center = ( L + RightEnd )/2;
		Msort(A,tmpA,L,center);
		Msort(A,tmpA,center+1,RightEnd);
		Merge(A,tmpA,L,center+1,RightEnd);
	}
}

void Merge_sort(long A[],int N){
	long tmpA[N];
	Msort(A,tmpA,0,N-1);
}
*/
/***************�ݹ�鲢�������***************/

/***************�ǵݹ�鲢����ʼ***************/
// �鲢ʵ�� ����󲻰�Ԫ�ص���A 
void Merge1(long A[],long tmpA[],int L,int R,int RightEnd){
	// L = ���Ԫ�ؿ�ʼλ�� ��R = �ұ�Ԫ�ؿ�ʼλ�� ��RightEnd = �ұ߽����յ�λ��
	int NumSize = RightEnd-L+1; // Ԫ�ظ���
	int LeftEnd = R-1;  // ���Ԫ���յ�λ��
	int tmp = L;  // tmp ���鿪ʼλ�� 
	while( L <= LeftEnd && R <= RightEnd ){
		if(A[L] <= A[R]) // ��С��������ѡС�� 
			tmpA[tmp++] = A[L++];
		else
			tmpA[tmp++] = A[R++];
	} 
	// Ҳ����û���� 
	while( L <= LeftEnd )
		tmpA[tmp++] = A[L++];
	// Ҳ���ұ�û���� 
	while( R <= RightEnd)
		tmpA[tmp++] = A[R++];
}

// һ�˹鲢 
void Merge_pass(long A[],long tmpA[],int N,int length){
	int i;
	// ÿ 2*length һ����Ԫ�鲢 
	for(i=0;i<N-2*length;i+=2*length)
		Merge1(A,tmpA,i,i+length,i+2*length-1);
	// ����ʣ�಻��һ����Ԫ��ֵ 
	if(i+length < N)  // ʣ���������У���߹����ұ߲��� 
		Merge1(A,tmpA,i,i+length,N-1);
	else    //  ʣ��һ�����У���߶����� 
		for(int j=i;j<N;j++)
			tmpA[j] = A[j];
}


void Merge_sort(long A[],int N){
	int length = 1;
	long tmpA[N];
	// ��֤ÿ�����˹鲢�����ս��һ������ A�� 
	while(length < N){
		Merge_pass(A,tmpA,N,length);
		length *=2;
		Merge_pass(tmpA,A,N,length);
		length *=2;
	}
}

/***************�ǵݹ�鲢�������***************/

/*********************��������ʼ*******************************************/ 
// ѡ��Ԫ 
long getPivot(long A[],int L,int R){
	int center = (L+R)/2;
	if(A[R] < A[center])
		swap(A[R],A[center]);
	if(A[R] < A[L])
		swap(A[R],A[L]);
	if(A[center] < A[L])
		swap(A[center],A[L]);
	swap(A[center],A[R-1]);
	return A[R-1];
}

void QucikSort(long A[],int Left,int Right){
	int cutoff = 50;
	if( cutoff <= Right - Left ){  // �����ģ���ÿ��� 
		int pivot = getPivot(A,Left,Right);
		int i = Left;      
		int j = Right-1; 
		for(;;){
			// ��ǰ�����ұ� pivot С�� 
			while(A[++i] < pivot);
			// �Ӻ���ǰ�ұ� pivot ��� 
			while(A[--j] > pivot);
			if(j <= i)
				break;
			swap(A[i],A[j]);
		}
		// ����Ԫ���ں���λ�� 
		swap(A[i],A[Right-1]);
		QucikSort(A,Left,i-1);
		QucikSort(A,i+1,Right);
	}else   // �����ò������� 
		Insertion_sort(A+Left,Right-Left+1);
}

void Quick_sort(long A[],int N){
	QucikSort(A,0,N-1);
}

/*********************�����������**********************************/ 

int main(){
	int N;
	cin>>N;
	long A[N];
	for(int i=0;i<N;i++)
		cin>>A[i];
	Quick_sort(A,N);
	for(int i=0;i<N;i++){
		if(i)
			cout<<" ";
		cout<<A[i];
	}
	return 0;
} 
