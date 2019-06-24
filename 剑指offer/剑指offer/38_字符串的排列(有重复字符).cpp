//-----------------------------------------------------------------------------
// �� �� ��: 38_�ַ���������(���ظ��ַ�).cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.24
// ��    �����ַ���������
// ��    ����
//-----------------------------------------------------------------------------
// ������38���ַ���������(���ظ��ַ�)
// ��Ŀ������һ�����ظ��ַ����ַ�������ӡ�����ַ������ַ����������С����������ַ���aac��
//      ���ӡ�����ַ�a��c�������г����������ַ���aac��aca��caa��

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Permutation(vector<char>& pStr, int pBegin, int pEnd);

// ȫ����һ���ַ���
void Permutation(vector<char>& pStr)
{
	if (pStr.empty())
		return;

	// �ַ���pStr�ĵ� 0 λ�ε� n-1 λ��ȫ����
	Permutation(pStr, 0, pStr.size() - 1);
}

// ����pStr��ĵ�i�͵�j��λ�õ��ַ�
void swap(vector<char>& pStr, int i, int j)
{
	swap(pStr[i], pStr[j]);
}

// �жϸ��ַ���pStr��ĵ�i�͵�j��λ�õ��ַ�֮����ַ���û���ظ���
bool isRepeat(vector<char>& pStr, int pBegin, int pEnd)
{
	for (int i = pBegin; i < pEnd; ++i)
	{
		if (pStr[i] == pStr[pEnd])
			return true;    // ��ʾ���ظ�
	}

	return false;    // ��ʾ���ظ�
}

// ��ӡ�ַ���
void PrintStr(vector<char>& pStr)
{
	for (size_t i = 0; i < pStr.size(); ++i)
		cout << pStr[i];
}

/*
����Permutation(vector<char>& pStr, int pBegin, int pEnd)
��ʾ���ַ���pStr�� ��pBegin��λ�� �� ��pEnd��λ�� ֮������ַ�������ȫ����
1. pStrָ���ַ����ĵ�һ���ַ�
2. pBeginָ��ִ�����в����ĵ�һ���ַ���λ��
3. pEndָ��ִ�в��������һ���ַ���λ��
*/
void Permutation(vector<char>& pStr, int pBegin, int pEnd)
{
	if (pBegin == pEnd)
	{
		static int pNumPer = 0;    // ��¼ȫ���и���
		cout << "��" << ++pNumPer << "������ ��> ";
		PrintStr(pStr);
	}
	else
	{
		for (int pCh = pBegin; pCh < pEnd; ++pCh)
		{
			if (!isRepeat(pStr, pBegin, pCh))
			{
				swap(pStr, pBegin, pCh);     // ���ν�pBegin�����ÿһ���ַ���pBegin���н���
				Permutation(pStr, pBegin + 1, pEnd);    // ��pBegin������ַ�������ȫ����
				swap(pStr, pBegin, pCh);	 // Ϊ�˲��ظ����У��軹ԭ
			}
		}
	}
}

int main()
{
	vector<char> str;
	cout << "�������ַ���:";
	char a;
	while (scanf("%c", &a))
		str.emplace_back(a);
	cout << "���ַ�����ȫ���зֱ�Ϊ��" << endl;
	Permutation(str);

	return 0;
}