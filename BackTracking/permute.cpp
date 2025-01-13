//
// Created by 18483 on 2025/1/13.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣46.全排列
/*
 * 排列与组合不同的是，排列讲究每一个结果中元素之间的顺序，一旦顺序不同，就是两种不同的情况，例如[1,2,3]和[1,3,2]
 * 可以看到在排列中，尽管已经取过一个元素，下一次依旧还是从头开始找，并且还需要跳过已经选择的数字，所以可以考虑使用一个used数组用来标记取过的元素
 */
class Solution46
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(const vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;

            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);

        backtracking(nums, used);

        return ret;
    }
};
