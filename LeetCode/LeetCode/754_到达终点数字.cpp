//-----------------------------------------------------------------------------
// �� �� ��: 754_�����յ�����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.12
// ��    ���������յ�����_BFS
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/reach-a-number/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>

using namespace std;

int reachNumber(int target)
{
	target = target > 0 ? target : -target;    // ��ΪtargetΪ��Ϊ�����ߵĲ�������һ���ģ�����ֻ�����������
	int sums = 0;
	int i = 0;
	/*
	    1. sums < target, �����ۼ� 0 + 1 + 2 + ... + i = sums;
		2. ǡ�� sums == target�� ��� i - 1, ��Ϊsums��i�տ�ʼ������ʼ��Ϊ0������һ������������ʱ��Ҫ��һ��;
		3. ��� sums > target, ��ʱsums - target�Ĳ�Ϊż����������ǰ���ĳ�����ֱ为�ɵã�
		   ���� target = 8���� 0 + 1 + 2 + 3 + 4 = 10��10 - 8 = 2, ��ʱ�� 1 ��Ϊ -1, ���ɵõ� 8��
		   ��� sums - target �Ĳ�Ϊ��������һֱ�ۼ�֪����Ϊ��һ��ż������
		   
	*/
	while (sums < target || (sums - target) % 2 != 0)
	{
		sums += i;
		++i;
	}
	return --i;
}

int main()
{
	int N;
	cin >> N;
	int nums = reachNumber(N);
	cout << nums << endl;
}