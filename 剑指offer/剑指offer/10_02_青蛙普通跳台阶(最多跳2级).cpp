//-----------------------------------------------------------------------------
// �� �� ��: 10_02_������ͨ��̨��(�����2��).cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.21
// ��    �������ϵ�n���ж���������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������10֮����������̨��
// ��Ŀ��һֻ����һ�ο�����1��̨�ף�Ҳ����������̨�ף�������ܿ�����һ��n��̨���ж�����������

/*
    ˼·��쳲������������еı��Σ���ʼֵ��ͬ
*/
#include <iostream>
#include <time.h>

using namespace std;

// �ݹ�
long long Frog_Jumps_normally_Recursive(size_t n)
{
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	return Frog_Jumps_normally_Recursive(n - 1) + Frog_Jumps_normally_Recursive(n - 2);
}

// ѭ��
long long Frog_Jumps_normally__Circulate(size_t n)
{
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	long long Fib_front = 1;
	long long Fib_back = 2;
	long long Fib_N = 0;

	for (size_t i = 3; i <= n; ++i)
	{
		Fib_N = Fib_front + Fib_back;

		Fib_front = Fib_back;
		Fib_back = Fib_N;
	}
	return Fib_N;
}


int main()
{
	cout << "С����������̨��: ";
	size_t n;
	cin >> n;
	clock_t Recursive_StartTime = clock();    // �ݹ鿪ʼʱ��
	size_t Recursive_value = Frog_Jumps_normally_Recursive(n);
	clock_t Recursive_EndTime = clock();      // �ݹ����ʱ��
	cout << "�ݹ����ù��У�" << Frog_Jumps_normally_Recursive(n) << "�ַ��� ��> ��ʱ: " << (Recursive_EndTime - Recursive_StartTime) << "ms" << endl;

	clock_t Circulate_StartTime = clock();    // �ݹ鿪ʼʱ��
	size_t Circulate_value = Frog_Jumps_normally__Circulate(n);
	clock_t Circulate_EndTime = clock();      // �ݹ����ʱ��
	cout << "ѭ�����ù��У�" << Frog_Jumps_normally__Circulate(n) << "�ַ��� ��> ��ʱ: " << (Circulate_EndTime - Circulate_StartTime) << "ms" << endl;

	return 0;
}