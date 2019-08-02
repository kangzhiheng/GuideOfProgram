//-----------------------------------------------------------------------------
// �� �� ��: 54_�����������ĵ�k��ڵ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.01
// ��    ���������������ĵ�k��ڵ�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������54�������������ĵ�k�����
// ��Ŀ������һ�ö��������������ҳ����еĵ�k��Ľ�㡣

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
	���������������ʣ�
	1. ������ڵ�����������գ��������������нڵ��ֵ��С�����ĸ��ڵ��ֵ��
	2. ������ڵ�����������գ��������������нڵ��ֵ���������ĸ��ڵ��ֵ��
	3. ����ڵ����������Ҳ�ֱ�Ϊ�����������
	4. û�м�ֵ��ȵĽڵ㡣
		 5
	   /   \
	  3     7
	 / \   / \
	2   4 6   8
	ǰ������� 5 3 2 4 7 6 8
	��������� 2 3 4 5 6 7 8
	��������� 2 4 3 6 8 7 5
	��������������򣬿����ҵ��˶������ĵ�k��Ľڵ�
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


// ��ӡ����һ���ڵ�
void PrintBinaryTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		cout << "��ǰ�ڵ��ֵΪ��" << pNode->value << endl;

		// ��ӡ��ڵ�
		if (pNode->pLeft != nullptr)
			cout << "����ڵ��ֵΪ��" << pNode->pLeft->value << endl;
		else
			cout << "����ڵ�Ϊ�գ�" << endl;
		// ��ӡ�ҽڵ�
		if (pNode->pRight != nullptr)
			cout << "���ҽڵ��ֵΪ��" << pNode->pRight->value << endl;
		else
			cout << "���ҽڵ�Ϊ�գ�" << endl;

	}
	else
		cout << "�˽ڵ�Ϊ��" << endl;

	cout << endl;
}

// ��ӡ����������
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

// ǰ��������ݹ�ʵ��
void pre_order_traversal_Recursive(BinaryTreeNode* pRoot, vector<int>& pre_order)
{
	// �쳣�ж�
	if (pRoot == nullptr)
		cout << "����Ϊ�գ�" << endl;

	pre_order.emplace_back(pRoot->value);
	// cout << pRoot->value << " ";

	if (pRoot->pLeft != nullptr)
		pre_order_traversal_Recursive(pRoot->pLeft, pre_order);

	if (pRoot->pRight != nullptr)
		pre_order_traversal_Recursive(pRoot->pRight, pre_order);
}

// ǰ��������ǵݹ�ʵ��
/*
     ����ջ��˼�룬�ȱ����ҽڵ㣬�ٱ�����ڵ㣬�����Ļ����Ϳ����ȵ�����ڵ��ֵ���ٵ����ҽڵ��ֵ
*/
void pre_order_traversal_NoRecursive(BinaryTreeNode* pRoot, vector<int>& pre_order)
{
	// �쳣����
	if (pRoot == nullptr)
		cout << "����Ϊ��" << endl;

	stack<BinaryTreeNode*> node_save;
	node_save.push(pRoot);

	while (!node_save.empty())
	{ 
		BinaryTreeNode* node = node_save.top();    // ����ջ��Ԫ��
		pre_order.emplace_back(node->value);
		node_save.pop();    // ɾ��ջ��Ԫ��

		if (node->pRight != nullptr)
			node_save.push(node->pRight);    // ������ҽڵ�

		if (node->pLeft != nullptr)
			node_save.push(node->pLeft);
	}
}

// �������, �ݹ�ʵ��
void In_order_traversal_Recursive(BinaryTreeNode* pRoot, vector<int>& In_order)
{
	// �쳣�ж�
	if (pRoot == nullptr)
		cout << "����Ϊ�գ�" << endl;

	if (pRoot->pLeft != nullptr)
		In_order_traversal_Recursive(pRoot->pLeft, In_order);

	In_order.emplace_back(pRoot->value);
		
	if (pRoot->pRight != nullptr)
		In_order_traversal_Recursive(pRoot->pRight, In_order);
}

// �������, �ǵݹ�ʵ��
void In_order_traversal_NoRecursive(BinaryTreeNode* pRoot, vector<int>& In_order)
{
	// �쳣�ж�
	if (pRoot == nullptr)
		cout << "����Ϊ�գ�" << endl;

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

// �������, �ݹ�ʵ��
void post_order_traversal_Recursive(BinaryTreeNode* pRoot, vector<int>& post_order)
{
	// �쳣�ж�
	if (pRoot == nullptr)
		cout << "����Ϊ�գ�" << endl;

	if (pRoot->pLeft != nullptr)
		post_order_traversal_Recursive(pRoot->pLeft, post_order);
	
	if (pRoot->pRight != nullptr)
		post_order_traversal_Recursive(pRoot->pRight, post_order);

	post_order.emplace_back(pRoot->value);

}

// ����������ǵݹ�ʵ��
/*
    Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ��
	���P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
	����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ�
	��ͬ������ֱ�ӷ��ʸý�㡣
	�������������������P���Һ��Ӻ�����������ջ��
	�����ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ�
	���Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
*/
void post_order_traversal_NoRecursive(BinaryTreeNode* pRoot, vector<int>& post_order)
{
	// �쳣�ж�
	if (pRoot == nullptr)
		cout << "����Ϊ�գ�" << endl;

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
		cout << "������Ϊ��" << endl;
	else
	{
		for (int i = 0; i < arr.size(); ++i)
			cout << arr[i] << " ";
	}
}

int FindThekNum(BinaryTreeNode* pRoot, int k)
{
	// �쳣�ж�
	if (pRoot == nullptr)
		cout << "����Ϊ�գ�" << endl;

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
	cout << "1. ǰ�����:" << endl;
	cout << "���ݹ飩  ��";
	pre_order_traversal_Recursive(pNode5, pre_re);
	PrintVec(pre_re);
	cout << endl;
	cout << "���ǵݹ飩��";
	pre_order_traversal_NoRecursive(pNode5, pre_No);
	PrintVec(pre_No); 
	cout << endl << endl;

	vector<int> In_re, In_No;
	cout << "2. �������:" << endl;
	cout << "���ݹ飩  ��";
	In_order_traversal_Recursive(pNode5, In_re);
	PrintVec(In_re);
	cout << endl;
	cout << "���ǵݹ飩��";
	In_order_traversal_NoRecursive(pNode5, In_No); 
	PrintVec(In_No);
	cout << endl << endl;

	vector<int> post_re, post_No;
	cout << "3. �������:" << endl;
	cout << "���ݹ飩  ��";
	post_order_traversal_Recursive(pNode5, post_re);
	PrintVec(post_re);
	cout << endl;
	cout << "���ǵݹ飩��";
	post_order_traversal_NoRecursive(pNode5, post_No);
	PrintVec(post_No);
	cout << endl << endl;

	int k;
	cout << "����kֵ��";
	cin >> k;

	int val = FindThekNum(pNode5, k);

	cout << "�ö����������ĵ� " << k << " ��ڵ��ֵΪ��" << val << endl;

	return 0;
}