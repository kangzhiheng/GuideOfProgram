//-----------------------------------------------------------------------------
// 文 件 名: 26_树的子结构.cpp
// 作    者：adoredee
// 创建时间：2019.05.16
// 描    述：树的子结构
// 版    本：
//-----------------------------------------------------------------------------

// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

#include <iostream>

using namespace std;

// 定义二叉树的结构
struct BinaryTreeNode
{
	double value;    // 定义为浮点型
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

// 定义二叉树节点
BinaryTreeNode* CreateBinaryNode(int pRootValue)
{
	BinaryTreeNode* pNewRoot = new BinaryTreeNode();
	pNewRoot->value = pRootValue;
	pNewRoot->pLeft = nullptr;
	pNewRoot->pRight = nullptr;

	return pNewRoot;
}

void ConnectTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->pLeft = pLeft;
		pParent->pRight = pRight;
	}
}

// 判断两个浮点数是否相等
bool equal(double Num1, double Num2)
{
	if (((Num1 - Num2) > -0.0000001) && ((Num1 - Num2) < 0.0000001))
		return true;
	else
		return false;
}

// 此时A中的某个节点和B的根节点值相等，判断他们是否具有相同的结构
bool DoseTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	// 结束条件
	if (pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr)
		return false;

	if (!equal(pRoot1->value, pRoot2->value))
		return false;

	return DoseTree1HasTree2(pRoot1->pLeft, pRoot2->pLeft) && DoseTree1HasTree2(pRoot1->pRight, pRoot2->pRight);
}

// 在二叉树A中是否存在与二叉树B根节点值相同的节点
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool exist = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		// 浮点型数据比较大小不能用 == 来判断
		if (equal(pRoot1->value, pRoot2->value))
			exist = DoseTree1HasTree2(pRoot1, pRoot2);
		if (!exist)
			exist = HasSubTree(pRoot1->pLeft, pRoot2);
		if (!exist)
			exist = HasSubTree(pRoot1->pRight, pRoot2);
	}

	return exist;
}

void PrintBinaryTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// 输出当前节点的值
		cout << "当前节点的值为: " << pNode->value << endl;

		// 输出左节点的值
		if (pNode->pLeft != nullptr)
			cout << "其左节点的值为: " << pNode->pLeft->value << endl;
		else
			cout << "其左节点为空" << endl;

		// 输出右节点的值
		if (pNode->pRight != nullptr)
			cout << "其右节点的值为: " << pNode->pRight->value << endl;
		else
			cout << "其右节点为空" << endl;
	}
	else
		cout << "该节点为空" << endl;

	cout << endl;
}

void PrintTree(BinaryTreeNode* pRoot)
{
	// 打印当前节点
	PrintBinaryTreeNode(pRoot);

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
	// 定义二叉树A
	BinaryTreeNode* BinaryTreeRootA = CreateBinaryNode(3);
	BinaryTreeNode* BinaryTreeNode1 = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode2 = CreateBinaryNode(2);
	BinaryTreeNode* BinaryTreeNode3 = CreateBinaryNode(0);
	BinaryTreeNode* BinaryTreeNode4 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode5 = CreateBinaryNode(8);
	BinaryTreeNode* BinaryTreeNode6 = CreateBinaryNode(3);

	ConnectTreeNode(BinaryTreeRootA, BinaryTreeNode1, BinaryTreeNode2);
	ConnectTreeNode(BinaryTreeNode1, BinaryTreeNode3, BinaryTreeNode4);
	ConnectTreeNode(BinaryTreeNode2, BinaryTreeNode5, BinaryTreeNode6);

	// 输出二叉树A
	cout << "二叉树A为：" << endl;
	PrintTree(BinaryTreeRootA);

	// 定义二叉树B
	BinaryTreeNode* BinaryTreeRootB = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode8 = CreateBinaryNode(0);
	BinaryTreeNode* BinaryTreeNode9 = CreateBinaryNode(7);

	ConnectTreeNode(BinaryTreeRootB, BinaryTreeNode8, BinaryTreeNode9);
	
	// 输出二叉树B
	cout << "二叉树B为：" << endl;
	PrintTree(BinaryTreeRootB);

	bool BIsExistA = HasSubTree(BinaryTreeRootA, BinaryTreeRootB);
	if (BIsExistA)
		cout << "二叉树B在A中有相同的结构" << endl;
	else
		cout << "二叉树B在A中不具有有相同的结构" << endl;

	return 0;
}