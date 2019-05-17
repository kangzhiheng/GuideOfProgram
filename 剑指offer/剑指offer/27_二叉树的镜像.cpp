//-----------------------------------------------------------------------------
// 文 件 名: 27_二叉树的镜像.cpp
// 作    者：adoredee
// 创建时间：2019.05.17
// 描    述：二叉树的镜像
// 版    本：
//-----------------------------------------------------------------------------

// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;    // 左节点
	BinaryTreeNode* pRight;   // 右节点
};

// 创建二叉树节点
BinaryTreeNode* CreateBinaryNode(int pRootValue)
{
	BinaryTreeNode* pNewRoot = new BinaryTreeNode();
	pNewRoot->value = pRootValue;
	pNewRoot->pLeft = nullptr;
	pNewRoot->pRight = nullptr;

	return pNewRoot;
}

// 连接两个子节点结构
void ConnectTwoBinaryNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	else
	{
		pRoot->pLeft = pLeft;
		pRoot->pRight = pRight;
	}
}

// 递归
void MirrorBinaryTree(BinaryTreeNode* pNode)
{
	// 异常检测
	if (pNode == nullptr)
	    return;
	// 递归结束条件
	if (pNode->pLeft == nullptr && pNode->pRight == nullptr)
		return;
	// 交换左右两节点
	BinaryTreeNode* pTemp = pNode->pLeft;
	pNode->pLeft = pNode->pRight;
	pNode->pRight = pTemp;

	if (pNode->pLeft)
		MirrorBinaryTree(pNode->pLeft);

	if (pNode->pRight)
		MirrorBinaryTree(pNode->pRight);
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// 打印当前节点
		cout << "当前节点的值为：" << pNode->value << endl;
		// 打印左节点
		if (pNode->pLeft != nullptr)
			cout << "其左节点的值为： " << pNode->pLeft->value << endl;
		else
			cout << "其左节点为空。" << endl;

		// 打印右节点
		if (pNode->pRight != nullptr)
			cout << "其右节点的值为：" << pNode->pRight->value << endl;
		else
			cout << "其右节点为空。" << endl;
	}
	else
	{
		cout << "该节点为空。" << endl;
	}	

	cout << endl;
}

void PrintTree(BinaryTreeNode* pRoot)
{
	// 打印当前节点
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		// 递归输出
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}

int main()
{
	BinaryTreeNode* BinaryTreepRoot = CreateBinaryNode(4);
	BinaryTreeNode* BinaryTreeNode1 = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode2 = CreateBinaryNode(2);
	BinaryTreeNode* BinaryTreeNode3 = CreateBinaryNode(0);
	BinaryTreeNode* BinaryTreeNode4 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode5 = CreateBinaryNode(8);
	BinaryTreeNode* BinaryTreeNode6 = CreateBinaryNode(3);

	ConnectTwoBinaryNode(BinaryTreepRoot, BinaryTreeNode1, BinaryTreeNode2);
	ConnectTwoBinaryNode(BinaryTreeNode1, BinaryTreeNode3, BinaryTreeNode4);
	ConnectTwoBinaryNode(BinaryTreeNode2, BinaryTreeNode5, BinaryTreeNode6);

	cout << "原链表为：" << endl;
	PrintTree(BinaryTreepRoot);

	MirrorBinaryTree(BinaryTreepRoot);
	cout << "镜像链表为：" << endl;
	PrintTree(BinaryTreepRoot);

	return 0;
}