
// NOTE:复制构造函数

#include <iostream>
using namespace std;

//使用深层复制构造函数
//返回时构造临时对象，动态分配将临时对象返回到主调函数，然后删除临时对象。

//使用移动构造函数
//将要返回的局部对象转移到主调函数，省去了构造和删除临时对象的过程。

class IntNum
{
public:
    IntNum(int x = 0) : xptr(new int(x))
    { //构造函数
        cout << "Calling constructor..." << endl;
    }
    IntNum(const IntNum &n) : xptr(new int(*n.xptr))
    { //复制构造
        cout << "Calling copy constructor..." << endl;
    };
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