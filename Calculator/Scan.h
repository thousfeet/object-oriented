 /************************************************************
  FileName: Scan.h
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	  定义Scan类。
 ***********************************************************/
#ifndef SCAN_H_
#define SCAN_H_

#include<queue>
#include<string>
using namespace std;

class Scan
{

public:
	queue<string> ToStringQueue(string input);

private:
	string m_sInput;
	string temp = "";  	     //暂存正在处理的字符串
	queue<string> StrQueue;  //存储字符的队列

};

#endif
