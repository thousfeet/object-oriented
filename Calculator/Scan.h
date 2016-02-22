/*
 * Scan类处理输入的字符串。
    函数：ToStringQueue(string input)
    用途：接收一个四则运算表达式（即input），逐个字符扫描这个表达式，将数字和符号提取出来，得到一组string
        例子：对于输入 -100*(20+1) 会得到： -、100 、 * 、 ( 、 20 、 + 、 1 和 ) 。

    return这个队列
 */
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
