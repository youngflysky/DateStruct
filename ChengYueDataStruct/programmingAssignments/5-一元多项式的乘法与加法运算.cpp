#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct LNode
{
    int index;
    int coefficient;
    struct LNode *next;
} LNode;					//�ڵ㶨��

typedef LNode *SList;
inline SList createSList()
{
    SList s;
    s = (LNode *)malloc(sizeof(LNode));
    s->next = NULL;
    return s;
}
inline LNode *createLNode()		//�����½��
{
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->next = NULL;
    return s;
}

SList storagePolynomial()	//��������ʽ�洢����ʽ
{
    int n;
    cin >> n;
    SList PtrL = createSList();
    LNode *rear = PtrL;
    while (n--)
    {
        LNode *s = createLNode();
        cin >> s->index >> s->coefficient;
        rear->next = s;
        rear = s;
    }
    return PtrL;
}

int compareCoef(LNode *nodePoly1, LNode *nodePoly2) //�Ƚ�����ϵ����С
{
    if (nodePoly1->coefficient > nodePoly2->coefficient)
    {
        return 1;
    }
    else if (nodePoly1->coefficient == nodePoly2->coefficient)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void mergeSlist(LNode *q, SList &rear)		//�ϲ�����ʽ
{
    rear->next = q;
    rear = q;
    return;
}

void printSList(SList p)	//�������ʽ
{
    if (!p->next)
    {
        cout << "0 0" << endl;//����Ϊ��ʱ��������ʽ
        return;
    }
    while (p = p->next)
    {
        cout << p->index << ' ' << p->coefficient;
        if (p->next)
        {
            cout << ' ';
        }
    }
    cout << endl;
    return;
}

SList Add(SList poly1, SList poly2)//����ʽ���
{
    LNode *p, *q;
    p = poly1->next;
    q = poly2->next;
    SList sumList = createSList();
    LNode *rearSum = sumList;
    while (p && q)
    {
        LNode *temp = createLNode();
        switch (compareCoef(p, q))
        {
            case 1:
            {
                temp->index = p->index;
                temp->coefficient = p->coefficient;
                rearSum->next = temp;
                rearSum = temp;
                p = p->next;
                break;
            }
            case 0:
            {
                temp->index = p->index + q->index;
                if (temp->index)
                {
                    temp->coefficient = p->coefficient;
                    mergeSlist(temp, rearSum);
                }
                else
                {
                    free(temp);
                }
                p = p->next;
                q = q->next;
                break;
            }
            case -1:
            {
                temp->index = q->index;
                temp->coefficient = q->coefficient;
                rearSum->next = temp;
                rearSum = temp;
                q = q->next;
                break;
            }
        }
    }
    for (; p; p = p->next)
    {
        LNode *temp = createLNode();
        temp->index = p->index;
        temp->coefficient = p->coefficient;
        mergeSlist(temp, rearSum);
    }
    for (; q; q = q->next)
    {
        LNode *temp = createLNode();
        temp->index = q->index;
        temp->coefficient = q->coefficient;
        mergeSlist(temp, rearSum);
    }
    return sumList;
}

SList Pro(SList poly1, SList poly2)//��������ʽ���
{
    SList productList = createSList();
    LNode *rearPro = productList;
    for (LNode *p = poly1->next; p; p = p->next)
    {
        SList tempList = createLNode();
        LNode *rearTemp = tempList;
        for (LNode *q = poly2->next; q; q = q->next)
        {
            if (p->index && q->index)
            {
                LNode *s = createLNode();
                s->index = p->index * q->index;
                s->coefficient = p->coefficient + q->coefficient;
                rearTemp->next = s;
                rearTemp = s;
            }
        }
        productList = Add(productList, tempList);
    }
    return productList;
}

int main()
{
    SList poly1;
    poly1 = storagePolynomial();
    SList poly2;
    poly2 = storagePolynomial();//����

    SList sumList;
    sumList = Add(poly1, poly2);//���

    SList productList;
    productList = Pro(poly1, poly2);//���

    printSList(productList);//���
    printSList(sumList);

    return 0;
}
