/*
 * Scan�ദ��������ַ�����
    ������ToStringQueue(string input)
    ��;������һ������������ʽ����input��������ַ�ɨ��������ʽ�������ֺͷ�����ȡ�������õ�һ��string
        ���ӣ��������� -100*(20+1) ��õ��� -��100 �� * �� ( �� 20 �� + �� 1 �� ) ��

    return�������
 */
#ifndef SCAN_H_
#define SCAN_H_

#include<queue>
#include<string>
using namespace std;

class Scan
{
public:
	queue<string> ToStringQueue(string input);
private:
	string m_sInput;
	string temp = "";  	     //�ݴ����ڴ�����ַ���
	queue<string> StrQueue;  //�洢�ַ��Ķ���
};

#endif
