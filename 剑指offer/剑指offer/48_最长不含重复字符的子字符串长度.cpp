//-----------------------------------------------------------------------------
// �� �� ��: 48_������ظ��ַ������ַ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.14
// ��    ����������ظ��ַ������ַ�������
// ��    ����
//-----------------------------------------------------------------------------

// ������48��������ظ��ַ������ַ���
// ��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�������������
//      �ַ����ĳ��ȡ������ַ�����ֻ������'a'��'z'���ַ���

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int g_InvalidInput = false;

int LongestSubArray(vector<char>& str)
{
	// �쳣���
	if (str.empty() || str.size() <= 0)
	{
		return 0;
		g_InvalidInput = true;
		cout << "�Ƿ��ַ���" << endl;
	}

	int res = 0;         // ��¼���ظ�������ַ�������
	size_t left = 0;     // ���ظ�������ַ������ȵ�����ߵ�λ��

	unordered_map<char, size_t> nums;    // ������ϣ����¼�ַ�����ÿһ���ַ����³��ֵ�λ��

	for (int i = 0; i < str.size(); i++)
	{
		// �������ظ�������ַ������ȵ�����ߵ�λ�ã�������ظ��ִ���nums[str[i]] 
		left = max(left, nums[str[i]]);
		nums[str[i]] = i + 1;      // ��¼str[i]���µ�λ�ã�+1 �����ֳ�����һ��
		res = max(res, int(i - left + 1));
	}

	return res;
}

int main()
{
	cout << "������һ���ַ�����";
	char cElement;
	vector<char> str;
	while (scanf("%c", &cElement))
		str.emplace_back(cElement);

	for (int i = 0; i < str.size(); ++i)
		cout << str[i] << " ";
	cout << endl;

	int res = LongestSubArray(str);

	cout << res << endl;

	return 0;
}