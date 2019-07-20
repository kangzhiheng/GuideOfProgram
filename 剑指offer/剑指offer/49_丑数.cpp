//-----------------------------------------------------------------------------
// �� �� ��: 49_����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.20
// ��    ����49_����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������49������
// ��Ŀ�����ǰ�ֻ��������2��3��5��������������Ugly Number�����󰴴�С��
//      ���˳��ĵ�1500������������6��8���ǳ�������14���ǣ���Ϊ����������7��
//      ϰ�������ǰ�1������һ��������

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int IsUgliNumber(int index)
{
	// �쳣���
	if (index <= 0)
		return 0;
	vector<int> num(index);    // ����ź���ĳ�����ע�⣬��ʱҪ���ٳ���Ϊindex���ڴ�ռ䣬��ָ�����Ȼᷢ���ڴ�й©��
	num[0] = 1;   // 1�ǵ�һ������
	int M2 = 0;   // ������2�ı�����λ��
	int M3 = 0;
	int M5 = 0;
	for (int i = 1; i < index; ++i)
	{
		// ÿһ����������ǰ��ĳ������Ӧ����(��2��3��5�ı����ĳ���)��������Сֵ
		int MinCadUglyNum = min(num[M2] * 2, min(num[M3] * 3, num[M5] * 5));
		// �ҵ���Ӧ�����ĳ�������Ӧ����λ�ü�1
		if (MinCadUglyNum == num[M2] * 2)
			++M2;
		else if (MinCadUglyNum == num[M3] * 3)
			++M3;
		else
			++M5;

		num[i] = MinCadUglyNum;
	}

	return num[index - 1];
}

int main()
{
	int index;
	cout << "������һ������: ";
	cin >> index;

	int UglyNum = IsUgliNumber(index);
	cout << "��" << index << "�������� " << UglyNum << endl;

	return 0;
}