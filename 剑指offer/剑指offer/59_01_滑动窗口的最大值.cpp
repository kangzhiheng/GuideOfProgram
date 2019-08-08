// �� �� ��: 59_�������ڵ����ֵ.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.05
// ��    �����������ڵ����ֵ
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������59��һ�����������ڵ����ֵ
// ��Ŀ������һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬
//      �����������{2, 3, 4, 2, 6, 2, 5, 1}���������ڵĴ�С3����ôһ������6��
//      �������ڣ����ǵ����ֵ�ֱ�Ϊ{4, 4, 6, 6, 6, 5}��

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int>& aArr, size_t size)
{
	vector<int> maxWindows;

	if (aArr.size() >= size && size >= 1)
	{
		deque<int> index;

		// �洢ǰsize���ֵ������
		for (size_t i = 0; i < size; ++i)
		{
			while (!index.empty() && aArr[i] >= aArr[index.back()])
				index.pop_back();

			index.push_back(i);
		}
		
		for (size_t i = size; i < aArr.size(); ++i)
		{
			// index�Ķ���ͷ��������ǻ������ڵ����ֵ������
			maxWindows.push_back(aArr[index.front()]);

			while (!index.empty() && aArr[i] >= aArr[index.back()])
				index.pop_back();

			// ��֤�������ڵ�size
			if (!index.empty() && index.front() <= (int)(i - size))
				index.pop_front();

			index.push_back(i);
		}
		maxWindows.push_back(aArr[index.front()]);
	}

	return maxWindows;
}

int main()
{
	vector<int> aArr = { 2, 3, 4, 2, 6, 2, 5, 1 };
	
	cout << "ԭ����Ϊ: ";
	for (int i = 0; i < aArr.size(); ++i)
		cout << aArr[i] << " ";
	cout << endl;

	cout << "�����뻬�����ڵĳߴ磺";
	int size;
	cin >> size;
	vector<int> maxValue = maxInWindows(aArr, size);

	cout << "�ߴ�Ϊ " << size << " �������ڵ����ֵ����Ϊ��";
	for (int i = 0; i < maxValue.size(); ++i)
		cout << maxValue[i] << " ";
	cout << endl;

	return 0;
}
