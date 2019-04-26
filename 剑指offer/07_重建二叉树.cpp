//-----------------------------------------------------------------------------
// �� �� ��: 07_�ؽ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.17
// ��    �����ؽ�������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
//      ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
//      2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
//      ͼ2.6��ʾ�Ķ��������������ͷ��㡣

/*
   ˼·��
*/
#include <iostream>

using namespace std;

// ����������ڵ�
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	/*
	1. startPreorder  ǰ���������ʼλ��
	2. endPreorder    ǰ������Ľ���λ��

	3. startInorder   �����������ʼλ��
	4. endInorder     ��������Ľ���λ��
	*/

	// ǰ������ĵ�һ������Ϊ���ڵ��ֵ
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->value = rootValue;
	root->pLeft = root->pRight = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *endPreorder)
			return root;
		else
			throw exception("Invalid Input.");
	}

	// ��������ҵ����ڵ��ֵ
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;     // ��û���ҵ����ڵ�֮ǰ��ָ��λ��һֱ����ƶ�
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid Input.");
	
	int leftLength = rootInorder - startInorder;   // �������Ľڵ����
	int* leftPreorderEnd = startPreorder + leftLength;   // �����������һ���ڵ��ֵ

	if (leftLength > 0)
	{
		// ����������
		root->pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// ����������
		root->pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	// �쳣����
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

// ��ӡ������
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// �����ǰ�ڵ��ֵ
		cout << "value of this node is: " << pNode->value << endl;

		// �������ڵ��ֵ
		if (pNode->pLeft != nullptr)
			cout << "value of its left child is: " << pNode->pLeft->value << endl;
		else
			cout << "left child is nullptr." << endl;

		// �������ڵ��ֵ
		if (pNode->pRight != nullptr)
			cout << "value of its right child is: " << pNode->pRight->value << endl;
		else
			cout << "right child is nullptr." << endl;
	}
	else    // �ýڵ�Ϊ��
	{
		cout << "this node is nullptr." << endl;
	}
	cout << endl;
}

void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		// �ݹ����
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->pLeft;
		BinaryTreeNode* pRight = pRoot->pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

int main()
{
	const int length = 8;
	// ǰ�����
	int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	// �������
	int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	cout << "The preorder sequence is: ";
	for (int i = 0; i < length; i++)
		cout << preorder[i] << ' ';
	cout << endl;

	cout << "The inorder sequence is: ";
	for (int i = 0; i < length; i++)
		cout << inorder[i] << ' ';
	cout << endl;

	// �쳣����
	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (exception& exception)
	{
		cout << "Invalid Input." << endl;
	}

	return 0;
}