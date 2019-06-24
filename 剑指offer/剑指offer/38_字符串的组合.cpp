//-----------------------------------------------------------------------------
// 文 件 名: 38_字符串的组合(无重复字符).cpp
// 作    者：adoredee
// 创建时间： 2019.06.24
// 描    述：字符串的排列
// 版    本：
//-----------------------------------------------------------------------------

// 题目：输入一个没有重复字符的字符串，输出该字符串中字符的所有组合。
// 举个例子，如果输入abc，它的组合有a、b、c、ab、ac、bc、abc。

#include <iostream>
#include <vector>

using namespace std;

/*
    位运算
	假设 pStr = abc，长度为3
	则对应的组合数目为 2^3 - 1 = 7
	1. 001 & abc = c
	2. 010 & abc = b
	3. 011 & abc = bc
	4. 100 & abc = a
	5. 110 & abc = ab
	6. 101 & abc = ac
	7. 111 & abc = abc
*/
void Combination(char *pStr)
{
	if (pStr == NULL || *pStr == '\0')
		return;
	int len = strlen(pStr);
	if (len >= 32)    // 32位编辑器最多接受32位
		return;

	int pNumCam = 0x1 << len;    // 将 1 向左移动 len-1 位，再减去1是该字符串的所有组合数
	cout << "字符串" << pStr << "共有" << pNumCam - 1 << "种组合" << endl;
	for (int i = 1; i < pNumCam; ++i)
	{
		cout << "第" << i << "种 : ";
		for (int j = 0; j < len; j++)
		{
			if (i & (0x1 << j))    // i对应有几种情况
				cout << pStr[j];
		}
		cout << endl;    // 对应一种情况
	}

}

int main()
{
	char a[26];
	cout << "请输入一个长度不超过26个字符的字符串：";
	scanf("%s", a);
	Combination(a);
	return 0;
}