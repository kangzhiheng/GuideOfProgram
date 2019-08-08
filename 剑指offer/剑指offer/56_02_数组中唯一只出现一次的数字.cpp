// �� �� ��: 56_01_������Ψһֻ����һ�ε�����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.04
// ��    ����������Ψһֻ����һ�ε�����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������56��������������Ψһֻ����һ�ε�����
// ��Ŀ����һ�������г���һ������ֻ����һ��֮�⣬�������ֶ����������Ρ���
//      �ҳ��Ǹ�ֻ����һ�ε����֡�

#include <iostream>
#include <vector>

using namespace std;

int FindNumAppearingOnce(vector<int>& aArr)
{
	// �쳣�ж�
	if (aArr.empty() || aArr.size() < 1)
		throw new exception("Invalid input");

	int bitSum[32] = { 0 };    // 32 = 8 * 4;  int����4���ֽڣ�ÿ���ֽ���8λ		
	for (int i = 0; i < aArr.size(); ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			// ����bitMask������Ϊ��aArr[i]����λ����
			int bit = aArr[i] & bitMask;
			// bitΪ0˵��aArr[i]��Ӧ��λΪ0��0 & 1 = 0����Ϊ0�������if���
			if (bit != 0)
				bitSum[j] += 1;    // ��Ӧλ�ۼ�
			bitMask = bitMask << 1;    // ����һλ��ͳ����һλ
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;

}

int main()
{
	vector<int> aNumber = { 2,3,2,2,4,4,4 };
	int nResult = FindNumAppearingOnce(aNumber);
	cout << "������Ψһֻ����һ�ε�����Ϊ��" << nResult << endl;

	return 0;
}