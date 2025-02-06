//
// Created by 18483 on 2025/2/6.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣53.最大子数组和
/*
 * 本题还是考虑使用局部最优推出全局最优的思路，考虑到如果当前和为负数时，那么不论下一个数是否是正数，都更新到下一个数，此时需要做到每一次计算和都保存一次和的最大值
 * 如果当前和小于0，更新sum到新的数
 * 此时存在两种情况：
 * 1. 当前为负数，此时因为ret已经存了上一次计算的和，如果当前为负数那么哪怕是小于当前sum的数也不会影响到最终结果
 * 2. 当前为正数，因为正数相加只会越来越大，如果sum为负数，那么与其加上正数，不如直接使用正数
 */
class Solution53
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ret = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 计算当前和
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];

            // 获取到当前的最大结果
            ret = max(sum, ret);
        }

        return ret;
    }
};
