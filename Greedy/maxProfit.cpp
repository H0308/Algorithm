//
// Created by 18483 on 2025/2/6.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣121.买卖股票的最佳时机
/*
 * 本题可以考虑思路：如果购买时的价格与卖出时的价格之差小于0，说明买的时候买贵了，此时不论后面怎么卖都不可能出现比下一次买利润多
 * 所以可以推出下面的情况：如果当前利润小于0，说明如果在下一次买入可能会获得更大利润，此时只需要更新指针指向下一次买入的价格即可，如果当前利润大于0，说明已经存在可用利润
 * 只需要更新遍历的指针，每一次遍历求出最大利润即可
 */
class Solution121
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 如果只有一个元素，说明没有卖出时间，直接返回0
        // 或者理解为买入即卖出
        if (prices.size() < 2)
            return 0;

        int ret = INT_MIN;
        for (int fast = 1, slow = 0; fast < prices.size() && slow < prices.size();)
        {
            int pro = prices[fast] - prices[slow];
            if (pro < 0)
                slow++;
            else
                fast++;
            ret = max(pro, ret);
        }

        return ret;
    }
};

// 力扣122.买卖股票的最佳时机Ⅱ
/*
 * 通过121题的理解，可以知道本题的大致意思，接着考虑本题的思路：
 * 考虑一个等式：假设i, j, k分别表示三个连续的下标，那么区间之差p[k]-p[i] = p[k]-p[j] + p[j]-p[i]
 * 通过上面这个等式，以[7,1,5,3,6,4]为例
 * 假设买入的是下标为1的股票，卖出时价格为下标为4的元素，那么p[4]-p[1] = p[4]-p[3]+p[3]-p[2]+p[2]-p[1] = 3 + -2 + 4 = 5
 * 也就是说，如果可以求出连续的差之和最大那么最后的利润就是最大的，即相邻元素之差之和最大即可获得最大利润
 * 此时就可以考虑何时使相邻元素之差之和最大，很明显，如果相邻元素之差为负数，那么此时和肯定会减小
 * 所以只需要做到相邻元素之和为正数时累加即可获得最大利润
 */
class Solution122
{
public:
    int maxProfit(vector<int> &prices)
    {
        int pro = 0;
        int ret = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            // 计算相邻元素之差
            int pro = prices[i] - prices[i - 1];
            // 如果相邻元素之差大于0即可累加
            if (pro > 0)
                ret += pro;
        }
        return ret;
    }
};
