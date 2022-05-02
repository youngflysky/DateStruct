#include<iostream>
using namespace std;
/* ����һ��ȷ�����еĿ�ͷ�ͽ�β���ٱ����ۼӣ�ʱ�临�Ӷ� O(n^3)*/
int MaxSubseqSum1(int n,int a[]){
	int max = 0;
	for(int i=0;i<n;i++){
		for(int k=0;k<i;k++){		
			int tmpSum = 0;
			for(int j=k;j<=i;j++){
				tmpSum+=a[j]; 
			}
			if(max < tmpSum)
				max = tmpSum;
		}
	}
	return max;
}
/* ��������ȷ�����еĽ�β�������ȥ����ǰ������ʱ�临�Ӷ� O(n^2)*/ 
int MaxSubseqSum2(int n,int a[]){
	int sum[100000+5];
	int max = 0;
	sum[0]=a[0];
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=0;i<n;i++){
		int tmpSum = sum[i];
		for(int j=0;j<=i;j++){
			if(max < tmpSum)
				max = tmpSum;
			tmpSum-=a[j]; 
		}
	}
	return max;
}
/* ��������ȷ�����е��ײ�������ۼӣ�ʱ�临�Ӷ� O(n^2)*/ 
int MaxSubseqSum3(int n,int a[]){
	int max = 0;
	for(int i=0;i<n;i++){
		int tmpSum = 0;
		for(int j=i;j<n;j++){
			tmpSum+=a[j];
			if(max < tmpSum)
				max = tmpSum;
		}
	}
	return max;
}
/* ��������ֱ���ۼӣ�����ۼӵ���ǰ�ĺ�Ϊ�������õ�ǰֵ��0��ʱ�临�Ӷ�Ϊ O(n)*/ 
int MaxSubseqSum5(int n,int a[]){
	int max = 0;
	int tmpSum=0;
	for(int i=0;i<n;i++){
		tmpSum+=a[i];
		if(tmpSum<0){
			tmpSum=0;
		}else if(max < tmpSum){
			max = tmpSum;
		}
	}
	return max;
}

/* �����ģ��ݹ�ֳ����ݣ��ֱ���ÿ���ָ�����е����ͣ�ʱ�临�Ӷ�Ϊ O(n*logn)*/
/* �������������ֵ*/
int Max3(int A,int B,int C){
	return (A>B)?((A>C)?A:C):((B>C)?B:C);
}
/* �ֽ�ɸ�С��ģ���*/
int DivideAndConquer(int a[],int left,int right){
	
	/*�ݹ��������������ֻ��һ������*/
	if(left == right){
		if(0 < a[left])
			return a[left];
		return 0;
	}
	
	/* �ֱ��ҵ�����������к�*/ 
	int center = (left+right)/2; 
	int MaxLeftSum = DivideAndConquer(a,left,center);
	int MaxRightSum = DivideAndConquer(a,center+1,right);
	
	/* �ٷֱ������ҿ��������к�*/
	int MaxLeftBorderSum = 0;
	int LeftBorderSum = 0;
	for(int i=center;i>=left;i--){
		LeftBorderSum += a[i];
		if(MaxLeftBorderSum < LeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;	
	}
	int MaXRightBorderSum = 0;
	int RightBorderSum = 0;
	for(int i=center+1;i<=right;i++){
		RightBorderSum += a[i];
		if(MaXRightBorderSum < RightBorderSum)
			MaXRightBorderSum = RightBorderSum;
	}
	
	/*��󷵻طֽ�����������кͣ��ұ�������кͣ��Ϳ��������к�������������*/
	return Max3(MaxLeftSum,MaxRightSum,MaXRightBorderSum+MaxLeftBorderSum);
}
int MaxSubseqSum4(int n,int a[]){
	return DivideAndConquer(a,0,n-1);
}
int main(){
	int n;
	int a[100000+5];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<MaxSubseqSum1(n,a);
	cout<<MaxSubseqSum2(n,a);
	cout<<MaxSubseqSum3(n,a);
	cout<<MaxSubseqSum4(n,a);
	cout<<MaxSubseqSum5(n,a);
	return 0;
} 

