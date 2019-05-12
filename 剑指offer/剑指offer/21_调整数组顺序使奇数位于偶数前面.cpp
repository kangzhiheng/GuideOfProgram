//-----------------------------------------------------------------------------
// 文 件 名: 21_调整数组顺序使奇数位于偶数前面.cpp
// 作    者：adoredee
// 创建时间：2019.05.11
// 描    述：调整数组顺序使奇数位于偶数前面
// 版    本：
//-----------------------------------------------------------------------------

/*
	面试题21：调整数组顺序使奇数位于偶数前面
	题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
		 奇数位于数组的前半部分，所有偶数位于数组的后半部分，并使各部分较小的数在较大的数前面
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
判断奇偶性，若有一个数字a
1. a & 0x1 == 0，则a为偶数，比如a为6，二进制为0110，0110 & 0001 = 0000
2. a & 0x1 != 0，则a为奇数，比如a为7，二进制为0111，0111 & 0001 = 0001
*/
bool isEven(int n)
{
	return (n & 0x01) == 0;
}

void ReOrganizationArray(vector<int>& arr)
{
	// 异常检测
	if (arr.empty())
		return;

	// 定义双指针
	int left = 0;                  // 左指针
	int right = arr.size() - 1;    // 右指针

	while (left < right)
	{

		// 先移动左指针，直到找到偶数时，停止移动
		while (left < right && !isEven(arr[left]))
			left++;
		// 再移动右指针，直到找到奇数时，停止移动
		while (left < right && isEven(arr[right]))
			right--;
		// 碰到偶数在左，奇数在右的情况，交换两个数字
		if (left < right)
		{
			swap(arr[left], arr[right]);
			// 下面两句不要加，我们的目的是为了让这两个指针相遇，这是为了后面的排序
			// left++;
			// right--;
		}
		if (left == right)
		{
			cout << left << " " << right << endl;
			sort(arr.begin(), arr.begin() + left);     // 奇数区间排序
			sort(arr.begin() + left, arr.begin() + arr.size());  // 偶数区间排序
		}
		
	}
	// cout << left << " " << right << endl;
}

int main()
{
	// vector<int> arr = { 3, 2, 1, 4, 5, 0, 7, 8, 1, 6 };
	vector<int> arr;
	int val;
	cout << "请输入数组元素: ";
	while (scanf("%d", &val))
		arr.emplace_back(val);

	cout << "原数组为: ";
	for (size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	
	// 重排数组
	ReOrganizationArray(arr);
	
	cout << "奇在前偶在后的数组为: ";
	for (size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	return 0;
}