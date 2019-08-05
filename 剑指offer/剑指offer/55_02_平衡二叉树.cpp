// �� �� ��: 52_02_ƽ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.08.03
// ��    ���������������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������55��������ƽ�������
// ��Ŀ������һ�ö������ĸ���㣬�жϸ����ǲ���ƽ������������ĳ��������
//      ��������������������������1����ô������һ��ƽ���������

// �ο���https://blog.csdn.net/qq_26768741/article/details/52904313

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
		cout << "�ýڵ�Ϊ��" << pNode->value << endl;

		if (pNode->pLeft != nullptr)
			cout << "�������Ϊ��" << pNode->pLeft->value << endl;
		else
			cout << "�������Ϊ��!" << endl;

		if (pNode->pRight != nullptr)
			cout << "���Ҷ���Ϊ��" << pNode->pRight->value << endl;
		else
			cout << "���Ҷ���Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�ýڵ�Ϊ�գ�" << endl;
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
    ����	
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
	���������ʽΪ��
	             1
			    /  \
			   2    3
			  / \    \
			 4   5    6
			   /
			  7
    �˺��������з�ʽ��
    1. �տ�ʼ��pNode1��Ϊ�գ����Խ��е��ڶ���if���ʱ����ִ��IsBalanced(pRoot->pLeft, &nLeft)����ʱpRoot->pLeftΪpNode2�������ݹ飻
	2. pNode2�����Ҷ���pNode4��pNode5�������ݹ��������pNode4����pNode4�����������ٵݹ�pNode5��
	3. pNode4�����Ҷ��ӣ�����ݹ�������������Ƚ���ѭ���壬nLeft = nRight = 0, *nDepth = 1, ����true;
	4. ��ʱ���ж��� IsBalanced(pNode2->pLeft, &nLeft) ���е����� IsBalanced(pNode2->pRight, &nRight),��pNode5��
	5. pNode5�������ΪpNode7���Ҷ���Ϊ�գ�
	6. pNode7���Ҷ��ӽ�Ϊ�գ��ʽ���ѭ���壬nLeft = nRight = 0, *nDepth = 1, Ҳ����˵pNode7�ĸ߶�Ϊ1������true����ΪIsBalanced(pNode5->pLeft, &Left)Ϊtrue��
	   ��ΪpNode5���Ҷ���Ϊ�գ�����IsBalanced(pNode5->pRight, &nRight)ҲΪtrue��
	5. ��ʱIsBalanced(pNode5->pLeft, &nLeft)&&IsBalanced(pNode5->pRight, &nRight)==true��ֱ�ӽ���ѭ���壬*nDepth = 1 + 1 = 2����
	   pNode5�ĸ���Ϊ2��nLeft = 1��nRight = 0��
	2. �Դ�����һ������ϵݹ飻
*/
bool IsBalanced(BinaryTreeNode* pRoot, int* nDepth)
{
	// �ݹ��������
	if (pRoot == nullptr)
	{
		nDepth = 0;
		return true;
	}
	int nLeft = 0, nRight = 0;
	// cout << pRoot->value << endl;
	if (IsBalanced(pRoot->pLeft, &nLeft) && IsBalanced(pRoot->pRight, &nRight))
	{
		cout << "��ʱ���ڵ��ֵ��" << pRoot->value << endl;
		cout << "���������߶ȣ�" << nLeft << ", ���������߶ȣ�" << nRight << endl;
		int diff = nLeft - nRight;
		cout << "�����������ĸ߶Ȳ�Ϊ��" << diff << endl;
		if (diff <= 1 && diff >= -1)
		{
			// ���������������ȣ������ã����Ե��ݹ�ص���һ���ʱ���ϲ��е�nRight��nLeft�����������������
			*nDepth = 1 + (nRight > nLeft ? nRight : nLeft);		
			cout << "��ʱ���ĸ߶�Ϊ��" << *nDepth << endl << endl;
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

// ��һ�ַ������ֱ�����������������
int TheDepthOfBianryTree(BinaryTreeNode* pRoot)
{
	// �ݹ����
	if (pRoot == nullptr)
		return 0;

	int nLeft = TheDepthOfBianryTree(pRoot->pLeft);
	int nRight = TheDepthOfBianryTree(pRoot->pRight);

	return 1 + (nRight > nLeft ?  nRight : nLeft);
}

bool IsBalanced_Other(BinaryTreeNode* pRoot)
{
	// �ݹ����
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

	cout << "����һ����������ĵݹ鷽�����Ƽ�����";
	if (flag_1)
		cout << "����Ϊƽ���������" << endl;
	else
		cout << "��������ƽ���������" << endl;

	// cout << TheDepthOfBianryTree(pNode1) << endl;

	cout << "�����������������������Ȳ�ķ�����";
	bool flag_2 = IsBalanced_Other(pNode1);
	if (flag_2)
		cout << "����Ϊƽ���������" << endl;
	else
		cout << "��������ƽ���������" << endl;

	return 0;
}