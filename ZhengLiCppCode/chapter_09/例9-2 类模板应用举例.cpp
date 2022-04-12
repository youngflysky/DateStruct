//��9-2.cpp ��ģ��Ӧ�þ���

#include<iostream>
#include<cstdlib>
using namespace std;

struct Student{               //�ṹ��Student 
	int id;                   //ѧ�� 
	float gpa;                //ƽ���� 
}; 

template<class T>             //��ģ�� 
class Store{
	private:
		T item;               //item���ڴ���������͵����� 
		bool haveValue;       //haveValue���item�Ƿ��ѱ��������� 
	public:
		Store();              //Ĭ����ʽ�����βΣ��Ĺ��캯�� 
		T &getElem();         //��ȡ���ݺ��� 
		void putElem(const T &x);  //�������ݺ��� 
};

//����ʵ�ָ���Ա����
template<class T>                 //Ĭ�Ϲ��캯����ʵ�� 
Store<T>::Store():haveValue(false){} 

template<class T>             //��ȡ���ݺ�����ʵ�� 
T &Store<T>::getElem(){
	if(!haveValue){             //�����ͼ��ȡδ��ʼ�������ݣ��������ֹ 
		cout<<"No item present!"<<endl;
		exit(1);              //ʹ������ȫ�˳������ص�����ϵͳ 
		//������������ʾ������ֹ��ԭ�򣬿��Ա�����ϵͳ���� 
	}
	return item;          //����item�д�ŵ����� 
} 

template<class T>             //�������ݺ�����ʵ�� 
void Store<T>::putElem(const T &x){
	haveValue=true;               //��haveValue��Ϊtrue����ʾitem���Ѵ�����ֵ 
	item=x;                     //��xֵ����item 
}

int main(){
	Store<int>s1,s2;   //��������Store<int>������������ݳ�ԱitemΪint���� 
	s1.putElem(3);          //�����s1�д������ݣ���ʼ������s1�� 
	s2.putElem(-7);         //�����s2�д������ݣ���ʼ������s2) 
	cout<<s1.getElem()<<" "<<s2.getElem()<<endl;   //�������s1��s2�����ݳ�Ա 
	
	Student g={1000,23};         //����Student���ͽṹ�������ͬʱ�����ֵ 
	Store<Student>s3;    //����Store<Student>�����s3���������ݳ�ԱitemΪStudent���� 
	s3.putElem(g);                 //�����s3�д������ݣ���ʼ������s3�� 
	cout<<"The student id is "<<s3.getElem().id<<endl;   //�������s3�����ݳ�Ա 
	
	Store<double>d;     //����Store<double>�����d���������ݳ�ԱitemΪdouble���� 
	cout<<"Retrieving object d...";
	cout<<d.getElem()<<endl;           //�������d�����ݳ�Ա 
	//����dδ����ʼ������ִ�к���d.getElem()�����е��³�����ֹ
	
	return 0; 
}
