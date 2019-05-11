//-----------------------------------------------------------------------------
// 文 件 名: 07_重建二叉树.cpp
// 作    者：adoredee
// 创建时间：2019.04.17
// 描    述：重建二叉树
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
//      入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
//      2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
//      图2.6所示的二叉树并输出它的头结点。

/*
   思路：
*/
#include <iostream>

using namespace std;

// 定义二叉树节点
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	/*
	1. startPreorder  前序遍历的起始位置
	2. endPreorder    前序遍历的结束位置

	3. startInorder   中序遍历的起始位置
	4. endInorder     中序遍历的结束位置
	*/

	// 前序遍历的第一个数字为根节点的值
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

	// 中序遍历找到根节点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;     // 在没有找到根节点之前，指针位置一直向后移动
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw exception("Invalid Input.");
	
	int leftLength = rootInorder - startInorder;   // 左子树的节点个数
	int* leftPreorderEnd = startPreorder + leftLength;   // 左子树的最后一个节点的值

	if (leftLength > 0)
	{
		// 构建左子树
		root->pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// 构建右子树
		root->pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	// 异常处理
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

// 打印二叉树
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// 输出当前节点的值
		cout << "value of this node is: " << pNode->value << endl;

		// 输出其左节点的值
		if (pNode->pLeft != nullptr)
			cout << "value of its left child is: " << pNode->pLeft->value << endl;
		else
			cout << "left child is nullptr." << endl;

		// 输出其左节点的值
		if (pNode->pRight != nullptr)
			cout << "value of its right child is: " << pNode->pRight->value << endl;
		else
			cout << "right child is nullptr." << endl;
	}
	else    // 该节点为空
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
		// 递归输出
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
	// 前序遍历
	int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	// 中序遍历
	int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	cout << "The preorder sequence is: ";
	for (int i = 0; i < length; i++)
		cout << preorder[i] << ' ';
	cout << endl;

	cout << "The inorder sequence is: ";
	for (int i = 0; i < length; i++)
		cout << inorder[i] << ' ';
	cout << endl;

	// 异常处理
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