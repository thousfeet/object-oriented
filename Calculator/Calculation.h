 /************************************************************
  FileName: Calculation.h
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	  定义Calculation类。
 ***********************************************************/
#ifndef CALCULATION_H_
#define CALCULATION_H_

#include<string>
#include<queue>
#include<stack>
namespace std {

class Calculation {

public:
	queue<string> str;  //传入的字符队列
	queue<string> suff; //后缀表达式队列
	stack<double> num;  //运算数字栈
	stack<string> oper;  //运算符栈
	double resu = 0; //暂存运算结果
	int minus = 0; //负号个数

	Calculation(queue<string> theQueue);
	void trans(queue<string> str); //转化为后缀表达式
	double calcu();  //计算后缀表达式
};

}

#endif
