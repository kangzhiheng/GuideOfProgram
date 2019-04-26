//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.22
// ��    ������֤���Ĵ�
//-----------------------------------------------------------------------------
/*
    ˼·��ͳ��ÿ���ַ����ֵĴ��������������
	1. ����ż��������ȫ����Ӽ��ɣ���Ϊ����ֱ�ӶԳƣ�
	2. ��������ż�����ַ����ֵĴ���Ϊż����Ȼȫ����ӣ��ַ����ֵĴ���Ϊ������
	   �����е�����-1ȡΪż�������Ӹ�1���ɣ����1Ϊ�Գ����ģ������������������
	
	���ӣ�
	s = "aaabbxxxxx"
	a -> 3��
	b -> 2��
	x -> 5��
	���������Ĵ���ʽ֮һΪ baxxxxxab��2 + (3 - 1) + (5 - 1) + 1 = 9���������������
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
	unordered_map<int, int> counts;    // �ֵ䣬���ÿ���ַ����ֵĴ���
	for (int i = 0; i < s.size(); i++)
		counts[s[i]] += 1;                // ͳ��s������ַ����ֵĸ���

	bool hasoddnum = false;   // �Ƿ�������
	int res = 0;   // ��������Ĵ�����
	for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); it++)
	{
		if (it->second % 2 != 0)    // ����
		{
			hasoddnum = true;
			res += it->second - 1;
		}
		else
			res += it->second;
	}

	return hasoddnum ? res + 1 : res;
}

int main()
{
	string s = "Aa";

	cout << longestPalindrome(s) << endl;

	return 0;
}