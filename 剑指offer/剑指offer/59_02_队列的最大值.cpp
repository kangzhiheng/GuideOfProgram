// �� �� ��: 59_02_���е����ֵ.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.06
// ��    �������е����ֵ
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������59�����������е����ֵ
// ��Ŀ������һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬
//      �����������{2, 3, 4, 2, 6, 2, 5, 1}���������ڵĴ�С3����ôһ������6��
//      �������ڣ����ǵ����ֵ�ֱ�Ϊ{4, 4, 6, 6, 6, 5}��

#include <iostream>
#include <deque>

using namespace std;

template<typename T>
class QueneWithMax
{
public:
	QueneWithMax() : currentIndex(0)
	{
	}
	void push_back(T number)
	{
		// ʼ�ս����ֵ������ǰ��
		while (!maximums.empty() && number >= maximums.back().number)
			maximums.pop_back();

		InternalData internalData = { number, currentIndex };
		data.push_back(internalData);
		maximums.push_back(internalData);

		++currentIndex;
	}

	void pop_front()
	{
		if (maximums.empty())
			throw new exception("queue is empty");

		if (maximums.front().index == data.front().index)
			maximums.pop_front();

		data.pop_front();
	}

	// ʵ���ж��� maximums �Ķ�����ŵ�ʼ���ǽ���ö��е����ֵ�������ֵС�ڸ����ֵ
	// �ʵ���queue��max����ʱ�����صĶ��еĶ�����ֵ��Ϊ���ֵ
	T max() const
	{
		if (maximums.empty())
			throw new exception("queue is empty");

		return maximums.front().number;
	}

private:
	struct InternalData
	{
		T number;
		int index;
	};

	deque<InternalData> data;      // ��Ž���ö��е�����ֵ
	deque<InternalData> maximums;  // ��Ž���ö��е�����ֵ�����ֵ��������ŵ�����
	int currentIndex;
};

int main()
{
	QueneWithMax<int> queue;

	cout << "�������������Ӧ��ֵ��";
	int val;
	while (scanf("%d", &val))    // Enter���У��ٰ�����Ctrl + z�� �ٰ�һ��Enter ��������
	{
		queue.push_back(val);
	}
	
	// ʵ����queue�Ķ�����ŵ�ʼ���ǽ���ö��е����ֵ�������ֵС�ڸ����ֵ
	// �ʵ���queue��max����
	int nMax = queue.max();
	cout << "��ʱ���е����ֵΪ��";
	cout << nMax << endl;

	return 0;
}