//-----------------------------------------------------------------------------
// �� �� ��: 27_�������ľ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.17
// ��    �����������ľ���
// ��    ����
//-----------------------------------------------------------------------------

// ������27���������ľ���
// ��Ŀ�������һ������������һ�����������ú���������ľ���

#include <iostream>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* pLeft;    // ��ڵ�
	BinaryTreeNode* pRight;   // �ҽڵ�
};

// �����������ڵ�
BinaryTreeNode* CreateBinaryNode(int pRootValue)
{
	BinaryTreeNode* pNewRoot = new BinaryTreeNode();
	pNewRoot->value = pRootValue;
	pNewRoot->pLeft = nullptr;
	pNewRoot->pRight = nullptr;

	return pNewRoot;
}

// ���������ӽڵ�ṹ
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

// �ݹ�
void MirrorBinaryTree(BinaryTreeNode* pNode)
{
	// �쳣���
	if (pNode == nullptr)
	    return;
	// �ݹ��������
	if (pNode->pLeft == nullptr && pNode->pRight == nullptr)
		return;
	// �����������ڵ�
	BinaryTreeNode* pTemp = pNode->pLeft;
	pNode->pLeft = pNode->pRight;
	pNode->pRight = pTemp;

	if (pNode->pLeft)
		MirrorBinaryTree(pNode->pLeft);

	if (pNode->pRight)
		MirrorBinaryTree(pNode->pRight);
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// ��ӡ��ǰ�ڵ�
		cout << "��ǰ�ڵ��ֵΪ��" << pNode->value << endl;
		// ��ӡ��ڵ�
		if (pNode->pLeft != nullptr)
			cout << "����ڵ��ֵΪ�� " << pNode->pLeft->value << endl;
		else
			cout << "����ڵ�Ϊ�ա�" << endl;

		// ��ӡ�ҽڵ�
		if (pNode->pRight != nullptr)
			cout << "���ҽڵ��ֵΪ��" << pNode->pRight->value << endl;
		else
			cout << "���ҽڵ�Ϊ�ա�" << endl;
	}
	else
	{
		cout << "�ýڵ�Ϊ�ա�" << endl;
	}	

	cout << endl;
}

void PrintTree(BinaryTreeNode* pRoot)
{
	// ��ӡ��ǰ�ڵ�
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		// �ݹ����
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);

		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}

int main()
{
	BinaryTreeNode* BinaryTreepRoot = CreateBinaryNode(4);
	BinaryTreeNode* BinaryTreeNode1 = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode2 = CreateBinaryNode(2);
	BinaryTreeNode* BinaryTreeNode3 = CreateBinaryNode(0);
	BinaryTreeNode* BinaryTreeNode4 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode5 = CreateBinaryNode(8);
	BinaryTreeNode* BinaryTreeNode6 = CreateBinaryNode(3);

	ConnectTwoBinaryNode(BinaryTreepRoot, BinaryTreeNode1, BinaryTreeNode2);
	ConnectTwoBinaryNode(BinaryTreeNode1, BinaryTreeNode3, BinaryTreeNode4);
	ConnectTwoBinaryNode(BinaryTreeNode2, BinaryTreeNode5, BinaryTreeNode6);

	cout << "ԭ����Ϊ��" << endl;
	PrintTree(BinaryTreepRoot);

	MirrorBinaryTree(BinaryTreepRoot);
	cout << "��������Ϊ��" << endl;
	PrintTree(BinaryTreepRoot);

	return 0;
}