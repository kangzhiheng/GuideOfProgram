//-----------------------------------------------------------------------------
// �� �� ��: 22_�����е�����k���ڵ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.13
// ��    ���������е�����k���ڵ�
// ��    ����
//-----------------------------------------------------------------------------

// ������22�������е�����k�����
// ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
//      �����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
//      ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
//      ֵΪ4�Ľ�㡣

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

// β�巨
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

// ���Ĵ���
ListNode* FindkthFromEndToBegin(ListNode* pHead, size_t k)
{
	// �쳣���
	if (pHead == nullptr || k == 0)
		return nullptr;

	// ˫ָ�뷨
	ListNode* pPre = pHead;
	ListNode* pNext = nullptr;

	// pPre��ǰ���� k - 2 + 1 = k - 1��
	for (int i = 0; i < k - 1; ++i)
	{
		if (pPre->next != nullptr)
			pPre = pPre->next;
		else    // ����ڵ�����С��k
			return nullptr;
	}
	// ��ʱpNext��pPreһ����
	pNext = pHead;
	while (pPre ->next != nullptr)
	{
		// pPre��pNextͬʱ��
		pPre = pPre->next;
		pNext = pNext->next;
	}

	return pNext;
}

// ��ӡ����ڵ�
void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
		cout << "�޸ýڵ�" << endl;
	else
		cout << "�ýڵ��ֵΪ ��> " << pNode->value << endl;
}

// ��ӡ��������
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

	cout << "ԭ����Ϊ��";
	PrintList(pNode);
	cout << endl;

	cout << "��������鿴�������е��������ڵ�(�ӵ�����1��ʼ����): ";
	int k;
	cin >> k;

	ListNode* pReserKthNode = FindkthFromEndToBegin(pNode, k);
	PrintListNode(pReserKthNode);
	cout << endl;

	return 0;
}