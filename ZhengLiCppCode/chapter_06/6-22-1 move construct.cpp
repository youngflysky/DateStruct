
// NOTE:���ƹ��캯��

#include <iostream>
using namespace std;

//ʹ����㸴�ƹ��캯��
//����ʱ������ʱ���󣬶�̬���佫��ʱ���󷵻ص�����������Ȼ��ɾ����ʱ����

//ʹ���ƶ����캯��
//��Ҫ���صľֲ�����ת�Ƶ�����������ʡȥ�˹����ɾ����ʱ����Ĺ��̡�

class IntNum
{
public:
    IntNum(int x = 0) : xptr(new int(x))
    { //���캯��
        cout << "Calling constructor..." << endl;
    }
    IntNum(const IntNum &n) : xptr(new int(*n.xptr))
    { //���ƹ���
        cout << "Calling copy constructor..." << endl;
    };
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