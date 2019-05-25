//-----------------------------------------------------------------------------
// 文 件 名: 32_1_从上到下打印二叉树.cpp
// 作    者：adoredee
// 创建时间：2019.05.23
// 描    述：不分行的从上到下打印二叉树
// 版    本：
//-----------------------------------------------------------------------------

// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

#include <iostream>
#include <deque>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNew = new BinaryTreeNode();
	pNew->value = value;
	pNew->pLeft = nullptr;
	pNew->pRight = nullptr;

	return pNew;
}

void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;

	pRoot->pLeft = pLeft;
	pRoot->pRight = pRight;

}

void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	// 异常处理
	if (!pRoot)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();    // 取序列最上面的元素
		dequeTreeNode.pop_front();    // 弹出序列起始元素（相当于删除操作）

		cout << pNode->value << " ";

		if (pNode->pLeft)
			dequeTreeNode.push_back(pNode->pLeft);
		if (pNode->pRight)
			dequeTreeNode.push_back(pNode->pRight);
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

	// 把所有节点打印成一行
	PrintFromTopToBottom(pRoot);

	return 0;
}