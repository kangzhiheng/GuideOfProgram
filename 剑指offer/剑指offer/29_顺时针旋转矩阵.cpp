//-----------------------------------------------------------------------------
// �� �� ��: 29_˳ʱ����ת����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.20
// ��    ����˳ʱ����ת����
// ��    ����
//-----------------------------------------------------------------------------

// ������29��˳ʱ���ӡ����
// ��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// ����һ��
void PrintSpiralMatrix(vector<vector<int>> matrix)
{
	// �쳣����
	if (matrix.empty())
		return;

	int top = 0;
	int bottom = matrix.size() - 1;    // ����
	int left = 0;
	int right = matrix[0].size() - 1;    // ����

	while (1)
	{
		// �������Ҵ�ӡ
		if (left > right)
			break;
		for (int i = left; i <= right; i++)
			cout << matrix[top][i] << " ";
		top++;    // ����һ��

		// ���ϵ��´�ӡ
		if (top > bottom)
			break;
		for (int i = top; i <= bottom; i++)
			cout << matrix[i][bottom] << " ";
		right--;

		// ���������ӡ
		if (left > right)
			break;
		for (int i = right; i >= left; i--)
			cout << matrix[bottom][i] << " ";
		bottom--;

		// ���µ��ϴ�ӡ
		for (int i = bottom; i >= top; i--)
			cout << matrix[i][left] << " ";
		left++;
	}

}

//��������
// ��ӡÿһȦ
void PrintMatrixInCircle(vector<vector<int>> matrix, int start)
{
	int rows = matrix.size();       // ����
	int cols = matrix[0].size();    // ���� 

	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	// �����Ҵ�ӡһ��
	for (int i = start; i <= endX; ++i)
		cout << matrix[start][i] << " ";

	// ���ϵ��´�ӡһ��
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
			cout << matrix[i][endX] << " ";
	}

	// ���ҵ����ӡһ��
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
			cout << matrix[endY][i] << " ";
	}

	// ���µ��ϴ�ӡһ��
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
			cout << matrix[i][start] << " ";
	}
}

void PrintMatrixClockWise(vector<vector<int>> matrix)
{
	int rows = matrix.size();       // ����
	int cols = matrix[0].size();    // ���� 
	// �쳣����
	if (matrix.empty() || rows <= 0 || cols <= 0)
		return;

	int start = 0;
	// ѭ������
	while (rows > start * 2 && cols > start * 2)
	{
		PrintMatrixInCircle(matrix, start);    // ��ӡÿһȦ
		++start;
	}
}

int main()
{
	int rows;
	cout << "����������������";
	cin >> rows;

	int cols;
	cout << "����������������";
	cin >> cols;

	vector<vector<int>> arr(rows, vector<int>(cols));

	cout << "���������Ԫ��: ";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int value;
			cin >> value;
			arr[i][j] = value;
		}

	cout << "����ľ���Ϊ: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << left << setw(5) << arr[i][j] << " ";    // �����
		cout << endl;
	}

	cout << "˳ʱ���ӡ��������: " << endl;
	cout << "����һ: ";
	PrintSpiralMatrix(arr);
	cout << endl;

	cout << "������: ";
	PrintMatrixClockWise(arr);
	cout << endl;

	return 0;
}