//
// Created by 18483 on 2025/1/12.
//
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// ����90.�Ӽ���
/*
 * �����˼·�����Ӽ���Ŀ��˼·+����ܺ͢��е�����ȥ�ؼ���
 */
class Solution90
{
public:
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> used(nums.size(), 0);
        sort(nums.begin(), nums.end());

        function<void(int)> backtracking = [&](int start)-> void
        {
            ret.push_back(path);

            for (int i = start; i < nums.size(); i++)
            {
                // ����ȥ��
                if (i - 1 >= 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;

                path.push_back(nums[i]);
                used[i] = 1;
                backtracking(i + 1);
                path.pop_back();
                used[i] = 0;
            }
        };

        backtracking(0);

        return ret;
    }
};
