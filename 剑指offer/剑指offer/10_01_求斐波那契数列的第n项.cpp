//-----------------------------------------------------------------------------
// �� �� ��: 10_01_��쳲��������еĵ�n��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.21
// ��    ������쳲��������еĵ�n��
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������10֮һ����쳲��������еĵ�n��
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n��

/*
˼·��
    1. �ݹ� ���� �����൫��Ч�ʵͣ����Ƽ�
	2. ѭ�� ���� ʵ�ýⷨ���Ƽ�
*/
#include <iostream>
#include <time.h>

using namespace std;

// �ݹ�
long long Fibonacci_Recursive(size_t n)
{
	if (n <= 0)
		return 0;

	if (n == 1)
		return 1;

	return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

// ѭ��
long long Fibonacci_Circulate(size_t n)
{
	size_t result[] = { 0,1 };
	if (n < 2)
		return result[n];

	long long Fib_front = 0;
	long long Fib_back = 1;
	long long Fib_N = 0;

	for (size_t i = 2; i <= n; ++i)
	{
		Fib_N = Fib_front + Fib_back;

		Fib_front = Fib_back;
		Fib_back = Fib_N;
	}
	return Fib_N;
}


int main()
{
	cout << "����֪��쳲��������еĵڼ����ֵ��������һ��������: ";
	size_t n;
	cin >> n;
	clock_t Recursive_StartTime = clock();    // �ݹ鿪ʼʱ��
	size_t Recursive_value = Fibonacci_Recursive(n);
	clock_t Recursive_EndTime = clock();      // �ݹ����ʱ��
	cout << "�ݹ����ã�" << Fibonacci_Recursive(n) << " ��> ��ʱ: " << (Recursive_EndTime - Recursive_StartTime) << "ms"<< endl;

	clock_t Circulate_StartTime = clock();    // �ݹ鿪ʼʱ��
	size_t Circulate_value = Fibonacci_Circulate(n);
	clock_t Circulate_EndTime = clock();      // �ݹ����ʱ��
	cout << "ѭ�����ã�" << Fibonacci_Circulate(n) << " ��> ��ʱ: " << (Circulate_EndTime - Circulate_StartTime) << "ms" << endl;

	return 0;
}