//��4-10.���һ���ṹ��洢ѧ���ĳɼ���Ϣ������ѧ�š��꼶�ͳɼ��������ݣ�
//ѧ�ŷ�Χ��0��99999999���꼶��Ϊfreshman��sophomore��junior��senior���֣��ɼ���ΪA\B\C\D�ĸ��ȼ� 

#include<iostream>
using namespace std;

enum Level{FRESHMAN,SOPHOMORE,JUNIOR,SENIOR};
enum Grade{A,B,C,D};
class Student{
	public:
		Student(unsigned number,Level level,Grade grade):number(number),level(level),grade(grade){}
		void show();
	private:
		unsigned number:27;
		Level level:2;
		Grade grade:2; 
}; 

void Student::show(){
	cout<<"Number:    "<<number<<endl;
	cout<<"Level:    ";
	switch(level){
		case FRESHMAN:  cout<<"freshman";break;
		case SOPHOMORE:	cout<<"sophomore";break;
		case JUNIOR:    cout<<"junior";break;
		case SENIOR:    cout<<"senior";break;
	}
	cout<<endl;
	cout<<"Grade:    ";
	switch(grade){
		case A:cout<<"A";break;
		case B:cout<<"B";break;
		case C:cout<<"C";break;
		case D:cout<<"D";break; 
	}
	cout<<endl;
}

int main(){
	Student s(12345678,SOPHOMORE,B);
	cout<<"Size of Student: "<<sizeof(Student)<<endl;
	s.show();
	return 0;
}

