//
// Created by 18483 on 2025/2/19.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣746.使用最小花费爬楼梯
/*
 * 本题的先理解题意，本题的意思是可以从0或者1开始爬楼梯，那么当前位置需要的消耗要么就是跳到前一个位置需要的消耗+跳到当前位置需要的效果（从起始位置跳一步），要么就是跳到前一个位置的前一个位置需要的消耗+跳到当前位置的前一个位置需要的消耗（从起始位置跳两步）
 * 所以dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
 * 其中dp数组的每个元素和下标表示跳到当前层数（下标）需要消耗的值为当前元素
 * 因为题目提到既可以从0开始，也可以使用1开始，那么只要站在起始位置就不会消耗起始位置需要的体力，因为此时还没有开始跳
 * 何时结束，就是在跳到顶层时，所谓的顶层就是体力数组元素的个数
 */
class Solution746
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1);

        // 因为可以从0或者1开始爬，所以起始的两个位置都是初始化为0
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

        return dp[cost.size()];
    }
};
