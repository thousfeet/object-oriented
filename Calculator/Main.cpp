 /************************************************************
  FileName: Main.cpp
  Project: Calculator
  Author: thousfeet
  Date: 2016.03.23
  Description:
      1.作为程序主入口。
   	  2.对输入进行判断：
    	1） 当输入的数字超过10位（包括小数位）时，报错。
    	2） 能够处理不超过10位的任意实数
  Function List:
      int main(int argc, char* argv[])
 ***********************************************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<cctype>
#include <fstream>
#include"Scan.h"
#include"Calculation.h"
#include"Print.h"
using namespace std;


int main(int argc, char* argv[])
{

	Scan *scan = new Scan();  //创建Scan对象

	//---------数字位数大于10时报错----------
	//------------报错不处理开始-------------
	if(scan->check(argv[argc-1]))
	{
		cout << "Error!" << endl;
		return 0;
	}
	//------------报错不处理结束-------------
	//--------------------------------------



	//------数字位数不大于10时处理字符串-------
	//---------------处理开始-----------------
	else
	{

	//--------读入表达式开始--------
	string read;
	bool flag1 = false,flag2 = false,flag3 = false;

	//参数有-a
	if(strcmp(argv[1],"-a") == 0)
	{
		read = argv[2];
		flag2 = true;
	}
	//参数有-f
	else if(strcmp(argv[1],"-f") == 0)
	{
		flag3 = true;
	}
	//无指定类型参数
	else
	{
		read = argv[1];
		flag1= true;
	}
	//--------读入表达式结束--------


	//-----------计算开始-----------
	double theResult;
	Print *print = new Print(); //创建Print对象

	queue<string> q;


	//读写文件方式计算输出
	if(flag3)
	{
		ifstream fin(argv[2]);
		while(!fin.eof())
		{
			getline(fin,read,'\n');

			q = scan->ToStringQueue(read);  //获取目标队列
			cout << read<<endl;
			Calculation *calculation = new Calculation(q);  //创建Calculation对象
			calculation->trans(q);  //转化为后缀表达式
			theResult = calculation->calcu();
			cout << theResult<<endl;
			print->fPrint(argv[3],theResult);//输出结果

			delete(calculation);
		}

		fin.close();
	}

	//直接打印输出
	else
	{
		q = scan->ToStringQueue(read);  //获取目标队列
		Calculation *calculation = new Calculation(q);  //创建Calculation对象
		calculation->trans(q);  //转化为后缀表达式
		theResult = calculation->calcu();


		//直接输出运算结果
		if(flag1)
		{
			print->nPrint(theResult);
		}
		//输出表达式和运算结果
		else if(flag2)
		{
			print->aPrint(argv[2],theResult);
		}
		delete(calculation);
	}

	delete(scan);


	//-----------计算结束-----------

	return 0;
	//---------------处理结束-----------------
	//----------------------------------------
	}

}





