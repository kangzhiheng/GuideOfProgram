//-----------------------------------------------------------------------------
// 文 件 名: 66_构建乘积数组.cpp
// 作    者：adoredee
// 创建时间： 2019.08.12
// 描    述：构建乘积数组
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

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
	// 异常判断
	if (A.empty() || A.size() < 1)
		return;

	int nLength = A.size();
	for (size_t i = 0; i < nLength; ++i)
	{
		B.emplace_back(multiply(A, i));
	}
}

/*
    B0    1 A1  A2  ···  An-2  An-1 
	B1   A0  1  A2  ···  An-2  An-1
	B2   A0 A1  1   ···  An-2  An-1
	.    ·				   ·	 ·	
	.    ·                 ·     ·
	.    ·                1    An-1
	Bn   A0 A1 A2   ···  An-2   1

*/
template <typename T>
void Construsct_On(vector<T>& A, vector<T>& B)
{
	// 异常判断
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
	cout << "请输入一组数字(按两下Ctrl+Z和几下Enter键结束输入)：";
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

	cout << "构建的乘积数组为：" << endl;
	cout << "O(n^2)方法：\t";
	for (size_t i = 0; i < A.size(); ++i)
		cout << B2[i] << " ";
	cout << endl;
	cout << "O(n)方法：\t";
	for (size_t i = 0; i < A.size(); ++i)
		cout << B1[i] << " ";
	cout << endl;

	return 0;
}
