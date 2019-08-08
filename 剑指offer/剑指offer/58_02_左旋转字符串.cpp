// �� �� ��: 58_02_����ת�ַ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.05
// ��    ��������ת�ַ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������58������������ת�ַ���
// ��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
//      �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ���"abcdefg"����
//      ��2���ú�������������ת2λ�õ��Ľ��"cdefgab"��

#include <iostream>

using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd)
	{
		swap(*pBegin, *pEnd);
		pBegin++;
		pEnd--;
	}

}

/*
     ���磬abcdefg, ����2
	 ��һ������ת�ַ�����ǰ2λ����bacdefg;
	 �ڶ�������ת������ַ�������bagfedc;
	 ����������ת�����ַ�������cdefgab;

*/
char* LeftRotateString(char* pStr, int n)
{
	if (pStr == nullptr || n < 0 || n > strlen(pStr))
	{
		cout << "�Ƿ����룡" << endl;
		throw new std::exception("InValid Input!");
	}

	int nLength = static_cast<int>(strlen(pStr));
	
	char* pFirstStart = pStr;
	char* pFirsrtEnd = pStr + n - 1;
	
	char* pSecondStart = pStr + n;
	char* pSecondEnd = pStr + nLength - 1;

	Reverse(pFirstStart, pFirsrtEnd);    // ��һ������תǰnλ��
	Reverse(pSecondStart, pSecondEnd);   // �ڶ�������תʣ���λ����
	Reverse(pFirstStart, pSecondEnd);    // ����������ת�����ַ�����

	return pStr;
}

void PrintCharArr(char* inputs)
{
	// �쳣���
	if (inputs == nullptr)
	{
		cout << "������" << endl;
		return;
	}

	for (int i = 0; inputs[i] != '\0'; ++i)
	{
		cout << inputs[i];
	}
	cout << endl;
}

int main()
{
	char pStr[1000];
	cout << "������һ���ַ�����";
	cin.get(pStr, 1000);

	cout << "Ҫ�ӵڶ�λ��ʼ��ת��";
	int n;
	cin >> n;

	cout << "��ת����ַ���Ϊ��";
	char* pResult = LeftRotateString(pStr, n);
	cout << pResult << endl;
	// PrintCharArr(pResult);

	return 0;
}