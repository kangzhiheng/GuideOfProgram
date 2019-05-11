//-----------------------------------------------------------------------------
// 文 件 名: 06_从尾到头打印链表.cpp
// 作    者：adoredee
// 创建时间：2019.04.16
// 描    述：从尾到头打印链表
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

/*
    思路：利用栈“后进先出”的的特点，存放链表的节点。
*/

/*
扩展：
    1. 创建
    2. 插入：头插法、尾插法、索引值插入
    3. 删除：索引值删除，数据域删除(一次性删除全部相同的值还是只删除第一个含有这个值的节点)
    4. 输出：原序输出、反转输出
*/
#include <iostream>
#include <stack>

using namespace std;

// 定义链表结构
struct ListNode
{
	int Value;
	struct ListNode* next;
};

// 创建链表
ListNode* CreateListNode(int data)
{
	ListNode* pNode = new ListNode();
	pNode->Value = data;
	pNode->next = nullptr;

	return pNode;
}

// 头插法
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
		*pHead = pNode;    // 重新定义pHead
	}

}

// 尾插法
void AddToTail(ListNode** pHead, int value)
{
	// 创建一个新的链表并初始化
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

// 指定位置插入元素
void AddAtIndex(ListNode** pHead, int index, int value)
{
	// 创建一个新的链表并初始化
	ListNode* pNew = new ListNode();
	pNew->Value = value;
	pNew->next = nullptr;

	// 创建临时节点
	ListNode* ptemp = *pHead;

	// 异常处理
	if (*pHead == nullptr)
	{
		cout << "链表为空!" << endl;
		return;
	}	

	if (index < 0)
		return;
	else if (index == 0)
		AddToHead(pHead, value);
	else
	{
		int i = 1;
		while (ptemp->next)    // pTemp->next为当前节点，pTemp为当前节点的上一个节点
		{
			if (i==index)
			{
				pNew->next = ptemp->next;    // 新节点插入到当前节点的位置，并向新节点pNew->next赋值，使新节点指向ptemp->next
				ptemp->next = pNew;          // 重新定义pTemp->next，使其指向新节点的数据域
				return;
			}
			else
			{
				i++;
				ptemp = ptemp->next;         // 移动到下一个节点，把temp->next的地址赋值给pTemp
			}
		}

		char choice = 'y';
		cout << "位置" << index << "超出链表节点数，是否添加到链表末端(y/n): ";
		scanf("%c", &choice);
		if (choice == 'y')
		{
			// 尾插法
			ptemp->next = pNew;
		}
	}
}

void DeleteAtIndex(ListNode** pHead, int index)
{
	// 异常处理
	if (pHead == nullptr)
	{
		cout << "链表为空!" << endl;
		return;
	}

	ListNode* pTemp = *pHead;         // 存放临时节点
	ListNode* pToBeDeleted = nullptr; // 存放要被删除的节点

	if (index == 0)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		int i = 1;

		while (pTemp->next)    // pTemp->next为当前节点
		{
			if (index == i)
			{
				pToBeDeleted = pTemp->next;        // 删除当前节点
				pTemp->next = pTemp->next->next;   // 使当前节点的下一个节点指向当前节点
				return;                            // 如无此句，后面的节点都会被删除
			}
			else if (i < index)
			{
				i++;
				pTemp = pTemp->next;
			}
		}
		// 索引值超出链表范围
		if (pTemp->next == nullptr)
		{
			cout << "警告：无此索引" << endl;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;          // new/delete是运算符，malloc/free是库函数
		pToBeDeleted = nullptr;
	}

}

// 
void DeleteAtValue(ListNode** pHead, int value, bool flag_alldelete = true)
{
	// flag_alldelete —— true:表示链表所有相同的value都删除掉

	// 异常处理
	if (pHead == nullptr)
	{
		cout << "链表为空!" << endl;
		return;
	}

	ListNode* pTemp = *pHead;         // 存放临时节点
	ListNode* pToBeDeleted = nullptr; // 存放要被删除的节点

	if ((*pHead)->Value == value)    // 删除头节点
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
				if (flag_alldelete == false)    // flag_alldelete为false，表示只删除第一含有value的节点
				{
					return;
				}
			}
			else
			{
				pTemp = pTemp->next;
			}
			// 链表没有此值
			if (pTemp->next == nullptr)
			{
				cout << "警告：无此值" << endl;
			}
		}
	}

}

// 从尾到头打印链表方法一：迭代方法
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);    // 将链表的数据域和指针域依次压入栈中
		pNode = pNode->next;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();   // 弹出栈顶元素
		                       // pop() —— 删除栈顶元素
		                       // top() —— 取出栈顶元素，不会删掉里边的元素
		cout << pNode->Value << ' ';
		nodes.pop();           // pop() —— 删除栈顶元素
	}
}


// 从尾到头打印链表方法二：递归方法
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->next != nullptr)
			PrintListReversingly_Recursively(pHead->next);
		cout << pHead->Value << ' ';
	}
}

// 打印链表
void PrintList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		cout << pNode->Value << ' ';
		pNode = pNode->next;
	}

	// cout << "打印完毕" << endl;
}

//#include <iostream>
///*
//    关于NULL和nullptr
//	NULL ——> 宏定义为0（C++中, 在C中, NULL可以表示为空指针）
//	nullptr ——> 标识空指针，可以被转换成任意类型的指针和bool类型，但不能转换为整数。
//*/
//// 函数重载
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
	cout << endl << "*************链表操作************" << endl << endl;
	// 添加数据形成链表
	cout << "-------------原始链表------------ " << endl;
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
	cout << "---------指定位置添加数据--------- " << endl;
	int pIndex, pValue;
	cout << "您想在链表的第几个节点开始插入数据(从0开始): ";
	cin >> pIndex;
	cout << "插入的数据的为: ";
	cin >> pValue;
	AddAtIndex(&pNode, pIndex, pValue);
	cout << "现在的链表为:";
	PrintList(pNode);
	cout << endl;

	cout << endl;
	cout << "-------------删除数据------------ " << endl;
	cout << "------1. 指定位置删除数据--------- " << endl;
	int dIndex;
	cout << "要删除的节点为: ";
	cin >> dIndex;
	DeleteAtIndex(&pNode, dIndex);
	cout << "现在的链表为:";
	PrintList(pNode);
	cout << endl;

	cout << "------2. 指定元素值删除数据------- " << endl;
	int dvalue;
	cout << "要删除的元素为: ";
	cin >> dvalue;
	DeleteAtValue(&pNode, dvalue, true);
	cout << "现在的链表为:";
	PrintList(pNode);
	cout << endl;

	cout << endl;
	cout << "-------------反转链表------------ " << endl;
	cout << "第一种方法：迭代" << endl;
	PrintListReversingly_Iteratively(pNode);

	cout << endl << "第二种方法：递归" << endl;
	PrintListReversingly_Recursively(pNode);
	cout << endl;

//	func(NULL);    // 调用func(int)     It's you!
//	func(nullptr); // 调用func(char*)   It's me!

	return 0;
}