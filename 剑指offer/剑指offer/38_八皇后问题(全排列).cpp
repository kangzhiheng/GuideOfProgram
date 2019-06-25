//-----------------------------------------------------------------------------
// �� �� ��: 38_�˻ʺ�����(ȫ����).cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.25
// ��    �����˻ʺ�����(ȫ����)
// ��    ����
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>

#define Max 8

using namespace std;

static int TotalNums = 0;

void swap(vector<int>& pStr, int i, int j)
{
	swap(pStr[i], pStr[j]);
}

// ɸѡ���������Ļʺ�
bool check(vector<int>& pStr)
{
	for (int i = 0; i < pStr.size(); i++)
	{
		for (int j = i + 1; j < pStr.size(); j++)
		{
			// �ж����Խ��ߺ͸��Խ������Ƿ��Ѿ���ռ��
			if (i - j == pStr[i] - pStr[j] || j - i == pStr[i] - pStr[j])
				return false;
		}
	}
	return true;
}

// ��8���ʺ����ȫ���У������Ӿͱ�֤��ÿһ�У�ÿһ�ж��������
void Permutation(vector<int>& pStr, int pBegin, int pEnd)
{
	if (pBegin == pEnd)
	{
		if (check(pStr))
		{
			++TotalNums;
			cout << "��" << TotalNums << "�ֽⷨ��";
			for (int i = 0; i < pStr.size(); ++i)
				cout << "(" << i << "," << pStr[i] << ") ";
			cout << endl;
		}
			
	}
	else
	{
		for (int pCh = pBegin; pCh < pEnd; ++pCh)
		{
			swap(pStr, pBegin, pCh);
			Permutation(pStr, pBegin + 1, pEnd);
			swap(pStr, pBegin, pCh);
		}
	}
}

void EightQuene()
{
	// �������飬�±��ʾ�У�Ԫ��ֵ��ʾ��
	vector<int> Queen;
	// ������Quene��ֵ0~7
	for (int i = 0; i < Max; ++i)
		Queen.emplace_back(i);
	// ��0~7����ȫ���У���ɸѡ����������check()����
	Permutation(Queen, 0, Max);
}

int main()
{
	// �˻ʺ�����
	EightQuene();
	cout << Max << "�ʺ��ܹ���" << TotalNums << "�ֽⷨ" << endl;

	return 0;
}