//-----------------------------------------------------------------------------
// �� �� ��: 06_��β��ͷ��ӡ����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.16
// ��    ������β��ͷ��ӡ����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��

/*
    ˼·������ջ������ȳ����ĵ��ص㣬�������Ľڵ㡣
*/

/*
��չ��
    1. ����
    2. ���룺ͷ�巨��β�巨������ֵ����
    3. ɾ��������ֵɾ����������ɾ��(һ����ɾ��ȫ����ͬ��ֵ����ֻɾ����һ���������ֵ�Ľڵ�)
    4. �����ԭ���������ת���
*/
#include <iostream>
#include <stack>

using namespace std;

// ��������ṹ
struct ListNode
{
	int Value;
	struct ListNode* next;
};

// ��������
ListNode* CreateListNode(int data)
{
	ListNode* pNode = new ListNode();
	pNode->Value = data;
	pNode->next = nullptr;

	return pNode;
}

// ͷ�巨
void AddToHead(ListNode** pHead, int value)
{
	ListNode* pNode = new ListNode();
	pNode->Value = value;
	pNode->next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNode;
	}
	else
	{
		pNode->next = *pHead;
		*pHead = pNode;    // ���¶���pHead
	}

}

// β�巨
void AddToTail(ListNode** pHead, int value)
{
	// ����һ���µ�������ʼ��
	ListNode* pNew = new ListNode();
	pNew->Value = value;
	pNew->next = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr)
			pNode = pNode->next;
		pNode->next = pNew;
	}
}

// ָ��λ�ò���Ԫ��
void AddAtIndex(ListNode** pHead, int index, int value)
{
	// ����һ���µ�������ʼ��
	ListNode* pNew = new ListNode();
	pNew->Value = value;
	pNew->next = nullptr;

	// ������ʱ�ڵ�
	ListNode* ptemp = *pHead;

	// �쳣����
	if (*pHead == nullptr)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}	

	if (index < 0)
		return;
	else if (index == 0)
		AddToHead(pHead, value);
	else
	{
		int i = 1;
		while (ptemp->next)    // pTemp->nextΪ��ǰ�ڵ㣬pTempΪ��ǰ�ڵ����һ���ڵ�
		{
			if (i==index)
			{
				pNew->next = ptemp->next;    // �½ڵ���뵽��ǰ�ڵ��λ�ã������½ڵ�pNew->next��ֵ��ʹ�½ڵ�ָ��ptemp->next
				ptemp->next = pNew;          // ���¶���pTemp->next��ʹ��ָ���½ڵ��������
				return;
			}
			else
			{
				i++;
				ptemp = ptemp->next;         // �ƶ�����һ���ڵ㣬��temp->next�ĵ�ַ��ֵ��pTemp
			}
		}

		char choice = 'y';
		cout << "λ��" << index << "��������ڵ������Ƿ���ӵ�����ĩ��(y/n): ";
		scanf("%c", &choice);
		if (choice == 'y')
		{
			// β�巨
			ptemp->next = pNew;
		}
	}
}

void DeleteAtIndex(ListNode** pHead, int index)
{
	// �쳣����
	if (pHead == nullptr)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}

	ListNode* pTemp = *pHead;         // �����ʱ�ڵ�
	ListNode* pToBeDeleted = nullptr; // ���Ҫ��ɾ���Ľڵ�

	if (index == 0)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		int i = 1;

		while (pTemp->next)    // pTemp->nextΪ��ǰ�ڵ�
		{
			if (index == i)
			{
				pToBeDeleted = pTemp->next;        // ɾ����ǰ�ڵ�
				pTemp->next = pTemp->next->next;   // ʹ��ǰ�ڵ����һ���ڵ�ָ��ǰ�ڵ�
				return;                            // ���޴˾䣬����Ľڵ㶼�ᱻɾ��
			}
			else if (i < index)
			{
				i++;
				pTemp = pTemp->next;
			}
		}
		// ����ֵ��������Χ
		if (pTemp->next == nullptr)
		{
			cout << "���棺�޴�����" << endl;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;          // new/delete���������malloc/free�ǿ⺯��
		pToBeDeleted = nullptr;
	}

}

