<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Calculation.h
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	Calculation(queue<string> theQueue);
	void trans(queue<string> str);
	double calcu();
 ***********************************************************/
=======
/************************************************************
 FileName: Calculation.h
 Author: thousfeet
 Date: 2016.04.04
 Function List:
   Calculation(queue<string> theQueue);
   void trans(queue<string> str);
   double calcu();
***********************************************************/
>>>>>>> ver_3.0
#ifndef CALCULATION_H_
#define CALCULATION_H_

#include<string>
#include<queue>
#include<stack>
namespace std {

class Calculation {

public:
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
	Calculation(queue<string> theQueue);
	void trans(queue<string> str); //ת��Ϊ��׺���ʽ
	double calcu();  //�����׺���ʽ

private:
	queue<string> str;  //������ַ�����
	queue<string> suff; //��׺���ʽ����
	stack<double> num;  //��������ջ
	stack<string> oper;  //�����ջ
	double resu = 0; //�ݴ�������
	int minus = 0; //���Ÿ���
=======
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
>>>>>>> ver_3.0

};

}

#endif
