//��5-3.���о�̬�Ͷ�̬�����ڶ����ʱ�ӳ���

#include<iostream>
using namespace std;

class Clock{                                       //ʱ���ඨ�� 
	public:                                        //�ⲿ�ӿ� 
		Clock();
		void setTime(int newH,int newM,int newS);  //3���βξ����к���ԭ�������� 
		void showTime();
	private:                                       //˽�����ݳ�Ա 
		int hour,minute,second;
}; 

//ʱ�����Ա������ʵ��
Clock::Clock():hour(0),minute(0),second(0){}       //���캯�� 

void Clock::setTime(int newH,int newM,int newS){   //3���βξ����оֲ������� 
	hour=newH;
	minute=newM;
	second=newS;
} 

void Clock::showTime(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

Clock globClock;                                   //��������globClock�����о�̬�����ڣ������ռ������� 
//��Ĭ�Ϲ��캯����ʼ��Ϊ0��0��0
int main(){                                        //������ 
	cout<<"First time output:"<<endl;
	//���þ��������ռ�������Ķ���globClock
	globClock.showTime();                          //����ĳ�Ա���������������� 
	//��ʾ0��0��0
	globClock.setTime(8,30,30);                    //��ʱ������Ϊ8��30��30 
	
	Clock myClock(globClock);                      //�������п�������Ķ���myClock 
	//���ø��ƹ��캯������globClockΪ��ʼֵ
	cout<<"Second time output:"<<endl;
	myClock.showTime();                            //���þ��п�������Ķ���myClock 
	//���8:30:30
	
	return 0; 
} 
