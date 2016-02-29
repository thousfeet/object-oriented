#include<iostream>
#include<queue>
#include "Print.h"
using namespace std;

void Print::PrintQueue(queue<string> theQueue)
{
	/*
	 * 发现queue没有迭代器
	queue<string>::iterator itor = theQueue.front();
	for(;itor!=theQueue.end();itor++)
	{
		cout << *itor <<endl;
	}
	*/
	int len = theQueue.size();             //记录弹出元素前的队列长度
	for(int i = 0;i < len;i++)             //输出队首元素后弹出 直到输出len个元素
	{
		cout << theQueue.front() <<endl;
		theQueue.pop();
	}
}
