//-----------------------------------------------------------------------------
// �� �� ��: 55_01_�����������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.03
// ��    ���������������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������55��һ���������������
// ��Ŀ������һ�ö������ĸ���㣬���������ȡ��Ӹ���㵽Ҷ������ξ�����
//      ��㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pParent;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* CreateBinnaryTree(int val)
{
	BinaryTreeNode* pNew = new BinaryTreeNode();
	pNew->value = val;
	pNew->pParent = nullptr;
	pNew->pLeft = nullptr;
	pNew->pRight = nullptr;

	return pNew;
}

void ConnectBianryTree(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;

	if (pLeft != nullptr)
		pRoot->pLeft = pLeft;
	else
		pRoot->pLeft = nullptr;

	if (pRight != nullptr)
		pRoot->pRight = pRight;
	else
		pRoot->pRight = nullptr;
}

void PrintBinaryTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		cout << "�ýڵ�Ϊ��" << pNode->value << endl;

		if (pNode->pLeft != nullptr)
			cout << "�������Ϊ��" << pNode->pLeft->value << endl;
		else
			cout << "�������Ϊ��!" << endl;

		if (pNode->pRight != nullptr)
			cout << "���Ҷ���Ϊ��" << pNode->pRight->value << endl;
		else
			cout << "���Ҷ���Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�ýڵ�Ϊ�գ�" << endl;
	}
	cout << endl;
}
		

void PrintBinaryTree(BinaryTreeNode* pRoot)
{

	PrintBinaryTreeNode(pRoot);

	if (pRoot != nullptr)
	{
	    if (pRoot->pLeft != nullptr)
			PrintBinaryTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintBinaryTree(pRoot->pRight);
	}
}

int TheDepthOfBianryTree(BinaryTreeNode* pRoot)
{
	// �ݹ��ֹ����
	if (pRoot == nullptr)
		return 0;

	int nLeft = TheDepthOfBianryTree(pRoot->pLeft);
	int nRight = TheDepthOfBianryTree(pRoot->pRight);

	return nRight > nLeft ? (nRight + 1) : (nLeft + 1);
}

int main()
{
	BinaryTreeNode* pNode1 = CreateBinnaryTree(1);
	BinaryTreeNode* pNode2 = CreateBinnaryTree(2);
	BinaryTreeNode* pNode3 = CreateBinnaryTree(3);
	BinaryTreeNode* pNode4 = CreateBinnaryTree(4);
	BinaryTreeNode* pNode5 = CreateBinnaryTree(5);
	BinaryTreeNode* pNode6 = CreateBinnaryTree(6);
	BinaryTreeNode* pNode7 = CreateBinnaryTree(7);

	ConnectBianryTree(pNode1, pNode2, pNode3);
	ConnectBianryTree(pNode2, pNode4, pNode5);
	ConnectBianryTree(pNode3, nullptr, pNode6);
	ConnectBianryTree(pNode5, pNode7, nullptr);

	// PrintBinaryTree(pNode1);

	int nDepth = TheDepthOfBianryTree(pNode1);
	cout << "�ö����������Ϊ��" << nDepth << endl;

	return 0;
}