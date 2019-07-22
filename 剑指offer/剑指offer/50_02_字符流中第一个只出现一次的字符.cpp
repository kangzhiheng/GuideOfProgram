//-----------------------------------------------------------------------------
// �� �� ��: 50_02_�ַ����е�һ��ֻ����һ�ε��ַ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.22
// ��    ����50_02_�ַ����е�һ��ֻ����һ�ε��ַ�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������50���������ַ����е�һ��ֻ����һ�ε��ַ�
// ��Ŀ����ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬����
//      �ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���'g'�����Ӹ���
//      �����ж���ǰ�����ַ�"google"ʱ����һ��ֻ����һ�ε��ַ���'l'��

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class  CharStatistics
{
public:
	CharStatistics() : index(0)
	{
		for (int i = 0; i < 256; ++i)
			occurrence[i] = -1;
	}

	void Insert(char ch)
	{
		cout << ch << " ";
		if (occurrence[ch] == -1)    // û�г��ֹ�
			occurrence[ch] = index;    // ��������ֵ
		else if (occurrence[ch] >= 0)    // �ٴγ��֣�����-2
			occurrence[ch] = -2;

		index++;
	}

	char FirstAppearingOnce()
	{
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();    // ��ʼ��minIndexΪ���͵����ֵ
		
		// �ҳ��ַ����д��ڵ���0��ֵ��Ӧ���ַ���ȷ����Щ�����ǵ�һ�γ��֣�,���ҵ���С������ֵ�����ǵ�һ�γ��ֵ�ֻ����һ�ε��ַ�
		for (int i = 0; i < 256; ++i)
		{
			if (occurrence[i] >= 0 && occurrence[i] < minIndex)
			{
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}

		return ch;
	}

private:
	int occurrence[256];
	int index;
};

int main()
{
	CharStatistics chars;
	vector<char> chs;

	cout << "��ȡ���ַ����������Ϊ��";
	chars.Insert('g');
	chars.Insert('o');
	cout << endl;

	char FirstChar = chars.FirstAppearingOnce();
	if (FirstChar == '\0')
		cout << "���ַ�����ֻ���ֹ�һ�ε��ַ��������³��ԡ�" << endl;
	else 
		cout << "��ʱ���ַ����е�һ��ֻ���ֹ�һ�ε��ַ�Ϊ��" << FirstChar << endl;

	cout << endl << "  �ַ�������......" << endl;

	chars.Insert('o');
	chars.Insert('g');
	chars.Insert('l');
	chars.Insert('e');
	cout << endl;

	FirstChar = chars.FirstAppearingOnce();
	if (FirstChar == '\0')
		cout << "���ַ�����ֻ���ֹ�һ�ε��ַ��������³��ԡ�" << endl;
	else
		cout << "��ʱ���ַ����е�һ��ֻ���ֹ�һ�ε��ַ�Ϊ��" << FirstChar << endl;

	return 0;
}