#include<iostream>
using namespace std;

const float PI=3.141593;                         //����PI��ֵ 
const float FENCE_PRICE=35;                      //դ���ĵ��� 
const float CONCRETE_PRICE=20;                   //����ˮ�൥�� 

class Circle{                                    //����������Circle�������ݺͷ��� 
	public:                                      //�ⲿ�ӿ� 
		Circle(float r);                         //���캯�� 
		float circumference();                   //����Բ���ܳ� 
		float area();                            //����Բ����� 
	private:                                     //˽�����ݳ�Ա 
		float radius;                            //Բ�İ뾶 
}; 


//���ʵ��
//���캯����ʼ�����ݳ�Ա  radius
Circle::Circle(float r){
	radius=r;
} 

//����Բ���ܳ�
float Circle::circumference(){
	return 2*PI*radius;
} 

//����Բ�����
float Circle::area(){
	return PI*radius*radius;
} 

//������ʵ��
int main(){
	float radius;
	cout<<"Enter the radius of the pool: ";       //��ʾ�û�����뾶 
	cin>>radius;
	Circle pool(radius);                          //��Ӿ�ر߽���� 
	Circle poolRim(radius+3);                     //դ������ 
	
	//����դ��������
	float fenceCost=poolRim.circumference()*FENCE_PRICE;
	cout<<"Fencing Cost is $"<<fenceCost<<endl;
	
	//�������������
	float concreteCost=(poolRim.area()-pool.area())*CONCRETE_PRICE;
	cout<<"Concrete Cost is $"<<concreteCost<<endl;
	
	return 0; 
} 
