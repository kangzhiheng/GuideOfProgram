//-----------------------------------------------------------------------------
// 文 件 名: 104_二叉树的最大深度_递归.cpp
// 作    者：adoredee
// 创建时间： 2019.09.05
// 描    述：二叉树的最大深度_递归
// 版    本：
// 链    接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>

using namespace std;

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* CreateBinaryNode(int val)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->val = val;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

void ConnectBianryTree(BinaryTreeNode* pPar, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pPar == nullptr)
		return;

	if (pLeft != nullptr)
		pPar->pLeft = pLeft;
	else
		pPar->pLeft = nullptr;

	if (pRight != nullptr)
		pPar->pRight = pRight;
	else
		pPar->pRight = nullptr;

}

int TheDepthOfBianryTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int left = TheDepthOfBianryTree(pRoot->pLeft);
	int right = TheDepthOfBianryTree(pRoot->pRight);

	return 1 + max(left, right);
}

int main()
{
	BinaryTreeNode* pNode1 = CreateBinaryNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryNode(9);
	BinaryTreeNode* pNode3 = CreateBinaryNode(20);
	BinaryTreeNode* pNode4 = CreateBinaryNode(15);
	BinaryTreeNode* pNode5 = CreateBinaryNode(7);

	ConnectBianryTree(pNode1, pNode2, pNode3);
	ConnectBianryTree(pNode3, pNode4, pNode5);

	int nDepth = TheDepthOfBianryTree(pNode1);

	cout << "该树的深度为：" << nDepth << endl;

	return 0;
}