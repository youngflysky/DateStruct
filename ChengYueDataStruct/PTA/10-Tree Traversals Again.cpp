// TITLE:10-Tree Traversals Again

#include <cstring>
#include <iostream>
using namespace std;

#define maxSize 30
#define Null -1

int pre[maxSize];
int PreTop = Null;
int in[maxSize];
int InTop = Null;

// NOTE:通过二叉树中序遍历过程中入栈和出栈情况确定一棵二叉树，本质上是已知前序序列和中序序列确定一棵二叉树
int restoreSequence() // README:用两个数组分别存储前序和中序序列 ;
{
    int N;
    cin >> N;
    if (!N)
    {
        return N;
    }
    string input;
    int stack[maxSize];
    int top = -1;
    for (int i = 0; i < 2 * N; ++i) // TOD
    {
        cin >> input;
        if (input == "Push")
        {
            cin >> pre[++PreTop];
            stack[++top] = pre[PreTop];
        }
        else
        {
            in[++InTop] = stack[top--];
        }
    }
    return N;
}

typedef struct TNode *Tree; //二叉树节点定义;
struct TNode
{
    int data;
    Tree left;
    Tree right;
};

Tree inSert(int data) //插入一个节点
{
    Tree s = new TNode();
    s->data = data;
    s->left = NULL;
    s->right = NULL;
    return s;
}

// NOTE:通过前序序列、中序序列确定一棵二叉树的递归算法;
Tree buildTee(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
    {
        return NULL;
    }
    Tree T = inSert(pre[L1]);
    int i;
    for (i = L2; i <= R2; ++i)
    {
        if (pre[L1] == in[i])
        {
            break;
        }
    }
    T->left = buildTee(L1 + 1, L1 + i - L2, L2, i - 1);
    T->right = buildTee(L1 + i - L2 + 1, R1, i + 1, R2);
    return T;
}

// NOTE:[扩展]通过后序序列、中序列确定一颗二叉树的递归算法
int post[maxSize];
Tree buildTreeWithPost(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
    {
        return NULL;
    }
    Tree T = inSert(post[R1]); // README:后序序列的最后一元素即为根节点;
    int i;
    for (i = L2; i <= R2; ++i)
    {
        if (in[i] == post[R1])
        {
            break;
        }
    }
    T->left = buildTreeWithPost(L1, L1 + i - L2 - 1, L2, i - 1);
    T->right = buildTreeWithPost(L1 + i - L2, R1 - 1, i + 1, R2);
    return T;
}

int result[maxSize];
int p = -1;
void postOrderTraversal(Tree T) //后序遍历
{
    if (T)
    {
        postOrderTraversal(T->left);
        postOrderTraversal(T->right);
        result[++p] = T->data;
    }
}

int main()
{
    int N = restoreSequence();
    Tree T = buildTee(0, N - 1, 0, N - 1);
    postOrderTraversal(T);
    for (int i = 0; i < N - 1; ++i)
    {
        cout << result[i] << ' ';
    }
    cout << result[N - 1];
    return 0;
}