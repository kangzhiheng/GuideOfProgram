//-----------------------------------------------------------------------------
// �� �� ��: 52_��������ĵ�һ�������ڵ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.22
// ��    ����52_��������ĵ�һ�������ڵ�
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������52����������ĵ�һ���������
// ��Ŀ���������������ҳ����ǵĵ�һ��������㡣

/*
    ˼·��
    1. ��ȡ��������ĳ��ȣ������Ȳ�pListDiff
    2. ���ó�����������pListDiff
    3. �ٱȽ���������ʣ�೤�ȵ�ÿһ���ڵ��Ƿ����(�����ڴ�λ�ú͸ýڵ��ֵ��С)
*/

#include <iostream>

using namespace std;

// ��������
struct ListNode
{
	int value;
	struct ListNode* Next;
};

ListNode* CreateListNode(int value)
{
	ListNode* pNew = new ListNode();

	pNew->value = value;
	pNew->Next = nullptr;

	return pNew;
}

void AddToHead(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->Next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else
	{
		pNew->Next = *pHead;
		*pHead = pNew;    // ���¶���ͷ�ڵ�
	}

}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->Next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->Next != nullptr)
			pNode = pNode->Next;
		pNode->Next = pNew;
	}
}

void ListConnection(ListNode* pPre, ListNode* pNext)
{
	if (pPre == nullptr)
	{
		cout << "�ڵ����Ӵ���" << endl;
		exit(1);
	}

	pPre->Next = pNext;

}

// ��ȡ������
int GetListLength(ListNode* pHead)
{
	if (pHead == nullptr)
		return 0;
	else
	{
		int ListLength = 0;
		ListNode* pNode = pHead;
		while (pNode != nullptr)
		{
			++ListLength;
			pNode = pNode->Next;
		}

		return ListLength;
	}
}

/*
    ���Ĵ���
	1. ��ȡ��������ĳ��ȣ������Ȳ�pListDiff
	2. ���ó�����������pListDiff
	3. �ٱȽ���������ʣ�೤�ȵ�ÿһ���ڵ��Ƿ����(�����ڴ�λ�ú͸ýڵ��ֵ��С)
*/
int FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	int pHeadLen1 = GetListLength(pHead1);
	int pHeadLen2 = GetListLength(pHead2);
	// Ĭ��phead1�ĳ��ȳ���pHead2
	ListNode* pListLong = pHead1;
	ListNode* pListShort = pHead2;
	int pListDiff = pHeadLen1 - pHeadLen2;
	if (pListDiff < 0)
	{
		pListDiff = pHeadLen2 - pHeadLen1;
		pListLong = pHead2;
		pListShort = pHead1;
	}

	// �ڳ�����������pListDiff��
	for (int i = 0; i < pListDiff; ++i)
		pListLong = pListLong->Next;

	// ��ͬʱ�Ƚϣ�ֱ���ҵ���ͬ�Ľڵ�
	// ѭ������������������Ϊ���Ҳ���ȣ����ʱ����whileѭ�����ҵ������ڵ�
	// while ((pListLong != nullptr) && (pListShort != nullptr) && (pListLong->value != pListShort->value))
	while ((pListLong != nullptr) && (pListShort != nullptr) && (pListLong != pListShort))
	{
		pListLong = pListLong->Next;
		pListShort = pListShort->Next;
	}

	ListNode* pListCommon = pListLong;
	return pListCommon->value;
}

// ��ӡ����
void PrintList(ListNode* pHead)
{
	if (pHead == nullptr)
		cout << "������Ϊ��" << endl;
	else
	{
		ListNode* pNode = pHead;
		while (pNode != nullptr)
		{
			cout << pNode->value << "��>";
			pNode = pNode->Next;
		}
		cout << endl;
	}
}

int main()
{
	// ��������1�� 1��2��3��6��7
	ListNode* pHead1 = CreateListNode(1);
	ListNode* p1Node1 = CreateListNode(2);
	ListNode* p1Node2 = CreateListNode(3);
	ListNode* p1Node3 = CreateListNode(6);
	// �������������Ľڵ�
	ListConnection(pHead1, p1Node1);
	ListConnection(p1Node1, p1Node2);
	ListConnection(p1Node2, p1Node3);

	AddToTail(&p1Node3, 7);

	// ��������2��4��5��6��7
	ListNode* pHead2 = CreateListNode(4);
	ListNode* p2Node1 = CreateListNode(5);
	// �������������Ľڵ�
	ListConnection(pHead2, p2Node1);
	// ����p2Node2��p1Node3������һ����p1Node3ӦΪ�����ڵ�
	ListConnection(p2Node1, p1Node3);


	cout << "����1Ϊ��";
	PrintList(pHead1);
	cout << "����2Ϊ��";
	PrintList(pHead2);
	
	int len1 = GetListLength(pHead1);
	int len2 = GetListLength(pHead2);
	cout << "����1�ĳ���Ϊ��" << len1 << endl;
	cout << "����2�ĳ���Ϊ��" << len2 << endl;

	// ListNode* pListCommonNode = FindFirstCommonNode(pHead1, pHead2);
	int pListCommonNodeValue = FindFirstCommonNode(pHead1, pHead2);

    cout << "����������Ĺ����ڵ��ֵΪ��" << pListCommonNodeValue << endl;

	return 0;
}