//-----------------------------------------------------------------------------
// �� �� ��: 44_����������ĳһλ������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.07
// ��    ��������������ĳһλ������
// ��    ����
//-----------------------------------------------------------------------------

// ������44������������ĳһλ������
// ��Ŀ��������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����
//      �������У���5λ����0��ʼ��������5����13λ��1����19λ��4���ȵȡ���дһ
//      ������������λ��Ӧ�����֡�

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// �õ�mλ�������м�������������2����ʾ��λ��(10~99)
/*
digit = 1, 0 ~ 9��10��
digit = 2, 10 ~ 99��100 - 10 = 90��
digit = 3, 100 ~ 999��1000 - 100 = 900��
digit = 4, 1000 ~ 9999��10000- 1000 = 9000��
*/
int CountOfInteger(int digit)
{
	if (digit == 1)
		return 10;

	return 9 * int(pow(10, digit - 1));
}

// mλ������ʼֵ������digit=1,��ʼֵΪ0��digit=2����ʼֵΪ10
int BeginNumber(int digit)
{
	if (digit = 1)
		return 0;
	else
		return (int)pow(10, digit - 1);
}

// ȷ��Ҫ�ҵ�����λ��ĳmλ���еĵڼ�λ����0��ʼ����
int DigitAtIndex(int index, int digit)
{
	int number = BeginNumber(digit) + index / digit;
	int IndexFromLeftToRight = digit - index % digit;    // ��λ���������ǵڼ�λ��1 ~ IndexFromLeftToRight
	for (int i = 1; i < IndexFromLeftToRight; ++i)
		number /= 10;

	return number % 10;
}

int DigitAtIndex(int index)
{
	if (index < 0)
		return -1;

	// digit��ʾ��λ����Ĭ��һλ��
	int digit = 1;

	while (true)
	{
		int numbers = CountOfInteger(digit);
		if (index < numbers * digit)
			return DigitAtIndex(index, digit);

		index -= digit * numbers;
		digit++;
	}
	
	return -1;
}


int main()
{
	int index;
	cout << "����������ֵ���ӿ�ʼ����: ";
	cin >> index;

	int value = DigitAtIndex(index);

	cout << "��" << index << "λ��ֵλ: " << value << endl;

	return 0;
}