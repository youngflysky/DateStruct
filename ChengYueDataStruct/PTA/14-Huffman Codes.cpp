// TITLE:Huffman Codes

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
typedef struct HuffmanNode
{
    char data;
    int frenquence;
} HNode;
HNode *InputArr;
bool cmp(HNode x, HNode y)
{
    return x.frenquence < y.frenquence;
}
void InputHNode()
{
    InputArr = new HNode[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> InputArr[i].data >> InputArr[i].frenquence;
    }
    sort(InputArr, InputArr + N, cmp);
}
//读入所有关键字及其权值,并按从大到小进行排列;

int main()
{
    cin >> N;
    InputHNode();

    return 0;
}