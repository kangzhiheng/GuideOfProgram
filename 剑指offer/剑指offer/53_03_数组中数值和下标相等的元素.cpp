//-----------------------------------------------------------------------------
// �� �� ��: 53_02_0~n-1��ȱʧ������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.30
// ��    �������������������г��ֵĴ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������53����������������ֵ���±���ȵ�Ԫ��
// ��Ŀ������һ�������������������ÿ��Ԫ�ض�������������Ψһ�ġ�����ʵ
//      ��һ�������ҳ�����������һ����ֵ�������±��Ԫ�ء����磬������{-3, -1,
//      1, 3, 5}�У�����3�������±���ȡ�

#include <iostream>
#include <vector>

using namespace std;

int FindTheIndexEqualNum(vector<int>& aArr)
{
	// �쳣���
	if (aArr.empty() || aArr.size() <= 0)
	{
		cout << "�޺�������" << endl;
		return -1;
		exit(1);    // �������˳�����
	}

	int left = 0;
	int right = aArr.size() - 1;

	while (left <= right)
	{
		/*
		����mid��������:
		1. mid = (left + right) / 2;
		2. mid = left + (right - left) / 2;
		��ʵ,
		(left + right) / 2 = (left + left + right - left) / 2 = left + (right - left) / 2
		Ϊʲô����ֵڶ���д���أ�����Ϊ �ӷ� ���ܻ���ɼ�����ڴ���������Եڶ���ʹ�ø�Ϊ����
		���⣬
		�����ڼ������ʵ������һ��Ψһ���������Խ� / 2 д�� >> 1����Ϊλ����ʹ�ü��������Ч�ʽϿ�
		*/
		int mid = (left + right) >> 1;

		if (aArr[mid] == mid)
			return aArr[mid];
		else if (aArr[mid] > mid)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	cout << "�޺�������" << endl;
	exit(1);
	return -1;
	
}

int main()
{
	vector<int> aArr = { -3, -1, 1, 3, 5 };

	int nNum = FindTheIndexEqualNum(aArr);

	cout << "����������ֵ���±���ȵ�Ԫ��Ϊ��" << nNum << endl;

	return 0;
}