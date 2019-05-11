//-----------------------------------------------------------------------------
// �� �� ��: 08_����������һ�����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.19
// ��    ��������������һ�����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������8������������һ�����
// ��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
//      ���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣

/*
    ˼·�� 
        һ����pNode����������
		�����˽ڵ�����������Ϊ���ڵ���ҽڵ�
		�����˽ڵ�����������Ϊ���ڵ����ڵ�
*/

#include <iostream>

using namespace std;

/*--------- ��������� ���� �����˽ڵ�����ҽڵ㼰���ڵ� --------*/
struct BinaryTreeNode
{
	int value;

	BinaryTreeNode* pParents;    // ���ڵ�
	BinaryTreeNode* pLeft;       // ��ڵ�
	BinaryTreeNode* pRight;      // �ҽڵ�
};

/*--------------- �õ���һ���ڵ� --------------*/
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	// �쳣����
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;

	// һ����pNode����������
	if (pNode->pRight != nullptr)
	{
		/* ����д��
		while (pNode->pRight->pLeft != nullptr)    // ���ڴ˽ڵ������������ڵ�
			pNext = pNode->pRight->pLeft;
		pNext = pNode->pRight;    // �˽ڵ������������ڵ�Ϊ�գ��򷵻ش˽ڵ���ҽڵ�
		*/
		// ����д��
		// ���ȶ���˽ڵ��������
		BinaryTreeNode* pRightTree = pNode->pRight;
		while (pRightTree->pLeft != nullptr)    // ���ڴ˽ڵ������������ڵ�
			pNext = pRightTree->pLeft;

		pNext = pNode->pRight;    // �˽ڵ������������ڵ�Ϊ�գ��򷵻ش˽ڵ���ҽڵ�
	}
	else if (pNode->pParents != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParentsNode = pNode->pParents;   // ��ǰ�ڵ�ĸ��ڵ�
		// �����˽ڵ�����������Ϊ���ڵ���ҽڵ�
		while (pParentsNode != nullptr && pCurrent == pParentsNode->pRight)
		{
			pCurrent = pParentsNode;
			pParentsNode = pParentsNode->pParents;
		}
		// ��仰��������˼��
		// ������1.�� �˽ڵ�����������Ϊ���ڵ����ڵ�
		// 2. �ڶ�������Ľ����������û��һ���ڵ㣬���ڵĽڵ�������ڵ����ڵ�
		pNext = pParentsNode;
	}

	return pNext;
}

/*-------------------- ���������� ---------------------*/
// ��ʼ��
BinaryTreeNode* CreateBinaryTreNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->value = value;
	pNode->pParents = nullptr;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

// ���ӽڵ�
void ConnectedTreeNodes(BinaryTreeNode* ParentNode, BinaryTreeNode* LeftNode, BinaryTreeNode* RightNode)
{
	if (ParentNode != nullptr)
	{
		ParentNode->pLeft = LeftNode;
		ParentNode->pRight = RightNode;
		
		if (LeftNode != nullptr)
			LeftNode->pParents = ParentNode;
		if (RightNode != nullptr)
			RightNode->pParents = ParentNode;
	}
}

/*-------------------- ��ӡ������ ---------------------*/
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		// ��ӡ��ǰ�ڵ��ֵ
		cout << "��ǰ�ڵ��ֵ ����> " << pNode->value << endl;

		// ��ӡ�˽ڵ�������
		if (pNode->pLeft != nullptr)
			cout << "������� ����> " << pNode->pLeft->value << endl;
		else
			cout << "�������" << endl;

		// ��ӡ�˽ڵ���Ҷ���
		if (pNode->pRight != nullptr)
			cout << "���Ҷ��� ����> " << pNode->pRight->value << endl;
		else
			cout << "���Ҷ���" << endl;
	}
	else
	{
		cout << "�˽ڵ�Ϊ��" << endl;
	}

	cout << endl;
}

void PrintTree(BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->pLeft != nullptr)
			PrintTree(pRoot->pLeft);
		
		if (pRoot->pRight != nullptr)
			PrintTree(pRoot->pRight);
	}
}


int main()
{
	//       2
	//     /   \
	//    4     5
	//   / \   / \
	//  7   9 3   8
	BinaryTreeNode* Node2 = CreateBinaryTreNode(2);
	BinaryTreeNode* Node4 = CreateBinaryTreNode(4);
	BinaryTreeNode* Node5 = CreateBinaryTreNode(5);
	BinaryTreeNode* Node7 = CreateBinaryTreNode(7);
	BinaryTreeNode* Node9 = CreateBinaryTreNode(9);
	BinaryTreeNode* Node3 = CreateBinaryTreNode(3);
	BinaryTreeNode* Node8 = CreateBinaryTreNode(8);

	ConnectedTreeNodes(Node2, Node4, Node5);
	ConnectedTreeNodes(Node4, Node7, Node9);
	ConnectedTreeNodes(Node5, Node3, Node8);

	PrintTree(Node2);

	cout << "Ҫ���ҵĽڵ��ֵΪ: " << Node9->value << endl;
	BinaryTreeNode* pCurrent_Next = GetNext(Node9);
	cout << "Ҫ���ҵĽڵ����һ���Ľڵ��ֵΪ: " << pCurrent_Next->value << endl;

	return 0;
}