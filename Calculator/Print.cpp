 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	  ������õ��Ķ��У�ÿ���һ����һ�С�
 ***********************************************************/
#include<iostream>
#include<queue>
#include "Print.h"
using namespace std;

void Print::PrintQueue(queue<string> theQueue)
{

	int len = theQueue.size();  //��¼����Ԫ��ǰ�Ķ��г���

	//�������Ԫ�غ󵯳� ֱ�����len��Ԫ��
	for(int i = 0; i < len; i++)
	{
		cout << theQueue.front() <<endl;
		theQueue.pop();
	}

}
