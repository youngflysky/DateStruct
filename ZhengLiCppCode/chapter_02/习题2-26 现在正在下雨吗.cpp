//ϰ��2-26.���û����ʡ��������������𣿡�����ʾ�û�����Y��N��
//������ΪY����ʾ�������������ꡣ����
//������ΪN����ʾ������û�����ꡣ����
//����������ʡ��������������𣿡��� 

#include<iostream>
using namespace std;

int main(){
	char que;
	cout<<"���������𣿣�������Y��N��"<<endl;
	cin>>que;
	while(que){
	if(que=='Y'){
	    cout<<"�����������ꡣ";
	    break;
	}
	else if(que=='N'){
	    cout<<"����û�����ꡣ";
	    break;
	}
	else
	    cout<<"���������𣿣�������Y��N��"<<endl;
	    cin>>que;
	    continue;
	}
	return 0;
}
