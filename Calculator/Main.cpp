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
	int num = 0;                      //��¼��������ָ���
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			num++;
		}
	}
	if(num>10)
	{
		return true;                  //����λ������10ʱ����true
	}
	else
	{
		return false;                 //����λ��������10ʱ����false
	}
}
