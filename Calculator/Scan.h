<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Scan.h
  Author: thousfeet
  Date: 2016.03.23
  Function List:
     queue<string> ToStringQueue(string input);
	 bool check(string s);
 ***********************************************************/
=======
/************************************************************
 FileName: Scan.h
 Author: thousfeet
 Date: 2016.03.23
 Function List:
    queue<string> ToStringQueue(string input);
    bool check(string s);
***********************************************************/
>>>>>>> ver_3.0
#ifndef SCAN_H_
#define SCAN_H_

#include<queue>
#include<string>
using namespace std;

class Scan
{

public:
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
	queue<string> ToStringQueue(string input);
	bool check(string s);

private:
	string m_sInput;
	string temp = "";  	     //�ݴ����ڴ�����ַ���
	queue<string> StrQueue;  //�洢�ַ��Ķ���
=======
   queue<string> ToStringQueue(string input);
   bool check(string s);

private:
   string m_sInput;
   string temp = "";  	     //暂存正在处理的字符串
   queue<string> StrQueue;  //存储字符的队列
>>>>>>> ver_3.0

};

#endif
