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
	string temp = "";  	     //Ôİ´æÕıÔÚ´¦ÀíµÄ×Ö·û´®
	queue<string> StrQueue;  //´æ´¢×Ö·ûµÄ¶ÓÁĞ
=======
   queue<string> ToStringQueue(string input);
   bool check(string s);

private:
   string m_sInput;
   string temp = "";  	     //æš‚å­˜æ­£åœ¨å¤„ç†çš„å­—ç¬¦ä¸²
   queue<string> StrQueue;  //å­˜å‚¨å­—ç¬¦çš„é˜Ÿåˆ—
>>>>>>> ver_3.0

};

#endif
