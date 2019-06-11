//-----------------------------------------------------------------------------
// �� �� ��: 39_�����г��ִ�������һ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.11
// ��    ���������г��ִ�������һ�������
// ��    ����
//-----------------------------------------------------------------------------

// ������39�������г��ִ�������һ�������
//         ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
//         ������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
//         ������5�Σ��������鳤�ȵ�һ�룬������2��

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <time.h>

using namespace std;

bool g_bInputInvalid = false;    // ��ʾ���������Ƿ���Ч

bool CheckInvalidArray(vector<int>& numbers)
{
	g_bInputInvalid = false;

	if (numbers.empty())    // �������Ϊ��
		g_bInputInvalid = true;

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(vector<int>& numbers, int number)
{
	int times = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	// ��Ŀ��˵��������һ����һ��������������ֵĴ����������鳤�ȵ�һ�룬�������ڲ�������������Ϊ�Ƿ�����
	if (times * 2 <= numbers.size())    
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

// ����һ
// ���طָ�ֵ���±�
int getPartition(vector<int>& array, int low, int high)
{
	srand(int(time(0)));    // ������һ���������
	int pivot = rand() % (high - low + 1) + low;    // ����[low, high]��������
	int key = array[pivot];    // ѡȡ��Ԫ
	swap(array[pivot], array[low]);    // ����׼���ŵ���һ��λ����
	while (low < high)
	{
		while (low < high && array[high] > key)
			high--;
		swap(array[low], array[high]);
		while (low < high && array[low] <= key)
			low++;
		swap(array[low], array[high]);
	}
	return low;

}

int Partition(vector<int>& data, int start, int end)
{
	if (data.empty() || data.size() <= 0 || start < 0 || end >= data.size())
		throw new std::exception("Invalid Parameters");

	srand(int(time(0)));    // ������һ���������
	int index = rand() % (end - start + 1) + start;    // ����[low, high]��������

	swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[index], data[small]);
		}
	}

	++small;
	swap(data[small], data[end]);

	return small;
}


int MoreThanHalfNum_BasedOnPartition(vector<int>& numbers)
{
	// �쳣���
	if (CheckInvalidArray(numbers))
		return 0;

	int middle = numbers.size() >> 1;    // ����һλ������һ�볤��
	int start = 0;
	int end = numbers.size() - 1;
	int index = getPartition(numbers, start, end);

	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = getPartition(numbers, start, end);
		}
		else
		{
			start = index + 1;
			index = getPartition(numbers, start, end);
		}
	}
	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, result))
		result = 0;

	return result;
}

int main()
{
	vector<int> arr;

	int length;
	cout << "���������鳤�ȣ�";
	cin >> length;

	cout << "�����볤��Ϊ" << length << "������Ԫ�أ�";
	for (size_t i = 0; i < length; i++)
	{
		int val;
		cin >> val;
		arr.emplace_back(val);
	}

	int result = MoreThanHalfNum_BasedOnPartition(arr);

	cout << "�����г��ִ�������һ�������Ϊ��" << result << endl;

	return 0;
}