//-----------------------------------------------------------------------------
// �� �� ��: 14_������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.06
// ��    ������ת����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
//      ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
//      ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
//      ʱ�õ����ĳ˻�18��

#include <iostream>

using namespace std;

int MaxProductAfterCuttingRope_DP(int length)
{
	// �����������
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* product = new int[length + 1];
	// �����ӳ��ȴ��ڵ���4ʱ����Ҫ�������������������ŵ����ֵ
	/* ���磬�����ӳ���Ϊ4ʱ�����ܵ�����У�
	   1. 1��3��1 x 3 = 3;
	   2. 2��2��2 x 2 = 4;
	   3. 1,1��2��1 x 1 x 2 = 2;
	   4. 1,1,1��1��1 x 1 x 1 x 1 = 1;
	   �������ƶϼ��Σ����Եó����ۣ�
	   1. �����и������ս���������ܴ��ڳ���Ϊ1���ӶΡ�
	*/
	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;

	int max = 0;

	for (int i = 4; i <= length; ++i)
	{
		for (int j = 1; j <= i / 2; ++j)
		{
			int products = product[j] * product[i - j];
			if (products > max)
				max = products;

			product[i] = max;
		}
	}

	max = product[length];
	delete[] product;

	return max;
}

int MaxProductAfterCuttingRope_Greedy(int length)
{
	/*
	���ݾ�����Ƶ������Եó���
	    �����и������ս����ֻ���ܴ������ֳ��ȵ��Ӷ�(����Ϊ1��2��3)��
		�����������˵��������ʹ����Ϊ3�����Ӷ�һЩ�����ʹ����Ϊ2�����Ӷ�һЩ
	*/
	// �����������
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// ������ʹ����Ϊ3�����Ӷ�һЩ
	int length_3 = length / 3;

	// ����������������Ϊ4������õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ 2 x 2 > 3 x 1
	if (length - length_3 * 3 == 1)
		length_3 -= 1;

	// ͳ�Ƴ���Ϊ2�����ӳ��ֵĴ���
	int length_2 = (length - length_3 * 3) / 2;
	
	return (int)(pow(3, length_3)) * (int)(pow(2, length_2));
}

int main()
{
	cout << "������һ�����ӵĳ���(Ϊһ������): ";
	int value;
	cin >> value;

	int ProductMax_DP = MaxProductAfterCuttingRope_DP(value);
	cout << "��̬�滮 ���� �Ӷ����˻�Ϊ: " << ProductMax_DP << endl;

	int ProductMax_Greedy = MaxProductAfterCuttingRope_Greedy(value);
	cout << "̰���㷨 ���� �Ӷ����˻�Ϊ: " << ProductMax_Greedy << endl;

	return 0;
}