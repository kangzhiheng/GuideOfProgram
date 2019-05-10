//-----------------------------------------------------------------------------
// �� �� ��: 17_��ӡ1������nλ��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.10
// ��    ������ӡ1������nλ��
// ��    ����
//-----------------------------------------------------------------------------
// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
//      ��ӡ��1��2��3һֱ������3λ����999��

// ע�⿼�Ǵ�������


#include<iostream>

using namespace std;

void PrintNumber(char* number);    // ��ӡ��ǰ�ַ�

// ����һ������ģ�����֣������������(���ֺܴ��޷���long long���洢��������ģ�����֣���ֹ���)
/* 
    ����ĸ�λΪ��ֵ�ĸ�λ������
	���� 126,
	���� number = {1, 2, 6};
	����ĸ�λnumber[3] = 6Ϊ����126�ĸ�λ
*/

// ��ǰ�ַ���1 
bool Increment(char* number) 
{
	bool isOverflow = false;    // ���λ�Ƿ��н�λ
	int nTakeover = 0;          // ��λĬ��Ϊ0
	int nLength = strlen(number);   // ͳ���ַ�������
	for (int i = nLength - 1; i >= 0; i--)     // �Ӹ�λ��ʼ
	{
		int nSum = number[i] - '0' + nTakeover;    // �ַ�ת��Ϊ��ֵ

		if (i == nLength - 1)    
			nSum++;             // ��ֵ��λ��1

		if (nSum >= 10)     // �����λ����ڵ���10
		{
			if (i == 0)     // �������λ������99...999��1ʱ�����ֵ������λ��������ʱ�Ѿ��ﵽ���ֵ
				isOverflow = true;
			else 
			{
				nSum -= 10;    // 
				nTakeover = 1;    // 
				number[i] = '0' + nSum;    // 
			}
		}
		else    // û�н�λ����ǰλ����֮���˳�����
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void Print1ToMaxOfNDigits_ArrayToNumber(int n)
{
	// �쳣���
	if (n <= 0) 
		return;
	char *number = new char[n + 1];    // ����һ��n+1���ַ����飬�����һ���洢'\0'����ʾ�ַ�������
	memset(number, '0', n);    // ��ʼ����ÿһλ������Ϊ0
	number[n] = '\0';

	// ����λ��Ϊ���ֵ99...999��1�������
	while (!Increment(number)) 
	{
		PrintNumber(number);
	}

	delete[]number;    // �ͷ��ڴ�
}


// ���������ݹ�
void Print1ToMaxOfNDigits_RecursivelyCore(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigits_RecursivelyCore(number, length, index + 1);
	}
}

void Print1ToMaxOfNDigits_Recursively(int n)
{
	// �쳣���
	if (n <= 0)
		return;

	char* number = new char[n + 1];    // ����һ��n+1���ַ����飬�����һ���洢'\0'����ʾ�ַ�������
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigits_RecursivelyCore(number, n, 0);
	}

	delete[] number;
}

/*�������������������������������������������� �������� ��������������������������������������������*/
// ��ӡ��ǰ�ַ�
// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
// ��ӡ��������֣������Կ�ͷ��0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;          // �Ƿ���0��ͷ
	int nLength = strlen(number);      // �ַ�������

	for (int i = 0; i < nLength; i++)
	{
		/*
		�����ַ�Ϊ090����Ч����Ϊ90����һ��0��Ч�������
		*/
		if (isBeginning0 && number[i] != '0')    // ����Ƿ�0�Ƿ�Ϊ��Ч����
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);    // ��ӡ��ǰ�ַ������ʾ������
	}

	printf("\t");
}

int main()
{
	cout << "������һ������: ";
	int value;
	cin >> value;
	// Print1ToMaxOfNDigits_ArrayToNumber(value);
	Print1ToMaxOfNDigits_Recursively(value);

	return 0;
}