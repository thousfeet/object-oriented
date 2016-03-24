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
#include<queue>
#include<cctype>
#include"Scan.h"
#include"Print.h"
using namespace std;

bool check(string s);  //�����������ָ���

int main()
{
	string input;
	cin >> input;

	//����λ������10ʱ����
	if(check(input))
	{
		cout << "Error!" << endl;
		return 0;
	}

	//����λ��������10ʱ�����ַ���
	else
	{
	Scan scan;  //����Scan����
	Print print;  //����Print����

	queue<string> q = scan.ToStringQueue(input);  //����ToStringQueue()������ȡĿ�����
	print.PrintQueue(q);  //����PrintQueue()����������и�Ԫ��

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



