//-----------------------------------------------------------------------------
// 文 件 名: 24_反转链表.cpp
// 作    者：adoredee
// 创建时间：2019.05.06
// 描    述：反转链表
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
//      头结点。

#include <iostream>

using namespace std;

struct ListNode
{
	int value;
	struct ListNode* next;
};

// 反转链表
ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = nullptr;    // 反转链表的头节点
	ListNode* pNode = pHead;             // 当前节点
	ListNode* pPrev = nullptr;           // 当前节点的前一个结点

	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->next;   // 当前节点的下一个节点

		if (pNext == nullptr)
			pReverseHead = pNode;

		// 核心代码
		pNode->next = pPrev;   // 当前节点指向前一个节点
		// 更新节点
		pPrev = pNode;         // 把当前节点的前一个节点移到当前节点上
		pNode = pNext;         // 把当前节点移到当前节点的后一个节点上
	}

	return pReverseHead;
}

// 创建链表
ListNode* CreateListNode(int data)
{
	// 初始化
	ListNode* pNode = new ListNode();
	pNode->value = data;
	pNode->next = nullptr;

	return pNode;
}

// 头插法
void AddToHead(ListNode** pHead, int value)
{
	// 初始化
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

// 尾插法
void AddToTail(ListNode** pHead, int value)
{
	// 初始化
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

// 打印链表
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
	// 添加数据形成链表
	cout << "---------原始链表--------- " << endl;
	ListNode* pNode = CreateListNode(6);

	AddToTail(&pNode, 4);
	AddToTail(&pNode, 7);
	AddToTail(&pNode, 2);
	AddToHead(&pNode, 9);

	PrintList(pNode);
	cout << endl;

	cout << "---------反转链表--------- " << endl;
	ListNode* pReverseNode = ReverseList(pNode);
	PrintList(pReverseNode);
	cout << endl;

	return 0;
}