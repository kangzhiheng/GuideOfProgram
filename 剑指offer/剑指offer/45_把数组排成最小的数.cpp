//-----------------------------------------------------------------------------
// �� �� ��: 45_�������ų���С����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.07.10
// ��    �����������ų���С����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------


// ������45���������ų���С����
// ��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ
//      �ӳ���������������С��һ����������������{3, 32, 321}�����ӡ����3����
//      �����ųɵ���С����321323��

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// ����һ���µıȽϷ���
static int compare(int strNumber1, int strNumber2)
{
	// ʹ��to_string��int��ת����string
	string m = to_string(strNumber1);
	string n = to_string(strNumber2);

	// �ַ�������ƴ��
	string mn = m + n;
	string nm = n + m;

	return mn < nm;    // ��С��������
}

string PrintMinNumber(vector<int>& numbers)
{
	// �쳣���
	string result;
	if (numbers.size() <= 0)
		return result;

	// �������������
	sort(numbers.begin(), numbers.end(), compare);

	// �ַ���ƴ��
	for (int i = 0; i < numbers.size(); ++i)
		result += to_string(numbers[i]);

	return result;
}

int main()
{
	vector<int> test{ 9, 8, 5, 1, 4, 7 };
	cout << "ԭ����Ϊ��";
	for (auto i : test)
		cout << i << " ";
	cout << endl;

	string result = PrintMinNumber(test);
	cout << "���������е���С������Ϊ:";
	cout << result << endl;

	return 0;
}