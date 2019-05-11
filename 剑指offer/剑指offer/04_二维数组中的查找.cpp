//-----------------------------------------------------------------------------
// 文 件 名: 03_01_找出数组中重复的数字.cpp
// 作    者：adoredee
// 创建时间：2019.04.14
// 描    述：04_二维数组中的查找
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
//      照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
//      整数，判断数组中是否含有该整数。

/*
    如果每个元素都比较，很麻烦。注意到该数组的特点：行递增且列递增，因此可以从数组的
    右上角至左下角寻找，每一次判断可以除去一列或一行的元素，方便。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 是否找到目标值
bool findtarget(vector<vector<int>> &arr, int target)    // 形参：定义了一个容器类型的数据arr，&arr表示要传递的参数是一个地址就好
{
	int row = arr.size();    // row个vector<int>容器
	int col = arr[0].size(); // 第0个容器的大小，即这个容器有多少个元素

	// 异常处理
	if (arr.empty() && row > 0 && col > 0)
		return false;

	// 从右上角开始检测
	/*for (int i = 0, j = col - 1; i < row, j >= 0;)
	{
		if (target == arr[i][j])
			return true;
		else if (target < arr[i][j])
			--j;
		else
			++i;
	}*/

	// 从右上角开始检测
	int i = 0, j = col - 1;
	while (i < row && j >= 0)
	{
		if (arr[i][j] == target)
			return true;
		else if (target < arr[i][j])
			--j;
		else
			++i;	
	}
	return false;
}

int main()
{
	/*------------- 读入二维数组---------------*/
	int row;
	cin >> row;    // 设置为row行

	int col;
	cin >> col;    // 设置为col列

	vector<vector<int>> arr(row, vector<int>(col));    // 创建一个容器arr，有row个vector<int>类型的数据，
	                                                   // 每一个row里又是一个容器vector组成，有col个元素，既col列
	                                                   // arr也是这个容器的首地址

	// 读入二维数组
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j ++)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}

	//// 显示二维数组
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;   // 每一行换行
	//}

	int target;
	cin >> target;    // 输入目标值

	if (findtarget(arr, target))
		cout << "找到了" << endl;
	else
		cout << "没有找到" << endl;

	return 0;
}