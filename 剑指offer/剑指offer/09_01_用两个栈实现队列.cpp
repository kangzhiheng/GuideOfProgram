//-----------------------------------------------------------------------------
// �� �� ��: 09_01_������ջʵ�ֶ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.20
// ��    ����������ջʵ�ֶ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
//      ��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�

/*
˼·��
    ������ջstack1��stack2��
	1. ���в���Ԫ�أ����ݶ��С��Ƚ��ȳ������ص㣬����Ԫ��ȫ�������stack1��β����
	2. ����ɾ��Ԫ�أ�ɾ������ͷ��Ԫ�أ�stack2���Ԫ�ض���stack1���Ԫ���ȵ�����ѹ��ģ�
	                ���Ե�stack2��Ϊ��ʱ��stack2��ջ��Ԫ�ؾ��Ƕ���Ҫɾ����Ԫ�أ�
*/

/*
    1. ����С���棬���£�
	"************************" 
	"          ����          "
	"|    1.  ���Ԫ��       |" 
	"|    2.  ɾ��Ԫ��       |" 
	"|    3.  ��ӡԪ��       |" 
	"|    4.  �˳�����       |" 
	"************************" 
	2. ���ܣ�
	    ���в���Ԫ��
		����ɾ��Ԫ��
		��ӡ����Ԫ��
*/

#include <iostream>
#include <stack>

using namespace std;

// ���������Ԫ��Ϊһ������
class StackToQueue
{
public:
	StackToQueue();    // ���캯��
	~StackToQueue();   // ��������
	void appendTail(int value);   // �����β�����Ԫ��
	int deleteHead();             // ɾ������ͷ��Ԫ��
	void PrintQueue();            // ��ͷ��β��ӡ����Ԫ��

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

// �����β�����Ԫ��
void StackToQueue::appendTail(int value)
{
	stack1.push(value);
}

// ɾ������ͷ��Ԫ��
int StackToQueue::deleteHead()
{
	// stack2��û��Ԫ��
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			int temp = stack1.top();    // ȡ��ջ��Ԫ�أ���ʱԪ�ػ���stack1��ջ��
			stack1.pop();    // ����ջ��Ԫ�أ���ʱԪ�ر�ɾ��
			stack2.push(temp);  // ��Ԫ��Ѻ�뵽stack2��
		}
	}

	if (stack1.size() == 0 && stack2.size() == 0)
	{
		cout << "����Ϊ��" << endl;
		return NULL;
	}

	// ɾ������ͷ��Ԫ��
	int deleteQueueHeadvalue = stack2.top();
	stack2.pop();  // ����ջ��Ԫ�أ���ʱԪ�ر�ɾ��
	cout << "��ɾ���Ķ��е�ͷ��Ԫ��Ϊ ����> " << deleteQueueHeadvalue << endl;

	return deleteQueueHeadvalue;
}

// ��ͷ��β��ӡ����Ԫ��
void StackToQueue::PrintQueue()
{
	// ��Ϊ��
	if (stack1.size() == 0 && stack2.size() == 0)
		cout << "����Ϊ��" << endl;

	stack<int> stack_1 = stack1;
	stack<int> stack_2 = stack2;

	cout << "���д�ͷ��β��Ԫ������Ϊ: ";

	// stack_1��Ԫ�أ�stack_2��û��Ԫ��
	if (stack_1.size() > 0 && stack_2.size() <= 0)
	{
		stack<int> stack_tmpe;
		while (stack_1.size() > 0)
		{
			int temp = stack_1.top();    // ȡ��ջ��Ԫ�أ���ʱԪ�ػ���stack_1��ջ��
			stack_1.pop();    // ����ջ��Ԫ�أ���ʱԪ�ر�ɾ��
			stack_tmpe.push(temp);  // ��Ԫ��Ѻ�뵽stack_2��
		}
		while (stack_tmpe.size() > 0)
		{
			int temp = stack_tmpe.top();
			stack_tmpe.pop();
			cout  << temp << "->";
		}
	}
	else if(stack_1.size() <= 0 && stack_2.size() > 0)// stack_2��Ԫ�أ�stack_1��û��Ԫ��
	{
		while (stack_2.size() > 0)
		{
			int temp = stack_2.top();
			cout << temp << "->";
			stack_2.pop();
		}
	}
	else // stack_2��Ԫ�أ�stack_1��Ҳ��Ԫ��
	{
		while (stack_2.size() > 0)  // �ȵ���stack_2��ջ��Ԫ��
		{
			int temp = stack_2.top();
			cout << temp << "->";
			stack_2.pop();
		}
		// stack_2��ջ��Ԫ��ȫ��ɾ���󣬻ص������һ��stack_1��Ԫ�أ�stack_2��û��Ԫ��
		if (stack_1.size() > 0 && stack_2.size() <= 0)
		{
			stack<int> stack_tmpe;
			while (stack_1.size() > 0)
			{
				int temp = stack_1.top();    // ȡ��ջ��Ԫ�أ���ʱԪ�ػ���stack_1��ջ��
				stack_1.pop();    // ����ջ��Ԫ�أ���ʱԪ�ر�ɾ��
				stack_tmpe.push(temp);  // ��Ԫ��Ѻ�뵽stack_2��
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
		cout << "           ����         " << endl;
		cout << "|     1.  ���Ԫ��      |" << endl;
		cout << "|     2.  ɾ��Ԫ��      |" << endl;
		cout << "|     3.  ��ӡԪ��      |" << endl;
		cout << "|     4.  �˳�����      |" << endl;
		cout << "************************" << endl;

		cout << "������������(1~4) ����> ";
		char choiceval;
		cin >> choiceval;
		
		if (choiceval < '1' || choiceval > '4')
		{
			cout << "������Ч������������" << endl;
		}

		// ���Ԫ��
		while (choiceval == '1')
		{
			cout << "��������Ԫ�أ�";
			int val;
			cin >> val;
			qQueue.appendTail(val);
			cout << "�Ƿ���������Ԫ��(y/n): ";			
			char choice = 'y';
			cin >> choice;
			if (choice == 'n' || choice == 'N')
				break;
		}

		// ɾ��Ԫ��
		while (choiceval == '2')
		{
			cout << "ȷ��ɾ������ͷ��Ԫ��(y/n): ";
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

		// ��ͷ��β��ӡ����Ԫ��
		if (choiceval == '3')
		{
			qQueue.PrintQueue();
		}

		// �˳�����
		if (choiceval == '4')
		{
			cout << "�˳����� " << endl;
			exit(0);
		}
	}

	return 0;
}