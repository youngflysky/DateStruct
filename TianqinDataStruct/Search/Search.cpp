#include <cstdlib>
#include <iostream>
using namespace std;

//Ë³Ğò²éÕÒ·¨
int Search(int arr[], int n, int k)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

typedef struct LNode
{
    int key;
    struct LNode *next;
} LNode, *LinkList;

LinkList Search(LinkList head, int k)
{
    LinkList p = head->next;
    for (p; p; p = p->next)
    {
        if (p->key == k)
        {
            return p;
        }
    }
    return NULL;
}

int main()
{

    return 0;
}