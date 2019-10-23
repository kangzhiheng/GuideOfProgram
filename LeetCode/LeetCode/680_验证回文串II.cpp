//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.22
// ��    ������֤���Ĵ�
//-----------------------------------------------------------------------------
/*
    ����һ���ǿ��ַ��� s�����ɾ��һ���ַ����ж��Ƿ��ܳ�Ϊ�����ַ�����

ʾ�� 1:

����: "aba"
���: True
ʾ�� 2:

����: "abca"
���: True
����: �����ɾ��c�ַ���
ע��:

�ַ���ֻ������ a-z ��Сд��ĸ���ַ�������󳤶���50000��

*/
/*
˼·��
*/
#include <iostream>
#include <string>

using namespace std;

// �ڶ��μ��
bool validPalindSupport(const string s, int left, int right)
{
	while (left < right)
	{
		if (s[left] != s[right])
			return false;
		++left;
		--right;
	}
	return true;
}

// ��һ�μ����Ĵ�
bool validPalindrome(string s)
{

	int left = 0, right = s.size() - 1;

	while (left < right)
	{
		if (s[left] != s[right])
			return validPalindSupport(s, left, right - 1) || validPalindSupport(s, left + 1, right);
		++left;
		--right;
	}
	return true;
}

int main()
{
	string s = "aA";

	bool isPalindrome = validPalindrome(s);

	cout << isPalindrome << endl;

	return 0;
}