//-----------------------------------------------------------------------------
// �� �� ��:  46_�����ַ�����ַ���.cpp
// ��    �ߣ� adoredee
// ����ʱ�䣺  2019.07.17
// ��    ���� �����ַ�����ַ���
// ��    ����
//-----------------------------------------------------------------------------

// ������46�������ַ�����ַ���
// ��Ŀ������һ�����֣����ǰ������¹����������Ϊ�ַ�����0�����"a"��1��
//      ���"b"��������11�����"l"��������25�����"z"��һ�����ֿ����ж�����롣��
//      ��12258��5�ֲ�ͬ�ķ��룬���Ƿֱ���"bccfi"��"bwfi"��"bczi"��"mcfi"��
//      "mzi"������ʵ��һ��������������һ�������ж����ֲ�ͬ�ķ��뷽����

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ���غ���
// int GetTranslationCount(int number);
void GetTranslationCount(const string& number);

//int GetTranslationCount(int number)
//{
//	// �쳣���
//	if (number < 0)
//		return 0;
//
//	string numberInString = to_string(number);
//
//	return GetTranslationCount(numberInString);
//}

void GetTranslationCount(const string& number)
{
	int length = number.length();
	int* kinds = new int[length];    // ��¼��ÿ��λ�ÿ�ʼ����ķ�������
	int count = 0;

	for (int i = length - 1; i >= 0; --i) 
	{
		count = 0;
		if (i < length - 1)    // �ӵ�ǰλ��i��ʼ���룬������i+1λ�õķ�������
			count = kinds[i + 1];  // ĩβ��ʼ�ķ���ֻ��һ��
		else
			count = 1;

		if (i < length - 1)    
		{
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;       // ƴ��i��i+1λ��
			if (converted >= 10 && converted <= 25)     // ƴ�ӵĽ���Ƿ����Ҫ��
			{
				if (i < length - 2)
					count += kinds[i + 2];    // �е���쳲���������
				else
					count += 1;
			}
		}

		kinds[i] = count;    // ��¼��ǰλ�ÿ��Է��������
		cout << kinds[i] << " ";
	}

	count = kinds[0];
	delete[] kinds;

	// return count;
}

int main()
{
	long number;
	cout << "������һ�����֣�";
	cin >> number;

	// int num = GetTranslationCount(number);
	string numberInString = to_string(number);
	GetTranslationCount(numberInString);
	// cout << number << "��" << num << "�ֲ�ͬ�ķ��뷽����" << endl;

	return 0;
}