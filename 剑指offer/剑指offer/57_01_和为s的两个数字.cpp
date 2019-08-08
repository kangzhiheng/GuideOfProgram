// �� �� ��: 57_01_��Ϊs����������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.05
// ��    ������Ϊs����������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������57��һ������Ϊs����������
// ��Ŀ������һ����������������һ������s���������в�����������ʹ������
//      �ĺ�������s������ж�����ֵĺ͵���s���������һ�Լ��ɡ�

#include <iostream>
#include <vector>

using namespace std;

void FindThePairSumIs_s(vector<int> aNum, int nGivenSum)
{
	// �쳣�ж�
	if (aNum.empty() || aNum.size() <= 0)
		throw new exception("Invalid Input!");

	int nLeft = 0;
	int nRight = aNum.size() - 1;

	bool flag = false;    // �Ƿ��ҵ�
	long long nSum = 0;

	while (nLeft < nRight)
	{
		nSum = aNum[nLeft] + aNum[nRight];
		if (nSum == nGivenSum)
		{
			flag = true;
			cout << aNum[nLeft] << " " << aNum[nRight] << endl;
			--nRight;    // �ϸ�����������
		}

		else if (nSum > nGivenSum)
			--nRight;
		else
			++nLeft;
	}

	if (flag == false)
		cout << "����������������ԣ�" << endl;
}

int main()
{
	vector<int> aArr = { 1, 2, 3, 4, 7, 11, 12, 15 };
	cout << "ԭ����Ϊ��";
	for (int i = 0; i != aArr.size(); ++i)
		cout << aArr[i] << " ";
	cout << endl;

	cout << "����һ����������ʾ��������ĳ����Ԫ�صĺ�: ";
	int nGivenSum;
	cin >> nGivenSum;

	cout << "�����Ϊ" << nGivenSum << "������Ϊ: " << endl;
	FindThePairSumIs_s(aArr, nGivenSum);

	return 0;
}