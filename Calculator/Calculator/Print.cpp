<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.05.03
  Function List:

 ***********************************************************/
=======
/************************************************************
 FileName: Print.cpp
 Author: thousfeet
 Date: 2016.05.03
 Function List:

***********************************************************/
>>>>>>> ver_3.0
#include<cstdio>
#include<iostream>
#include <fstream>
#include "Print.h"

using namespace std;

void Print::nPrint(double re)
{
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
	cout << re;
=======
   cout << re;
>>>>>>> ver_3.0
}

void Print::aPrint(string s,double re)
{
<<<<<<< 65557f4a3f3a059bbeefb8e4aa81534f9fbf8ba2
	cout << s <<" "<<re;
}

void Print::fPrint(char *s,double re)
{
	ofstream fout(s,ofstream::app);
	fout << re <<endl;
	fout.close();
=======
   cout << s <<" "<<re;
}

void Print::fPrint(string s,double re)
{
//   ofstream fout(s,ofstream::app);
//   fout << re <<endl;
//   fout.close();
>>>>>>> ver_3.0
}
