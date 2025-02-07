//
// Created by 18483 on 2025/2/7.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣134.加油站
/*
 * 本题的暴力思路是模拟每一个位置作为起点判断是否可以走到终点，但是时间复杂度比较高，考虑使用贪心
 * 本题主要贪的就是当前位置及之前的和是否是对油量有增益效果（即加的油和最后消耗的油之和是否大于0），如果没有，就到下一个位置继续查找，如果总和都是消耗效果，那么说明不存在该起点
 */
class Solution134
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 记录当前位置是增益还是损耗
        int curSum = 0;
        // 记录整体和是增益还是消耗
        int totalSum = 0;
        // 记录起始位置
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];

            // 如果当前位置是消耗，则说明之前的所有位置作为起始位置到达当前位置都会导致油量不够
            if (curSum < 0)
            {
                // 从下一个位置开始
                start = i + 1;
                // 重新统计增益还是消耗
                curSum = 0;
            }
        }

        // 如果整体是消耗，则说明不存在一个起点可以满足条件
        if (totalSum < 0)
            return -1;
        return start;
    }
};
