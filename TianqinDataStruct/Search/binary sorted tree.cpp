#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct BTNode
{
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

// 1.�������������ң�
BTNode *BSTSearch1(BTNode *bt, int key) //�ǵݹ���ҷ�
{
    while (bt)
    {
        if (key == bt->key)
        {
            return bt;
        }
        else if (key > bt->key)
        {
            bt = bt->rchild;
        }
        else
        {
            bt = bt->lchild;
        }
    }
    return NULL;
}

BTNode *BSTSearch(BTNode *bt, int key) //�ݹ����
{
    if (!bt)
    {
        return NULL;
    }
    else
    {
        if (key == bt->key)
        {
            return bt;
        }
        else if (key > bt->key)
        {
            return BSTSearch(bt->rchild, key);
        }
        else
        {
            return BSTSearch(bt->lchild, key); // NOTE: return ������ ����㽫Ŀ�� bt ������������
        }
    }
}

// 2.�����������Ĳ���
int BSTInsert(BTNode *&p, int key)
{
    if (p == NULL)
    {
        p = (BTNode *)malloc(sizeof(BTNode));
        p->key = key;
        p->lchild = p->rchild = NULL;
        return 1;
    }
    else
    {
        if (key == p->key)
        {
            return 0;
        }
        else if (key < p->key)
        {
            return BSTInsert(p->lchild, key);
        }
        else
        {
            return BSTInsert(p->rchild, key);
        }
    }
}

// 3. create binary sort tree;
void CreateBST(BTNode *&bt, int key[], int n)
{
    int i;
    bt = NULL;
    for (i = 0; i < n; ++i)
    {
        BSTInsert(bt, key[i]);
    }
}

// 4.delete BST
bool DeleteBST(BTNode *&bt, int key)
{
    if (!bt) //������ �ؼ���==key ������Ԫ�أ�����false��
    {
        return false;
    }
    else
    {
        if (key == bt->key) //�ҵ��ؼ��֣�ִ��ɾ������
        {
            return Delete(bt);
        }
        else if (key > bt->key) //�ݹ�����Ѱ�ҹؼ���
        {
            return DeleteBST(bt->rchild, key);
        }
        else
        {
            return DeleteBST(bt->lchild, key);
        }
    }
}

bool Delete(BTNode *&p)
{
    BTNode *q;
    if (!p->lchild) //��������ֻ���ؽ�������
    {
        q = p;
        p = p->rchild;
        free(q);
        return true;
    }
    else if (!p->rchild) //��������ֻ���ؽ���������
    {
        q = p;
        p = p->lchild;
        free(q);
        return true;
    }
    else //��������������
    {
        q = p;
        BTNode *s = p->lchild; //ת��Ȼ�����ҵ���ͷ
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        p->key = s->key;
        if (q != p) // �ؽ� q ��������
        {
            q->rchild = s->lchild;
        }
        else // p ��������û����������ֻ���ؽ� s ��������
        {
            q->lchild = s->lchild;
        }
        free(s);

        free(s);
    }
}