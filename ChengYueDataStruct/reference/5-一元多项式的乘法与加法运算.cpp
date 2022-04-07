#include<stdio.h>
#include<stdlib.h>
typedef struct Node *List;
struct Node{
	List Next;
	int z;   // ָ�� 
	int x;  // ϵ�� 
};

// �������� 
List Read(){
	List L = (List)malloc(sizeof(struct Node));
	List head = L;
	int n;
	int i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int x;
		int z;
		List t = (List)malloc(sizeof(struct Node));
		scanf("%d %d",&x,&z);
		t->x = x;
		t->z = z;
		L->Next = t;
		L = L->Next;
	}
	L->Next = NULL;
	return head->Next;
}

// ʵ�ּӷ����� 
List addition(List L1,List L2){
	List tmpL1 = L1;
	List tmpL2 = L2;
	List add=(List)malloc(sizeof(struct Node));
	add->Next = NULL;
	List head = add;
	List t;
	while(tmpL1 && tmpL2){
		t = (List)malloc(sizeof(struct Node));
		if(tmpL1->z == tmpL2->z){  //ָ����ȣ�ϵ�����  
			t->x = tmpL1->x + tmpL2->x;
			t->z = tmpL1->z;
			tmpL1 = tmpL1->Next;
			tmpL2 = tmpL2->Next;
		}else if(tmpL1->z < tmpL2->z){   // L2 ���ָ�����󣬰� L2 ���������� 
			t->x = tmpL2->x;
			t->z = tmpL2->z;
			tmpL2 = tmpL2->Next;
		}else if(tmpL2->z < tmpL1->z){   // L1 ���ָ�����󣬰� L1 ���������� 
			t->x = tmpL1->x;
			t->z = tmpL1->z;
			tmpL1 = tmpL1->Next;
		}
		add->Next = t;
		add = add->Next; 
	}
	if(tmpL1)   // �� L1 ������ NULL����ʣ�½�������� 
		add->Next = tmpL1;
	else if(tmpL2)  // ͬ�� 
		add->Next = tmpL2;
	return head->Next; // head ���ֻ��ָ�����ֵ 
}

// ʵ�ֳ˷����� 
List multiplication(List L1,List L2){
	List tmpL1 = L1;
	List tmpL2 = L2;
	List mul=(List)malloc(sizeof(struct Node));
	mul->Next = NULL;
	List head = mul;
	List t;
	for(;tmpL1;tmpL1=tmpL1->Next)
		for(tmpL2 = L2;tmpL2;tmpL2=tmpL2->Next){
			t = (List)malloc(sizeof(struct Node));
			t->x = tmpL1->x * tmpL2->x;  // ϵ�����
			t->z = tmpL1->z + tmpL2->z;  // ָ�����
			t->Next = NULL;
			head = addition(t,mul);  // ����������֮ǰ�Ѿ��ź���Ľ������ 
			mul = head; // ����ȷ����ͷ 
		}
	return head;
}
void Print(List L){
	List t = L;
	int flag = 1;
	for(;t;t = t->Next){
		if(!flag && t->x)   //���ƿո����
			printf(" ");
		if(t->x){   // ���ϵ��Ϊ 0������� 
			printf("%d %d",t->x,t->z);
			flag =0;		
		}
	}
	if(flag)
		printf("0 0");
	printf("\n");
}
int main(){
	List L1,L2,add,mul;
	L1 = Read();
	L2 = Read();
	add = addition(L1,L2);
	mul = multiplication(L1,L2);
	Print(mul);
	Print(add);
	return 0;
} 
