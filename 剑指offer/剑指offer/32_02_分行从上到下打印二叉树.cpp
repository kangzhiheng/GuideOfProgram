//-----------------------------------------------------------------------------
// 文 件 名: 32_2_分行从上到下打印二叉树.cpp
// 作    者：adoredee
// 创建时间： 2019.05.25
// 描    述：分行从上到下打印二叉树
// 版    本：
//-----------------------------------------------------------------------------

// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
//      打印到一行。

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
	
void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pPre, BinaryTreeNode* pBack)
{
	if (pRoot == nullptr)
		return;

	pRoot->pLeft = pPre;
	pRoot->pRight = pBack;

}

void PrintFormTopToEndOnLayer(BinaryTreeNode* pRoot)
{
	// 异常检测
	if (pRoot == nullptr)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);

	int nextlevel = 0;  // 记录父节点的子节点数
	int toBrPrint = 1;  // 当前序列里的节点数
	int layers = 0;     // 该二叉树的层数

	// 当序列为空时，结束循环
	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		cout << pNode->value << " ";

		if (pNode->pLeft != nullptr)
		{
			dequeTreeNode.push_back(pNode->pLeft);
			++nextlevel;
		}
		if (pNode->pRight != nullptr)
		{
			dequeTreeNode.push_back(pNode->pRight);
			++nextlevel;
		}

		dequeTreeNode.pop_front();
		--toBrPrint;

		

		if (toBrPrint == 0)
		{
			++layers;
			cout << endl;
			toBrPrint = nextlevel;
			nextlevel = 0;
		}
	}
	cout << "该二叉树有" << layers << "层" << endl;
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

	// 分行从上到下打印二叉树
	PrintFormTopToEndOnLayer(pRoot);

	return 0;

}