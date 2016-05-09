 /************************************************************
  FileName: Main.cpp
  Project: Calculator
  Author: thousfeet
  Date: 2016.03.23
  Description:
      1.��Ϊ��������ڡ�
   	  2.����������жϣ�
    	1�� ����������ֳ���10λ������С��λ��ʱ������
    	2�� �ܹ���������10λ������ʵ��
  Function List:
      int main(int argc, char* argv[])
 ***********************************************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<cctype>
#include <fstream>
#include"Scan.h"
#include"Calculation.h"
#include"Print.h"
using namespace std;


int main(int argc, char* argv[])
{

	Scan *scan = new Scan();  //����Scan����

	//---------����λ������10ʱ����----------
	//------------��������ʼ-------------
	if(scan->check(argv[argc-1]))
	{
		cout << "Error!" << endl;
		return 0;
	}
	//------------�����������-------------
	//--------------------------------------



	//------����λ��������10ʱ�����ַ���-------
	//---------------����ʼ-----------------
	else
	{

	//--------������ʽ��ʼ--------
	string read;
	bool flag1 = false,flag2 = false,flag3 = false;

	//������-a
	if(strcmp(argv[1],"-a") == 0)
	{
		read = argv[2];
		flag2 = true;
	}
	//������-f
	else if(strcmp(argv[1],"-f") == 0)
	{
		flag3 = true;
	}
	//��ָ�����Ͳ���
	else
	{
		read = argv[1];
		flag1= true;
	}
	//--------������ʽ����--------


	//-----------���㿪ʼ-----------
	double theResult;
	Print *print = new Print(); //����Print����

	queue<string> q;


	//��д�ļ���ʽ�������
	if(flag3)
	{
		ifstream fin(argv[2]);
		while(!fin.eof())
		{
			getline(fin,read,'\n');

			q = scan->ToStringQueue(read);  //��ȡĿ�����
			cout << read<<endl;
			Calculation *calculation = new Calculation(q);  //����Calculation����
			calculation->trans(q);  //ת��Ϊ��׺���ʽ
			theResult = calculation->calcu();
			cout << theResult<<endl;
			print->fPrint(argv[3],theResult);//������

			delete(calculation);
		}

		fin.close();
	}

	//ֱ�Ӵ�ӡ���
	else
	{
		q = scan->ToStringQueue(read);  //��ȡĿ�����
		Calculation *calculation = new Calculation(q);  //����Calculation����
		calculation->trans(q);  //ת��Ϊ��׺���ʽ
		theResult = calculation->calcu();


		//ֱ�����������
		if(flag1)
		{
			print->nPrint(theResult);
		}
		//������ʽ��������
		else if(flag2)
		{
			print->aPrint(argv[2],theResult);
		}
		delete(calculation);
	}

	delete(scan);


	//-----------�������-----------

	return 0;
	//---------------�������-----------------
	//----------------------------------------
	}

}





