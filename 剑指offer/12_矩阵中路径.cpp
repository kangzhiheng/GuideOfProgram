//-----------------------------------------------------------------------------
// �� �� ��: 12_������·��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.07
// ��    ����������·��
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
//      �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
//      �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
//      �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
//      ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
//      �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
//      A B T G
//      C F C S
//      J D E H

/* ���ݷ� */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// ��matrix��Ѱ��Ŀ���ַ���
// matrix, ��Ϊrows��cols�ж�ά�������ڽ�����ֱΪ����Ϊ rows * cols ��һ��
bool hasPathCore(char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

// �������Ϊ���ƾ��󣬿��Ʋ��Ҳ���
bool hasPath(char* matrix, int rows, int cols, const char* str)
{
	// �쳣����
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	// ��ʼ��visited��ָ����ڴ�ռ�
	bool *visited = new bool[rows * cols];
	/*
	����ԭ���ǣ�void *memset(void *s, int ch, size_t n);
	���������ǣ���s��ָ���ĳһ���ڴ��е�ǰn���ֽڵ�����ȫ������Ϊchָ����ASCIIֵ
	*/
	memset(visited, 0, sizeof(bool) * (rows*cols));    // ��visited��ָ��ǰrows*cols�ֽ�����ȫ���滻��0�����г�ʼ��

	int pathLength = 0;    // ����ƥ��Ŀ���ַ����ĵڼ�λ

	// �����Ͻǿ�ʼ����
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			// ���ҵ�Ŀ���ַ���
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
		}
	}

	delete[] visited;   // delete[] ���� ����visited���ÿһ��Ԫ�ص���������

	// û���ҵ�����Ϊfalse
	return false;
}

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	/*
	�������ͣ�
	1. matrix ���� �ַ����������ɵ�����������Ϊrows��cols�ж�ά�������ڽ�����ֱΪ����Ϊ rows * cols ��һ��
	2. rows ���� �ַ����������
	3. cols ���� �ַ����������
	4. row ���� ��ǰ�����ҵ��ַ����ڵ�������С��rows
	5. col ���� ��ǰ�����ҵ��ַ����ڵ�������С��cols
	6. str ���� Ŀ���ַ���
	7. pathLength ���� ����ƥ��Ŀ���ַ����ĵڼ�λ
	8. visited ���� �Ƿ񱻷��ʹ�
	*/
	
	/* if (pathLength == str.size() - 1)
	 	return true;*/
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;

	if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
	{
		++pathLength;    // ��ǰ�ַ���Ŀ�������ƥ��ɹ�
		visited[row * cols + col] = true;    // ��ǰ�ַ������ʹ�

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)    // ��ǰƥ���ַ����ڵ�Ŀ��������λ�õ�ǰһ����������
			   || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)    // ����
			   || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)    // ����
			   || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);   // ����

		if (!hasPath)
		{
			--pathLength;    // ���ݣ�û�н�һ���ҵ�Ŀ��ֵ
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}

int main()
{
	cout << "�������ά�ַ���������� ��> ";
	int rows;
	cin >> rows;

	cout << "�������ά�ַ���������� ��> ";
	int cols;
	cin >> cols;

	cout << "�������ά�ַ����飬��һά��������ʾ: ";
	char *matrix = new char[rows * cols];    // ����һ������Ϊchar�ĳ���Ϊ rows*cols ���ڴ�ռ�
	memset(matrix, 0, sizeof(char) * (rows * cols));
	for (int i = 0; i < rows * cols; ++i)
	{
		char ch;
		cin >> ch;
		matrix[i] = ch;
	}
	// ��ʾ���������
	/*for (int i = 0; i < rows * cols; ++i)
		cout << matrix[i];
	cout << endl;*/

	/*cout << "������Ҫ���ҵ�Ŀ���ַ���: ";
	vector<char> str;
	char a;
	while (scanf("%c", &a))
		str.emplace_back(a);*/
	/*for (int i = 0; i < str.size(); ++i)
		cout << str[i];
	cout << endl;*/

	const char* str = "bfce";

	bool flag = hasPath(matrix, rows, cols, str);
	if (flag)
		cout << endl << "�ڶ�ά�ַ������д���Ŀ���ַ��� ^_^ " << endl << endl;
	else
		cout << endl << "�ڶ�ά�ַ������в�����Ŀ���ַ���... " << endl << endl;

	delete[] matrix;  // �ͷſռ�
}