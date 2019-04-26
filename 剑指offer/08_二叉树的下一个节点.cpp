//-----------------------------------------------------------------------------
// 文 件 名: 08_二叉树的下一个结点.cpp
// 作    者：adoredee
// 创建时间：2019.04.19
// 描    述：二叉树的下一个结点
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
//      树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

/*
    思路： 
        一、若pNode的有右子树
		二、此节点无右子树且为父节点的右节点
		三、此节点无右子树且为父节点的左节点
*/

#include <iostream>

using namespace std;

/*--------- 定义二叉树 —— 包含此节点的左右节点及父节点 --------*/
struct BinaryTreeNode
{
	int value;

	BinaryTreeNode* pParents;    // 父节点
	BinaryTreeNode* pLeft;       // 左节点
	BinaryTreeNode* pRight;      // 右节点
};

/*--------------- 得到下一个节点 --------------*/
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	// 异常处理
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;

	// 一、若pNode的有右子树
	if (pNode->pRight != nullptr)
	{
		/* 简略写法
		while (pNode->pRight->pLeft != nullptr)    // 存在此节点的右子树的左节点
			pNext = pNode->pRight->pLeft;
		pNext = pNode->pRight;    // 此节点的右子树的左节点为空，则返回此节点的右节点
		*/
		// 清晰写法
		// 首先定义此节点的右子树
		BinaryTreeNode* pRightTree = pNode->pRight;
		while (pRightTree->pLeft != nullptr)    // 存在此节点的右子树的左节点
			pNext = pRightTree->pLeft;

		pNext = pNode->pRight;    // 此节点的右子树的左节点为空，则返回此节点的右节点
	}
	else if (pNode->pParents != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParentsNode = pNode->pParents;   // 当前节点的父节点
		// 二、此节点无右子树且为父节点的右节点
		while (pParentsNode != nullptr && pCurrent == pParentsNode->pRight)
		{
			pCurrent = pParentsNode;
			pParentsNode = pParentsNode->pParents;
		}
		// 这句话有两个意思：
		// 三、（1.） 此节点无右子树且为父节点的左节点
		// 2. 第二种情况的结束情况，即没有一个节点，现在的节点是这个节点的左节点
		pNext = pParentsNode;
	}

	return pNext;
}

/*-------------------- 构建二叉树 ---------------------*/
// 初始化
BinaryTreeNode* CreateBinaryTreNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->value = value;
	pNode->pParents = nullptr;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

// 连接节点
void ConnectedTreeNodes(BinaryTreeNode* ParentNode, BinaryTreeNode* LeftNode, BinaryTreeNode* RightNode)
{
	if (ParentNode != nullptr)
	{
		ParentNode->pLeft = LeftNode;
		ParentNode->pRight = RightNode;
		
		if (LeftNode != nullptr)
			LeftNode->pParents = ParentNode;
		if (RightNode != nullptr)
			RightNode->pParents = ParentNode;
	}
}

/*-------------------- 打印二叉树 ---------------------*/
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// 打印当前节点的值
		cout << "当前节点的值 ——> " << pNode->value << endl;

		// 打印此节点的左儿子
		if (pNode->pLeft != nullptr)
			cout << "其左儿子 ——> " << pNode->pLeft->value << endl;
		else
			cout << "无左儿子" << endl;

		// 打印此节点的右儿子
		if (pNode->pRight != nullptr)
			cout << "其右儿子 ——> " << pNode->pRight->value << endl;
		else
			cout << "无右儿子" << endl;
	}
	else
	{
		cout << "此节点为空" << endl;
	}

	cout << endl;
}

void PrintTree(BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);
		
		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}


int main()
{
	//       2
	//     /   \
	//    4     5
	//   / \   / \
	//  7   9 3   8
	BinaryTreeNode* Node2 = CreateBinaryTreNode(2);
	BinaryTreeNode* Node4 = CreateBinaryTreNode(4);
	BinaryTreeNode* Node5 = CreateBinaryTreNode(5);
	BinaryTreeNode* Node7 = CreateBinaryTreNode(7);
	BinaryTreeNode* Node9 = CreateBinaryTreNode(9);
	BinaryTreeNode* Node3 = CreateBinaryTreNode(3);
	BinaryTreeNode* Node8 = CreateBinaryTreNode(8);

	ConnectedTreeNodes(Node2, Node4, Node5);
	ConnectedTreeNodes(Node4, Node7, Node9);
	ConnectedTreeNodes(Node5, Node3, Node8);

	PrintTree(Node2);

	cout << "要查找的节点的值为: " << Node9->value << endl;
	BinaryTreeNode* pCurrent_Next = GetNext(Node9);
	cout << "要查找的节点的下一个的节点的值为: " << pCurrent_Next->value << endl;

	return 0;
}