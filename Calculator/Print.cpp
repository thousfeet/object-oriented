 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	  输出所得到的队列，每输出一个换一行。
 ***********************************************************/
#include<iostream>
#include<queue>
#include "Print.h"
using namespace std;

void Print::PrintQueue(queue<string> theQueue)
{

	int len = theQueue.size();  //记录弹出元素前的队列长度

	//输出队首元素后弹出 直到输出len个元素
	for(int i = 0; i < len; i++)
	{
		cout << theQueue.front() <<endl;
		theQueue.pop();
	}

}
