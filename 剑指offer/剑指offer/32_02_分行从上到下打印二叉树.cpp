//-----------------------------------------------------------------------------
// �� �� ��: 32_2_���д��ϵ��´�ӡ������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.05.25
// ��    �������д��ϵ��´�ӡ������
// ��    ����
//-----------------------------------------------------------------------------

// ������32�����������д��ϵ��´�ӡ������
// ��Ŀ�����ϵ��°����ӡ��������ͬһ��Ľ�㰴�����ҵ�˳���ӡ��ÿһ��
//      ��ӡ��һ�С�

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
	
void ConnectBinaryTreeNode(BinaryTreeNode* pRoot, BinaryTreeNode* pPre, BinaryTreeNode* pBack)
{
	if (pRoot == nullptr)
		return;

	pRoot->pLeft = pPre;
	pRoot->pRight = pBack;

}

void PrintFormTopToEndOnLayer(BinaryTreeNode* pRoot)
{
	// �쳣���
	if (pRoot == nullptr)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pRoot);

	int nextlevel = 0;  // ��¼���ڵ���ӽڵ���
	int toBrPrint = 1;  // ��ǰ������Ľڵ���
	int layers = 0;     // �ö������Ĳ���

	// ������Ϊ��ʱ������ѭ��
	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		cout << pNode->value << " ";

		if (pNode->pLeft != nullptr)
		{
			dequeTreeNode.push_back(pNode->pLeft);
			++nextlevel;
		}
		if (pNode->pRight != nullptr)
		{
			dequeTreeNode.push_back(pNode->pRight);
			++nextlevel;
		}

		dequeTreeNode.pop_front();
		--toBrPrint;

		

		if (toBrPrint == 0)
		{
			++layers;
			cout << endl;
			toBrPrint = nextlevel;
			nextlevel = 0;
		}
	}
	cout << "�ö�������" << layers << "��" << endl;
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

	// ���д��ϵ��´�ӡ������
	PrintFormTopToEndOnLayer(pRoot);

	return 0;

}