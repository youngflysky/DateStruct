
// NOTE:�ƶ����캯��
#include <iostream>
using namespace std;
class IntNum
{
public:
    IntNum(int x = 0) : xptr(new int(x))
    { //���캯��
        cout << "Calling constructor..." << endl;
    }
    // IntNum(const IntNum &n) : xptr(new int(*n.xptr))
    // { //���ƹ��캯��
    //     cout << "Calling copy constructor..." << endl;
    // }
    IntNum(IntNum &&n) : xptr(n.xptr) // ע��&&����ֵ����.�������ص���ʱ��������ֵ
    {                                 //�ƶ����캯��
        n.xptr = nullptr;
        cout << "Calling move constructor..." << endl;
    }
    ~IntNum()
    { //��������
        delete xptr;
        cout << "Destructing..." << endl;
    }
    int getInt() { return *xptr; }

private:
    int *xptr;
};
//����ֵΪIntNum�����
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