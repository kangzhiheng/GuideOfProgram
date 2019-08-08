// �� �� ��: 57_02_��Ϊs��������������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.05
// ��    ������Ϊs��������������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������57��������Ϊs��������������
// ��Ŀ������һ������s����ӡ�����к�Ϊs�������������У����ٺ�������������
//      ��������15������1+2+3+4+5=4+5+6=7+8=15�����Խ����ӡ��3����������1��5��
//      4��6��7��8��

#include <iostream>
#include <vector>
using namespace std;

void PrintArr(int nSmall, int nBig)
{
	cout << nSmall << "~" << nBig << ": ";
	int nLength = nBig - nSmall + 1;

	if (nLength >= 10)
		cout << "���й�����������ʾ��" << endl;
	else
	{
		for (int i = nSmall; i <= nBig; ++i)
			cout << i << " ";
		cout << endl;
	}

}

void FindTheSOfSequence(long long nGivenSum)
{
	int nSmall = 1;
	int nBig = 2;

	int nMid = (1 + nGivenSum) / 2;
	long nSum = nSmall + nBig;

	while (nSmall < nMid)
	{		
		if (nSum == nGivenSum)
		{
			PrintArr(nSmall, nBig);
			nSum -= nSmall;
			++nSmall;
		}
		else if (nSum < nGivenSum)
		{
			++nBig;
			nSum += nBig;
		}
		else
		{
			nSum -= nSmall;
			++nSmall;		
		}
			
	}
}

int main()
{
	cout << "����s: ";
	long long val;
	cin >> val;

	cout << "��Ϊs�����������������£�" << endl;
	FindTheSOfSequence(val);

	return 0;
}