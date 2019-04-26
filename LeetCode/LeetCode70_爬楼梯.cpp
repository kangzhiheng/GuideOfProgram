//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.23
// ��    ������¥��
//-----------------------------------------------------------------------------
/*
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������

ʾ�� 1��

���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��
ʾ�� 2��

���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ClimStaires(int n)
{
	if (n < 1)
		return 0;
	/*if (n == 1)
		return 1;
	if (n == 2)
		return 2;*/
	return (n == 1 || n == 2) ? n : ClimStaires(n - 1) + ClimStaires(n - 2);
}

// �ݹ�
int test01(int n)
{
	return ClimStaires(n);
}

// ��̬�滮
int test02(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
	return 1;
	if (n == 2)
	return 2;

	int sum = 0;
	int sum1 = 1, sum2 = 2;

	for (int i = 2; i < n; i++)
	{
		sum = sum1 + sum2;
		sum1 = sum2;
		sum2 = sum;
	}
	return sum;

}

int main()
{
	int n;
	cout << "����n��̨��: ";
	cin >> n;

	cout << test01(n) << endl;
	cout << test02(n) << endl;

	return 0;
}