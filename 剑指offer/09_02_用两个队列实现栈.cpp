//-----------------------------------------------------------------------------
// �� �� ��: 09_02_����������ʵ��ջ.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.20
// ��    ��������������ʵ��ջ
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������9������������ʵ��ջ
// ��Ŀ������������ʵ��һ��ջ��ģ��ջ��ѹ��͵�����

/*
˼·��
1. ���в���Ԫ�أ�push()���ܣ�����������������һ���ǿյģ����������������
1). ����������ж�Ϊ�� ����> ��queue1���Ԫ��
2). queue1�ǿն�queue2Ϊ�գ���queue1���Ԫ��
3). queue2�ǿն�queue1Ϊ�գ���queue2���Ԫ��
Ҳ��˵�ǣ�����Ԫ�صĶ������Ԫ�أ�Ϊʲô�أ�
___            ___
| |            | |
|4|            | |
|2|            | |
|3|            | |
queue1         queue2

�ƶ�Ԫ�غ�
___            ___
| |            | |
| |            | |
| |            |2|
|4|            |3|
queue1        queue2

����queue1��Ԫ�ؼ����ջ��ɾ��Ԫ�ز���(pop()����)����ʱqueue1Ϊ�գ�
��ô�ٽ���������Ԫ��(push()������ʱ��Ӧ����queue2��ӣ���Ϊ����Ԫ�ص�
�������Ԫ�أ�ջ�����Ԫ�ص�˳�򲻱䣬�������Ԫ��6������
___            ___
| |            | |
| |            |6|
| |            |2|
| |            |3|
queue1        queue2
ԭ��ջ��Ԫ�أ�ջ�׵�ջ����Ϊ��3 ��> 2 ��> 4
����ջ��Ԫ��4�������Ԫ��6���У�3 ��> 2 ��> 6����queue2��ʾ��

2. ɾ��Ԫ�أ�pop()���ܣ�: �� ǰһ������ �� ��һ������ ת��Ԫ��ʱ��
ǰһ������ֻʣһ��Ԫ��ʱ�����ж���pop()��������ģ��ɾ��ջ��Ԫ�ء�

/*
/*
1. ���棬���£�
"************************"
"|           ջ         |"
"|    1.  ���Ԫ��       |"
"|    2.  ɾ��Ԫ��       |"
"|    3.  ��ӡԪ��       |"
"|    4.  �˳�����       |"
"************************"
2. ���ܣ�
- ��ջ������Ԫ��
- ����ջ��ɾ��Ԫ��
- ��ջ����ջ�״�ӡԪ��
*/

#include <iostream>
#include <queue>

using namespace std;

// ���������Ԫ��Ϊһ������
class StackToWithTwoQueue
{
public:
	StackToWithTwoQueue();    // ���캯��
	~StackToWithTwoQueue();   // ��������
	void appendTail(int value);   // ��ջβ�����Ԫ��
	int deleteTail();             // ɾ������ͷ��Ԫ��
	void PrintStack();            // ��ջ����ջ�״�ӡԪ��

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

// ģ���������ջ�����Ԫ��
void StackToWithTwoQueue::appendTail(int value)
{
	// ����������ж�Ϊ��
	if (queue1.empty() && queue2.empty())
		queue1.push(value);
	else if (queue1.empty())    // queue1Ϊ�ն�queue2�ǿգ���queue2���Ԫ��
		queue2.push(value);    
	else    // queue1�ǿն�queue2Ϊ�գ���queue1���Ԫ��
		queue1.push(value);
}

// ģ�����������(ɾ��)ջ��Ԫ��
// ���ٱ�֤��һ������Ϊ��
int StackToWithTwoQueue::deleteTail()
{
	// �쳣����
	if (queue1.empty() && queue2.empty())
	{
		cout << "ջ��û��Ԫ�أ�" << endl;
		return NULL;
	}
	// ����1�ǿգ�����2Ϊ��
	if (!queue1.empty() && queue2.empty())
	{
		// queue1���Ԫ�ظ�������1
		if (queue1.size() < 1)
			return NULL;
		// queue1���Ԫ�ظ�������1
		while (queue1.size() != 1)
		{
			int temp = queue1.front();    // ��ȡ����queue1ͷ��Ԫ��
			queue1.pop();                 // ɾ������queue1ͷ��Ԫ��
			queue2.push(temp);            // ��Ԫ��ѹ��queue2
		}
		// queue1���Ԫ�ظ�������1
		int deleteStackTailvalue = queue1.front();
		cout << "Ҫɾ����Ԫ��Ϊ ����> " << deleteStackTailvalue;
		queue1.pop();

		return deleteStackTailvalue;
	}
	// ����2�ǿգ�����1Ϊ��
	if (!queue2.empty() && queue1.empty())
	{
		// queue2���Ԫ�ظ�������1
		if (queue2.size() < 1)
			return NULL;
		// queue1���Ԫ�ظ�������1
		while (queue2.size() != 1)
		{
			int temp = queue2.front();    // ��ȡ����queue1ͷ��Ԫ��
			queue2.pop();                 // ɾ������queue1ͷ��Ԫ��
			queue1.push(temp);            // ��Ԫ��ѹ��queue2
		}
		// queue1���Ԫ�ظ�������1
		int deleteStackTailvalue = queue2.front();
		cout << "Ҫɾ����ջ��Ԫ��Ϊ ����> " << deleteStackTailvalue;
		queue2.pop();

		return deleteStackTailvalue;
	}
}

// ��ջ����ջ�״�ӡԪ��
void StackToWithTwoQueue::PrintStack()
{
	// ��Ϊ��
	if (queue1.empty() && queue2.empty())
		cout << "ջΪ��" << endl;

	queue<int> queue_1 = queue1;
	queue<int> queue_2 = queue2;

	cout << "��ջ����ջ�״�ӡԪ��: ";

	// ��Ϊ������һ������Ϊ�գ�����ɾ���������ƣ�����Ԫ�صĶ��н�Ԫ����������ն��У�
	// ֱ��ֻʣ��һ��Ԫ��λ�ã���ӡ���Ԫ�ز�ɾ����
	// �������б�Ϊ��ʱ������ӡԪ�����
	while (!queue_1.empty() || !queue_2.empty())
	{
		if (!queue_1.empty() && queue_2.empty())   // queue1�ǿգ�queue2Ϊ��
		{
			while (queue_1.size() != 1)
			{
				int temp = queue_1.front();
				queue_1.pop();
				queue_2.push(temp);
			}
			int val = queue_1.front();
			cout << val << "->";    // ջ��Ԫ��
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
			cout << val << "->";    // ջ��Ԫ��
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
		cout << "|          ջ            |" << endl;
		cout << "|      1. ���Ԫ��       |" << endl;
		cout << "|      2. ɾ��Ԫ��       |" << endl;
		cout << "|      3. ��ӡԪ��       |" << endl;
		cout << "|      4. �˳�����       |" << endl;
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
			cout << "��ջ���Ԫ�أ�";
			int val;
			cin >> val;
			sStack.appendTail(val);
			cout << "�Ƿ���ջ���Ԫ��(y/n): ";
			char choice = 'y';
			cin >> choice;
			if (choice == 'n' || choice == 'N')
				break;
		}

		// ɾ��Ԫ��
		while (choiceval == '2')
		{
			cout << "ȷ��ɾ��ջ��Ԫ��(y/n): ";
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

		// ��ջ����ջ�״�ӡԪ��
		if (choiceval == '3')
		{
			sStack.PrintStack();
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