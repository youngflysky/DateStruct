#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    typedef struct TNode // Array node storing binary tree nodes
    {
        char ch;
        int leftIndex = -1;
        int rightIndex = -1;
    } TNode;

    TNode *T = new TNode[10];

    return 0;
}