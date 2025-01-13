//
// Created by 18483 on 2025/1/13.
//
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 力扣47.全排列Ⅱ
/*
 * 本题就是全排列的思路+使用unordered_set对同层进行去重，但是因为本题数据范围很小，所以直接考虑用数组代替unordered_set
 *
 * 注意，如果使用used数组进行去重，此时会出现树层和树枝去重都可以解决的效果，具体原因以数组[1,1,1]分析，更推荐树层去重
 */
class Solution
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // 使用used标记是否已经使用过
        vector<bool> used(nums.size(), false);

        function < void() > backtracing = [&]()-> void
        {
            if (path.size() == nums.size())
            {
                ret.push_back(path);
                return;
            }

            // 记录当前层是否有相同元素已经被使用
            int isAppeared[21] = {0};

            for (int i = 0; i < nums.size(); i++)
            {
                if (used[i] || isAppeared[nums[i] + 10])
                    continue;

                path.push_back(nums[i]);
                used[i] = true;
                isAppeared[nums[i] + 10] = 1;
                backtracing();
                path.pop_back();
                used[i] = false;
            }
        };

        backtracing();

        return ret;
    }
};
