//-----------------------------------------------------------------------------
// 文 件 名: 64_求1+2+···+n.cpp
// 作    者：adoredee
// 创建时间： 2019.08.12
// 描    述：求1+2+···+n
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
//      等关键字及条件判断语句（A?B:C）。

#include <iostream>

using namespace std;

class Temp
{
public:
	Temp()
	{
		++N;
		nSum += N;	
	}

	static void Reset()
	{
		N = 0;
		nSum = 0;
	}

	static size_t GetSum()
	{
		return nSum;
	}

private:
	static size_t N;
	static size_t nSum;
};

// 静态成员变量的初始化
size_t Temp::N = 0;
size_t Temp::nSum = 0;

int main()
{
	int n;
	cout << "请输入一个数：";
	cin >> n;
	// 重置为0
	Temp::Reset();

	Temp *a = new Temp[n];    // 创建n个对象，就调用了n次构造函数
	delete[]a;   // new delete相对应，防止指正错误
	a = nullptr;

	size_t nTheSum = Temp::GetSum();
	cout << "从1到" << nTheSum << "的和为：" << nTheSum << endl;

	return 0;
}