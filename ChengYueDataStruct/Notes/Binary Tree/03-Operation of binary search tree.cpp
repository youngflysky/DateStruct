// TITLE: Operation of binary search tree.cpp

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
typedef int ElementType;
typedef struct TreeNode *BinTree;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void InOrderTraversal(BinTree BST) //�������;
{
    if (!BST)
    {
        return;
    }
    else
    {
        InOrderTraversal(BST->Left);
        cout << BST->Data << " ";
        InOrderTraversal(BST->Right);
    }
}

//���ҵݹ�ʵ�� NOTE:����һ��β�ݹ麯����Ч�ʵͣ�����ѭ��ʵ�ָ�����
BinTree Find(ElementType X, BinTree BST)
{
    if (!BST)
    {
        return NULL;
    }
    if (X < BST->Data)
    {
        return Find(X, BST->Left);
    }
    else if (X > BST->Data)
    {
        return Find(X, BST->Right);
    }
    else
    {
        return BST;
    }
}

//���ҷǵݹ�ʵ��
BinTree IterFind(ElementType X, BinTree BST)
{
    while (BST)
    {
        if (X > BST->Data)
        {
            BST = BST->Right;
        }
        if (X < BST->Data)
        {
            BST = BST->Left;
        }
        else
        {
            return BST;
        }
    }
    return NULL;
}

// ������Сֵ�ĵݹ�ʵ��
BinTree FindMin(BinTree BST)
{
    if (!BST) // ���Ϊ���ˣ����� NULL
        return NULL;
    else if (BST->Left) // �������������������֧��������
        return FindMin(BST->Left);
    else // �ҵ���
        return BST;
}

// �������ֵ�ķǵݹ�ʵ��
BinTree FindMax(BinTree BST)
{
    if (BST)               // �������
        while (BST->Right) // ֻҪ������������
            BST = BST->Right;
    return BST;
}

// NOTE: BST Insert ���ѵ�
BinTree Insert(ElementType X, BinTree BST) // README:����ָ��
{
    if (!BST)
    {
        BST = new struct TreeNode;
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    if (X > BST->Data)
    {
        BST->Right = Insert(X, BST->Right);
    }
    else if (X < BST->Data)
    {
        BST->Left = Insert(X, BST->Left);
    }
    return BST;
}

bool Insert(BinTree &BST, ElementType X) // README:����ָ�������
{
    if (!BST)
    {
        BST = new struct TreeNode;
        BST->Left = BST->Right = NULL;
        BST->Data = X;
        return true;
    }
    if (X == BST->Data)
    {
        return false; //����Ԫ���Ѵ��� BST ��
    }
    else if (X > BST->Data)
    {
        return Insert(BST->Right, X);
    }
    else
    {
        return Insert(BST->Left, X);
    }
}

// NOTE:���� BST
BinTree CreateBST()
{
    int N;
    cin >> N;
    if (N <= 0)
    {
        return NULL;
    }
    BinTree BST;
    ElementType Data;
    for (int i = 0; i < N; ++i)
    {
        cin >> Data;
        BST = Insert(Data, BST);
    }
    return BST;
}

// NOTE:ɾ��ָ���ڵ�
BinTree Delete(ElementType X, BinTree BST)
{
    if (!BST)
    {
        cout << "The element to delete was not found��\n";
        return NULL;
    }
    else if (X < BST->Data)
    {
        BST->Left = Delete(X, BST->Left);
    }
    else if (X > BST->Data)
    {
        BST->Right = Delete(X, BST->Right);
    }
    else
    {
        BinTree Temp;
        if (BST->Left && BST->Right)
        {
            Temp = FindMin(BST->Right);
            BST->Data = Temp->Data;
            BST->Right = Delete(Temp->Data, BST->Right);
        }
        else
        {
            Temp = BST;
            if (!BST->Left)
            {
                BST = BST->Right;
            }

            else
            {
                BST = BST->Left;
            }
            delete Temp;
        }
    }
    return BST;
}

int main()
{
    BinTree BST = CreateBST();
    int a;
    srand((unsigned)time(NULL));
    a = (rand() % 9 + 1);
    /*
                5
               /\
              3  7
             /\	 /\
            1 4 6  8
            \      \
             2      9
    */
    cout << "��������Ľ���ǣ�";
    InOrderTraversal(BST);
    cout << endl;
    cout << "������Сֵ�ǣ�" << FindMin(BST)->Data << endl;
    cout << "�������ֵ�ǣ�" << FindMax(BST)->Data << endl;
    cout << "����ֵΪ3�Ľ�����������ֵΪ��" << Find(3, BST)->Left->Data << endl;
    cout << "����ֵΪ7�Ľ�����������ֵΪ��" << IterFind(7, BST)->Right->Data << endl;
    cout << "ɾ��ֵΪ" << a << "�Ľ��" << endl;
    Delete(a, BST);
    /*
                6
               /\
              3  7
             /\	  \
            1 4    8
            \      \
             2      9
    */
    cout << "��������Ľ���ǣ�";
    InOrderTraversal(BST);
    cout << endl;
    return 0;
}