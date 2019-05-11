//-----------------------------------------------------------------------------
// 文 件 名: 05_替换空格.cpp
// 作    者：adoredee
// 创建时间：2019.04.15
// 描    述：替换空格
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题5：替换空格
//    题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
//          则输出“We%20are%20happy.”。

/*
     先统计空格长度，得到替换完空格后的字符串长度。
*/

// 坑：
// 1. 原著里没有用容器，vector<char>里的寻找'\0'貌似没有用
// 2. 注意索引，C++里的索引都是从0开始计数的，故在惊喜替换空格操作时，不能直接索引长度，要索引 长度-1

#define _CRT_SECURE_NO_WARNINGS;   // vs2017使用scanf显示警告

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

vector<char> ReplaceBlank(vector<char> & str)
{
	// 异常处理
	//if (str.empty() || str.size() < 0)
	//	return char.Minvalue;

	// 统计空格数
	int numsofBlank = 0;
	int i = 0;
	while (i < str.size())    // 使用while(str[i] == '\0')会出问题
	{
		if (str[i] == ' ')    // 遇到空格就加一
			++numsofBlank;
		++i;
	}

	cout << "输入的字符串有" << numsofBlank << "个空格" << endl;
	
	int NewStrLength = str.size() + 2 * numsofBlank;    // 新字符串长度

	int OriginStrLength = str.size();

	str.resize(NewStrLength);

	int indexoriginlength = OriginStrLength - 1;    // 这一步很关键，原索引值要减一
	int indexnewlength = NewStrLength - 1;          // 新索引值也要减一

	while (indexoriginlength >= 0 && indexnewlength > indexoriginlength)
	{
		if (str[indexoriginlength] != ' ')                   // 原索引没有遇到空格符
		{
			str[indexnewlength] = str[indexoriginlength];    // 把原索引对应的字符移动到相应的新的字符串里
			--indexnewlength;                                // 新索引向前移动一个单位
		}
		else   // 遇到空格符
		{   // %20，从后往前添加
			str[indexnewlength] = '0';
			str[indexnewlength - 1] = '2';
			str[indexnewlength - 2] = '%';
			indexnewlength -= 3;            // 新索引减三个长度
		}

		--indexoriginlength;                // 原索引向前移动一个单位
	}

	cout << "替换空格后的字符串为：";

	return str;	
}

int main()
{
	/*
	char a[] = "we are happy  .";
	vector<char> str(a, a + 15);
	*/

	vector<char> str;

	char a;

	cout << "请输入的字符串：";
	while (scanf("%c", &a))
		str.push_back(a);      // 结束方式：1.先按Enter; 2. 按下Ctrl + Z; 3. 再按两下Enter键即可

	cout << "输入的字符串为：";
	for (int i = 0; i < str.size(); i++)
		cout << str[i];

	cout << endl;

	vector<char> new_str = ReplaceBlank(str);

	for (int i = 0; i < new_str.size(); i++)
		cout << new_str[i];

	return 0;
}