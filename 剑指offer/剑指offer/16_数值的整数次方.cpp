//-----------------------------------------------------------------------------
// �� �� ��: 16_��ֵ�������η�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.08
// ��    ������ֵ�������η�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
//      �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

// ע������жϵ�������ָ���Ƿ�Ϊ����

#include <iostream>

using namespace std;

// ����һ�����淽��
double Power_Normal(double base, int exponent)
{
	/*
	base ����> ����
	exponent ����> ָ��
	*/
	// �쳣��� ����> ��������ָ��Ϊ��
	if (base == 0.0)
	{
		if (exponent < 0)
		{
			cout << "�Ƿ�����" << endl;
			return 0;
		}
		else
			return 0;
	}

	// ȡָ������ֵ
	size_t abs_exponent = exponent > 0 ? exponent : -exponent;

	// �����㷨
	double sum = 1.0;
	for (size_t i = 0; i < abs_exponent; i++)
		sum *= base;

	// ������ʵֵ
	return exponent > 0 ? sum : 1 / sum;
}


// ����������ʽ����
/*
    nΪż�� ����> a^n = a^(n/2) * a^(n/2)
	nΪ���� ����> a^n = a^((n-1)/2) * a^((n-1)/2) * a
*/
double PowerWithFormula(double base, size_t exponent)
{
	// �ݹ��������
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithFormula(base, exponent >> 1);
	result *= result;

	// ����ļ�������ǵݹ麯���壬����ݹ�������exponent�ָ�ԭֵ����ʱ�ж�ָ����ż��
	if (exponent & 0x1 == 1)    // exponentΪ����
		result *= base;

	return result;
}
double Power_Formula(double base, int exponent)
{
	/*
	base ����> ����
	exponent ����> ָ��
	*/
	// �쳣��� ����> ��������ָ��Ϊ��
	if (base == 0.0)
	{
		if (exponent < 0)
		{
			cout << "�Ƿ�����" << endl;
			return 0;
		}
		else
			return 0;
	}

	// ȡָ������ֵ
	size_t abs_exponent = exponent > 0 ? exponent : -exponent;

	// �����㷨
	double sum = PowerWithFormula(base, exponent);

	// ������ʵֵ
	return exponent > 0 ? sum : 1 / sum;
}


int main()
{
	cout << "���������(double��):";
	double base;
	cin >> base;

	cout << "������ָ��:";
	int exponent;
	cin >> exponent;

	double sum_1 = Power_Normal(base, exponent);
	cout << "���淽��: " << base << "��" << exponent << "�η�Ϊ: " << sum_1 << endl;

	double sum_2 = Power_Formula(base, exponent);
	cout << "��ʽ����: " << base << "��" << exponent << "�η�Ϊ: " << sum_2 << endl;

	return 0;
}