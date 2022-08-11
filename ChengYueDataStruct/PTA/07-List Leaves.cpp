
// README: 09 树 List Leaves

#include <iostream>
using namespace std;
#define Null -1

struct TNode // define array;
{
    int left = Null;
    int right = Null;
} T[10];

int leaves[10];
int top = -1;

int buildTree() // Build a static linked list to store the binary tree and return the subscript of the root node;
{
    int N;
    cin >> N;
    if (!N)
    {
        return Null;
    }
    int root = 0;
    char l, r;
    for (int i = 0; i < N; ++i)
    {

        cin >> l >> r;
        if (l != '-')
        {
            T[i].left = l - '0';
            root -= T[i].left;
        }
        if (r != '-')
        {
            T[i].right = r - '0';
            root -= T[i].right;
        }
        root += i;
    }
    return root;
}

void printLeaves(int R)
{
    if (R == Null)
    {
        return;
    }

// NOTE:Level traversal has no recursive algorithm and relies on queues to achieve;
#define maxSize 5
    int queue[maxSize];
    int front = 0, rear = 0;
    int p;

    rear = (rear + 1) % maxSize;
    queue[rear] = R;
    while (front != rear)
    {
        front = (front + 1) % maxSize;
        p = queue[front];
        if (T[p].left == Null && T[p].right == Null)
        {
            leaves[++top] = p;
        }
        if (T[p].left != Null)
        {
            rear = (rear + 1) % maxSize;
            queue[rear] = T[p].left;
        }
        if (T[p].right != Null)
        {
            rear = (rear + 1) % maxSize;
            queue[rear] = T[p].right;
        }
    }
}

int main()
{
    int R;
    R = buildTree();
    printLeaves(R);

    for (int i = 0; i < top; ++i)
    {
        cout << leaves[i] << ' ';
    }
    cout << leaves[top];
    return 0;
}