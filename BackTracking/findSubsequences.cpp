//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

// 力扣491.非递减子序列
/*
 * 使用unordered_set进行去重，只需要确保当前数值比当前组合的最后一个元素大即可插入到当前组合中
 * 本题不建议使用used数组进行去重，因为used数组需要用到排序的条件，但是本题不能进行排序，一旦排序就会打乱原有的元素顺序从而出现不存在的非递减序列
 *
 * 拓展：之前使用used数组进行去重的题目也可以使用unordered_set进行去重，道理都是一样的，只是思路上有一点不同
 */
class Solution491_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        function<void(int)> backtracking = [&](int start)-> void
        {
            if (path.size() >= 2)
                ret.push_back(path);

            // 使用set记录当前层的数值，便于后续判断是否重复使用数值相同的数字
            unordered_set<int> uset;
            for (int i = start; i < nums.size(); i++)
            {
                // 树层去重
                if (!path.empty() && nums[i] < path.back() || uset.count(nums[i]))
                    continue;

                path.push_back(nums[i]);
                // 不需要对uset进行回溯，因为每一次递归都是新的uset
                uset.insert(nums[i]);
                backtracking(i + 1);
                path.pop_back();
            }
        };

        backtracking(0);

        return ret;
    }
};

// 数组优化
// 因为本题数据范围是[-100, 100]，所以可以考虑直接使用数组进行直接定址，但是需要注意，因为存在负数，所以考虑整体对插入的数字加100，映射到[0, 200]范围的空间
class Solution491_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        function<void(int)> backtracking = [&](int start)-> void
        {
            if (path.size() >= 2)
                ret.push_back(path);

            // 使用set记录当前层的数值，便于后续判断是否重复使用数值相同的数字
            int uset[201] = {0};
            for (int i = start; i < nums.size(); i++)
            {
                // 树层去重
                if (!path.empty() && nums[i] < path.back() || uset[nums[i] + 100])
                    continue;

                path.push_back(nums[i]);
                // 不需要对uset进行回溯，因为每一次递归都是新的uset
                uset[nums[i] + 100] = 1;
                backtracking(i + 1);
                path.pop_back();
            }
        };

        backtracking(0);

        return ret;
    }
};
