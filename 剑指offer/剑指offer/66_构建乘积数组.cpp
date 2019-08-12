//-----------------------------------------------------------------------------
// �� �� ��: 66_�����˻�����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.12
// ��    ���������˻�����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������66�������˻�����
// ��Ŀ������һ������A[0, 1, ��, n-1]���빹��һ������B[0, 1, ��, n-1]����
// ��B�е�Ԫ��B[i] =A[0]��A[1]���� ��A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����

#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
int multiply(vector<int>& A, int nIndex)
{
	int nSum = 1;
	
	for (size_t i = 0; i < nIndex; ++i)
	{
		nSum *= A[i];
	}

	for (size_t i = nIndex + 1; i < A.size(); ++i)
	{
		nSum *= A[i];
	}

	return nSum;
}

void Construsct_On2(vector<int>& A, vector<int>& B)
{
	// �쳣�ж�
	if (A.empty() || A.size() < 1)
		return;

	int nLength = A.size();
	for (size_t i = 0; i < nLength; ++i)
	{
		B.emplace_back(multiply(A, i));
	}
}

/*
    B0    1 A1  A2  ������  An-2  An-1 
	B1   A0  1  A2  ������  An-2  An-1
	B2   A0 A1  1   ������  An-2  An-1
	.    ��				   ��	 ��	
	.    ��                 ��     ��
	.    ��                1    An-1
	Bn   A0 A1 A2   ������  An-2   1

*/
template <typename T>
void Construsct_On(vector<T>& A, vector<T>& B)
{
	// �쳣�ж�
	if (A.empty() || A.size() < 1)
		return;

	int nLengthA = A.size();

	B[0] = 1;

	for (int i = 1; i < nLengthA; ++i)
	{
		B[i] = B[i - 1] * A[i - 1];
	}

	T temp = 1;

	for (int i = nLengthA - 2; i >= 0; --i)
	{
		temp *= A[i + 1];
		B[i] *= temp;
	}

}

int main()
{
	cout << "������һ������(������Ctrl+Z�ͼ���Enter����������)��";
	vector<int> A;
	int nVal;
	while (scanf("%d", &nVal))
	{
		A.emplace_back(nVal);
	}

	vector<int> B1(A.size());
	vector<int> B2;

	Construsct_On(A, B1);
	Construsct_On2(A, B2);

	cout << "�����ĳ˻�����Ϊ��" << endl;
	cout << "O(n^2)������\t";
	for (size_t i = 0; i < A.size(); ++i)
		cout << B2[i] << " ";
	cout << endl;
	cout << "O(n)������\t";
	for (size_t i = 0; i < A.size(); ++i)
		cout << B1[i] << " ";
	cout << endl;

	return 0;
}
