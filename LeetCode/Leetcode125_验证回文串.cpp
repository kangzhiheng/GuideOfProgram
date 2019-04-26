//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.22
// ��    ������֤���Ĵ�
//-----------------------------------------------------------------------------
/*
    ����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false

*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	if (s.empty())
		return false;
	int i = 0, j = s.size() - 1;
	while (i < j)
	{
		while (i < j && !isalnum(s[i]))
			i++;
		while (i < j && !isalnum(s[j]))
			j--;
		if (toupper(s[i]) != toupper(s[j]))
			return false;
		i++;
		j--;
	}

	return true;
}

int main()
{
	string s = "A man, a plan, a canal: Panama";

	bool a = isPalindrome(s);
	cout << a << endl;

	return 0;
}