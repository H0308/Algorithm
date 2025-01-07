//
// Created by 18483 on 2025/1/7.
//
#include <iostream>
#include <vector>

using namespace std;

// 力扣216.组合总和Ⅲ
// 基本思路和力扣77一致，唯一不同的是递归结束条件包括path长度和sum都满足要求
// 另外在枚举每一种情况时需要更新path和sum，递归结束后需要恢复path和sum，直到找到满足的情况才将path插入到结果集中
class Solution216_1
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(int k, int n, int sum, int start)
    {
        if (path.size() == k && sum == n)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backtracking(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 0, 1);
        return ret;
    }
};

// 剪枝优化
// 本题的剪枝很明显，如果sum已经大于目标值n时就不需要再向后递归了
// 除了上面的剪枝外，与力扣77一样也有对for循环的次数进行剪枝
class Solution216_2
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    void backtracking(int k, int n, int sum, int start)
    {
        if (path.size() == k && sum == n)
        {
            ret.push_back(path);
            return;
        }

        for (int i = start; i <= (9 - (k - path.size()) + 1); i++)
        {
            path.push_back(i);
            sum += i;
            // 剪枝优化
            if (sum > n)
            {
                path.pop_back();
                sum -= i;
                return;
            }
            backtracking(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 0, 1);
        return ret;
    }
};
