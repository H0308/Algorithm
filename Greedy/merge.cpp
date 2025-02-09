//
// Created by 18483 on 2025/2/9.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 力扣56.合并区间
/*
 * 本题与射爆气球思路也非常类似，依旧是判断当前区间的左边界是否小于等于上一区间的右边界作为判断重叠条件
 * 如果满足重叠，就需要合并区间，需要注意，默认情况下，返回值数组中有一个起始区间，合并区间之前需要先弹出前一个区间，并更新新的区间的左边界为前一个区间的左边界和当前区间的左边界中的最小值
 * 同理更新新的区间的右边界为前一个区间的右边界和当前区间的右边界的最大值
 * 此时也可以确保下一次比较是按照新区间和当前区间进行比较从而不会遗漏情况
 * 如果没有重叠就直接插入当前区间即可
 */
class Solution56
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end(), [](vector<int> &i1, vector<int> &i2)
        {
            return i1[0] < i2[0];
        });

        // 默认有第一个区间
        ret.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            // 判断当前区间的左边界是否小于等于上一区间的右边界
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                // 先移除前一个区间
                ret.pop_back();
                // 合并区间并插入合并后的区间
                intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
                ret.push_back(intervals[i]);
            }
            else
            {
                // 否则直接插入
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};
