//-----------------------------------------------------------------------------
// 文 件 名: 09_01_用两个栈实现队列.cpp
// 作    者：adoredee
// 创建时间：2019.04.20
// 描    述：用两个栈实现队列
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
//      和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

/*
思路：
    有两个栈stack1和stack2，
	1. 队列插入元素：根据队列“先进先出”的特点，将新元素全部加入的stack1的尾部；
	2. 队列删除元素：删除队列头部元素，stack2里的元素都有stack1里的元素先弹出再压入的，
	                所以当stack2不为空时，stack2的栈顶元素就是队列要删除的元素；
*/

/*
    1. 做了小界面，如下：
	"************************" 
	"          队列          "
	"|    1.  添加元素       |" 
	"|    2.  删除元素       |" 
	"|    3.  打印元素       |" 
	"|    4.  退出程序       |" 
	"************************" 
	2. 功能：
	    队列插入元素
		队列删除元素
		打印队列元素
*/

#include <iostream>
#include <stack>

using namespace std;

// 假设操作的元素为一个整数
class StackToQueue
{
public:
	StackToQueue();    // 构造函数
	~StackToQueue();   // 析构函数
	void appendTail(int value);   // 向队列尾部添加元素
	int deleteHead();             // 删除队列头部元素
	void PrintQueue();            // 从头到尾打印队列元素

private:
	stack<int> stack1;
	stack<int> stack2;
};

StackToQueue::StackToQueue()
{
}

StackToQueue::~StackToQueue()
{
}

// 向队列尾部添加元素
void StackToQueue::appendTail(int value)
{
	stack1.push(value);
}

// 删除队列头部元素
int StackToQueue::deleteHead()
{
	// stack2里没有元素
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			int temp = stack1.top();    // 取出栈顶元素，此时元素还在stack1的栈顶
			stack1.pop();    // 弹出栈顶元素，此时元素被删除
			stack2.push(temp);  // 将元素押入到stack2里
		}
	}

	if (stack1.size() == 0 && stack2.size() == 0)
	{
		cout << "队列为空" << endl;
		return NULL;
	}

	// 删除队列头部元素
	int deleteQueueHeadvalue = stack2.top();
	stack2.pop();  // 弹出栈顶元素，此时元素被删除
	cout << "被删除的队列的头部元素为 ——> " << deleteQueueHeadvalue << endl;

	return deleteQueueHeadvalue;
}

// 从头到尾打印队列元素
void StackToQueue::PrintQueue()
{
	// 都为空
	if (stack1.size() == 0 && stack2.size() == 0)
		cout << "队列为空" << endl;

	stack<int> stack_1 = stack1;
	stack<int> stack_2 = stack2;

	cout << "序列从头到尾的元素依次为: ";

	// stack_1有元素，stack_2里没有元素
	if (stack_1.size() > 0 && stack_2.size() <= 0)
	{
		stack<int> stack_tmpe;
		while (stack_1.size() > 0)
		{
			int temp = stack_1.top();    // 取出栈顶元素，此时元素还在stack_1的栈顶
			stack_1.pop();    // 弹出栈顶元素，此时元素被删除
			stack_tmpe.push(temp);  // 将元素押入到stack_2里
		}
		while (stack_tmpe.size() > 0)
		{
			int temp = stack_tmpe.top();
			stack_tmpe.pop();
			cout  << temp << "->";
		}
	}
	else if(stack_1.size() <= 0 && stack_2.size() > 0)// stack_2有元素，stack_1里没有元素
	{
		while (stack_2.size() > 0)
		{
			int temp = stack_2.top();
			cout << temp << "->";
			stack_2.pop();
		}
	}
	else // stack_2有元素，stack_1里也有元素
	{
		while (stack_2.size() > 0)  // 先弹出stack_2的栈顶元素
		{
			int temp = stack_2.top();
			cout << temp << "->";
			stack_2.pop();
		}
		// stack_2的栈顶元素全部删除后，回到了情况一：stack_1有元素，stack_2里没有元素
		if (stack_1.size() > 0 && stack_2.size() <= 0)
		{
			stack<int> stack_tmpe;
			while (stack_1.size() > 0)
			{
				int temp = stack_1.top();    // 取出栈顶元素，此时元素还在stack_1的栈顶
				stack_1.pop();    // 弹出栈顶元素，此时元素被删除
				stack_tmpe.push(temp);  // 将元素押入到stack_2里
			}
			while (stack_tmpe.size() > 0)
			{
				int temp = stack_tmpe.top();
				stack_tmpe.pop();
				cout << temp << "->";
			}
		}
	}

	cout << endl;
}

int main()
{
	StackToQueue qQueue;

	while (1)
	{
		cout << "************************" << endl;
		cout << "           队列         " << endl;
		cout << "|     1.  添加元素      |" << endl;
		cout << "|     2.  删除元素      |" << endl;
		cout << "|     3.  打印元素      |" << endl;
		cout << "|     4.  退出程序      |" << endl;
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
			cout << "向队列添加元素：";
			int val;
			cin >> val;
			qQueue.appendTail(val);
			cout << "是否向队列添加元素(y/n): ";			
			char choice = 'y';
			cin >> choice;
			if (choice == 'n' || choice == 'N')
				break;
		}

		// 删除元素
		while (choiceval == '2')
		{
			cout << "确认删除队列头部元素(y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y')
			{
				qQueue.deleteHead();
			}
			else
			{
				break;
			}
		}

		// 从头到尾打印队列元素
		if (choiceval == '3')
		{
			qQueue.PrintQueue();
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