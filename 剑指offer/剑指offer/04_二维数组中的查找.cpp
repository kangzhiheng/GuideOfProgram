//-----------------------------------------------------------------------------
// �� �� ��: 03_01_�ҳ��������ظ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.14
// ��    ����04_��ά�����еĲ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
//      �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
//      �������ж��������Ƿ��и�������

/*
    ���ÿ��Ԫ�ض��Ƚϣ����鷳��ע�⵽��������ص㣺�е������е�������˿��Դ������
    ���Ͻ������½�Ѱ�ң�ÿһ���жϿ��Գ�ȥһ�л�һ�е�Ԫ�أ����㡣
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �Ƿ��ҵ�Ŀ��ֵ
bool findtarget(vector<vector<int>> &arr, int target)    // �βΣ�������һ���������͵�����arr��&arr��ʾҪ���ݵĲ�����һ����ַ�ͺ�
{
	int row = arr.size();    // row��vector<int>����
	int col = arr[0].size(); // ��0�������Ĵ�С������������ж��ٸ�Ԫ��

	// �쳣����
	if (arr.empty() && row > 0 && col > 0)
		return false;

	// �����Ͻǿ�ʼ���
	/*for (int i = 0, j = col - 1; i < row, j >= 0;)
	{
		if (target == arr[i][j])
			return true;
		else if (target < arr[i][j])
			--j;
		else
			++i;
	}*/

	// �����Ͻǿ�ʼ���
	int i = 0, j = col - 1;
	while (i < row && j >= 0)
	{
		if (arr[i][j] == target)
			return true;
		else if (target < arr[i][j])
			--j;
		else
			++i;	
	}
	return false;
}

int main()
{
	/*------------- �����ά����---------------*/
	int row;
	cin >> row;    // ����Ϊrow��

	int col;
	cin >> col;    // ����Ϊcol��

	vector<vector<int>> arr(row, vector<int>(col));    // ����һ������arr����row��vector<int>���͵����ݣ�
	                                                   // ÿһ��row������һ������vector��ɣ���col��Ԫ�أ���col��
	                                                   // arrҲ������������׵�ַ

	// �����ά����
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j ++)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}

	//// ��ʾ��ά����
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;   // ÿһ�л���
	//}

	int target;
	cin >> target;    // ����Ŀ��ֵ

	if (findtarget(arr, target))
		cout << "�ҵ���" << endl;
	else
		cout << "û���ҵ�" << endl;

	return 0;
}