//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣78.子集
/*
 * 自己问题本质也是组合问题，但是子集和前面的组合问题不同的是，子集问题中每一次的递归都会存在需要的结果，而前面的组合只有在满足条件时才会可能有需要的结果
 * 所以子集问题收集结果时需要每一次递归就收集一次
 * 另外，因为组合问题注定会有下标控制防止重复，而本题的子集问题不需要考虑特定条件终止递归，所以本题的递归也可以不显式写递归终止条件，其逻辑已经在循环中体现
 */
class Solution78
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(const vector<int> &nums, int start)
    {
        ret.push_back(path);
        // 可以不需要单独写递归结束条件，start赋值给i时会在下面的for循环判断从而结束递归
        // if(start == nums.size())
        //     return;

        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtracking(nums, 0);

        return ret;
    }
};
