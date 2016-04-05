 /************************************************************
  FileName: Calculation.cpp
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	  1.将中缀表达式转化为后缀表达式
	  2.计算后缀表达式得到最终计算结果
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
		//读取队列第一个元素
		temp = str.front();
		//若是（，直接入栈
		if(temp == "(")
		{
			oper.push(temp);
		}
		//若是*或/，直接入栈
		if(temp == "*"||temp == "/")
		{
			oper.push(temp);
		}
		//若是+，判断栈顶元素，若低于栈顶元素优先级，则栈顶元素出栈后该元素入栈；否则直接入栈
		if(temp == "+")
		{
			//考虑到负数情况，所以先做减法
			if(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
			{
				suff.push(oper.top());  //进入后缀运算表达式队列
				oper.pop();  //弹出栈顶元素
				oper.push(temp);  //当前元素入栈
			}
			else
			{
				oper.push(temp);
			}
		}
		//若是-
		if(temp == "-")
				{
					//括号内有负数的情况
					if(!oper.empty() && oper.top() == "(")
					{
						suff.push("0");
					}
					//若-低于栈顶元素优先级，则栈顶元素出栈后该元素入栈；否则直接入栈
					if(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
					{
						suff.push(oper.top());  //进入后缀运算表达式队列
						oper.pop();  //弹出栈顶元素
						oper.push(temp);  //当前元素入栈
					}
					else
					{
						oper.push(temp);
					}
				}
		//若是），则依次弹出栈顶元素直到遇到（
		if(temp == ")")
		{
			while(oper.top()!="(")
			{
				suff.push(oper.top());
				oper.pop();
			}
			oper.pop();//弹出（
		}
		//若是运算数字，则入队列
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
	num.push(resu); //将0压入栈，用以处理负数
	stringstream ss;
	int tempnum;

	while(!suff.empty())
	{
		string temp = suff.front();
		//对栈顶元素进行对应操作运算，运算结果入栈
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
		//若为数字字符串，则转化为数字后入栈
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
