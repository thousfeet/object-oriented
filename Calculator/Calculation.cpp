 /************************************************************
  FileName: Calculation.cpp
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	  1.����׺���ʽת��Ϊ��׺���ʽ
	  2.�����׺���ʽ�õ����ռ�����
 ***********************************************************/
#include "Calculation.h"
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<sstream>

namespace std {

Calculation::Calculation(queue<string> theQueue)
{
	str = theQueue;
}

void Calculation::trans(queue<string> str)
{
	string temp = "";
	int len = str.size();
	for(int i = 0; i < len; i++)
	{
		//��ȡ���е�һ��Ԫ��
		temp = str.front();
		//���ǣ���ֱ����ջ
		if(temp == "(")
		{
			oper.push(temp);
		}
		//����*��/��ֱ����ջ
		if(temp == "*"||temp == "/")
		{
			oper.push(temp);
		}
		//����+���ж�ջ��Ԫ�أ�������ջ��Ԫ�����ȼ�����ջ��Ԫ�س�ջ���Ԫ����ջ������ֱ����ջ
		if(temp == "+")
		{
			//���ǵ����������������������
			if(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
			{
				suff.push(oper.top());  //�����׺������ʽ����
				oper.pop();  //����ջ��Ԫ��
				oper.push(temp);  //��ǰԪ����ջ
			}
			else
			{
				oper.push(temp);
			}
		}
		//����-
		if(temp == "-")
				{
					//�������и��������
					if(!oper.empty() && oper.top() == "(")
					{
						suff.push("0");
					}
					//��-����ջ��Ԫ�����ȼ�����ջ��Ԫ�س�ջ���Ԫ����ջ������ֱ����ջ
					if(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
					{
						suff.push(oper.top());  //�����׺������ʽ����
						oper.pop();  //����ջ��Ԫ��
						oper.push(temp);  //��ǰԪ����ջ
					}
					else
					{
						oper.push(temp);
					}
				}
		//���ǣ��������ε���ջ��Ԫ��ֱ��������
		if(temp == ")")
		{
			while(oper.top()!="(")
			{
				suff.push(oper.top());
				oper.pop();
			}
			oper.pop();//������
		}
		//�����������֣��������
		else if(isdigit(temp[0]))
		{
			suff.push(temp);
		}
		str.pop();
	}
	while(!oper.empty())
	{
		suff.push(oper.top());
		oper.pop();
	}
}

int Calculation::calcu()
{
	num.push(resu); //��0ѹ��ջ�����Դ�����
	stringstream ss;
	int tempnum;

	while(!suff.empty())
	{
		string temp = suff.front();
		//��ջ��Ԫ�ؽ��ж�Ӧ�������㣬��������ջ
		if(temp == "+")
		{
			resu = num.top();
			num.pop();
			resu += num.top();
			num.pop();
			num.push(resu);
		}
		if(temp == "-")
		{
			resu = num.top();
			num.pop();
			resu = num.top() - resu;
			num.pop();
			num.push(resu);
		}
		if(temp == "*")
		{
			resu = num.top();
			num.pop();
			resu *= num.top();
			num.pop();
			num.push(resu);
		}
		if(temp == "/")
		{
			resu = num.top();
			num.pop();
			resu = num.top() / resu;
			num.pop();
			num.push(resu);
		}
		//��Ϊ�����ַ�������ת��Ϊ���ֺ���ջ
		else if(isdigit(temp[0]))
		{
			ss << suff.front();
			ss >> tempnum;
			num.push(tempnum);
			ss.clear();
		}
		suff.pop();
	}
	return num.top();
}


}
