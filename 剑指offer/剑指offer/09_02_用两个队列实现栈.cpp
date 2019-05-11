//-----------------------------------------------------------------------------
// 文 件 名: 09_02_用两个队列实现栈.cpp
// 作    者：adoredee
// 创建时间：2019.04.20
// 描    述：用两个队列实现栈
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题9：用两个队列实现栈
// 题目：用两个队列实现一个栈。模拟栈的压入和弹出。

/*
思路：
1. 队列插入元素（push()功能），两个队列至少有一个是空的，所以有三种情况：
1). 如果两个队列都为空 ——> 向queue1添加元素
2). queue1非空而queue2为空，向queue1添加元素
3). queue2非空而queue1为空，向queue2添加元素
也就说是，向有元素的队列添加元素，为什么呢？
___            ___
| |            | |
|4|            | |
|2|            | |
|3|            | |
queue1         queue2

移动元素后
___            ___
| |            | |
| |            | |
| |            |2|
|4|            |3|
queue1        queue2

弹出queue1的元素即完成栈的删除元素操作(pop()功能)，此时queue1为空，
那么再进行添加添加元素(push()）操作时，应该向queue2添加，因为向有元素的
队列添加元素，栈里面的元素的顺序不变，例如添加元素6，则有
___            ___
| |            | |
| |            |6|
| |            |2|
| |            |3|
queue1        queue2
原来栈的元素（栈底到栈顶）为：3 —> 2 —> 4
弹出栈顶元素4，再添加元素6，有：3 —> 2 —> 6，如queue2所示。

2. 删除元素（pop()功能）: 当 前一个队列 向 后一个队列 转移元素时，
前一个队列只剩一个元素时，进行队列pop()操作，就模拟删除栈的元素。

/*
/*
1. 界面，如下：
"************************"
"|           栈         |"
"|    1.  添加元素       |"
"|    2.  删除元素       |"
"|    3.  打印元素       |"
"|    4.  退出程序       |"
"************************"
2. 功能：
- 向栈顶插入元素
- 弹出栈顶删除元素
- 从栈顶从栈底打印元素
*/

#include <iostream>
#include <queue>

using namespace std;

// 假设操作的元素为一个整数
class StackToWithTwoQueue
{
public:
	StackToWithTwoQueue();    // 构造函数
	~StackToWithTwoQueue();   // 析构函数
	void appendTail(int value);   // 向栈尾部添加元素
	int deleteTail();             // 删除队列头部元素
	void PrintStack();            // 从栈顶到栈底打印元素

private:
	queue<int> queue1;
	queue<int> queue2;
};

StackToWithTwoQueue::StackToWithTwoQueue()
{
}

StackToWithTwoQueue::~StackToWithTwoQueue()
{
}

// 模拟操作：向栈顶添加元素
void StackToWithTwoQueue::appendTail(int value)
{
	// 如果两个队列都为空
	if (queue1.empty() && queue2.empty())
		queue1.push(value);
	else if (queue1.empty())    // queue1为空而queue2非空，向queue2添加元素
		queue2.push(value);    
	else    // queue1非空而queue2为空，向queue1添加元素
		queue1.push(value);
}

// 模拟操作：弹出(删除)栈顶元素
// 至少保证有一个队列为空
int StackToWithTwoQueue::deleteTail()
{
	// 异常警告
	if (queue1.empty() && queue2.empty())
	{
		cout << "栈里没有元素！" << endl;
		return NULL;
	}
	// 队列1非空，队列2为空
	if (!queue1.empty() && queue2.empty())
	{
		// queue1里的元素个数少于1
		if (queue1.size() < 1)
			return NULL;
		// queue1里的元素个数大于1
		while (queue1.size() != 1)
		{
			int temp = queue1.front();    // 获取队列queue1头部元素
			queue1.pop();                 // 删除队列queue1头部元素
			queue2.push(temp);            // 将元素压入queue2
		}
		// queue1里的元素个数等于1
		int deleteStackTailvalue = queue1.front();
		cout << "要删除的元素为 ——> " << deleteStackTailvalue;
		queue1.pop();

		return deleteStackTailvalue;
	}
	// 队列2非空，队列1为空
	if (!queue2.empty() && queue1.empty())
	{
		// queue2里的元素个数少于1
		if (queue2.size() < 1)
			return NULL;
		// queue1里的元素个数大于1
		while (queue2.size() != 1)
		{
			int temp = queue2.front();    // 获取队列queue1头部元素
			queue2.pop();                 // 删除队列queue1头部元素
			queue1.push(temp);            // 将元素压入queue2
		}
		// queue1里的元素个数等于1
		int deleteStackTailvalue = queue2.front();
		cout << "要删除的栈顶元素为 ——> " << deleteStackTailvalue;
		queue2.pop();

		return deleteStackTailvalue;
	}
}

// 从栈顶到栈底打印元素
void StackToWithTwoQueue::PrintStack()
{
	// 都为空
	if (queue1.empty() && queue2.empty())
		cout << "栈为空" << endl;

	queue<int> queue_1 = queue1;
	queue<int> queue_2 = queue2;

	cout << "从栈顶到栈底打印元素: ";

	// 因为至少有一个队列为空，故与删除操作类似，将有元素的队列将元素依次移入空队列，
	// 直到只剩下一个元素位置，打印这个元素并删除。
	// 当两个列表都为空时，即打印元素完毕
	while (!queue_1.empty() || !queue_2.empty())
	{
		if (!queue_1.empty() && queue_2.empty())   // queue1非空，queue2为空
		{
			while (queue_1.size() != 1)
			{
				int temp = queue_1.front();
				queue_1.pop();
				queue_2.push(temp);
			}
			int val = queue_1.front();
			cout << val << "->";    // 栈顶元素
			queue_1.pop();
		}

		if (!queue_2.empty() && queue_1.empty())
		{
			if (queue_2.size() < 1)
				return;
			while (queue_2.size() != 1)
			{
				int temp = queue_2.front();
				queue_2.pop();
				queue_1.push(temp);
			}
			int val = queue_2.front();
			cout << val << "->";    // 栈顶元素
			queue_2.pop();
		}
	}


	cout << endl;
}

int main()
{
	StackToWithTwoQueue sStack;

	while (1)
	{
		cout << "************************" << endl;
		cout << "|          栈            |" << endl;
		cout << "|      1. 添加元素       |" << endl;
		cout << "|      2. 删除元素       |" << endl;
		cout << "|      3. 打印元素       |" << endl;
		cout << "|      4. 退出程序       |" << endl;
		cout << "************************" << endl;

		cout << "请输入操作序号(1~4) ——> ";
		char choiceval;
		cin >> choiceval;

		if (choiceval < '1' || choiceval > '4')
		{
			cout << "输入无效，请重新输入" << endl;
		}

		// 添加元素
		while (choiceval == '1')
		{
			cout << "向栈添加元素：";
			int val;
			cin >> val;
			sStack.appendTail(val);
			cout << "是否向栈添加元素(y/n): ";
			char choice = 'y';
			cin >> choice;
			if (choice == 'n' || choice == 'N')
				break;
		}

		// 删除元素
		while (choiceval == '2')
		{
			cout << "确认删除栈顶元素(y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y')
			{
				sStack.deleteTail();
				cout << endl;
			}
			else
			{
				break;
			}
		}

		// 从栈顶到栈底打印元素
		if (choiceval == '3')
		{
			sStack.PrintStack();
		}

		// 退出程序
		if (choiceval == '4')
		{
			cout << "退出程序 " << endl;
			exit(0);
		}
	}

	return 0;
}