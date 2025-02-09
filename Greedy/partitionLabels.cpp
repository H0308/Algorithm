//
// Created by 18483 on 2025/2/9.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 力扣763.划分字母区间
/*
 * 本题最容易想到的就是找到最大区间边界，判断哪些字母的最远位置小于等于最远区间边界就囊括这些字母放在一个区间中
 * 所以就需要先统计每个字母最远出现的位置
 * 接着就是再一次遍历整个字符串，遍历的过程中不断更新最远区间边界，确保其可以囊括当前字母
 * 一旦当前位置等于最远区间边界就说明已经找到一个区间
 * 本题获取到每个字母最远出现的位置后，不要考虑仅根据每个字母最远出现的位置进行分割，因为单看这个位置值无法确定何时差值为一个合理值，他们之间本身没有直接的关系
 * 有关系的应该是每个字母的当前下标和当前字母之前的最远区间边界值，如果当前下标小于最远边界值，那么就一定说明后面还出现过当前字母之前的字母
 * 所以考虑完统计每个字母最远出现的位置后，应该考虑遍历原字符串而不是仅仅死磕每个字母的出现位置，从而将每个字母的当前位置和最远出现位置联系起来
 */
class Solution763
{
public:
    vector<int> partitionLabels(string s)
    {
        // 使用哈希表统计每个字符最远出现的位置
        unordered_map<char, int> maxPos;

        for (int i = 0; i < s.size(); i++)
            maxPos[s[i]] = i;

        // 从前向后遍历整个字符串，找出每个区间的最大位置
        int start = 0, end = 0;
        vector<int> ret;
        for (int i = 0; i < s.size(); i++)
        {
            end = max(end, maxPos[s[i]]);
            // 如果当前位置已经到达区间最大位置，就说明已经找到一个区间
            if (i == end)
            {
                ret.push_back(end - start + 1);
                // 更新左边界
                start = i + 1;
            }
        }

        return ret;
    }
};
