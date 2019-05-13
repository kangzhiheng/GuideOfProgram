//-----------------------------------------------------------------------------
// 文 件 名: 22_链表中倒数第k个节点.cpp
// 作    者：adoredee
// 创建时间：2019.05.13
// 描    述：链表中倒数第k个节点
// 版    本：
//-----------------------------------------------------------------------------

// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
//      本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
//      从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
//      值为4的结点。

#include <iostream>

using namespace std;

// 创建链表
struct ListNode
{
	int value;
	struct ListNode* next;
};

// 创建链表节点
ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = nullptr;

	return pNode;
}

// 头插法
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

// 尾插法
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->value = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr)
			pNode = pNode->next;
		pNode->next = pNew;
	}	
}

// 核心代码
ListNode* FindkthFromEndToBegin(ListNode* pHead, size_t k)
{
	// 异常检测
	if (pHead == nullptr || k == 0)
		return nullptr;

	// 双指针法
	ListNode* pPre = pHead;
	ListNode* pNext = nullptr;

	// pPre向前走了 k - 2 + 1 = k - 1步
	for (int i = 0; i < k - 1; ++i)
	{
		if (pPre->next != nullptr)
			pPre = pPre->next;
		else    // 链表节点总数小于k
			return nullptr;
	}
	// 此时pNext与pPre一起走
	pNext = pHead;
	while (pPre ->next != nullptr)
	{
		// pPre和pNext同时走
		pPre = pPre->next;
		pNext = pNext->next;
	}

	return pNext;
}

// 打印链表节点
void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		cout << "无该节点" << endl;
	else
		cout << "该节点的值为 —> " << pNode->value << endl;
}

// 打印整个链表
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
	ListNode* pNode = CreateListNode(6);
	AddToTail(&pNode, 3);
	AddToTail(&pNode, 6);
	AddToTail(&pNode, 2);
	AddToHead(&pNode, 10);
	AddToTail(&pNode, 8);
	AddToHead(&pNode, 20);

	cout << "原链表为：";
	PrintList(pNode);
	cout << endl;

	cout << "输入您想查看的链表中倒数几个节点(从倒数第1开始算起): ";
	int k;
	cin >> k;

	ListNode* pReserKthNode = FindkthFromEndToBegin(pNode, k);
	PrintListNode(pReserKthNode);
	cout << endl;

	return 0;
}