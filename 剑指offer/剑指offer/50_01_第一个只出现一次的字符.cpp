//-----------------------------------------------------------------------------
// �� �� ��: 50_01_��һ��ֻ����һ�ε��ַ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.20
// ��    ����50_01_��һ��ֻ����һ�ε��ַ�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������50��һ�����ַ����е�һ��ֻ����һ�ε��ַ�
// ��Ŀ�����ַ������ҳ���һ��ֻ����һ�ε��ַ���������"abaccdeff"�������
//     'b'��

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

char TheOnlyChar(vector<char>& ch)
{
	// �쳣���
	if (ch.empty())
		return '\0';

	unordered_map<char, size_t> counts;

	// ���ù�ϣ��ͳ��ÿ���ַ����ֵĴ���
	for (size_t i = 0; i < ch.size(); ++i)
	{
		counts[ch[i]]++;
	}
	// �����ҳ���һ������Ϊ1���Ǹ��ַ�
	for (size_t i = 0; i < ch.size(); i++)
	{
		if (counts[ch[i]] == 1)
			return ch[i];
	}
	return '\0';
}

int main()
{
	// vector<char> ch = { 'a', 'b', 'b', 'c', 'd' };
	vector<char> ch;
	char chm;
	cout << "������һ���ַ�����";
	while (scanf("%c", &chm))    // �������룺1. ��һ��Enter�� 2. ctrl+Z��3. �ٰ�����Enter
	{
		ch.emplace_back(chm);
	}

	char a = TheOnlyChar(ch);

	cout << a << endl;

	return 0;
}