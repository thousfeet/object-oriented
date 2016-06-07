 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.05.03
  Function List:

 ***********************************************************/
#include<cstdio>
#include<iostream>
#include <fstream>
#include "Print.h"

using namespace std;

void Print::nPrint(double re)
{
	cout << re;
}

void Print::aPrint(string s,double re)
{
	cout << s <<" "<<re;
}

void Print::fPrint(char *s,double re)
{
	ofstream fout(s,ofstream::app);
	fout << re <<endl;
	fout.close();
}
