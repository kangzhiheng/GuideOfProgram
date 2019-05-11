//-----------------------------------------------------------------------------
// �� �� ��: 13_�����˵��˶���Χ.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.07
// ��    ���������˵��˶���Χ
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
//      ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
//      ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
//      �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

/* ���ݷ� */

#include <iostream>

using namespace std;

int MovingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
// ���������ܷ��������Ϊ(row, col)�ķ���
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
// �õ�һ�����ֵ���λ֮�ͣ�����31��λ��֮��Ϊ 3+1 = 4
int getDigitSum(int number);


int MovingCount(int threshold, int rows, int cols)
{
	// threshold ���� ��ֵ

	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	// �����ڴ沢��ʼ��
	bool *visited = new bool[rows * cols];
	// memset(visited, 0, sizeof(bool) * (rows * cols));
	for (size_t i = 0; i < rows * cols; ++i)
		visited[i] = false;

	int counts = MovingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;    // �ͷ��ڴ�

	return counts;
}

int MovingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int counts = 0;

	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row * cols + col] = true;

		// ++counts;    // ����仰��������1�������⡭��
		// ��ǰ������������,��1
		counts = 1 + MovingCountCore(threshold, rows, cols, row, col - 1, visited)    // ����
			       + MovingCountCore(threshold, rows, cols, row, col + 1, visited)    // ����
			       + MovingCountCore(threshold, rows, cols, row - 1, col, visited)    // ����
			       + MovingCountCore(threshold, rows, cols, row + 1, col, visited);   // ����
	}

	return counts;
}

// ���������ܷ��������Ϊ(row, col)�ķ���
bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
		return true;
	return false;
}

// �õ�һ�����ֵ���λ֮�ͣ�����31��λ��֮��Ϊ 3+1 = 4
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;   // ȡ���λ
		number /= 10;         
	}

	return sum;
}

int main()
{
	cout << "�������������� ��> ";
	int rows;
	cin >> rows;

	cout << "�������������� ��> ";
	int cols;
	cin >> cols;

	cout << "��ֵΪ ��> ";
	int threshold;
	cin >> threshold;

	int sum = MovingCount(threshold, rows, cols);
	cout << "�����˿��Ե���ĸ�����Ϊ ��> " << sum << endl;
	return 0;
}