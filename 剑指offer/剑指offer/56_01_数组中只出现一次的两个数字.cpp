// �� �� ��: 56_01_������ֻ����һ�ε���������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.04
// ��    ����������ֻ����һ�ε���������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������56��һ����������ֻ����һ�ε���������
// ��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ���д����
//      �ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

// ˼·��λ����

#include <iostream>
#include <vector>

using namespace std;

bool IsBit_1(int num, size_t indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

size_t FindTheFirstBit_1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

vector<int> FindNumsAppearOnce(vector<int>& aArr)
// int FindNumsAppearOnce(vector<int>& aArr)
{
	// �쳣����
	/*if (aArr.empty() || aArr.size() < 2)
		return aArr;*/

	int resultExclusiveOR = 0;
	// ѭ����򣬵ó����
	for (int i = 0; i < aArr.size(); ++i)
		resultExclusiveOR ^= aArr[i];
	// �ҳ���������ұ�1���ֵ�λ��
	size_t indexOf_1 = FindTheFirstBit_1(resultExclusiveOR);

	vector<int> TheDiffTwoNum(2);

	for (int i = 0; i < aArr.size(); ++i)
	{
		// ��Ϊ���������ֲ���ͬ������ĳһλ������Ҳ��ͬ���������һλ���Ľ��Ϊ1��
		// ��������ص㣬������ɱ���Ϊ���飬�ٷֱ����ÿһ�����µļ�Ϊ�������鲻ͬ���������֡�
		if (IsBit_1(aArr[i], indexOf_1))    // ��aArr[i] �����ƶ� indexOf_1 λ���жϸ�λ��1�Ƿ���ͬ���ǵķ�Ϊһ��
			TheDiffTwoNum[0] ^= aArr[i];
		else
			TheDiffTwoNum[1] ^= aArr[i];
	}

	return TheDiffTwoNum;
}

int main()
{
	vector<int> aArr = { 2, 4, 3, 6, 3, 2, 5, 5 };

	vector<int> AppearOnce = FindNumsAppearOnce(aArr);

	cout << "������ֻ����һ�ε��������֣�";
	for (int i = 0; i < AppearOnce.size(); ++i)
		cout << AppearOnce[i] << " ";
	cout << endl;

	return 0;
}