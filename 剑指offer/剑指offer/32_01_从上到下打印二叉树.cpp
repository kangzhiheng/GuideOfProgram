//-----------------------------------------------------------------------------
// �� �� ��: 32_1_���ϵ��´�ӡ������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.23
// ��    ���������еĴ��ϵ��´�ӡ������
// ��    ����
//-----------------------------------------------------------------------------

// ������32��һ���������д������´�ӡ������
// ��Ŀ���������´�ӡ����������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��

#include <iostream>
#include <deque>

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

void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;

	pRoot->pLeft = pLeft;
	pRoot->pRight = pRight;

}

void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	// �쳣����
	if (!pRoot)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();    // ȡ�����������Ԫ��
		dequeTreeNode.pop_front();    // ����������ʼԪ�أ��൱��ɾ��������

		cout << pNode->value << " ";

		if (pNode->pLeft)
			dequeTreeNode.push_back(pNode->pLeft);
		if (pNode->pRight)
			dequeTreeNode.push_back(pNode->pRight);
	}
}

int main()
{
	// �����ڵ�
	BinaryTreeNode* pRoot = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(11);

	// ���Ӹ����ӽڵ�
	ConnectBinaryTreeNode(pRoot, pNode1, pNode2);    
	ConnectBinaryTreeNode(pNode1, pNode3, pNode4);
	ConnectBinaryTreeNode(pNode2, pNode5, pNode6);

	// �����нڵ��ӡ��һ��
	PrintFromTopToBottom(pRoot);

	return 0;
}