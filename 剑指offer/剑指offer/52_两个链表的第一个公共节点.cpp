//-----------------------------------------------------------------------------
// 文 件 名: 52_两个链表的第一个公共节点.cpp
// 作    者：adoredee
// 创建时间： 2019.07.22
// 描    述：52_两个链表的第一个公共节点
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

/*
    思路：
    1. 获取两个链表的长度，做长度差pListDiff
    2. 再让长的链表先走pListDiff
    3. 再比较两个链表剩余长度的每一个节点是否相等(包括内存位置和该节点的值大小)
*/

#include <iostream>

using namespace std;

// 创建链表
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
		*pHead = pNew;    // 重新定义头节点
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
		cout << "节点连接错误！" << endl;
		exit(1);
	}

	pPre->Next = pNext;

}

// 获取链表长度
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
    核心代码
	1. 获取两个链表的长度，做长度差pListDiff
	2. 再让长的链表先走pListDiff
	3. 再比较两个链表剩余长度的每一个节点是否相等(包括内存位置和该节点的值大小)
*/
int FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	int pHeadLen1 = GetListLength(pHead1);
	int pHeadLen2 = GetListLength(pHead2);
	// 默认phead1的长度长于pHead2
	ListNode* pListLong = pHead1;
	ListNode* pListShort = pHead2;
	int pListDiff = pHeadLen1 - pHeadLen2;
	if (pListDiff < 0)
	{
		pListDiff = pHeadLen2 - pHeadLen1;
		pListLong = pHead2;
		pListShort = pHead1;
	}

	// 在长链表上先走pListDiff步
	for (int i = 0; i < pListDiff; ++i)
		pListLong = pListLong->Next;

	// 再同时比较，直到找到相同的节点
	// 循环条件：两个链表不能为空且不相等，相等时跳出while循环，找到公共节点
	// while ((pListLong != nullptr) && (pListShort != nullptr) && (pListLong->value != pListShort->value))
	while ((pListLong != nullptr) && (pListShort != nullptr) && (pListLong != pListShort))
	{
		pListLong = pListLong->Next;
		pListShort = pListShort->Next;
	}

	ListNode* pListCommon = pListLong;
	return pListCommon->value;
}

// 打印链表
void PrintList(ListNode* pHead)
{
	if (pHead == nullptr)
		cout << "该链表为空" << endl;
	else
	{
		ListNode* pNode = pHead;
		while (pNode != nullptr)
		{
			cout << pNode->value << "—>";
			pNode = pNode->Next;
		}
		cout << endl;
	}
}

int main()
{
	// 创建链表1， 1，2，3，6，7
	ListNode* pHead1 = CreateListNode(1);
	ListNode* p1Node1 = CreateListNode(2);
	ListNode* p1Node2 = CreateListNode(3);
	ListNode* p1Node3 = CreateListNode(6);
	// 连接两个样本的节点
	ListConnection(pHead1, p1Node1);
	ListConnection(p1Node1, p1Node2);
	ListConnection(p1Node2, p1Node3);

	AddToTail(&p1Node3, 7);

	// 创建链表2，4，5，6，7
	ListNode* pHead2 = CreateListNode(4);
	ListNode* p2Node1 = CreateListNode(5);
	// 连接两个样本的节点
	ListConnection(pHead2, p2Node1);
	// 将节p2Node2与p1Node3连接在一起，则p1Node3应为公共节点
	ListConnection(p2Node1, p1Node3);


	cout << "链表1为：";
	PrintList(pHead1);
	cout << "链表2为：";
	PrintList(pHead2);
	
	int len1 = GetListLength(pHead1);
	int len2 = GetListLength(pHead2);
	cout << "链表1的长度为：" << len1 << endl;
	cout << "链表2的长度为：" << len2 << endl;

	// ListNode* pListCommonNode = FindFirstCommonNode(pHead1, pHead2);
	int pListCommonNodeValue = FindFirstCommonNode(pHead1, pHead2);

    cout << "这两个链表的公共节点的值为：" << pListCommonNodeValue << endl;

	return 0;
}