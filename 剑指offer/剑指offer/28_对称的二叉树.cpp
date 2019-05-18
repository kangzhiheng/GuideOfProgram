//-----------------------------------------------------------------------------
// 文 件 名: 28_对称的二叉树.cpp
// 作    者：adoredee
// 创建时间：2019.05.18
// 描    述：对称的二叉树
// 版    本：
//-----------------------------------------------------------------------------

// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
//      它的镜像一样，那么它是对称的。

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

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	// 结束条件 —— 同时为空，不然
	/*
	        7
		   / \
		 7     7
		/ \   / 
	   7   7 7
	   这种情况不是对称的
	*/
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->value != pRoot2->value)
		return false;
	
	// 递归 
	return isSymmetrical(pRoot1->pLeft, pRoot2->pRight) && isSymmetrical(pRoot1->pRight, pRoot2->pLeft);
}

// 重载
bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
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
	BinaryTreeNode* BinaryTreeNode1 = CreateBinaryNode(6);
	BinaryTreeNode* BinaryTreeNode2 = CreateBinaryNode(6);
	BinaryTreeNode* BinaryTreeNode3 = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode4 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode5 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode6 = CreateBinaryNode(0);

	ConnectTwoBinaryNode(BinaryTreepRoot, BinaryTreeNode1, BinaryTreeNode2);
	ConnectTwoBinaryNode(BinaryTreeNode1, BinaryTreeNode3, BinaryTreeNode4);
	ConnectTwoBinaryNode(BinaryTreeNode2, BinaryTreeNode5, BinaryTreeNode6);

	cout << "原链表为：" << endl;
	PrintTree(BinaryTreepRoot);

	if (isSymmetrical(BinaryTreepRoot))
		cout << "该二叉树是对称的。" << endl;
	else
		cout << "该二叉树不是对称的。" << endl;


	return 0;
}