// 
void DeleteAtValue(ListNode** pHead, int value, bool flag_alldelete = true)
{
	// flag_alldelete ���� true:��ʾ����������ͬ��value��ɾ����

	// �쳣����
	if (pHead == nullptr)
	{
		cout << "����Ϊ��!" << endl;
		return;
	}

	ListNode* pTemp = *pHead;         // �����ʱ�ڵ�
	ListNode* pToBeDeleted = nullptr; // ���Ҫ��ɾ���Ľڵ�

	if ((*pHead)->Value == value)    // ɾ��ͷ�ڵ�
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
		return;
	}
	else
	{
		while (pTemp->next)
		{
			if (pTemp->next->Value == value)
			{
				pToBeDeleted = pTemp->next;
				pTemp ->next = pTemp->next->next;
				if (flag_alldelete == false)    // flag_alldeleteΪfalse����ʾֻɾ����һ����value�Ľڵ�
				{
					return;
				}
			}
			else
			{
				pTemp = pTemp->next;
			}
			// ����û�д�ֵ
			if (pTemp->next == nullptr)
			{
				cout << "���棺�޴�ֵ" << endl;
			}
		}
	}

}

// ��β��ͷ��ӡ������һ����������
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);    // ��������������ָ��������ѹ��ջ��
		pNode = pNode->next;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();   // ����ջ��Ԫ��
		                       // pop() ���� ɾ��ջ��Ԫ��
		                       // top() ���� ȡ��ջ��Ԫ�أ�����ɾ����ߵ�Ԫ��
		cout << pNode->Value << ' ';
		nodes.pop();           // pop() ���� ɾ��ջ��Ԫ��
	}
}


// ��β��ͷ��ӡ�����������ݹ鷽��
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->next != nullptr)
			PrintListReversingly_Recursively(pHead->next);
		cout << pHead->Value << ' ';
	}
}

// ��ӡ����
void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->Value << ' ';
		pNode = pNode->next;
	}

	// cout << "��ӡ���" << endl;
}

//#include <iostream>
///*
//    ����NULL��nullptr
//	NULL ����> �궨��Ϊ0��C++��, ��C��, NULL���Ա�ʾΪ��ָ�룩
//	nullptr ����> ��ʶ��ָ�룬���Ա�ת�����������͵�ָ���bool���ͣ�������ת��Ϊ������
//*/
//// ��������
//void func(char*)
//{
//	cout << "It's me!" << endl;
//}
//
//void func(int)
//{
//	cout << "It's you!" << endl;
//}

int main()
{
	cout << endl << "*************�������************" << endl << endl;
	// ��������γ�����
	cout << "-------------ԭʼ����------------ " << endl;
    ListNode* pNode = CreateListNode(5);
    AddToTail(&pNode, 3);
    AddToTail(&pNode, 6);
    AddToTail(&pNode, 2);
    AddToHead(&pNode, 10);
    AddToTail(&pNode, 8);
    AddToHead(&pNode, 20);

	PrintList(pNode);
	cout << endl;
	
	cout << endl;
	cout << "---------ָ��λ���������--------- " << endl;
	int pIndex, pValue;
	cout << "����������ĵڼ����ڵ㿪ʼ��������(��0��ʼ): ";
	cin >> pIndex;
	cout << "��������ݵ�Ϊ: ";
	cin >> pValue;
	AddAtIndex(&pNode, pIndex, pValue);
	cout << "���ڵ�����Ϊ:";
	PrintList(pNode);
	cout << endl;

	cout << endl;
	cout << "-------------ɾ������------------ " << endl;
	cout << "------1. ָ��λ��ɾ������--------- " << endl;
	int dIndex;
	cout << "Ҫɾ���Ľڵ�Ϊ: ";
	cin >> dIndex;
	DeleteAtIndex(&pNode, dIndex);
	cout << "���ڵ�����Ϊ:";
	PrintList(pNode);
	cout << endl;

	cout << "------2. ָ��Ԫ��ֵɾ������------- " << endl;
	int dvalue;
	cout << "Ҫɾ����Ԫ��Ϊ: ";
	cin >> dvalue;
	DeleteAtValue(&pNode, dvalue, true);
	cout << "���ڵ�����Ϊ:";
	PrintList(pNode);
	cout << endl;

	cout << endl;
	cout << "-------------��ת����------------ " << endl;
	cout << "��һ�ַ���������" << endl;
	PrintListReversingly_Iteratively(pNode);

	cout << endl << "�ڶ��ַ������ݹ�" << endl;
	PrintListReversingly_Recursively(pNode);
	cout << endl;

//	func(NULL);    // ����func(int)     It's you!
//	func(nullptr); // ����func(char*)   It's me!

	return 0;
}