//例6-24.cpp 用getline输入字符串

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string exp;
	getline(cin, exp, '=');
	cout << exp.length() << endl
		 << exp;
	return 0;
}
