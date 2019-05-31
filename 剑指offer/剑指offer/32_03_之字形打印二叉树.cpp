//-----------------------------------------------------------------------------
// 文 件 名: 32_03_之字形打印二叉树.cpp
// 作    者：adoredee
// 创建时间： 2019.05.31
// 描    述：之字形打印二叉树
// 版    本：
//-----------------------------------------------------------------------------

// 面试题32（三）：之字形打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
//      打印到一行。

#include <iostream>
#include <stack>

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

void ConnectBinareTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	else
	{
		pRoot->pLeft = pLeft;
		pRoot->pRight = pRight;
	}
}

void PrintZhi(BinaryTreeNode* pRoot)
{
	// 异常处理
	if (pRoot == nullptr)
		return;

	stack<BinaryTreeNode*> levels[2];     // 建立两个栈
	
	// 第一个栈，先存放左子节点，再存放右子节点
	// 第二个栈，先存放右子节点，再存放左子节点
	int current = 0;    // 栈的标志
	int next = 1;       // 栈的标志

	levels[current].push(pRoot);   // 将头节点压入第一个栈中
	
	while (!levels[0].empty() || !levels[1].empty())
	{
		BinaryTreeNode* pNode = levels[current].top();    // 取出当前栈的栈顶元素
		levels[current].pop();    // 弹出（删除）栈顶元素

		cout << pNode->value << " ";

		if (current == 0)    // 第一个栈，先存放左子节点，再存放右子节点
		{
			if (pNode->pLeft != nullptr)
				levels[next].push(pNode->pLeft);
			if (pNode->pRight != nullptr)
				levels[next].push(pNode->pRight);
		}
		else    // 第二个栈，先存放右子节点，再存放左子节点
		{
			if (pNode->pRight != nullptr)
				levels[next].push(pNode->pRight);
			if (pNode->pLeft != nullptr)
				levels[next].push(pNode->pLeft);
		}

		if (levels[current].empty())
		{
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}

int main()
{
	BinaryTreeNode* pRoot = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);

	ConnectBinareTreeNode(pRoot, pNode1, pNode2);
	ConnectBinareTreeNode(pNode1, pNode3, pNode4);
	ConnectBinareTreeNode(pNode2, pNode5, pNode6);

	cout << "之字形打印二叉树: " << endl;
	PrintZhi(pRoot);

	return 0;
}