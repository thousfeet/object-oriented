#include<iostream>
#include<queue>
#include "Print.h"
using namespace std;

void Print::PrintQueue(queue<string> theQueue)
{
	/*
	 * ����queueû�е�����
	queue<string>::iterator itor = theQueue.front();
	for(;itor!=theQueue.end();itor++)
	{
		cout << *itor <<endl;
	}
	*/
	int len = theQueue.size();             //��¼����Ԫ��ǰ�Ķ��г���
	for(int i = 0;i < len;i++)             //�������Ԫ�غ󵯳� ֱ�����len��Ԫ��
	{
		cout << theQueue.front() <<endl;
		theQueue.pop();
	}
}
