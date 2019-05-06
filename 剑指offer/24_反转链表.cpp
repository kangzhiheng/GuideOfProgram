//-----------------------------------------------------------------------------
// �� �� ��: 24_��ת����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.06
// ��    ������ת����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
//      ͷ��㡣

#include <iostream>

using namespace std;

struct ListNode
{
	int value;
	struct ListNode* next;
};

// ��ת����
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = nullptr;    // ��ת�����ͷ�ڵ�
	ListNode* pNode = pHead;             // ��ǰ�ڵ�
	ListNode* pPrev = nullptr;           // ��ǰ�ڵ��ǰһ�����

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->next;   // ��ǰ�ڵ����һ���ڵ�

		if (pNext == nullptr)
			pReverseHead = pNode;

		// ���Ĵ���
		pNode->next = pPrev;   // ��ǰ�ڵ�ָ��ǰһ���ڵ�
		// ���½ڵ�
		pPrev = pNode;         // �ѵ�ǰ�ڵ��ǰһ���ڵ��Ƶ���ǰ�ڵ���
		pNode = pNext;         // �ѵ�ǰ�ڵ��Ƶ���ǰ�ڵ�ĺ�һ���ڵ���
	}

	return pReverseHead;
}

// ��������
ListNode* CreateListNode(int data)
{
	// ��ʼ��
	ListNode* pNode = new ListNode();
	pNode->value = data;
	pNode->next = nullptr;

	return pNode;
}

// ͷ�巨
void AddToHead(ListNode** pHead, int value)
{
	// ��ʼ��
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNode;
	else
	{
		pNode->next = *pHead;
		*pHead = pNode;
	}

}

// β�巨
void AddToTail(ListNode** pHead, int value)
{
	// ��ʼ��
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNode;

	else
	{
		ListNode* pNew = *pHead;
		while (pNew->next != nullptr)
			pNew = pNew->next;
		pNew->next = pNode;
	}
}

// ��ӡ����
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
	// ��������γ�����
	cout << "---------ԭʼ����--------- " << endl;
	ListNode* pNode = CreateListNode(6);

	AddToTail(&pNode, 4);
	AddToTail(&pNode, 7);
	AddToTail(&pNode, 2);
	AddToHead(&pNode, 9);

	PrintList(pNode);
	cout << endl;

	cout << "---------��ת����--------- " << endl;
	ListNode* pReverseNode = ReverseList(pNode);
	PrintList(pReverseNode);
	cout << endl;

	return 0;
}