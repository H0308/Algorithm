//
// Created by 18483 on 2025/1/31.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 力扣455.分发饼干
/*
 * 首先理解题目的要求：保证当前饼干的尺寸可以满足孩子的胃口，也就是说，可能存在孩子的胃口大于当前饼干的尺寸
 * 所以考虑遍历饼干，当遇到一个饼干尺寸大于等于孩子的胃口时，就更新孩子数组的下标，但是此时就会出现一个问题：
 * 当饼干数组的大小小于孩子数组的大小时，如果饼干数组中所有的元素均小于孩子数组对应的元素，但是孩子数组剩余的元素存在小于饼干数组的元素时就会出现遗留
 * 所以考虑对两个数组都进行排序，确保可以满足大的饼干优先喂给胃口小的孩子，这样就不会出现遗漏计算
 * 因为一旦大尺寸的饼干喂给了小胃口的孩子，那么当前尺寸的饼干之前的饼干一定是没有意义的，所以继续向后遍历即可
 * 而孩子数组只需要更新下标到下一个孩子，即一旦饼干满足胃口就更新下标
 */
class Solution455
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int index = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (index < g.size() && s[i] >= g[index])
            {
                index++;
                count++;
            }
        }

        return count;
    }
};
