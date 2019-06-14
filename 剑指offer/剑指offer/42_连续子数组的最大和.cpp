//-----------------------------------------------------------------------------
// �� �� ��: 42_���������������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.14
// ��    �������������������
// ��    ����
//-----------------------------------------------------------------------------

// ������42�����������������
// ��Ŀ������һ���������飬������������Ҳ�и�����������һ���������Ķ����
//      �����һ�������顣������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool g_InvalidInput = false;    // ����Ƿ������

int GreatestSumOfSubarray_Myself(vector<int>& arr)
{
	if (arr.empty() || arr.size() <= 0)
	{
		return 0;
		g_InvalidInput = true;
		cout << "�Ƿ�����!";
	}	

	g_InvalidInput = false;

	int sum_num = arr[0];
	int max_subarray = arr[0];

	for (int i = 1; i < arr.size(); ++i)
	{
		// �ӵڶ���Ԫ�ؿ�ʼ���Ƚϵ�ǰ������뵱ǰԪ��
		sum_num = max(sum_num + arr[i], arr[i]);
		// �����ǰ����ʹ�����ʷ�������ͣ����滻
		if (sum_num > max_subarray)
			max_subarray = sum_num;
	}

	return max_subarray;
}

int GreatestSumOfSubarray_Book(vector<int>& arr)
{
	if (arr.empty() | arr.size() <= 0)
	{
		return 0;
		g_InvalidInput = true;
		cout << "�Ƿ�����!";
	}

	g_InvalidInput = false;

	int nCurNum = arr[0];
	int nGreatNum = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		if (nCurNum <= 0)
			nCurNum = arr[i];
		else
			nCurNum += arr[i];

		if (nCurNum > nGreatNum)
			nGreatNum = nCurNum;
	}

	return nGreatNum;
}

int main()
{
	vector<int> arr;

	cout << "������һ�����飺";
	int val;
	while (scanf("%d", &val))
		arr.emplace_back(val);    // ���У�����ctrl+xֹͣ����

	//for (int i = 0; i < arr.size(); ++i)
	//	cout << arr[i] << " ";
	//cout << endl;
	cout << "�����е����������֮��Ϊ��" << endl;
	int Max_Numsubarray_1 = GreatestSumOfSubarray_Myself(arr);
	cout << "1. ���Լ��ķ�����" << Max_Numsubarray_1 << endl;

	int Max_Numsubarray_2 = GreatestSumOfSubarray_Book(arr);
	cout << "2. <<��ָoffer>>�ϵķ������޸ģ���" << Max_Numsubarray_2 << endl;

	return 0;
}