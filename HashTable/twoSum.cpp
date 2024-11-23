//
// Created by 18483 on 2024/11/23.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 力扣1.两数之和
// 判断target - 当前数值是否在map中，如果在就说明map中的数值和当前数值为需要的数值，返回下标即可
// 不用set是因为要返回下标，需要建立下标和数值的映射
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ret;
        // map存储下标和数值映射
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]))
            {
                return {i, m[target - nums[i]]};
            }
            m.insert({nums[i], i});
        }

        return {0};
    }
};

// 如果本题没有限制返回下标，则可以考虑使用双指针