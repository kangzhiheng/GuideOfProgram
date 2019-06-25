//-----------------------------------------------------------------------------
// �� �� ��: 38_�˻ʺ�����(����).cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.25
// ��    �����˻ʺ�����(����)
// ��    ����
//-----------------------------------------------------------------------------

#include <iostream>

using namespace std;

#define Max 8    // maxΪ�����������


int Queen[Max];    // ģ���ά���̣������±�����У�����Ԫ��ֵ������
static int sum = 0;    // ��¼������� 

void show() // ������лʺ������
{
	++sum;
	cout << "��" << sum << "�ֽⷨ��";
	for (int i = 0; i < Max; i++)
	{
		cout << "(" << i << "," << Queen[i] << ")";
	}
	cout << endl;
}

int check(int n) // ��鵱ǰ���ܷ���ûʺ� 
{
	for (int i = 0; i < n; i++) // �����źͶԽ������Ƿ���Է��ûʺ�
	{
		if (Queen[i] == Queen[n] || (Queen[i] - Queen[n]) == (n - i) || (Queen[i] - Queen[n]) == (i - n))
		{
			return 1;
		}
	}
	return 0;
}

void EightQueen(int line) // ���ݳ��Իʺ�λ��,nΪ������ 
{
	for (int i = 0; i < Max; i++)
	{
		Queen[line] = i; // ���ʺ�ڵ���ǰѭ������λ��
		if (!check(line))
		{
			if (line == Max - 1)
			{
				show(); // ���ȫ���ںã���������лʺ������
			}
			else
			{
				EightQueen(line + 1); // ��������ڷ���һ���ʺ�
			}
		}
	}
}

int main()
{
	// �Ӻ�����Ϊ0��ʼ���γ���
	EightQueen(0);
	cout << Max << "�ʺ��ܹ���" << sum << "�ֽⷨ" << endl;
	system("pause");
	return 0;
}