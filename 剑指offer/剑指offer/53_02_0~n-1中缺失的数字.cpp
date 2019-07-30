//-----------------------------------------------------------------------------
// �� �� ��: 53_02_0~n-1��ȱʧ������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.30
// ��    �������������������г��ֵĴ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������53��������0��n-1��ȱʧ������
// ��Ŀ��һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ������
//      ���ڷ�Χ0��n-1֮�ڡ��ڷ�Χ0��n-1��n������������ֻ��һ�����ֲ��ڸ�����
//      �У����ҳ�������֡�

#include <iostream>
#include <vector>

using namespace std;

// ���ַ�
int FindTheDiffNum(vector<int>& aArr)
{
	// �쳣�ж�
	if (aArr.empty() || aArr.size() <= 0)
		return -1;

	int start = 0;
	int end = aArr.size() - 1;


	while (start <= end)
	{
		int mid = (start + end) >> 1;

		if (aArr[mid] != mid)
		{
			// 1. ���aArr[mid] != mid �� aArr[mid - 1] == mid - 1����mid����Ϊȱʧ������
			// 2. ���aArr[mid] != mid �� mid = 0��˵��������Ŀ�ʼ����Ϊȱʧ������
			if (mid == 0 || aArr[mid - 1] == mid - 1)
				return mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	if (start == aArr.size())
		return aArr.size();

	return -1;

}

int main()
{
	vector<int> aArr = { 0, 1, 2, 3, 4, 5, 7 };

	int nNum = FindTheDiffNum(aArr);

	cout << "0 ~ " << aArr.size() - 1 << "��ȱʧ������Ϊ��" << nNum << endl;

	return 0;
}