 /************************************************************
  FileName: Calculation.h
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	  ����Calculation�ࡣ
 ***********************************************************/
#ifndef CALCULATION_H_
#define CALCULATION_H_

#include<string>
#include<queue>
#include<stack>
namespace std {

class Calculation {

public:
	queue<string> str;  //������ַ�����
	queue<string> suff; //��׺���ʽ����
	stack<int> num;  //��������ջ
	stack<string> oper;  //�����ջ
	int resu = 0; //�ݴ�������

	Calculation(queue<string> theQueue);
	void trans(queue<string> str); //ת��Ϊ��׺���ʽ
	int calcu();  //�����׺���ʽ
};

}

#endif
