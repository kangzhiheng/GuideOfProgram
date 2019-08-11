// �� �� ��: 61_�˿����е�˳��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.10
// ��    �����˿����е�˳��
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//----------------------------------------------------------------------------- 

// ������61���˿��Ƶ�˳��
// ��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
//      2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void PrintNum(vector<int>& aNum);

bool IsContinuous(vector<int>& aNumbers)
{
	// �쳣�ж�
	if (aNumbers.empty() || aNumbers.size() < 5)
		return false;

	sort(aNumbers.begin(), aNumbers.end(), less<int>());    // less<int>()�Ǵ�С��������greater<int>()�ǴӴ�С����

	// PrintNum(aNumbers);
	size_t nNumOfZero = 0;
	size_t nNumOfGap = 0;

	for (size_t i = 0; i < aNumbers.size() && aNumbers[i] == 0; ++i)
		++nNumOfZero;

	// ͳ�������еļ����Ŀ
	size_t nSmall = nNumOfZero;
	size_t nBig = nSmall + 1;

	while (nBig < aNumbers.size())
	{
		// ��������ȣ��ж��ӣ���������˳��
		if (aNumbers[nSmall] == aNumbers[nBig])
			return false;

		/*
		   ���� { 0��1��2��5��6 }, ���2��5Ҫ����������Ҫ�� 2(5 -2 - 1 = 2) ��0��
		   ���Ǹ�������1��0���ʸ����鲻����˳��
		*/
		nNumOfGap += aNumbers[nBig] - aNumbers[nSmall] - 1;
		nSmall = nBig;
		++nBig;

	}

	return nNumOfGap > nNumOfZero ? false : true;
}

template <typename T>
void PrintNum(vector<T>& aNum)
{
	if (aNum.empty() || aNum.size() < 1)
		return;

	for (auto i : aNum)
		cout << i << " ";

	cout << endl;
}

// ���������е�����ת���ɶ�Ӧ������
int read_ChartoInt()
{
	int value = 0;
	int ch;    // ��Ӧ���ַ���ASCII��
	// ת���ɴӱ�׼�����������֣������ǵõ�һ���������ַ�ʱ��ֹͣ
	while ((ch = getchar()) != EOF && isdigit(ch))
	{
		value *= 10;		
		value += ch - '0'; 
	}
	// �ѷ������ַ��˻ص����У��������Ͳ��ᶪʧ
	ungetc(ch, stdin);
	return value;
}

int main()
{
	vector<string> pStr;
	vector<int> aNum;
	string a;

	cout << "�����5���˿��ƣ���С���ɴ����κ�������С��Ϊ0��JΪ11��QΪ12��KΪ13����";
	for (size_t i = 0; i < 5; i++)
	{
		cin >> a;               // ����5���˿��ƣ�1~10, A, J, Q, K
		pStr.emplace_back(a);
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (pStr[i] == "A")
			aNum.emplace_back(0);
		else if (pStr[i] == "J")
			aNum.emplace_back(11);
		else if (pStr[i] == "Q")
			aNum.emplace_back(12);
		else if (pStr[i] == "K")
			aNum.emplace_back(13);
		else
			aNum.emplace_back(stoi(pStr[i]));    // stoi()���ַ���ת�������֣�"1234" ��> 1234
	}

	bool b_flag = IsContinuous(aNum);    // �ǲ���˳��

	if (b_flag)
		cout << "��ϲ��ϲ��˳�ӣ�" << endl;
	else
		cout << "����˳�ӡ�" << endl;

	return 0;
}