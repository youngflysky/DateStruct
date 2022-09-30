// TITLE : //平衡二叉树
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct AVLNode *AVLTree, AVLNode;
struct AVLNode
{
    int value;
    AVLTree lChild;
    AVLTree rChild;
};

AVLTree InsertAVL(AVLTree T, int data)
{
}

AVLTree BuildAVL()
{
    int N;
    cin >> N;
    int data;
    AVLTree AVL = NULL;
    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        AVL = InsertAVL(AVL, data);
    }
}

int main()
{

    return 0;
}