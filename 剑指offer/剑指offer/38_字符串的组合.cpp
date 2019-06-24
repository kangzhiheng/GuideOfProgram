//-----------------------------------------------------------------------------
// �� �� ��: 38_�ַ��������(���ظ��ַ�).cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.24
// ��    �����ַ���������
// ��    ����
//-----------------------------------------------------------------------------

// ��Ŀ������һ��û���ظ��ַ����ַ�����������ַ������ַ���������ϡ�
// �ٸ����ӣ��������abc�����������a��b��c��ab��ac��bc��abc��

#include <iostream>
#include <vector>

using namespace std;

/*
    λ����
	���� pStr = abc������Ϊ3
	���Ӧ�������ĿΪ 2^3 - 1 = 7
	1. 001 & abc = c
	2. 010 & abc = b
	3. 011 & abc = bc
	4. 100 & abc = a
	5. 110 & abc = ab
	6. 101 & abc = ac
	7. 111 & abc = abc
*/
void Combination(char *pStr)
{
	if (pStr == NULL || *pStr == '\0')
		return;
	int len = strlen(pStr);
	if (len >= 32)    // 32λ�༭��������32λ
		return;

	int pNumCam = 0x1 << len;    // �� 1 �����ƶ� len-1 λ���ټ�ȥ1�Ǹ��ַ��������������
	cout << "�ַ���" << pStr << "����" << pNumCam - 1 << "�����" << endl;
	for (int i = 1; i < pNumCam; ++i)
	{
		cout << "��" << i << "�� : ";
		for (int j = 0; j < len; j++)
		{
			if (i & (0x1 << j))    // i��Ӧ�м������
				cout << pStr[j];
		}
		cout << endl;    // ��Ӧһ�����
	}

}

int main()
{
	char a[26];
	cout << "������һ�����Ȳ�����26���ַ����ַ�����";
	scanf("%s", a);
	Combination(a);
	return 0;
}