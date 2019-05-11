//-----------------------------------------------------------------------------
// �� �� ��: 18_2_ɾ���������ظ��Ľڵ�.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.11
// ��    ����ɾ���������ظ��Ľڵ�
// ��    ����
//-----------------------------------------------------------------------------

// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿

#include <iostream>

using namespace std;

// ��������ṹ
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

// ���������ڵ�
void ConnectListNode(ListNode* pPre, ListNode* pNext)
{
	if (pPre == nullptr)
	{
		cout << "ǰһ�����Ϊ��" << endl;
		exit(EXIT_FAILURE);    // �൱��exit(1), EXIT_FAILURE���궨��Ϊ1����ʾ���̷������˳���
		                       // exit(0)��ʾ�����˳�
	}
	else
	{
		pPre->next = pNext;    // ���ڵ�ǰ������
	}
}

// ���Ĵ���
void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	// pNodeΪ��ǰ�ڵ�
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->next;
		bool needDelete = false;

		// �����ǰ�ڵ㲻Ϊ�գ��ҵ�ǰ�ڵ����һ���ڵ����ֵ�͵�ǰ�ڵ��ֵ��ͬ������Ҫɾ����������ͬ�Ľڵ�
		if (pNext != nullptr && pNext->value == pNode->value)
			needDelete = true;

		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		// ɾ���ظ��ڵ�
		else
		{
			int value = pNode->value;
			ListNode* pToBeDeleted = pNode;
			// whileѭ���ɾ�������ظ��Ľڵ�
			while (pToBeDeleted != nullptr && pToBeDeleted->value == value)
			{
				// ���Ĵ���
				pNext = pToBeDeleted->next;    // pNextΪҪɾ���ڵ����һ���ڵ�
				//  ɾ����ǰ�ڵ�
				delete pToBeDeleted; 
				pToBeDeleted = nullptr;
				// ��pNext���¸�ֵ��pToBeDeleted������ѭ�����鿴�Ƿ������ֵͬ�Ľڵ�
				pToBeDeleted = pNext;
			}

			if (pPreNode == nullptr)
				*pHead = pNext;
			else    // �ѵ�ǰҪɾ���Ľڵ��ǰһ���ڵ�����һ���ȵ�ǰֵ��Ľڵ�����
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
		cout << "�ýڵ�Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "�ýڵ��ֵ��>" << pNode->value << "�ýڵ�ĵ�ַΪ��>" << &pNode << endl;
	}
}

void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	cout << "�������ֵΪ��";
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

	cout << "������Ľڵ����Ϊ��>" << CountListNode(pHead) << endl;

	cout << "����ɾ���������ظ��Ľڵ�..." << endl;
	DeleteDuplication(&pHead);
	PrintList(pHead);

	return 0;
}