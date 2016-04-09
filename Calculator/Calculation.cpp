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
#include<iostream>

namespace std {

Calculation::Calculation(queue<string> theQueue)
{
	str = theQueue;
}

void Calculation::trans(queue<string> str)
{
	string temp = "";
	temp = str.front();

	if(temp == "-")
	{
		minus++;

		str.pop();
		//���е�һ������
		if(isdigit(str.front()[0]))
		{
			suff.push(str.front());
			str.pop();
			suff.push(temp);
		}
		//-()�����
		else
		{
			//���Ϊ-<)
			str.front() = "<";
			oper.push(temp);
		}
	}

	//������׺���ʽ����
	bool flag = true;
	bool isminus = true;

	while(!str.empty())
	{
		flag = true;
		//��ȡ���е�һ��Ԫ��
		temp = str.front();
		//���ǣ���ֱ����ջ
		if(temp == "(" || temp == "<")
		{
			oper.push(temp);
			str.pop();
			if(isdigit(str.front()[0]))
			{
				isminus = false; //���Ǹ���
			}
			flag = false;
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
			while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
			{
				suff.push(oper.top());  //�����׺������ʽ����
				oper.pop();  //����ջ��Ԫ��
			}
			oper.push(temp);  //��ǰԪ����ջ

		}
		//����-
		if(temp == "-")
		{
			minus++;

			//�������и��ŵ����
			if(!oper.empty() && oper.top() == "(")
			{
				//����
				if(isminus)
				{
					str.pop(); //����-��
					suff.push("0"); //0�����
					suff.push(str.front()); //�˸�����ֵ�����
					suff.push(temp); //-�������
				}
				//-()
				else
				{
					oper.push(temp);
				}
			}
			//��-��Ϊ��������
			else
			{
				//��-����ջ��Ԫ�����ȼ�����ջ��Ԫ�س�ջ���Ԫ����ջ������ֱ����ջ
				while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
				{
					suff.push(oper.top());  //�����׺������ʽ����
					oper.pop();  //����ջ��Ԫ��
				}
				oper.push(temp);  //��ǰԪ����ջ

			}
		}
		//���ǣ��������ε���ջ��Ԫ��ֱ��������
		if(temp == ")")
		{

			while(oper.top()!="(" && oper.top()!="<")
			{
				suff.push(oper.top());
				oper.pop();
			}

			if(oper.top() == "<")
			{
				oper.pop();//����<
				suff.push(oper.top());//-�������
			}

			oper.pop();

			isminus = true;

		}
		//�����������֣��������
		else if(isdigit(temp[0]))
		{
			suff.push(temp);
		}

		if(flag)
		{
			str.pop();
		}
	}
	while(!oper.empty())
	{
		suff.push(oper.top());
		oper.pop();
	}
}

double Calculation::calcu()
{
	while(minus--)
	{
		num.push(resu); //��0ѹ��ջ�����Դ�����
	}

	stringstream ss;
	double tempnum;

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
			if(resu == 0)
			{
				cout << "����˵��������Ϊ0"<<endl;
				return 0;
			}
			else
			{
				num.pop();
				resu = num.top() / resu;
				num.pop();
				num.push(resu);
			}
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
