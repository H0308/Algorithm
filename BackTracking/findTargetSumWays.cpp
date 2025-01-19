//
// Created by 18483 on 2025/1/19.
//
#include <iostream>
#include <vector>

using namespace std;

// ����494.Ŀ���
/*
 * ������Ϊÿ�����ֶ���������������Կ������Ϊ���ö���������һ�ö��������ڵ�Ϊ1���ڶ��ö��������ڵ�Ϊ-1���Դ�����
 *
 * 1. ��ǰ��ֵΪ�����������Ϊsum+nums[i]
 * 2. ��ǰ��ֵΪ�����������Ϊsum-nums[i]
 */
class Solution494
{
public:
    int count = 0;

    void backtracking(vector<int> &nums, int target, int start, int sum)
    {
        if (start == nums.size())
        {
            if (sum == target)
                count++;
            return;
        }

        // ��ȡ����
        backtracking(nums, target, start + 1, nums[start] + sum);
        // ��ȡ����
        backtracking(nums, target, start + 1, sum - nums[start]);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        backtracking(nums, target, 0, 0);

        return count;
    }
};
