#include<iostream>
#include<string>
#include<cctype>
#include<queue>
#include "Scan.h"
using namespace std;


queue<string> Scan::ToStringQueue(string input)
{
	m_sInput = input;

	for(int i=0;i<m_sInput.size();i++)                            //����input��ÿ���ַ�
			{
				if(!isdigit(m_sInput[i])&&m_sInput[i]!='.')       //��Ϊ��ΪС����ķ������ַ�
				{
					if(!temp.empty())
						StrQueue.push(temp);                      //�ݴ��ַ����ǿ������
					temp.clear();                                 //��Ӻ�����ݴ��ַ���

					temp = m_sInput[i];                           //��ǰ�������
					if(!temp.empty())
						StrQueue.push(temp);
					temp.clear();
				}
				else if(isdigit(m_sInput[i])||'.')                 //��Ϊ�����ַ���С����
				{
					temp += m_sInput[i];                           //��ǰ���ֻ�С��������ݴ��ַ���ĩ
					continue;
				}
			}
	if(!temp.empty())
	{
		StrQueue.push(temp);                                        //������ɺ��ݴ��ַ����ǿ������
	}

	return StrQueue;                                                //���ش˶���
}


