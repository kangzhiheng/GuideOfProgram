//-----------------------------------------------------------------------------
// 文 件 名: 54_二叉搜索树的第k大节点.cpp
// 作    者：adoredee
// 创建时间： 2019.08.01
// 描    述：二叉搜索树的第k大节点
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
	二叉搜索树的性质：
	1. 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
	2. 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
	3. 任意节点的左、右子树也分别为二叉查找树；
	4. 没有键值相等的节点。
		 5
	   /   \
	  3     7
	 / \   / \
	2   4 6   8
	前序遍历： 5 3 2 4 7 6 8
	中序遍历： 2 3 4 5 6 7 8
	后序遍历： 2 4 3 6 8 7 5
	故中序遍历是升序，可以找到此二叉树的第k大的节点
*/

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pParent;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->value = value;
	pNode->pParent = nullptr;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

void ConnectBinaryTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent == nullptr)
		return;

	if (pLeft != nullptr)
		pParent->pLeft = pLeft;
	else
		pParent->pLeft = nullptr;

	if (pRight != nullptr)
		pParent->pRight = pRight;
	else
		pParent->pRight = nullptr;

}


// 打印其中一个节点
void PrintBinaryTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		cout << "当前节点的值为：" << pNode->value << endl;

		// 打印左节点
		if (pNode->pLeft != nullptr)
			cout << "其左节点的值为：" << pNode->pLeft->value << endl;
		else
			cout << "其左节点为空！" << endl;
		// 打印右节点
		if (pNode->pRight != nullptr)
			cout << "其右节点的值为：" << pNode->pRight->value << endl;
		else
			cout << "其右节点为空！" << endl;

	}
	else
		cout << "此节点为空" << endl;

	cout << endl;
}

// 打印整个二叉树
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

// 前序遍历，递归实现
void pre_order_traversal_Recursive(BinaryTreeNode* pRoot, vector<int>& pre_order)
{
	// 异常判断
	if (pRoot == nullptr)
		cout << "该树为空！" << endl;

	pre_order.emplace_back(pRoot->value);
	// cout << pRoot->value << " ";

	if (pRoot->pLeft != nullptr)
		pre_order_traversal_Recursive(pRoot->pLeft, pre_order);

	if (pRoot->pRight != nullptr)
		pre_order_traversal_Recursive(pRoot->pRight, pre_order);
}

// 前序遍历，非递归实现
/*
     利用栈的思想，先保存右节点，再保存左节点，这样的话，就可以先弹出左节点的值，再弹出右节点的值
*/
void pre_order_traversal_NoRecursive(BinaryTreeNode* pRoot, vector<int>& pre_order)
{
	// 异常处理
	if (pRoot == nullptr)
		cout << "该树为空" << endl;

	stack<BinaryTreeNode*> node_save;
	node_save.push(pRoot);

	while (!node_save.empty())
	{ 
		BinaryTreeNode* node = node_save.top();    // 弹出栈顶元素
		pre_order.emplace_back(node->value);
		node_save.pop();    // 删除栈顶元素

		if (node->pRight != nullptr)
			node_save.push(node->pRight);    // 先添加右节点

		if (node->pLeft != nullptr)
			node_save.push(node->pLeft);
	}
}

// 中序遍历, 递归实现
void In_order_traversal_Recursive(BinaryTreeNode* pRoot, vector<int>& In_order)
{
	// 异常判断
	if (pRoot == nullptr)
		cout << "该树为空！" << endl;

	if (pRoot->pLeft != nullptr)
		In_order_traversal_Recursive(pRoot->pLeft, In_order);

	In_order.emplace_back(pRoot->value);
		
	if (pRoot->pRight != nullptr)
		In_order_traversal_Recursive(pRoot->pRight, In_order);
}

// 中序遍历, 非递归实现
void In_order_traversal_NoRecursive(BinaryTreeNode* pRoot, vector<int>& In_order)
{
	// 异常判断
	if (pRoot == nullptr)
		cout << "该树为空！" << endl;

	stack<BinaryTreeNode*> node_save;

	BinaryTreeNode* pTemp = pRoot;

	while (pTemp != nullptr || !node_save.empty())
	{
		if (pTemp != nullptr)
		{
			node_save.push(pTemp);
			pTemp = pTemp->pLeft;
		}
        else
		{
			pTemp = node_save.top();
			In_order.emplace_back(pTemp->value);
			// cout << pTemp->value << " ";
			node_save.pop();

			pTemp = pTemp->pRight;
		}
	}
}

