// �� �� ��: 63_��Ʊ���������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.11
// ��    ������Ʊ���������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������63����Ʊ���������
// ��Ŀ�������ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У������������׸ù�
//      Ʊ���ܻ�õ������Ƕ��٣�����һֻ��Ʊ��ĳЩʱ��ڵ�ļ۸�Ϊ{9, 11, 8, 5,
//      7, 12, 16, 14}������������ڼ۸�Ϊ5��ʱ�����벢�ڼ۸�Ϊ16ʱ����������
//      �ջ���������11��

#include <iostream>
#include <vector>

using namespace std;

int TheMaxDiff(vector<int>& aNum)
{
	// �쳣�ж�
	if (aNum.empty() || aNum.size() < 2)
		return 0;

	int nSmall = aNum[0];
	int nDiff = aNum[1] - nSmall;

	for (size_t i = 2; i < aNum.size(); ++i)
	{
		if (aNum[i - 1] < nSmall)
			nSmall = aNum[i - 1];

		int nCurrentDiff = aNum[i] - nSmall;
		if (nCurrentDiff > nDiff)
			nDiff = nCurrentDiff;
	}

	return nDiff;
}

int main()
{
	vector<int> aNumber = { 9, 11, 8, 5, 7, 12, 16, 14 };

	cout << "��Ʊ�۸�Ϊ��";
	for (size_t i = 0; i < aNumber.size(); ++i)
		cout << aNumber[i] << " ";
	cout << endl;

	int nDiff = TheMaxDiff(aNumber);

	cout << "��ʱ���������Ϊ��" << nDiff << endl;

	return 0;
}