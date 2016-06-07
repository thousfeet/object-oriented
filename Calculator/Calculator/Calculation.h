/************************************************************
  FileName: Calculation.h
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	Calculation(queue<string> theQueue);
	void trans(queue<string> str);
	double calcu();
 ***********************************************************/
/************************************************************
 FileName: Calculation.h
 Author: thousfeet
 Date: 2016.04.04
 Function List:
   Calculation(queue<string> theQueue);
   void trans(queue<string> str);
   double calcu();
***********************************************************/
#ifndef CALCULATION_H_
#define CALCULATION_H_

#include<string>
#include<queue>
#include<stack>
namespace std {

class Calculation {

public:
	Calculation(queue<string> theQueue);
	void trans(queue<string> str); //转化为后缀表达式
	double calcu();  //计算后缀表达式

private:
	queue<string> str;  //传入的字符队列
	queue<string> suff; //后缀表达式队列
	stack<double> num;  //运算数字栈
	stack<string> oper;  //运算符栈
	double resu = 0; //暂存运算结果
	int minus = 0; //负号个数
   Calculation(queue<string> theQueue);
   void trans(queue<string> str); //简体中文
   double calcu();  //璁＄畻鍚庣紑琛ㄨ揪寮�

private:
   queue<string> str;  //浼犲叆鐨勫瓧绗﹂槦鍒�
   queue<string> suff; //鍚庣紑琛ㄨ揪寮忛槦鍒�
   stack<double> num;  //杩愮畻鏁板瓧鏍�
   stack<string> oper;  //杩愮畻绗︽爤
   double resu = 0; //鏆傚瓨杩愮畻缁撴灉
   int minus = 0; //璐熷彿涓暟

};

}

#endif
