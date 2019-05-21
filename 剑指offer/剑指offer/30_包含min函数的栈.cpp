//-----------------------------------------------------------------------------
// 文 件 名: 30_包含min函数的栈.cpp
// 作    者：adoredee
// 创建时间：2019.05.21
// 描    述：包含min函数的栈
// 版    本：
//-----------------------------------------------------------------------------

// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
//      函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

template <typename T> 
class StackWithMin
{
public:
	StackWithMin() {}
	virtual ~StackWithMin() {}

	T& top();
	const T& top() const;    // 只有类的成员函数才能在函数名后面加上const

	void push(const T& value);
	void pop();

	const T& min() const;

	bool empty() const;
	size_t size() const;

private:
	std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
	std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};

template <typename T> 
void StackWithMin<T>::push(const T& value)
{
	// 把新元素添加到辅助栈
	m_data.push(value);

	// 当新元素比之前的最小元素小时，把新元素插入辅助栈里；
	// 否则把之前的最小元素重复插入辅助栈里
	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T> 
void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}


template <typename T> 
const T& StackWithMin<T>::min() const
{
	assert(m_data.size() > 0 && m_min.size() > 0);

	return m_min.top();
}

template <typename T> 
T& StackWithMin<T>::top()
{
	return m_data.top();
}

template <typename T> 
const T& StackWithMin<T>::top() const
{
	return m_data.top();
}

template <typename T> 
bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template <typename T> 
size_t StackWithMin<T>::size() const
{
	return m_data.size();
}

int main()
{
	StackWithMin<int> stack;

	stack.push(3);
	stack.push(2);
	stack.push(5);

	cout << "栈中最小元素为: " << stack.min() << endl;

	return 0;
}