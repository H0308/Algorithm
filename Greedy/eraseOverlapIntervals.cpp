//
// Created by 18483 on 2025/2/9.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 力扣435.无重叠区间
/*
 * 本题思路与射爆气球思路非常类似，不同的是，本题不考虑等于的情况，即比较左边界是否小于上一个元素的右边界作为判断重叠的条件
 * 如果满足重叠条件，就更新计数器，并且因为要判断下一个区间是否依旧重叠，需要更新右边界为较小的右边界，这一步更新就相当于移除当前导致重叠的区间
 * 让新区间和旧区间再做一次判断是否重叠
 */
class Solution435
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int count = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &i1, vector<int> &i2)
        {
            return i1[0] < i2[0];
        });

        for (int i = 1; i < intervals.size(); i++)
        {
            // 判断当前位置的左边界是否小于前一个位置的右边界
            if (intervals[i][0] < intervals[i - 1][1])
            {
                count++;
                // 取最小右边界作为下一次判断的条件，此步骤就相当于移除重叠区间
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return count;
    }
};
