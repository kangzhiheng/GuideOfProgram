// �� �� ��: 62_ԲȦ�����ʣ�µ�����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.10
// ��    ����ԲȦ�����ʣ�µ�����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//----------------------------------------------------------------------------- 

// ������62��ԲȦ�����ʣ�µ�����
// ��Ŀ��0, 1, ��, n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��
//      ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// ����һ��˫������
int LastReamin_List(size_t n, size_t m)
{
	// �쳣�ж�
	if (n < 1 || m < 1 || m > n)
		return -1;

	list<int> numbers;

	for (size_t i = 0; i < n; i++)
		numbers.emplace_back(i);

	list<int>::iterator current = numbers.begin();

	while (numbers.size() > 1)
	{
		for (size_t i = 1; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}

		list<int>::iterator next = ++current;   // ����ɾ��λ�õ���һ��λ��
		if (next == numbers.end())
			next = numbers.begin();

		--current;    // ���˵�ɾ��λ��
		numbers.erase(current);
		current = next;
	}

	return *current;
}

// ���������ҹ���
/*
    �ο��� https://blog.csdn.net/u011500062/article/details/72855826
    ����f(n, m)��ʾn�������m����ɾ�������֣�����ʤ���ߵı��
	   f(n-1, m)��ʾn-1�������m����ɾ�������֣�����ʤ���ߵı�ţ�ע�⣬ʤ���߱�����ı䣬������ԲȦ�е��±��ı䣡
	���� n = 5, m = 3, ����
	f(5,3)  0 1 2 3 4    ����> 2 ��ɾ������ʱ3��Ϊ��һ�ֵĿ�ʼ����
	f(4,3)  3 4 0 1      ����> 0 ��ɾ������ʱ1��Ϊ��һ�ֵĿ�ʼ����
	f(3,3)  1 3 4        ����> 4 ��ɾ������ʱ1��Ϊ��һ�ֵĿ�ʼ����
	f(2,3)  1 3          ����> 1 ��ɾ������ʱ3��Ϊ��һ�ֵĿ�ʼ����
	f(1,3)  3            ����> ֻʣһ������3����������
	���ˣ������ܽ�һ�����ʣ��������ڸ��ֵ��±�
	f(5,3)  0 1 2 3 4    ����> 3���±�Ϊ3��f(5,3) = 3
	f(4,3)  3 4 0 1      ����> 3���±�Ϊ0��f(4,3) = 0
	f(3,3)  1 3 4        ����> 3���±�Ϊ1��f(3,3) = 1
	f(2,3)  1 3          ����> 3���±�Ϊ1��f(2,3) = 1
	f(1,3)  3            ����> 3���±�Ϊ0��f(1,3) = 0  
	���µ����Ƶ��ɵã�
	f(1,3) = 0                              = 0
	f(2,3) = (f(1,3) + 3) % 2 = (0 + 3) % 2 = 1
	f(3,3) = (f(2,3) + 3) % 3 = (1 + 3) % 3 = 1
	f(4,3) = (f(3,3) + 3) % 4 = (1 + 3) % 4 = 0
	f(5,3) = (f(4,3) + 3) % 5 = (0 + 3) % 5 = 3

	��˵õ���ʽ��f(n,m) = (f(n-1,m) + m) % (n-1), n>=2
*/

int LastReamin_Formula(size_t n, size_t m)
{
	// �쳣�ж�
	if (n < 1 || m < 1 || m > n)
		return -1;

	int nLast = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		nLast = (nLast + m) % i;
	}

	return nLast;
}

int main()
{
	int n;
	int m;
	cout << "ԭʼ����ĸ�����";
	cin >> n;
	cout << "ÿ��ɾ���ڼ���λ�ã�";
	cin >> m;

	int nLastNumber_list = LastReamin_List(n, m);
	int nLastNumber_Formula = LastReamin_Formula(n, m);
	cout << "��ԲȦʣ������һ��Ԫ��Ϊ��" << endl;
	cout << "˫��������\t" << nLastNumber_list << endl;
	cout << "�ҹ��ɣ�\t" << nLastNumber_Formula << endl;

	return 0;
}