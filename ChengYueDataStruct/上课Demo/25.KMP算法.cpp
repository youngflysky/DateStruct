/* ������ʵ�ְ� 
#include<stdio.h>
#include<string.h>
typedef char* Position;
#define NotFound NULL 

char *Mystr(char* string,char *pattern){
	int Strlen = strlen(string);
	int Patlen = strlen(pattern);
	int i,j;
	int tmpi;
	for(i=0;i<Strlen;i++){
		tmpi=i;
		j=0;
		while(string[tmpi++] == pattern[j++] && j < Patlen);
		if(j==Patlen){
			return string+i;
		}
	}
	return NULL;
}


int main(){
	char string[] = "this is a simple example.";
//	char string[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char pattern[] = "simple";
//	char pattern[] = "ab";
	Position p = Mystr(string,pattern);
	if(p==NotFound)
		printf("NotFound\n");
	else
		printf("%s",p);
	return 0;
} 


*/
// KMP �㷨 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Position;
#define NotFound -1
using namespace std;

void BuildMatch(char *pattern,int *match){
	int i,j;
	int m = strlen(pattern);
	match[0] = -1;
	for(j=1;j<m;j++){
		i = match[j-1];   // ǰһ���ַ��� match 
		while((i>=0) && (pattern[i+1] != pattern[j]))  // ������ȣ����� 
			i = match[i];
		if(pattern[i+1] == pattern[j])  // ��ĳ�����ڵ��� 
			match[j] = i+1;  // match+1 
		else  // ����ǰ��û����ȵ� 
			match[j] = -1; 
	}
}

Position KMP(char* string,char *pattern){
	int n = strlen(string);
	int m = strlen(pattern);
	int s,p;
	if(n < m)
		return NotFound;
	int *match = (int *)malloc(sizeof(int) * m);
	BuildMatch(pattern,match);   // ���� match ���� 
	s = p = 0;
	while(s < n && p < m){
		if(string[s] == pattern[p]){ // �����ʱ���Ƚ���һ�� 
			s++;
			p++;
		}else if(p>0)  // �������ˣ�pattern ���˵� match[p-1] + 1 ��λ��  
			p = match[p-1]+1;
		else   // �� p = 0 ʱ�϶�û�˵� 
			s++;
	}
	return (p == m) ? (s-m) : NotFound;
}

int main(){
	char string[] = "this is a simple example.";
//	char string[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char pattern[] = "simple";
//	char pattern[] = "ab";
	Position p = KMP(string,pattern);
	if(p==NotFound)
		printf("NotFound\n");
	else
		printf("%s",string+p);
	return 0;
}











