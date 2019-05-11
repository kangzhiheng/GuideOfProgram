//-----------------------------------------------------------------------------
// �� �� ��: 03_01_�ҳ��������ظ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.10
// ��    �����ҳ��������ظ�������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
//      Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
//      ��ô��Ӧ��������ظ�������2����3��

#include <iostream>

using namespace std;

bool duplicate(int number[], int length, int* duplication)
{
	if (number == nullptr || length <= 0)    // �������Ϊ�ջ������鳤��С��0
		return false;

	for (size_t i = 0; i != length; i++)
	{
		if (number[i] < 0 || number[i] > length - 1)
			return false;
	}

	for (size_t i = 0; i != length; i++)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				*duplication = number[i];
				return true;
			}
			else    // ����
			{
				int temp = number[i];
				number[i] = number[temp];
				number[temp] = temp;
			}
		}
	}
	return false;
}

int main()
{
	int a[] = { 4, 0, 1, 2, 3 };
	int length = sizeof(a) / sizeof(a[0]);

	int x;
	cout << duplicate(a, length, &x) << endl;

	//cout << length << endl;

	return 0;
}