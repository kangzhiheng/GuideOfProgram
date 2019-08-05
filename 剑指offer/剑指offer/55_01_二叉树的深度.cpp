//-----------------------------------------------------------------------------
// 文 件 名: 55_01_二叉树的深度.cpp
// 作    者：adoredee
// 创建时间： 2019.08.03
// 描    述：二叉树的深度
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
//      结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

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
		cout << "该节点为：" << pNode->value << endl;

		if (pNode->pLeft != nullptr)
			cout << "其左儿子为：" << pNode->pLeft->value << endl;
		else
			cout << "其左儿子为空!" << endl;

		if (pNode->pRight != nullptr)
			cout << "其右儿子为：" << pNode->pRight->value << endl;
		else
			cout << "其右儿子为空！" << endl;
	}
	else
	{
		cout << "该节点为空！" << endl;
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
	// 递归截止条件
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
	cout << "该二叉树的深度为：" << nDepth << endl;

	return 0;
}