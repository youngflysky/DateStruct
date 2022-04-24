
// README: 8、树的同构
#include <iostream>
using namespace std;
#define Null -1

typedef struct TNode // Array node storing binary tree nodes
{
    char ch;
    int left = Null;
    int right = Null;
} TNode, *Tree;

int buildTree(Tree T, int N) // Read in all tree nodes and store in an array NodeArray[N]
{
    char l, r;
    int *check = new int[N]();
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i].ch >> l >> r;
        if (l != '-')
        {
            T[i].left = l - '0';
            check[T[i].left] = 1;
        }
        if (r != '-')
        {
            T[i].right = r - '0';
            check[T[i].right] = 1;
        }
    }
    int root = 0;
    for (root = 0; root < N; ++root)
    {
        if (!check[root])
        {
            break;
        }
    }
    return root;
}
bool isSameStruct(const Tree T1, int root1, const Tree T2, int root2)
{
    if (root1 == Null && root2 == Null)
    {
        return true;
    }
    else if (root1 == Null || root2 == Null)
    {
        return false;
    }
    else if (T1[root1].ch != T2[root2].ch)
    {
        return false;
    }
    else
    {
        int l1 = T1[root1].left, r1 = T1[root1].right;
        int l2 = T2[root2].left, r2 = T2[root2].right;
        if (l1 == Null && l2 == Null) // l-l:Null;
        {
            return isSameStruct(T1, r1, T2, r2);
        }
        else if (l1 == Null && r2 == Null) // l-r:Null;
        {
            return isSameStruct(T1, r1, T2, l2);
        }
        else if (r1 == Null && l2 == Null) // r-l:Null;
        {
            return isSameStruct(T1, l1, T2, r2);
        }
        else if (r1 == Null && r2 == Null) // r-r:Null;
        {
            return isSameStruct(T1, l1, T2, l2);
        }
        else if (T1[l1].ch == T2[l2].ch)
        {
            if (isSameStruct(T1, l1, T2, l2) && isSameStruct(T1, r1, T2, r2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (isSameStruct(T1, l1, T2, r2) && isSameStruct(T1, r1, T2, l2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int main()
{
    int N1;
    cin >> N1;
    Tree T1;
    int root1;
    if (N1)
    {
        T1 = new TNode[N1]();
        root1 = buildTree(T1, N1);
    }

    int N2;
    cin >> N2;
    Tree T2;
    int root2;
    if (N2)
    {
        T2 = new TNode[N2]();
        root2 = buildTree(T2, N2);
    }

    if (N1 == 0 && N2 == 0)
    {
        cout << "Yes\n";
        return 0;
    }
    else if (N1 && N2)
    {
        if (isSameStruct(T1, root1, T2, root2))
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
