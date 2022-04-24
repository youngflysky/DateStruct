
// README:Ê÷µÄÍ¬¹¹

#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct TNode // Array node storing binary tree nodes
{
    char ch;
    int leftIndex = -1;
    int rightIndex = -1;
} TNode, *Tree;

int FindRoot(const Tree T, int N);

int buildTree(Tree T, int N) // Read in all tree nodes and store in an array NodeArray[N]
{
    char l, r;
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i].ch >> l >> r;
        cin.get();
        if (l != '-')
        {
            T[i].leftIndex = l - '0';
        }
        if (r != '-')
        {
            T[i].rightIndex = r - '0';
        }
    }
    int root = FindRoot(T, N);
    return root;
}

int FindRoot(const Tree T, int N) // Find the index of the root TNode;
{
    int *p = new int[N]();
    for (int i = 0; i < N; ++i)
    {
        if (T[i].leftIndex != -1)
        {
            p[i] = 1;
        }
        if (T[i].rightIndex != -1)
        {
            p[i] = 1;
        }
    }
    int root = 0;
    for (root = 0; root < N; ++root)
    {
        if (!p[root])
        {
            return root;
        }
    }
    return N;
}

// bool isSameStruct(const Tree T1, int root1, const Tree T2, int root2)
// {
//     if (T1[root1].ch == T2[root2].ch)
//     {
//         if (T1[T1[root1].leftIndex].ch == T2[T2[root2].leftIndex].ch)
//         {
//             isSameStruct(T1, T1[root1].leftIndex, T2, T2[root2].leftIndex);
//             isSameStruct(T1, T1[root1].rightIndex, T2, T2[root2].rightIndex);
//         }
//         else
//         {
//             isSameStruct(T1, T1[root1].leftIndex, T2, T2[root2].rightIndex);
//             isSameStruct(T1, T1[root1].rightIndex, T2, T2[root2].leftIndex);
//         }
//     }
//     else
//     {
//         return false;
//     }
// }

int main()
{
    int N1;
    cin >> N1;
    Tree T1 = new TNode[N1]();
    int root1 = buildTree(T1, N1);

    int N2;
    cin >> N2;
    Tree T2 = new TNode[N2]();
    int root2 = buildTree(T2, N2);

    for (int i = 0; i < N1; ++i)
    {
        cout << T1[i].ch;
    }
    cout << endl;
    for (int i = 0; i < N2; ++i)
    {
        cout << T2[i].ch;
    }

    return 0;
}
