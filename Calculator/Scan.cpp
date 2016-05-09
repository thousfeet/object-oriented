 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	 queue<string> ToStringQueue(string input);
	 bool check(string s);
 ***********************************************************/
#include<iostream>
#include<string>
#include<cctype>
#include<queue>
#include "Scan.h"
using namespace std;


/*************************************************
  Description:
     �����������ָ���
  Input: String s �������ַ���
  Output: ��
  Return: ���ַ��������ֳ���10λ������true����δ����
     �򷵻�false
*************************************************/
bool Scan::check(string s)
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

/*************************************************
  Description:
     ����һ������������ʽ����input��������ַ�ɨ����
     �����ʽ�������ֺͷ�����ȡ�������õ�һ��string
  Input: String input ��ɨ����ַ���
  Output: ��
  Return: queue<string> ת��֮���string
*************************************************/
queue<string> Scan::ToStringQueue(string input)
{
	//��ʼ��
	m_sInput = input;
	while(StrQueue.size())
		StrQueue.pop();

	//����input��ÿ���ַ�
	for(int i = 0; i  <m_sInput.size(); i++)
	{
		 //��Ϊ��ΪС����ķ������ַ�
		if( !isdigit(m_sInput[i]) && m_sInput[i] != '.')
		{
			if(!temp.empty())
			{
				StrQueue.push(temp);  //�ݴ��ַ����ǿ������
			}
			temp.clear();  //��Ӻ�����ݴ��ַ���

			temp = m_sInput[i];   //��ǰ�������
			if(!temp.empty())
			{
				StrQueue.push(temp);
			}
			temp.clear();
		}

		//��Ϊ�����ַ���С����
		else if( isdigit(m_sInput[i]) || '.')
		{
			temp += m_sInput[i];   //��ǰ���ֻ�С��������ݴ��ַ���ĩ
			continue;
		}

	}

	//������ɺ��ݴ��ַ����ǿ������
	if(!temp.empty())
	{
		StrQueue.push(temp);
	}

	temp.clear();

	return StrQueue;  //���ش˶���
}

