 /************************************************************
  FileName: Calculation.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	Calculation(queue<string> theQueue);
	void trans(queue<string> str);
	double calcu();
 ***********************************************************/

#include "Calculation.h"
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<sstream>
#include<iostream>

namespace std {


Calculation::Calculation(queue<string> theQueue)
{
	str = theQueue;
}

/*************************************************
  Description:
     将中缀表达式转化为后缀表达式
  Input: queue<string> str 转化前的中缀表达式队列
  Output: 无
  Return: 无
*************************************************/
void Calculation::trans(queue<string> str)
{
	string temp = "";
	temp = str.front();

	if(temp == "-")
	{
		minus++;

		str.pop();
		//特判第一个负数
		if(isdigit(str.front()[0]))
		{
			suff.push(str.front());
			str.pop();
			suff.push(temp);
		}
		//-()的情况
		else
		{
			//标记为-<)
			str.front() = "<";
			oper.push(temp);
		}
	}

	//遍历中缀表达式队列
	bool flag = true;
	bool isminus = true;

	while(!str.empty())
	{
		flag = true;
		//读取队列第一个元素
		temp = str.front();
		//若是（，直接入栈
		if(temp == "(" || temp == "<")
		{
			oper.push(temp);
			str.pop();
			if(isdigit(str.front()[0]))
			{
				isminus = false; //不是负数
			}
			flag = false;
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
			while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
			{
				suff.push(oper.top());  //进入后缀运算表达式队列
				oper.pop();  //弹出栈顶元素
			}
			oper.push(temp);  //当前元素入栈

		}
		//若是-
		if(temp == "-")
		{
			minus++;

			//括号内有负号的情况
			if(!oper.empty() && oper.top() == "(")
			{
				//负数
				if(isminus)
				{
					str.pop(); //弹出-号
					suff.push("0"); //0入队列
					suff.push(str.front()); //此负数数值入队列
					suff.push(temp); //-号入队列
				}
				//-()
				else
				{
					oper.push(temp);
				}
			}
			//该-号为减法符号
			else
			{
				//若-低于栈顶元素优先级，则栈顶元素出栈后该元素入栈；否则直接入栈
				while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
				{
					suff.push(oper.top());  //进入后缀运算表达式队列
					oper.pop();  //弹出栈顶元素
				}
				oper.push(temp);  //当前元素入栈

			}
		}
		//若是），则依次弹出栈顶元素直到遇到（
		if(temp == ")")
		{

			while(oper.top()!="(" && oper.top()!="<")
			{
				suff.push(oper.top());
				oper.pop();
			}

			if(oper.top() == "<")
			{
				oper.pop();//弹出<
				suff.push(oper.top());//-号入队列
			}

			oper.pop();

			isminus = true;

		}
		//若是运算数字，则入队列
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


/*************************************************
  Description:
     计算后缀表达式得到最终计算结果
  Input: 无
  Output: 无
  Return: num.top 表达式的计算结果
*************************************************/
double Calculation::calcu()
{
	while(minus--)
	{
		num.push(resu); //将0压入栈，用以处理负数
	}

	stringstream ss;
	double tempnum;

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
			if(resu == 0)
			{
				cout << "泡泡说除数不能为0"<<endl;
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
		//若为数字字符串，则转化为数字后入栈
		else if(isdigit(temp[0]))
		{
			ss << suff.front();
			ss >> tempnum;
			num.push(tempnum);
			ss.clear();
			ss.str("");
		}
		suff.pop();
	}


	return num.top();
}

}


