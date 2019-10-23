//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.22
// ��    ������������λ��
//-----------------------------------------------------------------------------
/*
    ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
	����Լ������������ظ�Ԫ�ء�

    ʾ�� 1:
    
    ����: [1,3,5,6], 5
    ���: 2
    ʾ�� 2:
    
    ����: [1,3,5,6], 2
    ���: 1
    ʾ�� 3:
    
    ����: [1,3,5,6], 7
    ���: 4
    ʾ�� 4:
    
    ����: [1,3,5,6], 0
    ���: 0
*/
#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	if (nums.empty() || nums.front() > target)  // ����Ϊ��,����Ŀ��ֵ������ֵΪ0
		return 0;
	if (nums.back() < target)
		return nums.size();

	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		if (nums[mid] == target)
			return mid;
		if (target < nums[mid])
			right = mid - 1;
		else if (target > nums[mid])
			left = mid + 1;

	}
	return nums[mid] > target ? mid : mid + 1;

}
int main()
{
	vector<int> arr = { 1, 3, 5, 7 };
	int target = 2;

	int mid = searchInsert(arr, target);

	cout << mid << endl;

	return 0;
}