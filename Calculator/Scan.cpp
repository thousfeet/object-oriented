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

=======
 Description:
    妫�鏌ヨ緭鍏ョ殑鏁板瓧涓暟
 Input: String s 琚鏌ョ殑瀛楃涓�
 Output: 鏃�
 Return: 鑻ュ瓧绗︿覆涓暟瀛楄秴杩�10浣嶏紝杩斿洖true锛涜嫢鏈秴杩�
    鍒欒繑鍥瀎alse
*************************************************/
bool Scan::check(string s)
{
   int num = 0;
   bool flag = false;

   for(int i = 0; i < s.size(); i++)
   {

       //鑻ヤ负涓嶄负灏忔暟鐐圭殑闈炴暟瀛楀瓧绗�
       if( !isdigit(s[i]) && s[i] != '.')
       {
           num = 0;
       }

       //鑻ヤ负鏁板瓧瀛楃鎴栧皬鏁扮偣
       else if( isdigit(s[i]) || '.')
       {
           num++;

           if(s[i] == '.')
           {
               flag = true;
           }

           //鏈夊皬鏁颁綅
           if(num > 11 && flag)
           {
               return true;
           }

           //鏃犲皬鏁颁綅
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
    鎺ユ敹涓�涓洓鍒欒繍绠楄〃杈惧紡锛堝嵆input锛夛紝閫愪釜瀛楃鎵弿杩�
    涓〃杈惧紡锛屽皢鏁板瓧鍜岀鍙锋彁鍙栧嚭鏉ワ紝寰楀埌涓�缁剆tring
 Input: String input 琚壂鎻忕殑瀛楃涓�
 Output: 鏃�
 Return: queue<string> 杞崲涔嬪悗鐨剆tring
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
   //鍒濆鍖�
   m_sInput = input;
   while(StrQueue.size())
       StrQueue.pop();

   //閬嶅巻input鐨勬瘡涓瓧绗�
   for(int i = 0; i  <m_sInput.size(); i++)
   {
        //鑻ヤ负涓嶄负灏忔暟鐐圭殑闈炴暟瀛楀瓧绗�
       if( !isdigit(m_sInput[i]) && m_sInput[i] != '.')
       {
           if(!temp.empty())
           {
               StrQueue.push(temp);  //鏆傚瓨瀛楃涓查潪绌哄垯鍏ラ槦
           }
           temp.clear();  //鍏ラ槦鍚庢竻闄ゆ殏瀛樺瓧绗︿覆

           temp = m_sInput[i];   //褰撳墠绗﹀彿鍏ラ槦
           if(!temp.empty())
           {
               StrQueue.push(temp);
           }
           temp.clear();
       }

       //鑻ヤ负鏁板瓧瀛楃鎴栧皬鏁扮偣
       else if( isdigit(m_sInput[i]) || '.')
       {
           temp += m_sInput[i];   //褰撳墠鏁板瓧鎴栧皬鏁扮偣璺熶簬鏆傚瓨瀛楃涓叉湯
           continue;
       }

   }

   //閬嶅巻瀹屾垚鍚庢殏瀛樺瓧绗︿覆闈炵┖鍒欏叆闃�
   if(!temp.empty())
   {
       StrQueue.push(temp);
   }

   temp.clear();

   return StrQueue;  //杩斿洖姝ら槦鍒�
}
>>>>>>> ver_3.0
