//-----------------------------------------------------------------------------
// �� �� ��: 26_�����ӽṹ.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.16
// ��    ���������ӽṹ
// ��    ����
//-----------------------------------------------------------------------------

// ������26�������ӽṹ
// ��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ��

#include <iostream>

using namespace std;

// ����������Ľṹ
struct BinaryTreeNode
{
	double value;    // ����Ϊ������
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};

// ����������ڵ�
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

// �ж������������Ƿ����
bool equal(double Num1, double Num2)
{
	if (((Num1 - Num2) > -0.0000001) && ((Num1 - Num2) < 0.0000001))
		return true;
	else
		return false;
}

// ��ʱA�е�ĳ���ڵ��B�ĸ��ڵ�ֵ��ȣ��ж������Ƿ������ͬ�Ľṹ
bool DoseTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	// ��������
	if (pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr)
		return false;

	if (!equal(pRoot1->value, pRoot2->value))
		return false;

	return DoseTree1HasTree2(pRoot1->pLeft, pRoot2->pLeft) && DoseTree1HasTree2(pRoot1->pRight, pRoot2->pRight);
}

// �ڶ�����A���Ƿ�����������B���ڵ�ֵ��ͬ�Ľڵ�
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool exist = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr)
	{
		// ���������ݱȽϴ�С������ == ���ж�
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
		// �����ǰ�ڵ��ֵ
		cout << "��ǰ�ڵ��ֵΪ: " << pNode->value << endl;

		// �����ڵ��ֵ
		if (pNode->pLeft != nullptr)
			cout << "����ڵ��ֵΪ: " << pNode->pLeft->value << endl;
		else
			cout << "����ڵ�Ϊ��" << endl;

		// ����ҽڵ��ֵ
		if (pNode->pRight != nullptr)
			cout << "���ҽڵ��ֵΪ: " << pNode->pRight->value << endl;
		else
			cout << "���ҽڵ�Ϊ��" << endl;
	}
	else
		cout << "�ýڵ�Ϊ��" << endl;

	cout << endl;
}

void PrintTree(BinaryTreeNode* pRoot)
{
	// ��ӡ��ǰ�ڵ�
	PrintBinaryTreeNode(pRoot);

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
	// ���������A
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

	// ���������A
	cout << "������AΪ��" << endl;
	PrintTree(BinaryTreeRootA);

	// ���������B
	BinaryTreeNode* BinaryTreeRootB = CreateBinaryNode(5);
	BinaryTreeNode* BinaryTreeNode8 = CreateBinaryNode(0);
	BinaryTreeNode* BinaryTreeNode9 = CreateBinaryNode(7);

	ConnectTreeNode(BinaryTreeRootB, BinaryTreeNode8, BinaryTreeNode9);
	
	// ���������B
	cout << "������BΪ��" << endl;
	PrintTree(BinaryTreeRootB);

	bool BIsExistA = HasSubTree(BinaryTreeRootA, BinaryTreeRootB);
	if (BIsExistA)
		cout << "������B��A������ͬ�Ľṹ" << endl;
	else
		cout << "������B��A�в���������ͬ�Ľṹ" << endl;

	return 0;
}