//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.23
// ��    ������С�����
//-----------------------------------------------------------------------------
/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums)
{
	// �쳣���� ���� ����Ϊ�ջ��������СС�ڵ���0
	if (nums.empty() || nums.size() <= 0)
	{
		return -1;
	}

	int sum = nums[0], max_sum = nums[0];
	for (int i = 1;	i < nums.size(); i++)
	{
		// ����������ڵ�nums[i]���ۼ�ֵ��nums[i]��ҪС������ȥ֮ǰ���ۼӺ�
		sum = max(sum + nums[i], nums[i]);
		if (sum > max_sum)
			max_sum = sum;
	}

	return max_sum;

}

int main()
{
	vector<int> arr = {-2, -1,-3, -4, -1, -2, -1, -5, -4};

	cout << "��������к�Ϊ" << maxSubArray(arr) << endl;

	return 0;
}