//
// Created by 18483 on 2025/1/19.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣494.目标和
/*
 * 本题因为每个数字都有两种情况，所以可以理解为两棵二叉树，第一棵二叉树根节点为1，第二棵二叉树根节点为-1，以此类推
 *
 * 1. 当前数值为正数，计算和为sum+nums[i]
 * 2. 当前数值为负数，计算和为sum-nums[i]
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

        // 当取正号
        backtracking(nums, target, start + 1, nums[start] + sum);
        // 当取负号
        backtracking(nums, target, start + 1, sum - nums[start]);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        backtracking(nums, target, 0, 0);

        return count;
    }
};
