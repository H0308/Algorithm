//
// Created by 18483 on 2025/1/8.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 力扣39.组合总和
/*
 * 本题与前面的组合问题最大的不同点就是每个元素可以被多次使用，即一个组合结果集中，同一个数字可以被重复使用多次
 * 但是其本质还是一个组合，只是因为多了上面的一个条件，使得每一次搜索应该从上一次搜索的位置继续向后，而不是全部从头开始，更不是像之前的直接从后一个元素进行搜索
 */
class Solution39_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int index)
    {
        // 防止栈溢出
        if (sum > target)
            return;
        // 更新结果
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0, 0);

        return ret;
    }
};

// 剪枝优化：结合排序
// 排序后可以使得原数组的元素单调递增，如果当前元素加上当前和sum已经大于target，那么后面的元素也就不需要再遍历了
// 注意此处的排序不可以省略，因为如果只是判断sum + 当前元素大于target就不再向后遍历时，就可能会出现后面存在小的元素可以确保sum + 小的元素等于target
class Solution39_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int index)
    {
        // 防止栈溢出
        if (sum > target)
            return;
        // 更新结果
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);

        return ret;
    }
};
