
// README: 8、树的同构
#include <iostream>
using namespace std;
#define Null -1

struct TNode // Directly define two static linked lists that store binary trees
{
    char ch;
    int left = Null;
    int right = Null;
} T1[10], T2[10];
typedef TNode *Tree;

int buildTree(Tree T) // Store all node information in a static linked list and return the subscript of the root node;
{
    int N;
    cin >> N;
    if (N == 0)
    {
        return Null;
    }
    char l, r;
    int R = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> T[i].ch >> l >> r;
        if (l != '-')
        {
            T[i].left = l - '0';
            R -= T[i].left;
        }
        if (r != '-')
        {
            T[i].right = r - '0';
            R -= T[i].right;
        }
        R += i;
    }
    return R;
}

bool isomorphic(int R1, int R2) // Use recursive function to determine whether a binary tree is isomorphic
{
    if (R1 == Null && R2 == Null) // both Null;
    {
        return true;
    }
    else if (R1 == Null || R2 == Null) // one is Null,and the other isn't
    {
        return false;
    }
    else if (T1[R1].ch != T2[R2].ch) // the data isn't same;
    {
        return false;
    }
    else
    {
        int l1 = T1[R1].left, r1 = T1[R1].right;
        int l2 = T2[R2].left, r2 = T2[R2].right;
        // NOTE: only two recursive input formats,so as long as one condition is written in full
        if ((l1 == Null && l2 == Null) || (l1 != Null && l2 != Null) && (T1[l1].ch == T2[l2].ch))
        {
            return (isomorphic(l1, l2) && isomorphic(r1, r2));
        }
        else
        {
            return (isomorphic(l1, r2) && isomorphic(r1, l2));
        }
    }
}

int main()
{
    int R1, R2;
    R1 = buildTree(T1);
    R2 = buildTree(T2);
    if (isomorphic(R1, R2))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
