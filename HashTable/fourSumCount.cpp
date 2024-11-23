//
// Created by 18483 on 2024/11/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 力扣454.四数相加II
class Solution454
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // map处理和与次数的映射
        unordered_map<int, int> m;
        int count = 0;
        // 遍历前两个数组
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                m[nums1[i] + nums2[j]]++;
            }
        }

        // 遍历后两个数组，如果获取到的值0-(c+d)==a+b，则说明出现过至少一次
        for (int i = 0; i < nums3.size(); i++)
        {
            for (int j = 0; j < nums4.size(); j++)
            {
                if (m.count(0 - nums3[i] - nums4[j]))
                {
                    count += m[0 - nums3[i] - nums4[j]];
                }
            }
        }

        return count;
    }
};
