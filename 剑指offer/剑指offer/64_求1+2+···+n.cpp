//-----------------------------------------------------------------------------
// �� �� ��: 64_��1+2+������+n.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.12
// ��    ������1+2+������+n
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������64����1+2+��+n
// ��Ŀ����1+2+��+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
//      �ȹؼ��ּ������ж���䣨A?B:C����

#include <iostream>

using namespace std;

class Temp
{
public:
	Temp()
	{
		++N;
		nSum += N;	
	}

	static void Reset()
	{
		N = 0;
		nSum = 0;
	}

	static size_t GetSum()
	{
		return nSum;
	}

private:
	static size_t N;
	static size_t nSum;
};

// ��̬��Ա�����ĳ�ʼ��
size_t Temp::N = 0;
size_t Temp::nSum = 0;

int main()
{
	int n;
	cout << "������һ������";
	cin >> n;
	// ����Ϊ0
	Temp::Reset();

	Temp *a = new Temp[n];    // ����n�����󣬾͵�����n�ι��캯��
	delete[]a;   // new delete���Ӧ����ָֹ������
	a = nullptr;

	size_t nTheSum = Temp::GetSum();
	cout << "��1��" << nTheSum << "�ĺ�Ϊ��" << nTheSum << endl;

	return 0;
}