 /************************************************************
  FileName: Print.h
  Author: thousfeet
  Date: 2016.05.03
  Function List:

 ***********************************************************/

#ifndef PRINT_H_
#define PRINT_H_

#include<string>
#include<cstring>
#include<queue>
#include"Calculation.h"

using namespace std;

class Print {

public:
	void nPrint(double re);
	void aPrint(string s,double re);
	void fPrint(char *s,double re);

};


#endif /* PRINT_H_ */
