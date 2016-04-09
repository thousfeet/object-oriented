 /************************************************************
  FileName: Main.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	  1.��Ϊ��������ڡ�
   	  2.����������жϣ�
    	1�� ����������ֳ���10λ������С��λ��ʱ������
    	2�� �ܹ���������10λ������ʵ��
 ***********************************************************/
#include<iostream>
#include<cstdio>
#include<string>
#include<string.h>
#include<queue>
#include<cctype>
#include"Scan.h"
#include"Calculation.h"
using namespace std;

bool check(string s);  //�����������ָ���

int main(int argc, char* argv[])
{

	//����λ������10ʱ����
	if(check(argv[argc-1]))
	{
		cout << "Error!" << endl;
		return 0;
	}

	//����λ��������10ʱ�����ַ���
	else
	{
	Scan scan;  //����Scan����

//	if(strcmp(argv[1],"-a") == 0)
//	{
//		cout << argv[argc-1]<<"= ";
//	}
//	queue<string> q = scan.ToStringQueue(argv[argc-1]);  //��ȡĿ�����

	string in;
	cin >> in;
	queue<string> q = scan.ToStringQueue(in);

	Calculation *calculation = new Calculation(q);  //����Calculation����
	calculation->trans(q);  //ת��Ϊ��׺���ʽ
	cout << calculation->calcu();  //�ó�������
	delete(calculation);

	return 0;
	}
}


bool check(string s)
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


