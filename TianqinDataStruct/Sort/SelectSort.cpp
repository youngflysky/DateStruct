#include <iostream>
#include <cstdlib>
using namespace std;

//选择排序

//顺序存储结构基于交换的选择排序【不稳定】
void SelectSort(int arr[], int n)
{
    int i = 0, j = 0, k = 0;
    int temp = 0;
    for (i = 0; i < n; ++i)
    {
        k = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    return;
}

//链式存储结构
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
LinkList createPLNode(int n = 1)
{
    LNode *s;
    s = (LNode *)malloc(n * sizeof(LNode));
    s->next = NULL;
    return s;
}

//链式存储结构基于插入的选择排序【稳定】
LinkList SelectSort(LinkList L)
{
    LinkList head;  //排序后有序序列的头指针
    LinkList tail;  //排序后有序序列的尾指针
    LinkList p_min; //保存最小节点的前驱节点指针
    LinkList min;   //存储最小节点
    LinkList p;     //便利的当前节点

    head = createPLNode();
    tail = head;
    while (L->next)
    {
        for (p = L->next, p_min = p, min = p; p->next; p = p->next)
        {
            if (p->next->data < min->data)
            {
                p_min = p;
                min = p->next;
            }
        }
        if (min == p_min)
        {
            L->next = min->next;
        }
        else
        {
            p_min->next = min->next;
        }
        tail->next = min;
        tail = min;
    }
    tail->next = NULL;
    return head;
}

//链式存储结构基于交换的选择排序【不稳定】
LinkList SelectSort2(LinkList L)
{
    LinkList p;     /*每次排序前无序序列的表头指针*/
    LinkList q;     /*遍历无序序列，从中找到关键字最小的节点*/
    LinkList small; /*保存无序序列中关键字最小节点的地址*/
    int temp;
    for (p = L->next; p->next; p = p->next)
    {
        small = p;
        for (q = p->next; q; q = q->next)
        {
            if (q->data < small->data)
            {
                small = q;
            }
        }
        cout << small->data << ' ';
        if (small != p)
        {
            temp = p->data;
            p->data = small->data;
            small->data = temp;
        }
    }
    cout << p->data << endl;
    return L;
}

int main()
{
    //线性表
    int arr[10] = {7, 5, 2, 6, 4, 3, 0, 8, 9, 1};
    for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    SelectSort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    //链表
    int temp[10] = {7, 5, 2, 6, 4, 3, 0, 8, 9, 1};
    LinkList L = createPLNode();
    LinkList rear = L;
    for (int i = 0; i < 10; ++i)
    {
        LNode *s = createPLNode();
        s->data = temp[i];
        cout << temp[i] << ' ';
        rear->next = s;
        rear = s;
    }
    cout << endl;
    L = SelectSort(L);
    for (LinkList p = L->next; p; p = p->next)
    {
        cout << p->data << " ";
    }
    cout << endl;
    return 0;
}