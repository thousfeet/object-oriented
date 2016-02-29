#include<iostream>
#include<string>
#include<cctype>
#include<queue>
#include "Scan.h"
using namespace std;


queue<string> Scan::ToStringQueue(string input)
{
	m_sInput = input;

	for(int i=0;i<m_sInput.size();i++)                            //遍历input的每个字符
			{
				if(!isdigit(m_sInput[i])&&m_sInput[i]!='.')       //若为不为小数点的非数字字符
				{
					if(!temp.empty())
						StrQueue.push(temp);                      //暂存字符串非空则入队
					temp.clear();                                 //入队后清除暂存字符串

					temp = m_sInput[i];                           //当前符号入队
					if(!temp.empty())
						StrQueue.push(temp);
					temp.clear();
				}
				else if(isdigit(m_sInput[i])||'.')                 //若为数字字符或小数点
				{
					temp += m_sInput[i];                           //当前数字或小数点跟于暂存字符串末
					continue;
				}
			}
	if(!temp.empty())
	{
		StrQueue.push(temp);                                        //遍历完成后暂存字符串非空则入队
	}

	return StrQueue;                                                //返回此队列
}


