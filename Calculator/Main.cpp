/*
 *
   在main中获取键盘输入 以及 创建Scan对象和Print对象。
    调用Scan对象的ToStringQueue(string input)，将输入传进去以获取队列。
    接着将这个队列传入Print对象的方法中，得到输出。

    1） 当输入的数字超过10位（包括小数位）时，报错。
    2） 能够处理不超过10位的任意实数
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cctype>
#include"Scan.h"
#include"Print.h"
using namespace std;

bool check(string s);               //检查输入的数字个数

int main()
{
	string input;
	cin>>input;

	if(check(input))
	{
		cout<<"Error!"<<endl;
		return 0;                   //数字位数大于10时报错
	}

	else                            //数字位数不大于10时处理字符串
	{

	Scan scan;                      //创建Scan对象
	Print print;                    //创建Print对象

	queue<string> q = scan.ToStringQueue(input);        //调用ToStringQueue()方法获取目标队列
	print.PrintQueue(q);                                //调用PrintQueue()方法输出队列各元素

	return 0;
	}
}


bool check(string s)
{
	int num = 0;                      //记录输入的数字个数
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			num++;
		}
	}
	if(num>10)
	{
		return true;                  //数字位数大于10时返回true
	}
	else
	{
		return false;                 //数字位数不大于10时返回false
	}
}
