//-----------------------------------------------------------------------------
// �� �� ��: 43_1~n������0���ֵĴ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.26
// ��    ����43_1~n������0���ֵĴ���
// ��    ����
//-----------------------------------------------------------------------------

// ������43����1��n������0���ֵĴ���
// ��Ŀ��x����1~9������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��x���ֵĴ���������
//      ����12����1��12��Щ�����а���1��������1��10��11��12��1һ��������5�Ρ�

#include <iostream>
#include <math.h>

using namespace std;

int ZeroBetween1ToN(size_t n)
{
	// �쳣�ж�
	if (n < 1)
		return 0;

	int counts = 0;

	for (int i = 1; pow(10, i - 1) < n; ++i)
	{
		int base = int(pow(10, i));
		int a = n / base;                            // ��λ
		int b = n % base / int(pow(10, i - 1));      // ��ǰλ
		int c = n % base - b * int(pow(10, i - 1));  // ��λ

		counts += a * pow(10, i - 1);
		
		if (b == 0)     // ��ǰλ���Ϊ0����ȥ�ظ�ֵ
		{
			counts += c + 1 - pow(10, i - 1);
		}

	}

	return counts;
}

int countZero(int n) {
	int cnt = 0, k;
	// k / 10 Ϊ��λ�����֡�
	for (int i = 1; (k = n / i) / 10; i *= 10) 
	{
		//cout << "k: " << k << endl;
		//cout << "(k = n / i) / 10: " << (k = n / i) / 10 << endl;
		cnt += (k / 10) * i;
		//cout << "1: " << cnt << endl;
		// k % 10 Ϊ��ǰλ�����֡�
		if (k % 10 == 0) 
		{
			// n - k * i Ϊ��λ�����֡�
			cnt += n - k * i + 1 - i;
		//	cout << "2: " << cnt << endl;
		}
	}
	return cnt;
}

int main()
{
	cout << "���������1������";
	int val;
	cin >> val;

	// int a = countZero(val);
	int numbers = ZeroBetween1ToN(val);

	cout << "1 ~ " << val << "�� 0 ���ֵĴ���Ϊ��";
	// cout << a << endl;
	cout << numbers << endl;

	return 0;
}