// 后序遍历, 递归实现
void post_order_traversal_Recursive(BinaryTreeNode* pRoot, vector<int>& post_order)
{
	// 异常判断
	if (pRoot == nullptr)
		cout << "该树为空！" << endl;

	if (pRoot->pLeft != nullptr)
		post_order_traversal_Recursive(pRoot->pLeft, post_order);
	
	if (pRoot->pRight != nullptr)
		post_order_traversal_Recursive(pRoot->pRight, post_order);

	post_order.emplace_back(pRoot->value);

}

// 后序遍历，非递归实现
/*
    要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
	如果P不存在左孩子和右孩子，则可以直接访问它；
	或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，
	则同样可以直接访问该结点。
	若非上述两种情况，则将P的右孩子和左孩子依次入栈，
	这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，
	左孩子和右孩子都在根结点前面被访问。
*/
void post_order_traversal_NoRecursive(BinaryTreeNode* pRoot, vector<int>& post_order)
{
	// 异常判断
	if (pRoot == nullptr)
		cout << "该树为空！" << endl;

	stack<BinaryTreeNode*> node_save;
	BinaryTreeNode* cur_node;
	BinaryTreeNode* pre_node = nullptr;
	node_save.push(pRoot);

	while (!node_save.empty())
	{
		cur_node = node_save.top();
		if ((cur_node->pLeft == nullptr && cur_node->pRight == nullptr)
			|| (pre_node != nullptr
				&& (pre_node == cur_node->pLeft || pre_node == cur_node->pRight)))
		{
			post_order.emplace_back(cur_node->value);
			node_save.pop();
			pre_node = cur_node;
		}
		else
		{
			if (cur_node->pRight != nullptr)
				node_save.push(cur_node->pRight);

			if (cur_node->pLeft != nullptr)
				node_save.push(cur_node->pLeft);
		}
	}

}

void PrintVec(vector<int>& arr)
{
	if (arr.empty())
		cout << "该数组为空" << endl;
	else
	{
		for (int i = 0; i < arr.size(); ++i)
			cout << arr[i] << " ";
	}
}

int FindThekNum(BinaryTreeNode* pRoot, int k)
{
	// 异常判断
	if (pRoot == nullptr)
		cout << "该树为空！" << endl;

	vector<int> arr;
	In_order_traversal_Recursive(pRoot, arr);

	return arr[k - 1];
}

int main()
{ 
	//       5
	//     /   \
	//    3     7
	//   / \   / \
	//  2   4 6   8
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

	ConnectBinaryTreeNode(pNode5, pNode3, pNode7);
	ConnectBinaryTreeNode(pNode3, pNode2, pNode4);
	ConnectBinaryTreeNode(pNode7, pNode6, pNode8);

	// PrintBinaryTree(pNode5);

	vector<int> pre_re, pre_No;
	cout << "1. 前序遍历:" << endl;
	cout << "（递归）  ：";
	pre_order_traversal_Recursive(pNode5, pre_re);
	PrintVec(pre_re);
	cout << endl;
	cout << "（非递归）：";
	pre_order_traversal_NoRecursive(pNode5, pre_No);
	PrintVec(pre_No); 
	cout << endl << endl;

	vector<int> In_re, In_No;
	cout << "2. 中序遍历:" << endl;
	cout << "（递归）  ：";
	In_order_traversal_Recursive(pNode5, In_re);
	PrintVec(In_re);
	cout << endl;
	cout << "（非递归）：";
	In_order_traversal_NoRecursive(pNode5, In_No); 
	PrintVec(In_No);
	cout << endl << endl;

	vector<int> post_re, post_No;
	cout << "3. 后序遍历:" << endl;
	cout << "（递归）  ：";
	post_order_traversal_Recursive(pNode5, post_re);
	PrintVec(post_re);
	cout << endl;
	cout << "（非递归）：";
	post_order_traversal_NoRecursive(pNode5, post_No);
	PrintVec(post_No);
	cout << endl << endl;

	int k;
	cout << "输入k值：";
	cin >> k;

	int val = FindThekNum(pNode5, k);

	cout << "该二叉搜索树的第 " << k << " 大节点的值为：" << val << endl;

	return 0;
}