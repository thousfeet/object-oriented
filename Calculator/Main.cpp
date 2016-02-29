/*
 *
   ��main�л�ȡ�������� �Լ� ����Scan�����Print����
    ����Scan�����ToStringQueue(string input)�������봫��ȥ�Ի�ȡ���С�
    ���Ž�������д���Print����ķ����У��õ������

    1�� ����������ֳ���10λ������С��λ��ʱ������
    2�� �ܹ���������10λ������ʵ��
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<cctype>
#include"Scan.h"
#include"Print.h"
using namespace std;

bool check(string s);               //�����������ָ���

int main()
{
	string input;
	cin>>input;

	if(check(input))
	{
		cout<<"Error!"<<endl;
		return 0;                   //����λ������10ʱ����
	}

	else                            //����λ��������10ʱ�����ַ���
	{

	Scan scan;                      //����Scan����
	Print print;                    //����Print����

	queue<string> q = scan.ToStringQueue(input);        //����ToStringQueue()������ȡĿ�����
	print.PrintQueue(q);                                //����PrintQueue()����������и�Ԫ��

	return 0;
	}
}


bool check(string s)
{
	int num = 0;
	bool flag = false;
	for(int i=0;i<s.size();i++)
	{
		if(!isdigit(s[i])&&s[i]!='.')           //��Ϊ��ΪС����ķ������ַ�
		{
			num = 0;
		}
		else if(isdigit(s[i])||'.')             //��Ϊ�����ַ���С����
		{
			num++;

			if(s[i] == '.')
			{
				flag = true;
			}

			if(num>11&&flag)                    //��С��λ
			{
				return true;
			}
			else if(num>10&&!flag)              //��С��λ
			{
				return true;
			}
		}
	}
	return false;
}
