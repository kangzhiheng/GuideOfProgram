// �� �� ��: 58_��ת����˳��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.05
// ��    ������ת����˳��
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
//      Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
//      �����"student. a am I"��

#include <iostream>
#include <algorithm>

using namespace std;

void Reverse(char *pBegin, char *pEnd)
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

// �ȷ�ת�������ӣ��ٷ�ת����
char* ReverseSentence(char* pData)
{
	// �쳣����
	if (pData == nullptr)
		return nullptr;

	char* pBegin = pData;

	char* pEnd = pData;

	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	// ��ת��������
	Reverse(pBegin, pEnd);

	// ��תÿ������
	pBegin = pEnd = pData;
	while (*pBegin != '\0')    // '\0'Ϊ�ַ���������
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;
}

char* ReverseSentence1(char *pData)
{
	if (pData == nullptr)
		return nullptr;

	char *pBegin = pData;

	char *pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	// ��ת��������
	Reverse(pBegin, pEnd);

	// ��ת�����е�ÿ������
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}
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
	// char inputs[] = "I am a Student.";
	cout << "������һ���ַ�����" << endl;
	char inputs[1000];
	cin.get(inputs, 1000);

	cout << "���ַ���Ϊ��";
	PrintCharArr(inputs);

	cout << "��ת����˳��";
	char* ReverseSe = ReverseSentence(inputs);
	PrintCharArr(ReverseSe);

	return 0;
}