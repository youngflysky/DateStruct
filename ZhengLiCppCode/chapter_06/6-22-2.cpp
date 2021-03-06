
// NOTE:移动构造函数
#include <iostream>
using namespace std;
class IntNum
{
public:
    IntNum(int x = 0) : xptr(new int(x))
    { //构造函数
        cout << "Calling constructor..." << endl;
    }
    // IntNum(const IntNum &n) : xptr(new int(*n.xptr))
    // { //复制构造函数
    //     cout << "Calling copy constructor..." << endl;
    // }
    IntNum(IntNum &&n) : xptr(n.xptr) // 注：&&是右值引用.函数返回的临时变量是右值
    {                                 //移动构造函数
        n.xptr = nullptr;
        cout << "Calling move constructor..." << endl;
    }
    ~IntNum()
    { //析构函数
        delete xptr;
        cout << "Destructing..." << endl;
    }
    int getInt() { return *xptr; }

private:
    int *xptr;
};
//返回值为IntNum类对象
IntNum getNum()
{
    IntNum a;
    return a;
}
int main()
{
    cout << getNum().getInt() << endl;
    return 0;
}