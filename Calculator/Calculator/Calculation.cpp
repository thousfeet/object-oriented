<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Calculation.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	Calculation(queue<string> theQueue);
	void trans(queue<string> str);
	double calcu();
 ***********************************************************/
=======
/************************************************************
 FileName: Calculation.cpp
 Author: thousfeet
 Date: 2016.03.23
 Function List:
   Calculation(queue<string> theQueue);
   void trans(queue<string> str);
   double calcu();
***********************************************************/
>>>>>>> ver_3.0

#include "Calculation.h"
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<sstream>
#include<iostream>

namespace std {


Calculation::Calculation(queue<string> theQueue)
{
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
	str = theQueue;
}

/*************************************************
  Description:
     ½«ÖĞ×º±í´ïÊ½×ª»¯Îªºó×º±í´ïÊ½
  Input: queue<string> str ×ª»¯Ç°µÄÖĞ×º±í´ïÊ½¶ÓÁĞ
  Output: ÎŞ
  Return: ÎŞ
*************************************************/
void Calculation::trans(queue<string> str)
{
	string temp = "";
	temp = str.front();

	if(temp == "-")
	{
		minus++;

		str.pop();
		//ÌØÅĞµÚÒ»¸ö¸ºÊı
		if(isdigit(str.front()[0]))
		{
			suff.push(str.front());
			str.pop();
			suff.push(temp);
		}
		//-()µÄÇé¿ö
		else
		{
			//±ê¼ÇÎª-<)
			str.front() = "<";
			oper.push(temp);
		}
	}

	//±éÀúÖĞ×º±í´ïÊ½¶ÓÁĞ
	bool flag = true;
	bool isminus = true;

	while(!str.empty())
	{
		flag = true;
		//¶ÁÈ¡¶ÓÁĞµÚÒ»¸öÔªËØ
		temp = str.front();
		//ÈôÊÇ£¨£¬Ö±½ÓÈëÕ»
		if(temp == "(" || temp == "<")
		{
			oper.push(temp);
			str.pop();
			if(isdigit(str.front()[0]))
			{
				isminus = false; //²»ÊÇ¸ºÊı
			}
			flag = false;
		}
		//ÈôÊÇ*»ò/£¬Ö±½ÓÈëÕ»
		if(temp == "*"||temp == "/")
		{
			oper.push(temp);
		}
		//ÈôÊÇ+£¬ÅĞ¶ÏÕ»¶¥ÔªËØ£¬ÈôµÍÓÚÕ»¶¥ÔªËØÓÅÏÈ¼¶£¬ÔòÕ»¶¥ÔªËØ³öÕ»ºó¸ÃÔªËØÈëÕ»£»·ñÔòÖ±½ÓÈëÕ»
		if(temp == "+")
		{
			//¿¼ÂÇµ½¸ºÊıÇé¿ö£¬ËùÒÔÏÈ×ö¼õ·¨
			while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
			{
				suff.push(oper.top());  //½øÈëºó×ºÔËËã±í´ïÊ½¶ÓÁĞ
				oper.pop();  //µ¯³öÕ»¶¥ÔªËØ
			}
			oper.push(temp);  //µ±Ç°ÔªËØÈëÕ»

		}
		//ÈôÊÇ-
		if(temp == "-")
		{
			minus++;

			//À¨ºÅÄÚÓĞ¸ººÅµÄÇé¿ö
			if(!oper.empty() && oper.top() == "(")
			{
				//¸ºÊı
				if(isminus)
				{
					str.pop(); //µ¯³ö-ºÅ
					suff.push("0"); //0Èë¶ÓÁĞ
					suff.push(str.front()); //´Ë¸ºÊıÊıÖµÈë¶ÓÁĞ
					suff.push(temp); //-ºÅÈë¶ÓÁĞ
				}
				//-()
				else
				{
					oper.push(temp);
				}
			}
			//¸Ã-ºÅÎª¼õ·¨·ûºÅ
			else
			{
				//Èô-µÍÓÚÕ»¶¥ÔªËØÓÅÏÈ¼¶£¬ÔòÕ»¶¥ÔªËØ³öÕ»ºó¸ÃÔªËØÈëÕ»£»·ñÔòÖ±½ÓÈëÕ»
				while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
				{
					suff.push(oper.top());  //½øÈëºó×ºÔËËã±í´ïÊ½¶ÓÁĞ
					oper.pop();  //µ¯³öÕ»¶¥ÔªËØ
				}
				oper.push(temp);  //µ±Ç°ÔªËØÈëÕ»

			}
		}
		//ÈôÊÇ£©£¬ÔòÒÀ´Îµ¯³öÕ»¶¥ÔªËØÖ±µ½Óöµ½£¨
		if(temp == ")")
		{

			while(oper.top()!="(" && oper.top()!="<")
			{
				suff.push(oper.top());
				oper.pop();
			}

			if(oper.top() == "<")
			{
				oper.pop();//µ¯³ö<
				suff.push(oper.top());//-ºÅÈë¶ÓÁĞ
			}

			oper.pop();

			isminus = true;

		}
		//ÈôÊÇÔËËãÊı×Ö£¬ÔòÈë¶ÓÁĞ
		else if(isdigit(temp[0]))
		{
			suff.push(temp);
		}

		if(flag)
		{
			str.pop();
		}
	}
	while(!oper.empty())
	{
		suff.push(oper.top());
		oper.pop();
	}
=======
   str = theQueue;
}

/*************************************************
 Description:
    å°†ä¸­ç¼€è¡¨è¾¾å¼è½¬åŒ–ä¸ºåç¼€è¡¨è¾¾å¼
 Input: queue<string> str è½¬åŒ–å‰çš„ä¸­ç¼€è¡¨è¾¾å¼é˜Ÿåˆ—
 Output: æ— 
 Return: æ— 
*************************************************/
void Calculation::trans(queue<string> str)
{
   string temp = "";
   temp = str.front();

   if(temp == "-")
   {
       minus++;

       str.pop();
       //ç‰¹åˆ¤ç¬¬ä¸€ä¸ªè´Ÿæ•°
       if(isdigit(str.front()[0]))
       {
           suff.push(str.front());
           str.pop();
           suff.push(temp);
       }
       //-()çš„æƒ…å†µ
       else
       {
           //æ ‡è®°ä¸º-<)
           str.front() = "<";
           oper.push(temp);
       }
   }

   //éå†ä¸­ç¼€è¡¨è¾¾å¼é˜Ÿåˆ—
   bool flag = true;
   bool isminus = true;

   while(!str.empty())
   {
       flag = true;
       //è¯»å–é˜Ÿåˆ—ç¬¬ä¸€ä¸ªå…ƒç´ 
       temp = str.front();
       //è‹¥æ˜¯ï¼ˆï¼Œç›´æ¥å…¥æ ˆ
       if(temp == "(" || temp == "<")
       {
           oper.push(temp);
           str.pop();
           if(isdigit(str.front()[0]))
           {
               isminus = false; //ä¸æ˜¯è´Ÿæ•°
           }
           flag = false;
       }
       //è‹¥æ˜¯*æˆ–/ï¼Œç›´æ¥å…¥æ ˆ
       if(temp == "*"||temp == "/")
       {
           oper.push(temp);
       }
       //è‹¥æ˜¯+ï¼Œåˆ¤æ–­æ ˆé¡¶å…ƒç´ ï¼Œè‹¥ä½äºæ ˆé¡¶å…ƒç´ ä¼˜å…ˆçº§ï¼Œåˆ™æ ˆé¡¶å…ƒç´ å‡ºæ ˆåè¯¥å…ƒç´ å…¥æ ˆï¼›å¦åˆ™ç›´æ¥å…¥æ ˆ
       if(temp == "+")
       {
           //è€ƒè™‘åˆ°è´Ÿæ•°æƒ…å†µï¼Œæ‰€ä»¥å…ˆåšå‡æ³•
           while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"||oper.top() == "-"))
           {
               suff.push(oper.top());  //è¿›å…¥åç¼€è¿ç®—è¡¨è¾¾å¼é˜Ÿåˆ—
               oper.pop();  //å¼¹å‡ºæ ˆé¡¶å…ƒç´ 
           }
           oper.push(temp);  //å½“å‰å…ƒç´ å…¥æ ˆ

       }
       //è‹¥æ˜¯-
       if(temp == "-")
       {
           minus++;

           //æ‹¬å·å†…æœ‰è´Ÿå·çš„æƒ…å†µ
           if(!oper.empty() && oper.top() == "(")
           {
               //è´Ÿæ•°
               if(isminus)
               {
                   str.pop(); //å¼¹å‡º-å·
                   suff.push("0"); //0å…¥é˜Ÿåˆ—
                   suff.push(str.front()); //æ­¤è´Ÿæ•°æ•°å€¼å…¥é˜Ÿåˆ—
                   suff.push(temp); //-å·å…¥é˜Ÿåˆ—
               }
               //-()
               else
               {
                   oper.push(temp);
               }
           }
           //è¯¥-å·ä¸ºå‡æ³•ç¬¦å·
           else
           {
               //è‹¥-ä½äºæ ˆé¡¶å…ƒç´ ä¼˜å…ˆçº§ï¼Œåˆ™æ ˆé¡¶å…ƒç´ å‡ºæ ˆåè¯¥å…ƒç´ å…¥æ ˆï¼›å¦åˆ™ç›´æ¥å…¥æ ˆ
               while(!oper.empty()&&(oper.top() == "*"||oper.top() == "/"))
               {
                   suff.push(oper.top());  //è¿›å…¥åç¼€è¿ç®—è¡¨è¾¾å¼é˜Ÿåˆ—
                   oper.pop();  //å¼¹å‡ºæ ˆé¡¶å…ƒç´ 
               }
               oper.push(temp);  //å½“å‰å…ƒç´ å…¥æ ˆ

           }
       }
       //è‹¥æ˜¯ï¼‰ï¼Œåˆ™ä¾æ¬¡å¼¹å‡ºæ ˆé¡¶å…ƒç´ ç›´åˆ°é‡åˆ°ï¼ˆ
       if(temp == ")")
       {

           while(oper.top()!="(" && oper.top()!="<")
           {
               suff.push(oper.top());
               oper.pop();
           }

           if(oper.top() == "<")
           {
               oper.pop();//å¼¹å‡º<
               suff.push(oper.top());//-å·å…¥é˜Ÿåˆ—
           }

           oper.pop();

           isminus = true;

       }
       //è‹¥æ˜¯è¿ç®—æ•°å­—ï¼Œåˆ™å…¥é˜Ÿåˆ—
       else if(isdigit(temp[0]))
       {
           suff.push(temp);
       }

       if(flag)
       {
           str.pop();
       }
   }
   while(!oper.empty())
   {
       suff.push(oper.top());
       oper.pop();
   }
>>>>>>> ver_3.0
}


/*************************************************
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
  Description:
     ¼ÆËãºó×º±í´ïÊ½µÃµ½×îÖÕ¼ÆËã½á¹û
  Input: ÎŞ
  Output: ÎŞ
  Return: num.top ±í´ïÊ½µÄ¼ÆËã½á¹û
*************************************************/
double Calculation::calcu()
{
	while(minus--)
	{
		num.push(resu); //½«0Ñ¹ÈëÕ»£¬ÓÃÒÔ´¦Àí¸ºÊı
	}

	stringstream ss;
	double tempnum;

	while(!suff.empty())
	{
		string temp = suff.front();

		//¶ÔÕ»¶¥ÔªËØ½øĞĞ¶ÔÓ¦²Ù×÷ÔËËã£¬ÔËËã½á¹ûÈëÕ»
		if(temp == "+")
		{
			resu = num.top();
			num.pop();
			resu += num.top();
			num.pop();
			num.push(resu);
		}
		if(temp == "-")
		{
			resu = num.top();
			num.pop();
			resu = num.top() - resu;
			num.pop();
			num.push(resu);
		}
		if(temp == "*")
		{
			resu = num.top();
			num.pop();
			resu *= num.top();
			num.pop();
			num.push(resu);
		}
		if(temp == "/")
		{
			resu = num.top();
			if(resu == 0)
			{
				cout << "ÅİÅİËµ³ıÊı²»ÄÜÎª0"<<endl;
				return 0;
			}
			else
			{
				num.pop();
				resu = num.top() / resu;
				num.pop();
				num.push(resu);
			}
		}
		//ÈôÎªÊı×Ö×Ö·û´®£¬Ôò×ª»¯ÎªÊı×ÖºóÈëÕ»
		else if(isdigit(temp[0]))
		{
			ss << suff.front();
			ss >> tempnum;
			num.push(tempnum);
			ss.clear();
			ss.str("");
		}
		suff.pop();
	}


	return num.top();
=======
 Description:
    è®¡ç®—åç¼€è¡¨è¾¾å¼å¾—åˆ°æœ€ç»ˆè®¡ç®—ç»“æœ
 Input: æ— 
 Output: æ— 
 Return: num.top è¡¨è¾¾å¼çš„è®¡ç®—ç»“æœ
*************************************************/
double Calculation::calcu()
{
   while(minus--)
   {
       num.push(resu); //å°†0å‹å…¥æ ˆï¼Œç”¨ä»¥å¤„ç†è´Ÿæ•°
   }

   stringstream ss;
   double tempnum;

   while(!suff.empty())
   {
       string temp = suff.front();

       //å¯¹æ ˆé¡¶å…ƒç´ è¿›è¡Œå¯¹åº”æ“ä½œè¿ç®—ï¼Œè¿ç®—ç»“æœå…¥æ ˆ
       if(temp == "+")
       {
           resu = num.top();
           num.pop();
           resu += num.top();
           num.pop();
           num.push(resu);
       }
       if(temp == "-")
       {
           resu = num.top();
           num.pop();
           resu = num.top() - resu;
           num.pop();
           num.push(resu);
       }
       if(temp == "*")
       {
           resu = num.top();
           num.pop();
           resu *= num.top();
           num.pop();
           num.push(resu);
       }
       if(temp == "/")
       {
           resu = num.top();
           if(resu == 0)
           {
               cout << "æ³¡æ³¡è¯´é™¤æ•°ä¸èƒ½ä¸º0"<<endl;
               return 0;
           }
           else
           {
               num.pop();
               resu = num.top() / resu;
               num.pop();
               num.push(resu);
           }
       }
       //è‹¥ä¸ºæ•°å­—å­—ç¬¦ä¸²ï¼Œåˆ™è½¬åŒ–ä¸ºæ•°å­—åå…¥æ ˆ
       else if(isdigit(temp[0]))
       {
           ss << suff.front();
           ss >> tempnum;
           num.push(tempnum);
           ss.clear();
           ss.str("");
       }
       suff.pop();
   }


   return num.top();
>>>>>>> ver_3.0
}

}

<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2

=======
>>>>>>> ver_3.0
