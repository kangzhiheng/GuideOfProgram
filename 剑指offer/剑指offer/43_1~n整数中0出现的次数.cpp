//-----------------------------------------------------------------------------
// 文 件 名: 43_1~n整数中0出现的次数.cpp
// 作    者：adoredee
// 创建时间： 2019.06.26
// 描    述：43_1~n整数中0出现的次数
// 版    本：
//-----------------------------------------------------------------------------

// 面试题43：从1到n整数中0出现的次数
// 题目：x属于1~9，输入一个整数n，求从1到n这n个整数的十进制表示中x出现的次数。例如
//      输入12，从1到12这些整数中包含1的数字有1，10，11和12，1一共出现了5次。

#include <iostream>
#include <math.h>

using namespace std;

int ZeroBetween1ToN(size_t n)
{
	// 异常判断
	if (n < 1)
		return 0;

	int counts = 0;

	for (int i = 1; pow(10, i - 1) < n; ++i)
	{
		int base = int(pow(10, i));
		int a = n / base;                            // 高位
		int b = n % base / int(pow(10, i - 1));      // 当前位
		int c = n % base - b * int(pow(10, i - 1));  // 低位

		counts += a * pow(10, i - 1);
		
		if (b == 0)     // 当前位如果为0，减去重复值
		{
			counts += c + 1 - pow(10, i - 1);
		}

	}

	return counts;
}

int countZero(int n) {
	int cnt = 0, k;
	// k / 10 为高位的数字。
	for (int i = 1; (k = n / i) / 10; i *= 10) 
	{
		//cout << "k: " << k << endl;
		//cout << "(k = n / i) / 10: " << (k = n / i) / 10 << endl;
		cnt += (k / 10) * i;
		//cout << "1: " << cnt << endl;
		// k % 10 为当前位的数字。
		if (k % 10 == 0) 
		{
			// n - k * i 为低位的数字。
			cnt += n - k * i + 1 - i;
		//	cout << "2: " << cnt << endl;
		}
	}
	return cnt;
}

int main()
{
	cout << "请输入大于1的数：";
	int val;
	cin >> val;

	// int a = countZero(val);
	int numbers = ZeroBetween1ToN(val);

	cout << "1 ~ " << val << "中 0 出现的次数为：";
	// cout << a << endl;
	cout << numbers << endl;

	return 0;
}