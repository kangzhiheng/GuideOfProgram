//-----------------------------------------------------------------------------
// �� �� ��: 05_�滻�ո�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.15
// ��    �����滻�ո�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������5���滻�ո�
//    ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
//          �������We%20are%20happy.����

/*
     ��ͳ�ƿո񳤶ȣ��õ��滻��ո����ַ������ȡ�
*/

// �ӣ�
// 1. ԭ����û����������vector<char>���Ѱ��'\0'ò��û����
// 2. ע��������C++����������Ǵ�0��ʼ�����ģ����ھ�ϲ�滻�ո����ʱ������ֱ���������ȣ�Ҫ���� ����-1

#define _CRT_SECURE_NO_WARNINGS;   // vs2017ʹ��scanf��ʾ����

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

vector<char> ReplaceBlank(vector<char> & str)
{
	// �쳣����
	//if (str.empty() || str.size() < 0)
	//	return char.Minvalue;

	// ͳ�ƿո���
	int numsofBlank = 0;
	int i = 0;
	while (i < str.size())    // ʹ��while(str[i] == '\0')�������
	{
		if (str[i] == ' ')    // �����ո�ͼ�һ
			++numsofBlank;
		++i;
	}

	cout << "������ַ�����" << numsofBlank << "���ո�" << endl;
	
	int NewStrLength = str.size() + 2 * numsofBlank;    // ���ַ�������

	int OriginStrLength = str.size();

	str.resize(NewStrLength);

	int indexoriginlength = OriginStrLength - 1;    // ��һ���ܹؼ���ԭ����ֵҪ��һ
	int indexnewlength = NewStrLength - 1;          // ������ֵҲҪ��һ

	while (indexoriginlength >= 0 && indexnewlength > indexoriginlength)
	{
		if (str[indexoriginlength] != ' ')                   // ԭ����û�������ո��
		{
			str[indexnewlength] = str[indexoriginlength];    // ��ԭ������Ӧ���ַ��ƶ�����Ӧ���µ��ַ�����
			--indexnewlength;                                // ��������ǰ�ƶ�һ����λ
		}
		else   // �����ո��
		{   // %20���Ӻ���ǰ���
			str[indexnewlength] = '0';
			str[indexnewlength - 1] = '2';
			str[indexnewlength - 2] = '%';
			indexnewlength -= 3;            // ����������������
		}

		--indexoriginlength;                // ԭ������ǰ�ƶ�һ����λ
	}

	cout << "�滻�ո����ַ���Ϊ��";

	return str;	
}

int main()
{
	/*
	char a[] = "we are happy  .";
	vector<char> str(a, a + 15);
	*/

	vector<char> str;

	char a;

	cout << "��������ַ�����";
	while (scanf("%c", &a))
		str.push_back(a);      // ������ʽ��1.�Ȱ�Enter; 2. ����Ctrl + Z; 3. �ٰ�����Enter������

	cout << "������ַ���Ϊ��";
	for (int i = 0; i < str.size(); i++)
		cout << str[i];

	cout << endl;

	vector<char> new_str = ReplaceBlank(str);

	for (int i = 0; i < new_str.size(); i++)
		cout << new_str[i];

	return 0;
}