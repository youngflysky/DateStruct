/*
#include<iostream>
#include<stdlib.h>
#include<string>
#include<cmath>
#define MAXTABLESIZE 1000000
using namespace std;
typedef struct Node Cell;
struct Node{
	bool exist;
	string acc;   // �˺�
	string pas;  // ���� 
};

typedef struct HashTBL *HashTable; 
struct HashTBL{
	int TableSize;
	Cell *users;
};

int Hash(int key,int p){
	return key%p;
}

int NextPrime(int N){
	int p = N%2?N+2:N+1;
	int i;
	while(p <= MAXTABLESIZE) {  
		for(i=(int)sqrt(p);i>2;i--)
			if(!(p%i))
				break;
		if(i==2 && p%4==3) // ��֤ƽ��̽�ⶼ���ҵ� 
			break;
		p +=2;
	}
	return p;
}

// ��ʼ�� 
HashTable Create(int TableSize){
	HashTable H;
	H = (HashTable)malloc(sizeof(struct HashTBL));
	H->TableSize = NextPrime(TableSize);
	H->users = new Node[H->TableSize];
	for(int i=0;i<H->TableSize;i++)
		H->users[i].exist = false;
	return H;
}

int Find(HashTable H,string key){
	int NewPos,CurrentPos;
	int CNum = 0;
	NewPos = CurrentPos = Hash(atoi(key.c_str()),H->TableSize);
	while(H->users[NewPos].exist && H->users[NewPos].acc != key){
		if(++CNum %2){
			NewPos =( CurrentPos + (CNum+1)/2*(CNum+1)/2 )%H->TableSize;
		}else{
			NewPos = CurrentPos - CNum/2*CNum/2;
			while(NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}

void Insert(HashTable H,string key,string pas,char flag){
	int pos;
	pos = Find(H,key);
	if(H->users[pos].exist){  // �Ѿ����� 
		if(flag == 'L'){   // ��½ 
			if(pas == H->users[pos].pas)   // ������ȷ����½�ɹ� 
				cout<<"Login: OK"<<endl;
			else   // ������󣬵�½ʧ�� 
				cout<<"ERROR: Wrong PW"<<endl;
		}else if(flag == 'N'){  // ע��ʧ�� 
			cout<<"ERROR: Exist"<<endl;
		} 
	}else{  // ������ 
		if(flag == 'L')   // ��½ʧ�� 
			cout<<"ERROR: Not Exist"<<endl;
		else if(flag == 'N'){ // ע��ɹ� 
			cout<<"New: OK"<<endl; 
			H->users[pos].exist = true;
			H->users[pos].pas = pas;
			H->users[pos].acc = key;
		}
	}
}

int main(){
	HashTable H;
	int N;
	char command;
	string account;
	string password;
	cin>>N;
	H = Create(N);
	for(int i=0;i<N;i++){
		cin>>command>>account>>password;
		Insert(H,account,password,command);
	} 
	return 0;
}*/


#include<cstdio>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	int N;
	char command;
	string qq;
	string ps;
	map<string,string> m;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		getchar();
		scanf("%c",&command);
		cin>>qq>>ps;
		if(command == 'N'){     // ���û� 
			if(m.find(qq)!=m.end())    // qq���Ѿ����� 
				printf("ERROR: Exist");
			else{    // ע��ɹ� 
				printf("New: OK");
				m[qq] = ps;
			}
		}else if(command == 'L'){  // ���û� 
			if(m.find(qq)==m.end())  // û�ҵ� 
				printf("ERROR: Not Exist"); 
			else if(m[qq] == ps)   // ������ȷ 
				printf("Login: OK");
			else   
				printf("ERROR: Wrong PW");
		}
		printf("\n");
	} 
	return 0;
}
