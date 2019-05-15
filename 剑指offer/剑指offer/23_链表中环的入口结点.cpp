//-----------------------------------------------------------------------------
// �� �� ��: 23_�����л�����ڽ��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.15
// ��    ���������л�����ڽ��
// ��    ����
//-----------------------------------------------------------------------------

// ������23�������л�����ڽ��
// ��Ŀ��һ�������а�����������ҳ�������ڽ�㣿

#include <iostream>

using namespace std;

// ��������
struct ListNode
{
	int value;
	struct ListNode* next;
};

// ��������ڵ�
ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->value = value;
	pNode->next = nullptr;

	return pNode;
}

// ͷ�巨
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

// ���Ĵ���
ListNode* MeetingNode(ListNode* pHead)
{
	// �쳣����
	if (pHead == nullptr)
		return nullptr;

	// ������ָ��
	ListNode* pSlow = pHead->next;
	if (pSlow == nullptr)
		return nullptr;
	// �����ָ��
	ListNode* pFast = pSlow->next;

	while (pFast != nullptr && pSlow != nullptr)
	{
		// ����졢��ָ�����������ʾ������
		if (pFast == pSlow)
			return pFast;
		// ��ָ��һ���ƶ�һ��
		pSlow = pSlow->next;
		// ��ָ��һ���ƶ�����
		pFast = pFast->next;
		if (pFast != nullptr)
			pFast = pFast->next;
	}

	return nullptr;
}

ListNode* FindLoopNode(ListNode* pHead)
{
	// �ҵ������Ľڵ�
	ListNode* pMeetingNode = MeetingNode(pHead);
	// ���û�������Ľڵ㣬����������ڻ�
	if (pMeetingNode == nullptr)
		return nullptr;
	// �������ٴ���һ����
	size_t NumOfLoopNode = 1;    // ���нڵ���Ŀ
	ListNode* pNodeOfLoop = pMeetingNode;

	while (pNodeOfLoop->next != pMeetingNode)
	{
		pNodeOfLoop = pNodeOfLoop->next;
		++NumOfLoopNode;
	}
	/*
	    ��ʱȷ���˻��еĽڵ��������ʱ�ٶ�������ָ�룬ǰһ��ָ������NumOfLoopNode������ȷ����ָ���
		�ľ���ΪNumOfLoopNode����ʱǰ������ָ��һ������ͬ���ٶ��ƶ�����������������ȷ�����е���ڽڵ�
	*/
	// ���ƶ�ǰһ��ָ��
	ListNode* pNode1 = pHead;
	for (size_t i = 0; i < NumOfLoopNode; ++i)
		pNode1 = pNode1->next;
	// ȷ������
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
		cout << "�޴νڵ�" << endl;
		return;
	}
	else
		cout << "�ýڵ��ֵΪ: " << pNode->value << endl;
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