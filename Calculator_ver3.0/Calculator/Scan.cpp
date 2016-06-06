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
     ¼ì²éÊäÈëµÄÊı×Ö¸öÊı
  Input: String s ±»¼ì²éµÄ×Ö·û´®
  Output: ÎŞ
  Return: Èô×Ö·û´®ÖĞÊı×Ö³¬¹ı10Î»£¬·µ»Øtrue£»ÈôÎ´³¬¹ı
     Ôò·µ»Øfalse
*************************************************/
bool Scan::check(string s)
{
	int num = 0;
	bool flag = false;

	for(int i = 0; i < s.size(); i++)
	{

		//ÈôÎª²»ÎªĞ¡ÊıµãµÄ·ÇÊı×Ö×Ö·û
		if( !isdigit(s[i]) && s[i] != '.')
		{
			num = 0;
		}

		//ÈôÎªÊı×Ö×Ö·û»òĞ¡Êıµã
		else if( isdigit(s[i]) || '.')
		{
			num++;

			if(s[i] == '.')
			{
				flag = true;
			}

			//ÓĞĞ¡ÊıÎ»
			if(num > 11 && flag)
			{
				return true;
			}

			//ÎŞĞ¡ÊıÎ»
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
     ½ÓÊÕÒ»¸öËÄÔòÔËËã±í´ïÊ½£¨¼´input£©£¬Öğ¸ö×Ö·ûÉ¨ÃèÕâ
     ¸ö±í´ïÊ½£¬½«Êı×ÖºÍ·ûºÅÌáÈ¡³öÀ´£¬µÃµ½Ò»×éstring
  Input: String input ±»É¨ÃèµÄ×Ö·û´®
  Output: ÎŞ
  Return: queue<string> ×ª»»Ö®ºóµÄstring
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
	//³õÊ¼»¯
	m_sInput = input;
	while(StrQueue.size())
		StrQueue.pop();

	//±éÀúinputµÄÃ¿¸ö×Ö·û
	for(int i = 0; i  <m_sInput.size(); i++)
	{
		 //ÈôÎª²»ÎªĞ¡ÊıµãµÄ·ÇÊı×Ö×Ö·û
		if( !isdigit(m_sInput[i]) && m_sInput[i] != '.')
		{
			if(!temp.empty())
			{
				StrQueue.push(temp);  //Ôİ´æ×Ö·û´®·Ç¿ÕÔòÈë¶Ó
			}
			temp.clear();  //Èë¶ÓºóÇå³ıÔİ´æ×Ö·û´®

			temp = m_sInput[i];   //µ±Ç°·ûºÅÈë¶Ó
			if(!temp.empty())
			{
				StrQueue.push(temp);
			}
			temp.clear();
		}

		//ÈôÎªÊı×Ö×Ö·û»òĞ¡Êıµã
		else if( isdigit(m_sInput[i]) || '.')
		{
			temp += m_sInput[i];   //µ±Ç°Êı×Ö»òĞ¡Êıµã¸úÓÚÔİ´æ×Ö·û´®Ä©
			continue;
		}

	}

	//±éÀúÍê³ÉºóÔİ´æ×Ö·û´®·Ç¿ÕÔòÈë¶Ó
	if(!temp.empty())
	{
		StrQueue.push(temp);
	}

	temp.clear();

	return StrQueue;  //·µ»Ø´Ë¶ÓÁĞ
}

=======
 Description:
    æ£€æŸ¥è¾“å…¥çš„æ•°å­—ä¸ªæ•°
 Input: String s è¢«æ£€æŸ¥çš„å­—ç¬¦ä¸²
 Output: æ— 
 Return: è‹¥å­—ç¬¦ä¸²ä¸­æ•°å­—è¶…è¿‡10ä½ï¼Œè¿”å›trueï¼›è‹¥æœªè¶…è¿‡
    åˆ™è¿”å›false
*************************************************/
bool Scan::check(string s)
{
   int num = 0;
   bool flag = false;

   for(int i = 0; i < s.size(); i++)
   {

       //è‹¥ä¸ºä¸ä¸ºå°æ•°ç‚¹çš„éæ•°å­—å­—ç¬¦
       if( !isdigit(s[i]) && s[i] != '.')
       {
           num = 0;
       }

       //è‹¥ä¸ºæ•°å­—å­—ç¬¦æˆ–å°æ•°ç‚¹
       else if( isdigit(s[i]) || '.')
       {
           num++;

           if(s[i] == '.')
           {
               flag = true;
           }

           //æœ‰å°æ•°ä½
           if(num > 11 && flag)
           {
               return true;
           }

           //æ— å°æ•°ä½
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
    æ¥æ”¶ä¸€ä¸ªå››åˆ™è¿ç®—è¡¨è¾¾å¼ï¼ˆå³inputï¼‰ï¼Œé€ä¸ªå­—ç¬¦æ‰«æè¿™
    ä¸ªè¡¨è¾¾å¼ï¼Œå°†æ•°å­—å’Œç¬¦å·æå–å‡ºæ¥ï¼Œå¾—åˆ°ä¸€ç»„string
 Input: String input è¢«æ‰«æçš„å­—ç¬¦ä¸²
 Output: æ— 
 Return: queue<string> è½¬æ¢ä¹‹åçš„string
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
   //åˆå§‹åŒ–
   m_sInput = input;
   while(StrQueue.size())
       StrQueue.pop();

   //éå†inputçš„æ¯ä¸ªå­—ç¬¦
   for(int i = 0; i  <m_sInput.size(); i++)
   {
        //è‹¥ä¸ºä¸ä¸ºå°æ•°ç‚¹çš„éæ•°å­—å­—ç¬¦
       if( !isdigit(m_sInput[i]) && m_sInput[i] != '.')
       {
           if(!temp.empty())
           {
               StrQueue.push(temp);  //æš‚å­˜å­—ç¬¦ä¸²éç©ºåˆ™å…¥é˜Ÿ
           }
           temp.clear();  //å…¥é˜Ÿåæ¸…é™¤æš‚å­˜å­—ç¬¦ä¸²

           temp = m_sInput[i];   //å½“å‰ç¬¦å·å…¥é˜Ÿ
           if(!temp.empty())
           {
               StrQueue.push(temp);
           }
           temp.clear();
       }

       //è‹¥ä¸ºæ•°å­—å­—ç¬¦æˆ–å°æ•°ç‚¹
       else if( isdigit(m_sInput[i]) || '.')
       {
           temp += m_sInput[i];   //å½“å‰æ•°å­—æˆ–å°æ•°ç‚¹è·Ÿäºæš‚å­˜å­—ç¬¦ä¸²æœ«
           continue;
       }

   }

   //éå†å®Œæˆåæš‚å­˜å­—ç¬¦ä¸²éç©ºåˆ™å…¥é˜Ÿ
   if(!temp.empty())
   {
       StrQueue.push(temp);
   }

   temp.clear();

   return StrQueue;  //è¿”å›æ­¤é˜Ÿåˆ—
}
>>>>>>> ver_3.0
