<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Calculation.h
  Author: thousfeet
  Date: 2016.04.04
  Function List:
   	Calculation(queue<string> theQueue);
	void trans(queue<string> str);
	double calcu();
 ***********************************************************/
=======
/************************************************************
 FileName: Calculation.h
 Author: thousfeet
 Date: 2016.04.04
 Function List:
   Calculation(queue<string> theQueue);
   void trans(queue<string> str);
   double calcu();
***********************************************************/
>>>>>>> ver_3.0
#ifndef CALCULATION_H_
#define CALCULATION_H_

#include<string>
#include<queue>
#include<stack>
namespace std {

class Calculation {

public:
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
	Calculation(queue<string> theQueue);
	void trans(queue<string> str); //×ª»¯Îªºó×º±í´ïÊ½
	double calcu();  //¼ÆËãºó×º±í´ïÊ½

private:
	queue<string> str;  //´«ÈëµÄ×Ö·û¶ÓÁĞ
	queue<string> suff; //ºó×º±í´ïÊ½¶ÓÁĞ
	stack<double> num;  //ÔËËãÊı×ÖÕ»
	stack<string> oper;  //ÔËËã·ûÕ»
	double resu = 0; //Ôİ´æÔËËã½á¹û
	int minus = 0; //¸ººÅ¸öÊı
=======
   Calculation(queue<string> theQueue);
   void trans(queue<string> str); //è½¬åŒ–ä¸ºåç¼€è¡¨è¾¾å¼
   double calcu();  //è®¡ç®—åç¼€è¡¨è¾¾å¼

private:
   queue<string> str;  //ä¼ å…¥çš„å­—ç¬¦é˜Ÿåˆ—
   queue<string> suff; //åç¼€è¡¨è¾¾å¼é˜Ÿåˆ—
   stack<double> num;  //è¿ç®—æ•°å­—æ ˆ
   stack<string> oper;  //è¿ç®—ç¬¦æ ˆ
   double resu = 0; //æš‚å­˜è¿ç®—ç»“æœ
   int minus = 0; //è´Ÿå·ä¸ªæ•°
>>>>>>> ver_3.0

};

}

#endif
