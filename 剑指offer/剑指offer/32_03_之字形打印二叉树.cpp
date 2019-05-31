//-----------------------------------------------------------------------------
// �� �� ��: 32_03_֮���δ�ӡ������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.05.31
// ��    ����֮���δ�ӡ������
// ��    ����
//-----------------------------------------------------------------------------

// ������32��������֮���δ�ӡ������
// ��Ŀ�����ϵ��°����ӡ��������ͬһ��Ľ�㰴�����ҵ�˳���ӡ��ÿһ��
//      ��ӡ��һ�С�

#include <iostream>
#include <stack>

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

void ConnectBinareTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pRoot == nullptr)
		return;
	else
	{
		pRoot->pLeft = pLeft;
		pRoot->pRight = pRight;
	}
}

void PrintZhi(BinaryTreeNode* pRoot)
{
	// �쳣����
	if (pRoot == nullptr)
		return;

	stack<BinaryTreeNode*> levels[2];     // ��������ջ
	
	// ��һ��ջ���ȴ�����ӽڵ㣬�ٴ�����ӽڵ�
	// �ڶ���ջ���ȴ�����ӽڵ㣬�ٴ�����ӽڵ�
	int current = 0;    // ջ�ı�־
	int next = 1;       // ջ�ı�־

	levels[current].push(pRoot);   // ��ͷ�ڵ�ѹ���һ��ջ��
	
	while (!levels[0].empty() || !levels[1].empty())
	{
		BinaryTreeNode* pNode = levels[current].top();    // ȡ����ǰջ��ջ��Ԫ��
		levels[current].pop();    // ������ɾ����ջ��Ԫ��

		cout << pNode->value << " ";

		if (current == 0)    // ��һ��ջ���ȴ�����ӽڵ㣬�ٴ�����ӽڵ�
		{
			if (pNode->pLeft != nullptr)
				levels[next].push(pNode->pLeft);
			if (pNode->pRight != nullptr)
				levels[next].push(pNode->pRight);
		}
		else    // �ڶ���ջ���ȴ�����ӽڵ㣬�ٴ�����ӽڵ�
		{
			if (pNode->pRight != nullptr)
				levels[next].push(pNode->pRight);
			if (pNode->pLeft != nullptr)
				levels[next].push(pNode->pLeft);
		}

		if (levels[current].empty())
		{
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}

int main()
{
	BinaryTreeNode* pRoot = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(7);

	ConnectBinareTreeNode(pRoot, pNode1, pNode2);
	ConnectBinareTreeNode(pNode1, pNode3, pNode4);
	ConnectBinareTreeNode(pNode2, pNode5, pNode6);

	cout << "֮���δ�ӡ������: " << endl;
	PrintZhi(pRoot);

	return 0;
}