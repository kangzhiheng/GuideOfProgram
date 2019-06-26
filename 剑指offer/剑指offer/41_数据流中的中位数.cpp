//-----------------------------------------------------------------------------
// �� �� ��: 41_�������е���λ��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.26
// ��    �����������е���λ��
// ��    ����
//-----------------------------------------------------------------------------

// ������41���������е���λ��
// ��Ŀ����εõ�һ���������е���λ����������������ж�����������ֵ����ô
//      ��λ������������ֵ����֮��λ���м����ֵ��������������ж���ż������ֵ��
//      ��ô��λ������������ֵ����֮���м���������ƽ��ֵ��

/*
    ����ָoffer���ڶ����216ҳ�ڶ��ο�ͷ�����������ѵ��������ݶ�Ҫ С�� ��С�ѵ���������
    ������������Ϊ�����֣���߲��ֵ��������Ǳ��ұߵ�����С����ô�Ϳ��������Ѻ���С����װ����Щ���ݣ�
    1. ����װ��ߵ����ݣ�ȡ���Ѷ�������������ʱ�临�Ӷ���O(1)
    2. ��С��װ�ұߵ����ݣ�ͬ����ȡ���Ѷ�����С��������ʱ�临�Ӷ���O(1)
	��С�ѶѶ��������ڵ������ѶѶ�����
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		// �ж��ܸ�������������ż����ż�����뵽��С�ѣ��������뵽����
		/* 
		     ����������С������
		     ż������£���Ԫ�ز��뵽��С�ѣ������������
			 1. ��Ԫ��С�����ѵ����ֵ�����ȰѸ�Ԫ�ز��뵽���ѣ�ȡ�����������Ǹ�Ԫ�ط��뵽��С�Ѽ��ɣ�
			 2. ��Ԫ�ش��ڵ������ѵ����ֵ��ֱ�Ӳ��뵽��С��
		*/
		int size = MinSubArray.size() + MaxSubArray.size();    // ����������
		if ((size & 1) == 0)    // ��������ż��
		{			
			// MaxSubArray[0]��ʾ�������������֣����������С���������������֣����ȰѸ����ݲ��뵽����
			if (MaxSubArray.size() > 0 && num < MaxSubArray[0])
			{
				MaxSubArray.push_back(num);
				push_heap(MaxSubArray.begin(), MaxSubArray.end(), less<T>());    // ��������

				num = MaxSubArray[0];    // ȡ����������������

										 // ���Ѷ������ֵ���Ƶ�����ĩβ���ٽ�ǰ���Ԫ����������һ�����ѣ�����pop_back()ɾ��ĩβԪ��
				pop_heap(MaxSubArray.begin(), MaxSubArray.end(), less<T>());
				MaxSubArray.pop_back();    // ɾ�����������һ��ԭ��
			}

			// �����Ƿ񾭹����Ѵ�����Ҫ�����ݲ��뵽��С�� 
			MinSubArray.push_back(num);
			// ���Ԫ�أ�������С��
			push_heap(MinSubArray.begin(), MinSubArray.end(), greater<T>());
		}
		/*
		    ��������£���С��Ԫ�ظ��������Ѹ�����1����Ԫ�ز��뵽���ѣ������������
			1. ��Ԫ�ش�����С�ѵ���Сֵ�����ȰѸ�Ԫ�ز��뵽��С�ѣ�ȡ��С������С���Ǹ�Ԫ�ط��뵽���Ѽ��ɣ�
			2. ��Ԫ��С�ڵ�����С�ѵ���Сֵ��ֱ�Ӳ��뵽����
		*/
		else
		{
			// MinSubArray[0]Ϊ��С�������Сֵ
			if (MinSubArray.size() > 0 && num > MinSubArray[0])
			{
				MinSubArray.push_back(num);
				push_heap(MinSubArray.begin(), MinSubArray.end(), greater<T>());    // ����������С��

				num = MinSubArray[0];    // ȡ��С�ѵ������Сֵ

				pop_heap(MinSubArray.begin(), MinSubArray.end(), greater<T>());     // ����Сֵ�ŵ���󣬽�ǰ���ֵ����������С��
				MinSubArray.pop_back();     // ɾ�����һ��Ԫ��
			}

			// �����Ƿ񾭹���С�Ѵ�����Ҫ�����ݲ��뵽���� 
			MaxSubArray.push_back(num);
			push_heap(MaxSubArray.begin(), MaxSubArray.end(), less<T>());
		}
	}

	T GetMedian()
	{
		int size = MinSubArray.size() + MaxSubArray.size();
		if (size == 0)
			throw("No Numbers are available");

		T middle = 0;
		// �������ܳ���Ϊ��������С�ѳ��ȱ����ѳ��ȴ�1
		if ((size & 1) == 1)
			middle = MinSubArray[0];
		else
			middle = (MaxSubArray[0] + MinSubArray[0]) / 2;    // ������λ���� >> 1�� ���Ϳ����ã��������ò���

		return middle;
	}

private:
	vector<T> MinSubArray;    // ��С��
	vector<T> MaxSubArray;    // ����
};

int main()
{
	DynamicArray<float> arr;

	vector<float> arrStream;
	int val;
	cout << "������������(�Ȱ�enter����ctrl+z,�ٰ�����enter��������,���߻���֮������ctrl+z(�м��ٰ�һ�»���),�ٰ�һ��enter��������)��" << endl;
	while (scanf("%d", &val))
	{
		arrStream.emplace_back(val);
		arr.Insert(val);
	}

	cout << "ԭ�������е�Ԫ��Ϊ��";
	for (int i = 0; i < arrStream.size(); ++i)
		cout << arrStream[i] << " ";
	cout << endl;

	cout << "������������뵽�����������֣�";
	int value;
	cin >> value;
	arr.Insert(value);

	float middle = arr.GetMedian();

	cout << "����������λ��Ϊ ��> " << middle << endl;

	return 0;
}