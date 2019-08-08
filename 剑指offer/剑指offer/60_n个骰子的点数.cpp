// �� �� ��: 60_n�����ӵĵ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.08
// ��    ����n�����ӵĵ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//----------------------------------------------------------------------------- 


// ������60��n�����ӵĵ���
// ��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s
//      �����п��ܵ�ֵ���ֵĸ��ʡ�

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// �ݹ�
/*
    ��n������ĳ��Ͷ��������Ϊs�ĳ��ִ�����F(n, s)����ô��Ͷ��n�����ӵĵ���֮��ֻ��Ͷ��n-1�������йأ��ʣ�
	F(n, s)����n - 1������Ͷ���ĵ�����Ϊs - 1��s - 2��s - 3��s -4��s - 5��s - 6ʱ�Ĵ������ܺͣ�
	F(n , s) = F(n - 1, s - 1) + F(n - 1, s - 2) + F(n - 1, s - 3) + F(n - 1, s - 4) + F(n - 1, s - 5) + F(n - 1, s - 6)��
*/
int CountNum(int n, int s)
{
	// �쳣�ж�
	if (s < n || s > 6 * n)
		return 0;

	// �ݹ����
	if (n == 1)
		return 1;
	else
		return CountNum(n - 1, s - 1) + CountNum(n - 1, s - 2) + CountNum(n - 1, s - 3)
		+ CountNum(n - 1, s - 4) + CountNum(n - 1, s - 5) + CountNum(n - 1, s - 6);
}

void PrintRadio(int n)    // n������
{
	double nRadio = 0;
	for (int i = n; i <= 6 * n; ++i)
	{
		printf("P( s = %d ) = %.4f (%d/%d)\n", i, CountNum(n, i) / pow(6, n), CountNum(n, i), int(pow(6, n)));
	}
		
}

int main()
{
	int n;
	cout << "���м������ӣ�";
	cin >> n;

	cout << n << "�����ӳ��ϵĵ���֮�Ϳ��ܳ��ֵĸ���Ϊ��" << endl;
	PrintRadio(n);

	return 0;
}