#include<iostream>
#include<vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  int tmp;
  int sum = 0;
  vector<int> A; // �� N 
  vector<bool> flag;
  for(int i=0;i<N;i++){
  	cin>>tmp;
  	A.push_back(tmp);
  	flag.push_back(false);
  }
  for(int i=0;i<N;i++){
  	if(A[i]!=i && !flag[i]){   // û�����ʹ��ĵ�Ԫ�� 
  		int tmpSum = 0;  // �ƽ�������
  		int j = i;
  		do{
  			tmpSum++;  // ÿ����һ��������+1 
  			flag[j] = true; // ��ǻ� 
  			if(!A[j])   // ��������� 0����ȥ�뻷���������� 
  				tmpSum-=2;
  			j = A[j];
  		}while(j!=i);
  		tmpSum++;    // ǰ���ȥ�� 0�����Խ��������ǵ�ǰ������+1 
  		sum += tmpSum;
  	}
  }
  cout<<sum<<endl;
  return 0;
}
