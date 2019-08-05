// 文 件 名: 52_02_平衡二叉树.cpp
// 作    者：adoredee
// 创建时间： 2019.08.03
// 描    述：二叉树的深度
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
//      任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

// 参考：https://blog.csdn.net/qq_26768741/article/details/52904313

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pParent;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* CreateBinnaryTree(int val)
{
	BinaryTreeNode* pNew = new BinaryTreeNode();
	pNew->value = val;
	pNew->pParent = nullptr;
	pNew->pLeft = nullptr;
	pNew->pRight = nullptr;

	return pNew;
}

void ConnectBianryTree(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;

	if (pLeft != nullptr)
		pRoot->pLeft = pLeft;
	else
		pRoot->pLeft = nullptr;

	if (pRight != nullptr)
		pRoot->pRight = pRight;
	else
		pRoot->pRight = nullptr;
}

void PrintBinaryTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		cout << "该节点为：" << pNode->value << endl;

		if (pNode->pLeft != nullptr)
			cout << "其左儿子为：" << pNode->pLeft->value << endl;
		else
			cout << "其左儿子为空!" << endl;

		if (pNode->pRight != nullptr)
			cout << "其右儿子为：" << pNode->pRight->value << endl;
		else
			cout << "其右儿子为空！" << endl;
	}
	else
	{
		cout << "该节点为空！" << endl;
	}
	cout << endl;
}


void PrintBinaryTree(BinaryTreeNode* pRoot)
{

	PrintBinaryTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->pLeft != nullptr)
			PrintBinaryTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintBinaryTree(pRoot->pRight);
	}
}

/*
    假设	
	BinaryTreeNode* pNode1 = CreateBinnaryTree(1);
	BinaryTreeNode* pNode2 = CreateBinnaryTree(2);
	BinaryTreeNode* pNode3 = CreateBinnaryTree(3);
	BinaryTreeNode* pNode4 = CreateBinnaryTree(4);
	BinaryTreeNode* pNode5 = CreateBinnaryTree(5);
	BinaryTreeNode* pNode6 = CreateBinnaryTree(6);
	BinaryTreeNode* pNode7 = CreateBinnaryTree(7);

	ConnectBianryTree(pNode1, pNode2, pNode3);
	ConnectBianryTree(pNode2, pNode4, pNode5);
	ConnectBianryTree(pNode3, nullptr, pNode6);
	ConnectBianryTree(pNode5, pNode7, nullptr);
	其二叉树形式为：
	             1
			    /  \
			   2    3
			  / \    \
			 4   5    6
			   /
			  7
    此函数的运行方式：
    1. 刚开始，pNode1不为空，所以进行到第二个if语句时，先执行IsBalanced(pRoot->pLeft, &nLeft)，此时pRoot->pLeft为pNode2，继续递归；
	2. pNode2有左右儿子pNode4和pNode5，继续递归其左儿子pNode4，若pNode4满足条件，再递归pNode5；
	3. pNode4无左右儿子，满足递归结束条件，首先进入循环体，nLeft = nRight = 0, *nDepth = 1, 返回true;
	4. 此时再判断与 IsBalanced(pNode2->pLeft, &nLeft) 并行的条件 IsBalanced(pNode2->pRight, &nRight),即pNode5；
	5. pNode5的左儿子为pNode7，右儿子为空，
	6. pNode7左右儿子皆为空，故进入循环体，nLeft = nRight = 0, *nDepth = 1, 也就是说pNode7的高度为1，返回true，故为IsBalanced(pNode5->pLeft, &Left)为true，
	   因为pNode5的右儿子为空，所以IsBalanced(pNode5->pRight, &nRight)也为true；
	5. 此时IsBalanced(pNode5->pLeft, &nLeft)&&IsBalanced(pNode5->pRight, &nRight)==true，直接进入循环体，*nDepth = 1 + 1 = 2，即
	   pNode5的告诉为2，nLeft = 1，nRight = 0；
	2. 以此类推一层层往上递归；
*/
bool IsBalanced(BinaryTreeNode* pRoot, int* nDepth)
{
	// 递归结束条件
	if (pRoot == nullptr)
	{
		nDepth = 0;
		return true;
	}
	int nLeft = 0, nRight = 0;
	// cout << pRoot->value << endl;
	if (IsBalanced(pRoot->pLeft, &nLeft) && IsBalanced(pRoot->pRight, &nRight))
	{
		cout << "此时父节点的值：" << pRoot->value << endl;
		cout << "其左子树高度：" << nLeft << ", 其右子树高度：" << nRight << endl;
		int diff = nLeft - nRight;
		cout << "其左右子树的高度差为：" << diff << endl;
		if (diff <= 1 && diff >= -1)
		{
			// 自身加上子树的深度，传引用，所以当递归回到上一层的时候，上层中的nRight和nLeft就是左右子树的深度
			*nDepth = 1 + (nRight > nLeft ? nRight : nLeft);		
			cout << "此时树的高度为：" << *nDepth << endl << endl;
			return true;
		}
	}
	
	return false;
}

bool IsBalanced(BinaryTreeNode* pRoot)
{
	int nDepth = 0;
	return IsBalanced(pRoot, &nDepth);
}

// 另一种方法：分别计算左右子树的深度
int TheDepthOfBianryTree(BinaryTreeNode* pRoot)
{
	// 递归出口
	if (pRoot == nullptr)
		return 0;

	int nLeft = TheDepthOfBianryTree(pRoot->pLeft);
	int nRight = TheDepthOfBianryTree(pRoot->pRight);

	return 1 + (nRight > nLeft ?  nRight : nLeft);
}

bool IsBalanced_Other(BinaryTreeNode* pRoot)
{
	// 递归出口
	if (pRoot == nullptr)
		return true;

	int nLeft = TheDepthOfBianryTree(pRoot->pLeft);
	int nRight = TheDepthOfBianryTree(pRoot->pRight);

	int nDiff = nLeft > nRight ? (nLeft - nRight) : (nRight - nLeft);

	if (nDiff > 1)
		return true;
	
	return IsBalanced_Other(pRoot->pLeft) && IsBalanced_Other(pRoot->pRight);

}

int main()
{
	BinaryTreeNode* pNode1 = CreateBinnaryTree(1);
	BinaryTreeNode* pNode2 = CreateBinnaryTree(2);
	BinaryTreeNode* pNode3 = CreateBinnaryTree(3);
	BinaryTreeNode* pNode4 = CreateBinnaryTree(4);
	BinaryTreeNode* pNode5 = CreateBinnaryTree(5);
	BinaryTreeNode* pNode6 = CreateBinnaryTree(6);
	BinaryTreeNode* pNode7 = CreateBinnaryTree(7);

	ConnectBianryTree(pNode1, pNode2, pNode3);
	ConnectBianryTree(pNode2, pNode4, pNode5);
	ConnectBianryTree(pNode3, nullptr, pNode6);
	ConnectBianryTree(pNode5, pNode7, nullptr);

	
	bool flag_1 = IsBalanced(pNode1);

	cout << "方法一：后序遍历的递归方法（推荐）：";
	if (flag_1)
		cout << "该树为平衡二叉树！" << endl;
	else
		cout << "该树不是平衡二叉树！" << endl;

	// cout << TheDepthOfBianryTree(pNode1) << endl;

	cout << "方法二：求各个左右子树深度差的方法：";
	bool flag_2 = IsBalanced_Other(pNode1);
	if (flag_2)
		cout << "该树为平衡二叉树！" << endl;
	else
		cout << "该树不是平衡二叉树！" << endl;

	return 0;
}