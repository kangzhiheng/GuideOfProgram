//-----------------------------------------------------------------------------
// �� �� ��: 28_�ԳƵĶ�����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.18
// ��    �����ԳƵĶ�����
// ��    ����
//-----------------------------------------------------------------------------

// ������28���ԳƵĶ�����
// ��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö�������
//      ���ľ���һ������ô���ǶԳƵġ�

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

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	// �������� ���� ͬʱΪ�գ���Ȼ
	/*
	        7
		   / \
		 7     7
		/ \   / 
	   7   7 7
	   ����������ǶԳƵ�
	*/
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->value != pRoot2->value)
		return false;
	
	// �ݹ� 
	return isSymmetrical(pRoot1->pLeft, pRoot2->pRight) && isSymmetrical(pRoot1->pRight, pRoot2->pLeft);
}

// ����
bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
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
	BinaryTreeNode* BinaryTreeNode1 = CreateBinaryNode(6);
	BinaryTreeNode* BinaryTreeNode2 = CreateBinaryNode(6);
	BinaryTreeNode* BinaryTreeNode3 = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode4 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode5 = CreateBinaryNode(7);
	BinaryTreeNode* BinaryTreeNode6 = CreateBinaryNode(0);

	ConnectTwoBinaryNode(BinaryTreepRoot, BinaryTreeNode1, BinaryTreeNode2);
	ConnectTwoBinaryNode(BinaryTreeNode1, BinaryTreeNode3, BinaryTreeNode4);
	ConnectTwoBinaryNode(BinaryTreeNode2, BinaryTreeNode5, BinaryTreeNode6);

	cout << "ԭ����Ϊ��" << endl;
	PrintTree(BinaryTreepRoot);

	if (isSymmetrical(BinaryTreepRoot))
		cout << "�ö������ǶԳƵġ�" << endl;
	else
		cout << "�ö��������ǶԳƵġ�" << endl;


	return 0;
}