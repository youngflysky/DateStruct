#include<iostream>
#include<cstring>
#define MaxSize 1000
typedef int ElementType;
typedef struct{
	ElementType Data; // ��ֵ
	int parent;  // ָ�򸸽�� 
}SetType;
using namespace std;

// ���� 
int Find(SetType s[],ElementType x){
	int i;  
	// �ҵ������и�ֵ��Ӧ���±� 
	for(i=0;i<MaxSize && s[i].Data!=x;i++);
	if(MaxSize <= i) // ���û���ҵ������� -1 
		return -1;
	// �ҵ��ý��ĸ���� 
	for(;s[i].parent >= 0;i = s[i].parent); 
	return i; // ���ظ���������� s �е��±� 
}

// �� 
void Union(SetType s[],ElementType x1,ElementType x2){
	int root1 = Find(s,x1);  // �ҵ� x1 �ĸ�����±� 
	int root2 = Find(s,x2);  // �ҵ� x2 �ĸ�����±� 
	// ����������±겻ͬ��˵������һ������
	if(root1 != root2){   
		s[root1].parent = root2;   // �� x1 �ҵ� x2 �ļ��� 
	}
}

int main(){
	SetType s[MaxSize];
	// ��ʼ�����飬�����ȫ��ָ�� -1 
	for(int i=0;i<MaxSize;i++){
		s[i].Data = i+1;
		s[i].parent = -1;
	}
	cout<<Find(s,5)<<endl;
	Union(s,3,5);
	cout<<Find(s,4)<<endl;
	cout<<Find(s,3)<<endl;
	Union(s,1,3);
	Union(s,2,4);
	Union(s,8,6);
	cout<<Find(s,6)<<endl;
	cout<<Find(s,8)<<endl;
	return 0;
}
