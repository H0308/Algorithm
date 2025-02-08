//
// Created by 18483 on 2025/2/8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 力扣452.用最少数量的箭引爆气球
/*
 * 本题的基本思路就是找出尽可能让可以用一支箭矢射爆的气球聚集在一起（即气球是否重叠），要判断是否重叠首先就需要对所有气球进行排序，可以按照左边界排序，也可以按照右边界排序
 * 下面以按照左边界排序为例，排序完后，相邻的气球就可以通过判断当前气球的左边界和上一个气球的右边界是否重叠决定是否需要增加箭矢
 * 接下来是本题的细节，除了判断当前气球和上一个气球是否重叠外，还需要判断下一个气球是否和当前或者上一个气球重叠，如果不重叠就依旧需要增加箭矢，判断方式就是找到当前气球和上一个气球的最小右边界
 * 只要大于这个最小右边界就可以满足不需要增加箭矢而使用同一支箭矢射爆气球
 */
class Solution452
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;

        int count = 1;

        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2)-> bool
        {
            // return p1[0] < p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
            // 也可以只比较左边界，因为下面会对右边界根据较小值进行更新
            return p1[0] < p2[0];
        });

        for (int i = 1; i < points.size(); i++)
        {
            // 如果没有重叠，就更新需要的箭矢数量
            // 即当前气球的左边界大于前一个气球的右边界
            if (points[i][0] > points[i - 1][1])
                count++;
            else
            {
                // 此时一定是有重合的，但是除了判断当前气球和上一个气球是否有重合外还需要判断下一个气球是否也可以使用同一支箭
                // 所以就需要更新右边界为当前气球的右边界和上一个气球的右边界的最小值
                // 更新完后，下一次判断就会拿着这个最小值判断是否有重叠从而决定是否需要增加箭矢
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return count;
    }
};
