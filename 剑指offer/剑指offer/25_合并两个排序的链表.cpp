//-----------------------------------------------------------------------------
// �� �� ��: 25_�ϲ��������������
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.15
// ��    �����ϲ��������������
// ��    ����
//-----------------------------------------------------------------------------

// ������25���ϲ��������������
// ��Ŀ������������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ�
//      �յ�������ġ���������ͼ3.11�е�����1������2����ϲ�֮���������������
//      ��3��ʾ��

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

// �ݹ�
ListNode* MergeTwoOrderedList(ListNode* pHead1, ListNode* pHead2)
{
	// �쳣����
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode* pMergeHead = nullptr;

	// ��С��������
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

	cout << "��һ����������Ϊ��";
	PrintList(pHead1);
	cout << endl;

	ListNode* pHead2 = CreateListNode(3);
	AddToTail(&pHead2, 4);
	AddToTail(&pHead2, 7);
	AddToTail(&pHead2, 9);

	cout << "�ڶ�����������Ϊ��";
	PrintList(pHead2);
	cout << endl;

	cout << "�ϲ��������Ϊ��";
	ListNode* MergeList = MergeTwoOrderedList(pHead1, pHead2);
	PrintList(MergeList);
	cout << endl;

	return 0;
}