//����༰�������๹�캯��
//����������˴������Ĺ��캯��

#include<iostream>
using namespace std;

class Base0{                            //�������Base0 
	public:                             //�ⲿ�ӿ� 
		Base0(int var):var0(var){}
		int var0;
		void fun0(){cout<<"Member of Base0"<<endl;}
}; 

class Base1:virtual public Base0{         //Base0Ϊ����࣬����Base1�� 
	public:                               //�����ⲿ�ӿ� 
		Base1(int var):Base0(var){}
		int var1;
};

class Base2:virtual public Base0{         //Base0Ϊ����࣬����Base2�� 
	public:                               //�����ⲿ�ӿ� 
		Base2(int var):Base0(var){}
		int var2;
};

class Derived:public Base1,public Base2{   //������Derived���� 
	public:                                //�����ⲿ�ӿ� 
		Derived(int var):Base0(var),Base1(var),Base2(var){}
		int var;
		void fun(){cout<<"Member of Derived"<<endl;}
};

int main(){                                //���������� 
	Derived d(1);                             //����Derived�����d 
	d.var=2;
	d.fun();
	return 0;
}
