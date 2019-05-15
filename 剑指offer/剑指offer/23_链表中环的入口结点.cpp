//-----------------------------------------------------------------------------
// 文 件 名: 23_链表中环的入口结点.cpp
// 作    者：adoredee
// 创建时间：2019.05.15
// 描    述：链表中环的入口结点
// 版    本：
//-----------------------------------------------------------------------------

// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？

#include <iostream>

using namespace std;

// 定义链表
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

void ConnectListNodes(ListNode* pPre, ListNode* pNext)
{
	if (pPre == nullptr)
	{
		return;
		exit(EXIT_FAILURE);
	}
	else
		pPre->next = pNext;
}

// 核心代码
ListNode* MeetingNode(ListNode* pHead)
{
	// 异常处理
	if (pHead == nullptr)
		return nullptr;

	// 定义慢指针
	ListNode* pSlow = pHead->next;
	if (pSlow == nullptr)
		return nullptr;
	// 定义快指针
	ListNode* pFast = pSlow->next;

	while (pFast != nullptr && pSlow != nullptr)
	{
		// 如果快、慢指针相遇，则表示环存在
		if (pFast == pSlow)
			return pFast;
		// 慢指针一次移动一次
		pSlow = pSlow->next;
		// 快指针一次移动两次
		pFast = pFast->next;
		if (pFast != nullptr)
			pFast = pFast->next;
	}

	return nullptr;
}

ListNode* FindLoopNode(ListNode* pHead)
{
	// 找到相遇的节点
	ListNode* pMeetingNode = MeetingNode(pHead);
	// 如果没有相遇的节点，则该链表不存在环
	if (pMeetingNode == nullptr)
		return nullptr;
	// 否则至少存在一个环
	size_t NumOfLoopNode = 1;    // 环中节点数目
	ListNode* pNodeOfLoop = pMeetingNode;

	while (pNodeOfLoop->next != pMeetingNode)
	{
		pNodeOfLoop = pNodeOfLoop->next;
		++NumOfLoopNode;
	}
	/*
	    此时确定了环中的节点个数，此时再定义两个指针，前一个指针先走NumOfLoopNode个步，确保两指针的
		的距离为NumOfLoopNode，此时前、后两指针一起以相同的速度移动，如若相遇，即可确定环中的入口节点
	*/
	// 先移动前一个指针
	ListNode* pNode1 = pHead;
	for (size_t i = 0; i < NumOfLoopNode; ++i)
		pNode1 = pNode1->next;
	// 确定相遇
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}

	return pNode1;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		cout << "无次节点" << endl;
		return;
	}
	else
		cout << "该节点的值为: " << pNode->value << endl;
}

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
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode3);

	ListNode* pMeetingNode = FindLoopNode(pNode1);
	// 
	PrintListNode(pMeetingNode);

	cout << endl;

	return 0;
}