<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	 queue<string> ToStringQueue(string input);
	 bool check(string s);
 ***********************************************************/
=======
/************************************************************
 FileName: Print.cpp
 Author: thousfeet
 Date: 2016.03.23
 Function List:
    queue<string> ToStringQueue(string input);
    bool check(string s);
***********************************************************/
>>>>>>> ver_3.0
#include<iostream>
#include<string>
#include<cctype>
#include<queue>
#include "Scan.h"
using namespace std;


/*************************************************
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
  Description:
     �����������ָ���
  Input: String s �������ַ���
  Output: ��
  Return: ���ַ��������ֳ���10λ������true����δ����
     �򷵻�false
*************************************************/
bool Scan::check(string s)
{
	int num = 0;
	bool flag = false;

	for(int i = 0; i < s.size(); i++)
	{

		//��Ϊ��ΪС����ķ������ַ�
		if( !isdigit(s[i]) && s[i] != '.')
		{
			num = 0;
		}

		//��Ϊ�����ַ���С����
		else if( isdigit(s[i]) || '.')
		{
			num++;

			if(s[i] == '.')
			{
				flag = true;
			}

			//��С��λ
			if(num > 11 && flag)
			{
				return true;
			}

			//��С��λ
			else if(num > 10 && !flag)
			{
				return true;
			}
		}

	}
	return false;
}

/*************************************************
  Description:
     ����һ������������ʽ����input��������ַ�ɨ����
     �����ʽ�������ֺͷ�����ȡ�������õ�һ��string
  Input: String input ��ɨ����ַ���
  Output: ��
  Return: queue<string> ת��֮���string
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
	//��ʼ��
	m_sInput = input;
	while(StrQueue.size())
		StrQueue.pop();

	//����input��ÿ���ַ�
	for(int i = 0; i  <m_sInput.size(); i++)
	{
		 //��Ϊ��ΪС����ķ������ַ�
		if( !isdigit(m_sInput[i]) && m_sInput[i] != '.')
		{
			if(!temp.empty())
			{
				StrQueue.push(temp);  //�ݴ��ַ����ǿ������
			}
			temp.clear();  //��Ӻ�����ݴ��ַ���

			temp = m_sInput[i];   //��ǰ�������
			if(!temp.empty())
			{
				StrQueue.push(temp);
			}
			temp.clear();
		}

		//��Ϊ�����ַ���С����
		else if( isdigit(m_sInput[i]) || '.')
		{
			temp += m_sInput[i];   //��ǰ���ֻ�С��������ݴ��ַ���ĩ
			continue;
		}

	}

	//������ɺ��ݴ��ַ����ǿ������
	if(!temp.empty())
	{
		StrQueue.push(temp);
	}

	temp.clear();

	return StrQueue;  //���ش˶���
}

=======
 Description:
    检查输入的数字个数
 Input: String s 被检查的字符串
 Output: 无
 Return: 若字符串中数字超过10位，返回true；若未超过
    则返回false
*************************************************/
bool Scan::check(string s)
{
   int num = 0;
   bool flag = false;

   for(int i = 0; i < s.size(); i++)
   {

       //若为不为小数点的非数字字符
       if( !isdigit(s[i]) && s[i] != '.')
       {
           num = 0;
       }

       //若为数字字符或小数点
       else if( isdigit(s[i]) || '.')
       {
           num++;

           if(s[i] == '.')
           {
               flag = true;
           }

           //有小数位
           if(num > 11 && flag)
           {
               return true;
           }

           //无小数位
           else if(num > 10 && !flag)
           {
               return true;
           }
       }

   }
   return false;
}

/*************************************************
 Description:
    接收一个四则运算表达式（即input），逐个字符扫描这
    个表达式，将数字和符号提取出来，得到一组string
 Input: String input 被扫描的字符串
 Output: 无
 Return: queue<string> 转换之后的string
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
   //初始化
   m_sInput = input;
   while(StrQueue.size())
       StrQueue.pop();

   //遍历input的每个字符
   for(int i = 0; i  <m_sInput.size(); i++)
   {
        //若为不为小数点的非数字字符
       if( !isdigit(m_sInput[i]) && m_sInput[i] != '.')
       {
           if(!temp.empty())
           {
               StrQueue.push(temp);  //暂存字符串非空则入队
           }
           temp.clear();  //入队后清除暂存字符串

           temp = m_sInput[i];   //当前符号入队
           if(!temp.empty())
           {
               StrQueue.push(temp);
           }
           temp.clear();
       }

       //若为数字字符或小数点
       else if( isdigit(m_sInput[i]) || '.')
       {
           temp += m_sInput[i];   //当前数字或小数点跟于暂存字符串末
           continue;
       }

   }

   //遍历完成后暂存字符串非空则入队
   if(!temp.empty())
   {
       StrQueue.push(temp);
   }

   temp.clear();

   return StrQueue;  //返回此队列
}
>>>>>>> ver_3.0
