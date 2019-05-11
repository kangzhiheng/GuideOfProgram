//-----------------------------------------------------------------------------
// �� �� ��: 18_1_��O(1)ʱ����ɾ������ڵ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.10
// ��    ������O(1)ʱ����ɾ������ڵ�
// ��    ����
//-----------------------------------------------------------------------------
// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣

#include <iostream>

using namespace std;

struct ListNode
{
	int value;
	struct ListNode* next;
};

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = nullptr;

	return pNode;
}

// ��ͷ����ӽڵ�
void AddToHead(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else
	{
		pNew->next = *pHead;
		*pHead = pNew;
	}

}

// ���������ڵ�
void ConnectListNodes(ListNode* pPre, ListNode* pNext)
{
	if (pPre == nullptr)
	{
		cout << "�ڵ����Ӵ���" << endl;
		exit(1);
	}

	pPre->next = pNext;
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDelete)
{
	// �쳣���
	// ���ԭ�������Ҫ��ɾ��������ڵ�Ϊ��
	if (!pHead || !pToBeDelete)
		return;

	/*
	����Ҫ��ɾ���Ľڵ�һ�����������O(1)ʱ����ɾ��ָ���ڵ㣬Ҫ�������������
	1. �ýڵ㲻������β����
	2. ����ֻ��һ���ڵ㣻
	3. �ýڵ�������β����
	*/

	// 1. �ýڵ㲻������β����
	if (pToBeDelete->next != nullptr)
	{
		ListNode* pNext = pToBeDelete->next;    // Ҫ��ɾ���Ľڵ����һ���ڵ�
		pToBeDelete->value = pNext->value;      // Ҫ��ɾ���Ľڵ����һ���ڵ��ֵ����Ҫ��ɾ���Ľڵ㴦��ֵ
		pToBeDelete->next = pNext->next;        // �� Ҫ��ɾ���Ľڵ����һ���ڵ����һ���ڵ� �ӵ� Ҫ��ɾ���Ľڵ����һ���ڵ� ��

		delete pNext;
		pNext = nullptr;
	}
	// 2. ����ֻ��һ���ڵ㣻
	else if (*pHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = nullptr;
		*pHead = nullptr;
	}
	// 3. �ýڵ�������β����
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != pToBeDelete)
			pNode = pNode->next;

		pNode->next = nullptr;
		delete pToBeDelete;
		pToBeDelete = nullptr;
	}
}

// ��ӡ�ڵ�����
void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		cout << "�ýڵ�Ϊ��" << endl;
	else
		cout << "�ýڵ��ֵΪ: " << pNode->value;
}

// ��ӡ��������
void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->value << "->";
		pNode = pNode->next;
	}
}

int main()
{
	ListNode* pNode = CreateListNode(8);
	ListNode* pNode1 = CreateListNode(5);
	ListNode* pNode2 = CreateListNode(6);
	ListNode* pNode3 = CreateListNode(7);
	ListNode* pNode4 = CreateListNode(3);

	ConnectListNodes(pNode, pNode1);
	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);

	PrintList(pNode);
	cout << endl;

	ListNode* pToBeDelete = pNode3;    // ָ��Ҫɾ���Ľڵ�
	PrintListNode(pToBeDelete);
	cout << endl;

	DeleteNode(&pNode, pToBeDelete);
	PrintList(pNode);

	return 0;
}