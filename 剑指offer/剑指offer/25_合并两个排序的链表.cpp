//-----------------------------------------------------------------------------
// 文 件 名: 25_合并两个排序的链表
// 作    者：adoredee
// 创建时间：2019.05.15
// 描    述：合并两个排序的链表
// 版    本：
//-----------------------------------------------------------------------------

// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
//      照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
//      表3所示。

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

// 递归
ListNode* MergeTwoOrderedList(ListNode* pHead1, ListNode* pHead2)
{
	// 异常处理
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode* pMergeHead = nullptr;

	// 从小到大排序
	if (pHead1->value < pHead2->value)
	{
		pMergeHead = pHead1;
		pMergeHead->next = MergeTwoOrderedList(pHead1->next, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->next = MergeTwoOrderedList(pHead1, pHead2->next);
	}

	return pMergeHead;
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
	ListNode* pHead1 = CreateListNode(2);
	AddToTail(&pHead1, 3);
	AddToTail(&pHead1, 5);
	AddToTail(&pHead1, 7);

	cout << "第一个有序链表为：";
	PrintList(pHead1);
	cout << endl;

	ListNode* pHead2 = CreateListNode(3);
	AddToTail(&pHead2, 4);
	AddToTail(&pHead2, 7);
	AddToTail(&pHead2, 9);

	cout << "第二个有序链表为：";
	PrintList(pHead2);
	cout << endl;

	cout << "合并后的链表为：";
	ListNode* MergeList = MergeTwoOrderedList(pHead1, pHead2);
	PrintList(MergeList);
	cout << endl;

	return 0;
}