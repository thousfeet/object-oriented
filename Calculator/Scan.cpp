 /************************************************************
  FileName: Print.cpp
  Author: thousfeet
  Date: 2016.03.23
  Function List:
   	  ����������ַ�����
 ***********************************************************/
#include<iostream>
#include<string>
#include<cctype>
#include<queue>
#include "Scan.h"
using namespace std;

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
	m_sInput = input;

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

	return StrQueue;  //���ش˶���
}


