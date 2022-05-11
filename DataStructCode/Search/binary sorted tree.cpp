#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct BTNode
{
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

// 1.二叉排序树查找；
BTNode *BSTSearch1(BTNode *bt, int key) //非递归查找法
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

BTNode *BSTSearch(BTNode *bt, int key) //递归查找
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
            return BSTSearch(bt->lchild, key); // NOTE: return 的作用 ：逐层将目标 bt 传回主函数；
        }
    }
}

// 2.二叉排序树的插入
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
    if (!bt) //不存在 关键字==key 的数据元素，返回false；
    {
        return false;
    }
    else
    {
        if (key == bt->key) //找到关键字，执行删除操作
        {
            return Delete(bt);
        }
        else if (key > bt->key) //递归向下寻找关键字
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
    if (!p->lchild) //左子树空只需重接右子树
    {
        q = p;
        p = p->rchild;
        free(q);
        return true;
    }
    else if (!p->rchild) //右子树空只需重接左子树；
    {
        q = p;
        p = p->lchild;
        free(q);
        return true;
    }
    else //左右子树都不空
    {
        q = p;
        BTNode *s = p->lchild; //转左，然后向右到尽头
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        p->key = s->key;
        if (q != p) // 重接 q 的右子树
        {
            q->rchild = s->lchild;
        }
        else // p 的左子树没有右子树，只需重接 s 的左子树
        {
            q->lchild = s->lchild;
        }
        free(s);

        free(s);
    }
}