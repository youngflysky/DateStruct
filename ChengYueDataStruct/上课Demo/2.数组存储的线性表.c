#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100  // MAXSIZE ����Ϊ Data ����Ĵ�С
typedef int ElementType;  // ElementType �ɶ���Ϊ��������
typedef struct LNode *List; 
struct LNode{
   ElementType Data[MAXSIZE]; 
   int Last;  // Last �������Ա�����һ��Ԫ��
};
List L;
//�����±�Ϊ i ��Ԫ�أ�L->Data[i]
//���Ա�ĳ��ȣ�L->Last+1

List MakeEmpty(); //��ʼ��˳��� 
int Find(ElementType X,List L); //���� X ��һ�γ��ֵ��±� 
void Insert(ElementType X,int i,List L); //���±�Ϊ i �ĵط����� X 
void Delete(int i,List L);   //ɾ���±�Ϊ i �ĵ�ǰֵ 
ElementType FindKth(int K,List L);  //�����±�Ϊ K �ĵ�ǰֵ
int Length(List L);  //����˳���ĳ��� 
 
//��ʼ�� 
List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

// ��ֵ���� 
int Find(ElementType X,List L){
    int i=0;
    while(i <= L->Last && L->Data[i] != X)  
        i++;
    if(L->Last < i)  //���û�ҵ������� -1
        return -1; 
    else    // �ҵ��󷵻��±� 
        return i;
}

// ����
void Insert(ElementType X,int i,List L){
    int j;
    if(L->Last == MAXSIZE-1){  //λ������ 
        printf("����");
        return;
    }
    if(i < 0 || L->Last+1 < i){  //λ��Խ�磬����������� L->Data[L->Last+1]�����涼������λ���� 
        printf("λ�ò��Ϸ�");
        return;
    }
    for(j=L->Last;j>=i;j--)   // �Ӻ���ǰ�������Ųһ������ a[i]�ڳ�λ��     
        L->Data[j+1] = L->Data[j];   
    L->Data[i] = X;    //��Ԫ�ز���
    L->Last++;    // Last��Ȼָ�����Ԫ��
    return;
} 

//ɾ��
void Delete(int i,List L){
    int j;
    if(i < 0 || L->Last <i){  //λ��Խ�磬��ɾ����ൽ L->Data[L->Last]
        printf("L->Data[%d]������Ԫ��",i);
        return;
    }
    for(j=i;j<=L->Last;j++)   // ��ǰ����������ǰŲһ������ a[i] ������ 
        L->Data[j-1] = L->Data[j];
    L->Last--;  // Last��Ȼָ�����Ԫ��
    return;
}

// �������
ElementType FindKth(int K,List L){
	if(K < 0 || L->Last < K){  //λ��Խ��
        printf("L->Data[%d]������Ԫ��",K);
        return;
    }
    return L->Data[K];
}

//��
int Length(List L){
	return L->Last+1;
} 

int main(){
	int i=0;
	L = MakeEmpty();
	Insert(11,0,L);
	printf("�����Ա�L-Data[0]����11\n");
	Insert(25,0,L);
	printf("�����Ա�L-Data[0]����25\n");
	Insert(33,0,L);
	printf("�����Ա�L-Data[0]����33\n");
	Insert(77,0,L);
	printf("�����Ա�L-Data[0]����77\n");
	printf("��ʱ�����Ա�Ϊ��"); 
	for(i=0;i<Length(L);i++)
		printf("%d ",L->Data[i]);
	printf("\n");
	printf("����ֵΪ12���±��ǣ�%d\n",Find(12,L));
	printf("�±�Ϊ3�����Ա��ֵ�ǣ�%d\n",FindKth(3,L));
	Delete(2,L);
	printf("ɾ�����Ա����±�Ϊ2��Ԫ��\n");
	Delete(2,L);
	printf("ɾ�����Ա����±�Ϊ2��Ԫ��\n");
	printf("��ʱ�����Ա�Ϊ��"); 
	for(i=0;i<Length(L);i++)
		printf("%d ",L->Data[i]);
	printf("\n"); 
	return 0;
} 
