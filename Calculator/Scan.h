 /************************************************************
  FileName: Scan.h
  Author: thousfeet
  Date: 2016.03.23
  Function List:
     queue<string> ToStringQueue(string input);
	 bool check(string s);
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
	bool check(string s);

private:
	string m_sInput;
	string temp = "";  	     //�ݴ����ڴ�����ַ���
	queue<string> StrQueue;  //�洢�ַ��Ķ���

};

#endif
