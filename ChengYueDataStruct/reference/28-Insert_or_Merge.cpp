#include<iostream>
using namespace std; 

bool judge(int A[],int B[],int N){
	for(int i=0;i<N;i++)
		if(A[i]!=B[i])
			return false;
	return true;
}

// �������� 
bool Insertion_Sort(int A[],int B[],int N){
	for(int P=1;P<N;P++){
		int tmp = A[P];
		int j = P;
		for(;j>0 && tmp < A[j-1];j--)
			A[j] = A[j-1];
		A[j] = tmp;
		if(judge(A,B,N)){  // �������ˣ�����һ�� 
			P++;
			int tmp = A[P];
			int j = P;
			for(;j>0 && tmp < A[j-1];j--)
				A[j] = A[j-1];
			A[j] = tmp;
			return false;
		}
	}
	return true; 
}


void Merge(int A[],int tmpA[],int L,int R,int RightEnd){
	// L = �����ʼλ�ã�R = �ұ���ʼλ�ã�RightEnd = �ұ��յ�λ�� 
	int NumSize = RightEnd-L+1;   //  �������  
	int LeftEnd = R-1;   // �����ֹλ�� 
	int tmp = L; 
	// ���� 
	while(L <= LeftEnd && R <= RightEnd){
		if(A[L] <= A[R])
			tmpA[tmp++] = A[L++];
		else
			tmpA[tmp++] = A[R++];
	} 
	// ��������ʣ 
	while(L <= LeftEnd)
		tmpA[tmp++] = A[L++];
	// ����ұ���ʣ 
	while(R <= RightEnd)
		tmpA[tmp++] = A[R++];
	//  ���� A ���� 
	for(int i=0;i<NumSize;i++)
		A[RightEnd--] = tmpA[--tmp];
}

void Merge_pass(int A[],int tmpA[],int N,int length){
	int i;
	// ÿ�� 2*length Ϊһ������Ԫ 
	for(i=0;i<=N-2*length;i+=2*length)
		Merge(A,tmpA,i,i+length,i+length*2-1);
	// ����ʣ�µĲ���һ�������Ԫ 
	if(i+length < N)   // �����߹��ˣ������ұ߲��룬�ٴν������� 
		Merge(A,tmpA,i,i+length,N-1);
	else   // �����߶�������ֱ�ӵ��� tmpA 
		for(int j=i;j<N;j++)
			tmpA[j] = A[j];			
}

// �鲢����
bool Merge_Sort(int A[],int B[],int N){
	int tmpA[N];
	int length = 1;
	while(length < N){
		Merge_pass(A,tmpA,N,length);  // һ�˹鲢 
		length *=2;
		if(judge(A,B,N)){   // �������ˣ�����һ�� 
			Merge_pass(A,tmpA,N,length);
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
	// �� tmpA �������鲢�����ж��Ƿ��ǹ鲢���� 
	if(!Merge_Sort(tmpA,B,N)){
		cout<<"Merge Sort"<<endl;
		output(tmpA,N);
		return 0;
	}
	// �� A ���������������ж��Ƿ��ǲ�������
	if(!Insertion_Sort(A,B,N)){
		cout<<"Insertion Sort"<<endl;
		output(A,N);
		return 0;
	}
	return 0;
}
