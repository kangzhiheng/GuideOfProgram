//-----------------------------------------------------------------------------
// 文 件 名: 18_1_在O(1)时间内删除链表节点.cpp
// 作    者：adoredee
// 创建时间：2019.05.10
// 描    述：在O(1)时间内删除链表节点
// 版    本：
//-----------------------------------------------------------------------------
// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。

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

// 在头部添加节点
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

// 连接两个节点
void ConnectListNodes(ListNode* pPre, ListNode* pNext)
{
	if (pPre == nullptr)
	{
		cout << "节点连接错误" << endl;
		exit(1);
	}

	pPre->next = pNext;
}

void DeleteNode(ListNode** pHead, ListNode* pToBeDelete)
{
	// 异常检测
	// 如果原链表或者要被删除的链表节点为空
	if (!pHead || !pToBeDelete)
		return;

	/*
	假设要被删除的节点一定在链表里，在O(1)时间内删除指定节点，要考虑三种情况：
	1. 该节点不在链表尾部；
	2. 链表只有一个节点；
	3. 该节点在链表尾部；
	*/

	// 1. 该节点不在链表尾部；
	if (pToBeDelete->next != nullptr)
	{
		ListNode* pNext = pToBeDelete->next;    // 要被删除的节点的下一个节点
		pToBeDelete->value = pNext->value;      // 要被删除的节点的下一个节点的值赋给要被删除的节点处的值
		pToBeDelete->next = pNext->next;        // 将 要被删除的节点的下一个节点的下一个节点 接到 要被删除的节点的下一个节点 处

		delete pNext;
		pNext = nullptr;
	}
	// 2. 链表只有一个节点；
	else if (*pHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = nullptr;
		*pHead = nullptr;
	}
	// 3. 该节点在链表尾部；
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

// 打印节点内容
void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		cout << "该节点为空" << endl;
	else
		cout << "该节点的值为: " << pNode->value;
}

// 打印链表内容
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

	ListNode* pToBeDelete = pNode3;    // 指定要删除的节点
	PrintListNode(pToBeDelete);
	cout << endl;

	DeleteNode(&pNode, pToBeDelete);
	PrintList(pNode);

	return 0;
}