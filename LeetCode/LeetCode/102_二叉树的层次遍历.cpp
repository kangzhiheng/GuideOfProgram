//-----------------------------------------------------------------------------
// 文 件 名: 102_二叉树的层次遍历.cpp
// 作    者：adoredee
// 创建时间：2019.09.03
// 描    述：二叉树的层次遍历
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	else
	{
		pRoot->pLeft = pLeft;
		pRoot->pRight = pRight;
	}
}

BinaryTreeNode* CreateBinaryTreeNode(int val)
{
	BinaryTreeNode* pNew = new BinaryTreeNode();
	pNew->val = val;
	pNew->pLeft = nullptr;
	pNew->pRight = nullptr;
	return pNew;
}

vector<vector<int>> levelOrder(BinaryTreeNode* pRoot)
{
	vector<vector<int>> BinaryTreeOrder;
	if (pRoot == nullptr)
		return BinaryTreeOrder;

	queue<BinaryTreeNode*> q;
	q.push(pRoot);

	while (!q.empty())
	{
		int sizes = q.size();
		vector<int> Binary;
		for (int i = 0; i < sizes; ++i)
		{		
            BinaryTreeNode* pNode = q.front();
			Binary.push_back(pNode->val);

			q.pop();

			if (pNode->pLeft != nullptr)
				q.push(pNode->pLeft);
			if (pNode->pRight != nullptr)
				q.push(pNode->pRight);
		}
		BinaryTreeOrder.push_back(Binary);
	}

	return BinaryTreeOrder;
}

void PrintNode(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		cout << "该节点为空!" << endl;
	else
	{
		cout << "父节点为：" << pNode->val << endl;
		if (pNode->pLeft)
			cout << "其左儿子为：" << pNode->pLeft->val << endl;
		else
			cout << "其左儿子为空" << endl;
		if (pNode->pRight)
			cout << "其右儿子为：" << pNode->pRight->val << endl;
		else
			cout << "其右儿子为空" << endl;
	}
	cout << endl;
}

void PrintBinary(BinaryTreeNode* pRoot)
{
	PrintNode(pRoot);
	if (pRoot != nullptr)
	{
		if (pRoot->pLeft != nullptr)
		    PrintBinary(pRoot->pLeft);
		if (pRoot->pRight != nullptr)
		    PrintBinary(pRoot->pRight);
	}
}

int main()
{

	// 创建节点
	BinaryTreeNode* pRoot = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(11);

	// 连接父与子节点
	ConnectBinaryTreeNode(pRoot, pNode1, pNode2);
	ConnectBinaryTreeNode(pNode1, pNode3, pNode4);
	ConnectBinaryTreeNode(pNode2, pNode5, pNode6);

	PrintBinary(pRoot);

	vector<vector<int>> BinaryOrder = levelOrder(pRoot);
	
	cout << "[" << endl;
	for (int i = 0; i < BinaryOrder.size(); ++i)
	{
		cout << " [";
		for (int j = 0; j < BinaryOrder[i].size() - 1; ++j)
			cout << BinaryOrder[i][j] << ",";
		cout << BinaryOrder[i][BinaryOrder[i].size() - 1];
		cout << "]," << endl;
	}
	cout << "]" << endl;

	return 0;
}