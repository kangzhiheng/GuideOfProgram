//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.17
// ��    �������ظ��ַ�����Ӵ�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/* 
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:

����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
ʾ�� 2:

����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
ʾ�� 3:

����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
*/

/*
    ˼·����������˼��
*/
/*
    �ӣ��ڱ���IED������ȷ������LeetCode�����д��󣬺ܿ���������ת�����⣬��line59.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>     // unordered_map������ģ���ѯЧ�ʸ�

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

// ����һ��ʹ��unordered_map��ʵ�ֹ�ϣ����
int lengthOfLongestSubstring(vector<char>& s)
{
	int res;         // res��¼����ظ��Ӵ��ĳ���
	size_t left = 0;    // left��ʾ����ߵ�λ��
	unordered_map<char, size_t> m;   // ����Ĺ�ϣ��
	for (int i = 0; i < s.size(); i++)
	{
		left = max(left, m[s[i]]);
		m[s[i]] = i + 1;
		res = max(res, int(i - left + 1));    // ע�����LeetCode���ܻ�����һ��������һ��ǿ������ת��
	}

	return res;
}


/*
// ����������������������ַ�������ʵ�ֹ�ϣ����
int lengthOfLongestSubstring(vector<char>& s)
{
	int res;         // res��¼����ظ��Ӵ��ĳ���
	int left = 0;    // left��ʾ����ߵ�λ��
	char m[256] = { 0 };    // ���������ڹ�ϣ��Ԫ���Ƿ���ֹ�
	for (int i = 0; i < s.size(); i++)
	{
		
		// 1. m[s[i]] == 0 ���������ʾs[i]����û�б���¼��
		// 2. m[s[i]] < left ��ʾs[i]�Ѿ�����¼������Ҫ������ߵ��ٽ�ֵ����ת��else���

		if (m[s[i]] == 0 || m[s[i]] < left)    // i��ʾ����ظ��Ӵ����ұߵ�λ�ã�left������ߵ�λ��
		{
			res = max(res, i - left + 1);
		}
		else
		{
			left = m[s[i]];                    // ��Ϊ��Ԫ����ǰ����ֹ��ˣ�����Ҫ����Ԫ�ص����µ�λ��
		}

		m[s[i]] = i + 1;    // ��ÿλԪ�ش��ǩ����1��ʼ
	}

	return res;
}
*/


int main()
{
	vector<char> str;
	char a;
	cout << "������һ���ַ���(���ΰ��»س�����Ctrl+z���س�����������):" << endl;
	while (cin >> a)
	{
		str.push_back(a);
	}

	int nums = lengthOfLongestSubstring(str);

	cout << "���ַ�������ظ��Ӵ��ĳ���Ϊ: " << nums << endl;

	return 0;
}