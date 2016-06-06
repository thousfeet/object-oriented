<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Calculation.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	Calculation(queue<string> theQueue);
	void trans(queue<string> str);
	double calcu();
 ***********************************************************/
=======
/************************************************************
 FileName: Calculation.cpp
 Author: thousfeet
 Date: 2016.03.23
 Function List:
   Calculation(queue<string> theQueue);
   void trans(queue<string> str);
   double calcu();
***********************************************************/
>>>>>>> ver_3.0

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
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
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
=======
   str = theQueue;
}

/*************************************************
 Description:
    灏嗕腑缂�琛ㄨ揪寮忚浆鍖栦负鍚庣紑琛ㄨ揪寮�
 Input: queue<string> str 杞寲鍓嶇殑涓紑琛ㄨ揪寮忛槦鍒�
 Output: 鏃�
 Return: 鏃�
*************************************************/
void Calculation::trans(queue<string> str)
{
   string temp = "";
   temp = str.front();

   if(temp == "-")
   {
       minus++;

       str.pop();
       //鐗瑰垽绗竴涓礋鏁�
       if(isdigit(str.front()[0]))
       {
           suff.push(str.front());
           str.pop();
           suff.push(temp);
       }
       //-()鐨勬儏鍐�
       else
       {
           //鏍囪涓�-<)
           str.front() = "<";
           oper.push(temp);
       }
   }

   //閬嶅巻涓紑琛ㄨ揪寮忛槦鍒�
   bool flag = true;
   bool isminus = true;

   while(!str.empty())
   {
       flag = true;
       //璇诲彇闃熷垪绗竴涓厓绱�
       temp = str.front();
       //鑻ユ槸锛堬紝鐩存帴鍏ユ爤
       if(temp == "(" || temp == "<")
       {
           oper.push(temp);
           str.pop();
           if(isdigit(str.front()[0]))
           {
               isminus = false; //涓嶆槸璐熸暟
           }
           flag = false;
       }
       //鑻ユ槸*鎴�/锛岀洿鎺ュ叆鏍�
       if(temp == "*"||temp == "/")
       {
           oper.push(temp);
       }
       //鑻ユ槸+锛屽垽鏂爤椤跺厓绱狅紝鑻ヤ綆浜庢爤椤跺厓绱犱紭鍏堢骇锛屽垯鏍堥《鍏冪礌鍑烘爤鍚庤鍏冪礌鍏ユ爤锛涘惁鍒欑洿鎺ュ叆鏍�
       if(temp == "+")
       {
           //鑰冭檻鍒拌礋鏁版儏鍐碉紝鎵�浠ュ厛鍋氬噺娉�
           while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
           {
               suff.push(oper.top());  //杩涘叆鍚庣紑杩愮畻琛ㄨ揪寮忛槦鍒�
               oper.pop();  //寮瑰嚭鏍堥《鍏冪礌
           }
           oper.push(temp);  //褰撳墠鍏冪礌鍏ユ爤

       }
       //鑻ユ槸-
       if(temp == "-")
       {
           minus++;

           //鎷彿鍐呮湁璐熷彿鐨勬儏鍐�
           if(!oper.empty() && oper.top() == "(")
           {
               //璐熸暟
               if(isminus)
               {
                   str.pop(); //寮瑰嚭-鍙�
                   suff.push("0"); //0鍏ラ槦鍒�
                   suff.push(str.front()); //姝よ礋鏁版暟鍊煎叆闃熷垪
                   suff.push(temp); //-鍙峰叆闃熷垪
               }
               //-()
               else
               {
                   oper.push(temp);
               }
           }
           //璇�-鍙蜂负鍑忔硶绗﹀彿
           else
           {
               //鑻�-浣庝簬鏍堥《鍏冪礌浼樺厛绾э紝鍒欐爤椤跺厓绱犲嚭鏍堝悗璇ュ厓绱犲叆鏍堬紱鍚﹀垯鐩存帴鍏ユ爤
               while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
               {
                   suff.push(oper.top());  //杩涘叆鍚庣紑杩愮畻琛ㄨ揪寮忛槦鍒�
                   oper.pop();  //寮瑰嚭鏍堥《鍏冪礌
               }
               oper.push(temp);  //褰撳墠鍏冪礌鍏ユ爤

           }
       }
       //鑻ユ槸锛夛紝鍒欎緷娆″脊鍑烘爤椤跺厓绱犵洿鍒伴亣鍒帮紙
       if(temp == ")")
       {

           while(oper.top()!="(" && oper.top()!="<")
           {
               suff.push(oper.top());
               oper.pop();
           }

           if(oper.top() == "<")
           {
               oper.pop();//寮瑰嚭<
               suff.push(oper.top());//-鍙峰叆闃熷垪
           }

           oper.pop();

           isminus = true;

       }
       //鑻ユ槸杩愮畻鏁板瓧锛屽垯鍏ラ槦鍒�
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
>>>>>>> ver_3.0
}


/*************************************************
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
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
=======
 Description:
    璁＄畻鍚庣紑琛ㄨ揪寮忓緱鍒版渶缁堣绠楃粨鏋�
 Input: 鏃�
 Output: 鏃�
 Return: num.top 琛ㄨ揪寮忕殑璁＄畻缁撴灉
*************************************************/
double Calculation::calcu()
{
   while(minus--)
   {
       num.push(resu); //灏�0鍘嬪叆鏍堬紝鐢ㄤ互澶勭悊璐熸暟
   }

   stringstream ss;
   double tempnum;

   while(!suff.empty())
   {
       string temp = suff.front();

       //瀵规爤椤跺厓绱犺繘琛屽搴旀搷浣滆繍绠楋紝杩愮畻缁撴灉鍏ユ爤
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
               cout << "娉℃场璇撮櫎鏁颁笉鑳戒负0"<<endl;
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
       //鑻ヤ负鏁板瓧瀛楃涓诧紝鍒欒浆鍖栦负鏁板瓧鍚庡叆鏍�
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
>>>>>>> ver_3.0
}

}

<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2

=======
>>>>>>> ver_3.0
