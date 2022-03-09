/*********************************************************************
	程序名:
	版权:
	作者:
	日期: 2022-03-08 11:09
	说明:
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cmath>
#define maxSize 1000
#define MIN 0.0001
using namespace std;

//打印出给定链表
void printProFix(char intfix[], int len)
{
	for (int i = 0; i <= len; ++i)
	{
		cout << intfix[i];
	}
	cout << endl;
}

void printPreFix(char intfix[], int len)
{
	for (int i = len; i >= 0; --i)
	{
		cout << intfix[i];
	}
	cout << endl;
}

//简单四则运算
int calSub(float opnd1, char op, float opnd2, float &result)
{
	if (op == '+')
		result = opnd1 + opnd2;
	if (op == '-')
		result = opnd1 - opnd2;
	if (op == '*')
		result = opnd1 * opnd2;
	if (op == '/')
	{
		if (fabs(opnd2) < MIN)
		{
			return 0;
		}
		else
		{
			result = opnd1 / opnd2;
		}
	}
	return 1;
}

//运算函数
int calStackTopTwo(float num[], int &top1, char op[], int &top2)
{
	if (calSub(num[top1 - 1], op[top2], num[top1], num[top1 - 1]))
	{
		--top1;
		--top2;
		return 1;
	}
	else
	{
		cout << "ERROR!" << endl;
		return 0;
	}
}

int calStackTopTwo(float num[], int &top1, char op)
{
	if (calSub(num[top1 - 1], op, num[top1], num[top1 - 1]))
	{
		--top1;
		return 1;
	}
	else
	{
		cout << "ERROR!" << endl;
		return 0;
	}
}

//1、判断运算符优先级
int getPriority(char op);

//2、表达式中缀转后缀
void intfixToPostFix(char intfix[], char s2[], int &top2);

//3、表达式中缀转前缀
void intfixToPreFix(char intfix[], int N, char s2[], int &top2);

//4、中缀表达式求值
float calIntfix(char exp[]);

//5、后缀表达式求值
float calPostFix(char exp[]);

//6、前缀表达式求值
float calPreFix(char exp[]);

int main()
{
	char intfix[maxSize] = "";
	gets(intfix);
	int N = strlen(intfix);

	//中缀转后缀
	char *b;
	b = (char *)calloc(N, sizeof(char));
	int lenb = -1;
	intfixToPostFix(intfix, b, lenb);
	printProFix(b, lenb);

	//中缀转前缀
	char *c;
	c = (char *)calloc(N, sizeof(char));
	int lenc = -1;
	intfixToPreFix(intfix, N, c, lenc);
	printPreFix(c, lenc);

	//计算中缀表达式值
	float value;
	value = calIntfix(intfix);
	cout << value << endl;

	//计算后缀表达式值
	float postValue;
	postValue = calPostFix(b);
	cout << postValue << endl;

	//计算前缀表达式值
	float preValue;
	preValue = calPreFix(c);
	cout << preValue << endl;

	return 0;
}

//1、判断运算符优先级
int getPriority(char op)
{
	if (op == '*' || op == '/')
	{
		return 1;
	}
	else if (op == '+' || op == '-')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

//2、表达式中缀转后缀
void intfixToPostFix(char intfix[], char s2[], int &top2)
{
	char *s1;
	s1 = (char *)calloc(maxSize, sizeof(char));
	int top1 = -1;
	int i = 0;
	while (intfix[i] != '\0')
	{
		if (intfix[i] >= '0' && intfix[i] <= '9')//数字直接入栈s2
		{
			s2[++top2] = intfix[i++];
		}
		else if (intfix[i] == '(')//左括号直接入栈s1
		{
			s1[++top1] = intfix[i++];
		}

		else if (intfix[i] == '+' || intfix[i] == '-' || intfix[i] == '*' || intfix[i] == '/')
		{
			//运算符号在s1栈空时入栈；在s1栈顶元素为左括号时入栈；
			//在运算符优先级高于s1栈顶运算符时入栈
			if (top1 == -1 || s1[top1] == '(' || (getPriority(intfix[i]) > getPriority(s1[top1])))
			{
				s1[++top1] = intfix[i++];
			}
			//在运算符优先级不高于s1栈顶运算符时，s1栈顶运算符出栈
			else //if((getPriority(intfix[i]) <= getPriority(s1[top1])))
			{
				s2[++top2] = s1[top1--];
			}
		}
		//当运算符为右括号时，s1出栈直到左括号出栈
		else if (intfix[i] == ')')
		{
			while (s1[top1] != '(')
			{
				s2[++top2] = s1[top1--];
			}
			--top1;
			++i;
		}
	}
	while (top1 != -1)
	{
		s2[++top2] = s1[top1--];
	}
	free(s1);
}

//3、表达式中缀转前缀
void intfixToPreFix(char intfix[], int N, char s2[], int &top2)
{
	char *s1;
	s1 = (char *)calloc(N, sizeof(char));
	int top1 = -1;
	int i = N - 1;//从右往左扫描
	while (i >= 0)
	{
		if (intfix[i] >= '0' && intfix[i] <= '9')
		{
			s2[++top2] = intfix[i--];
		}
		else if (intfix[i] == ')')
		{
			s1[++top1] = intfix[i--];
		}
		else if (intfix[i] == '+' || intfix[i] == '-' || intfix[i] == '*' || intfix[i] == '/')
		{
			if (
			    top1 == -1 ||
			    s1[top1] == ')' ||
			    //在运算符优先级不低于s1栈顶运算符时入栈
			    (getPriority(intfix[i]) >= getPriority(s1[top1]))
			)
			{
				s1[++top1] = intfix[i--];
			}
			//在运算符优先级低于s1栈顶运算符时，s1栈顶运算符出栈
			else // if ((getPriority(intfix[i]) < getPriority(s1[top1])))
			{
				s2[++top2] = s1[top1--];
			}
		}
		else if (intfix[i] == '(')
		{
			while (s1[top1] != ')')
			{
				s2[++top2] = s1[top1--];
			}
			--top1;
			--i;
		}
	}
	while (top1 != -1)
	{
		s2[++top2] = s1[top1--];
	}
	free(s1);
}

//4、中缀表达式求值
float calIntfix(char exp[])
{
	int n = strlen(exp);
	float *stackNum;
	int top1 = -1;
	char *stackOp;
	int top2 = -1;
	stackNum = (float *)calloc(n, sizeof(float));
	stackOp = (char *)calloc(n, sizeof(char));
	int i = 0;
	while (i < n)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			stackNum[++top1] = exp[i++] - '0'; //字符整型转化成int整型
		}
		else if (exp[i] == '(')
		{
			stackOp[++top2] = exp[i++];
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if (top2 == -1 ||
			        stackOp[top2] == '(' ||
			        (getPriority(exp[i]) > getPriority(stackOp[top2]))
			   )
			{
				stackOp[++top2] = exp[i++];
			}
			else //if((getPriority(exp[i])<=getPriority(stackOp[top2])))
			{
				calStackTopTwo(stackNum, top1, stackOp, top2);
			}
		}
		else if (exp[i] == ')')
		{
			while (stackOp[top2] != '(')
			{
				calStackTopTwo(stackNum, top1, stackOp, top2);
			}
			--top2;
			++i;
		}
	}
	while (top2 != -1)
	{
		calStackTopTwo(stackNum, top1, stackOp, top2);
	}
	free(stackOp);
	return stackNum[top1];
}

//5、后缀表达式求值
float calPostFix(char exp[])
{
	int n = strlen(exp);
	float *stackNum;
	int top1 = -1;
	stackNum = (float *)calloc(n, sizeof(float));
	int i = 0;
	while (i < n)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			stackNum[++top1] = exp[i++] - '0'; //字符整型转化成int整型
		}
		else //if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			calStackTopTwo(stackNum, top1, exp[i]);
			++i;
		}
	}
	return stackNum[top1];
}

//6、前缀表达式求值
float calPreFix(char exp[])
{
	int n = strlen(exp);
	float *stackNum;
	int top1 = -1;
	stackNum = (float *)calloc(n, sizeof(float));
	int i = 0;
	while (i < n)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
		{
			stackNum[++top1] = exp[i++] - '0'; //字符整型转化成int整型
		}
		else //if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if (calSub(stackNum[top1], exp[i], stackNum[top1 - 1], stackNum[top1 - 1]))
			{
				--top1;
			}
			else
			{
				cout << "ERROR!" << endl;
				return 0;
			}
			++i;
		}
	}
	return stackNum[top1];

}