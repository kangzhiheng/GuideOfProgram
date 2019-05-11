//-----------------------------------------------------------------------------
// �� �� ��: 20_��ʾ��ֵ���ַ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.11
// ��    ������ʾ��ֵ���ַ���
// ��    ����
//-----------------------------------------------------------------------------

// ������20����ʾ��ֵ���ַ���
// ��Ŀ����ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
//      �ַ�����+100������5e2������-123������3.1416������-1E-16������ʾ��ֵ������12e����
//      ��1a3.14������1.2.3������+-5������12e+5.4��������

/*
    ע�⣺
    Դ������ȱ�ݣ������������ -.e2��Ҳ���ж�Ϊ��ȷ���ʼ���46��47�����ж����
*/


#include <iostream>

using namespace std;

bool scanUnsignedInteger(const char **str);
bool scanInteger(const char** str);

/* ���ָ�ʽ������ [A][.[B]][e|E][C]����.B[e|E][C]��ʾ
   A:�з���������+/-
   B:�޷���������ʾС������
   C:�з�������,��ʾָ����+/-
*/

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
// �����������������ţ�Ҳ����û�У�����B��һ���޷�������
bool isNumeric(const char* str)
{
	// �쳣����
	if (str == nullptr)
		return false;

	// 1. ɨ��A����
	bool numeric = scanInteger(&str);
	// ����� -.e2 �������ͣ�����A�����ж���false����ʱ�Ϳ�����Ϊ���ַ��������Ա�ʾһ����ֵ
	if (numeric == false)
		return false;

	// 2. �ж�A���ֺ��ǲ���С���㣬��������ַ���С���㿪ʼ
	// �������'.'�������������ֵ�С������B
	if (*str == '.')
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	// 3. �ж�A��B���ֺ��ǲ�����e����E��ʼ
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && scanInteger(&str);
	}

	// �жϽ�����ʾ��־��numeric״̬��������ַ��Ƿ��жϵ����һλ
	return numeric && *str == '\0';

}

// �ж�A����C�����Ƿ����з�����������+/-���������
bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
			++(*str);    // ���str�ĵ�һ���ַ�Ϊ +/- �ţ����ַ������һλ

	// �жϽ������Ĳ����Ƿ�����������
	return scanUnsignedInteger(str);
}

// �Ƿ�������
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;    // ��*str����ʼ��ַ��ֵ��before
	// ��û�е��ַ���ĩβ�����ҵ�ǰ�ַ���0~9֮��
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	// ��*str�д�������0~9������ʱ������true
	// Ϊʲô�Ǵ��ںţ���Ϊ�ַ�����������Ԫ�صĵ�ַ���ε��������Ժ���Ԫ�صĵ�ַ����ǰ��ģ�
	// �������whileѭ���壬���ʾ*str�д�������0~9�����֣�
	// ������ѭ����Ԫ�صĵ�ַ�϶������ʼ�ĵ�ַ�����Է���true
	return *str > before;
}

int main()
{
	const char* str = "1.1e1";

	if (isNumeric(str))
		cout << "���ַ������Ա�ʾΪһ����ֵ" << endl;
	else
		cout << "���ַ��������Ա�ʾΪһ����ֵ" << endl;

	return 0;
}