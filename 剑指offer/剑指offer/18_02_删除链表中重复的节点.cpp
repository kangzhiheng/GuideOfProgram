//-----------------------------------------------------------------------------
// 文 件 名: 18_2_删除链表中重复的节点.cpp
// 作    者：adoredee
// 创建时间：2019.05.11
// 描    述：删除链表中重复的节点
// 版    本：
//-----------------------------------------------------------------------------

// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？

#include <iostream>

using namespace std;

// 定义链表结构
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

// 连接两个节点
void ConnectListNode(ListNode* pPre, ListNode* pNext)
{
	if (pPre == nullptr)
	{
		cout << "前一个结点为空" << endl;
		exit(EXIT_FAILURE);    // 相当于exit(1), EXIT_FAILURE被宏定义为1，表示进程非正常退出；
		                       // exit(0)表示正常退出
	}
	else
	{
		pPre->next = pNext;    // 两节点前后连接
	}
}

// 核心代码
void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	// pNode为当前节点
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->next;
		bool needDelete = false;

		// 如果当前节点不为空，且当前节点的下一个节点里的值和当前节点的值相同，则需要删除这两个相同的节点
		if (pNext != nullptr && pNext->value == pNode->value)
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		// 删除重复节点
		else
		{
			int value = pNode->value;
			ListNode* pToBeDeleted = pNode;
			// while循环里，删除所有重复的节点
			while (pToBeDeleted != nullptr && pToBeDeleted->value == value)
			{
				// 核心代码
				pNext = pToBeDeleted->next;    // pNext为要删除节点的下一个节点
				//  删除当前节点
				delete pToBeDeleted; 
				pToBeDeleted = nullptr;
				// 将pNext重新赋值给pToBeDeleted，进行循环，查看是否具有相同值的节点
				pToBeDeleted = pNext;
			}

			if (pPreNode == nullptr)
				*pHead = pNext;
			else    // 把当前要删除的节点的前一个节点与下一个比当前值大的节点相连
				pPreNode->next = pNext;

			pNode = pNext;
		}
	}
}

int CountListNode(ListNode* pHead)
{
	ListNode* pNode = pHead;

	int NodeNums = 0;
	while (pNode != nullptr)
	{
		++NodeNums;
		pNode = pNode->next;
	}

	return NodeNums;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		cout << "该节点为空" << endl;
		return;
	}
	else
	{
		cout << "该节点的值—>" << pNode->value << "该节点的地址为—>" << &pNode << endl;
	}
}

void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	cout << "该链表的值为：";
	while (pNode != nullptr)
	{
		cout << pNode->value << "->";
		pNode = pNode->next;
	}

	cout << endl;
}

int main()
{

	ListNode* pHead = CreateListNode(3);
	ListNode* pNode1 = CreateListNode(3);
	ListNode* pNode2 = CreateListNode(3);
	ListNode* pNode3 = CreateListNode(4);
	ListNode* pNode4 = CreateListNode(5);
	ListNode* pNode5 = CreateListNode(6);
	ListNode* pNode6 = CreateListNode(6);


	ConnectListNode(pHead, pNode1);
	ConnectListNode(pNode1, pNode2);
	ConnectListNode(pNode2, pNode3);
	ConnectListNode(pNode3, pNode4);
	ConnectListNode(pNode4, pNode5);
	ConnectListNode(pNode5, pNode6);

	PrintList(pHead);

	cout << "该链表的节点个数为—>" << CountListNode(pHead) << endl;

	cout << "正在删除链表中重复的节点..." << endl;
	DeleteDuplication(&pHead);
	PrintList(pHead);

	return 0;
}